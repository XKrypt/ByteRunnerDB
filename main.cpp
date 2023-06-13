#include <iostream>
#include <mono-2.0/mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <fstream>
#include <json.hpp>

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}

int main()
{
    mono_set_dirs("/lib", "/etc");
    mono_config_parse("/etc/mono/config");
    MonoDomain *domain = mono_jit_init("Domain");

    if (!domain)
    {
        std::cout << "inicialização falhou";
    }
    if (!fileExists("../CSharp_Tests/test.cs"))
    {
        std::cout << "Arquivo não encontrado \n";
        return 0;
    }
    else
    {
        std::cout << "Arquivo encontrado.. \n";
    }

    std::cout << "Compilando arquivo .cs";
    system("mcs /target:library /out:../CSharp_Tests/test.dll ../CSharp_Tests/test.cs");
    std::cout << "Carregando assembly";
    MonoAssembly *assembly = mono_domain_assembly_open(domain, "../CSharp_Tests/test.dll");

    if (!assembly)
    {
        std::cout << "inicialização falhou";
    }

    std::cout << "carregando imagem";
    MonoImage *image = mono_assembly_get_image(assembly);
    if (!image)
    {
        std::cout << "erro ao carregar a imagem.. \n";
        return 0;
    }

    std::cout << "carregando classe";
    MonoClass *classe = mono_class_from_name(image, "", "test");

    if (!classe)
    {
        std::cout << "erro ao carregar a imagem.. \n";
        return 0;
    }

    MonoObject *mono_obj = mono_object_new(domain, classe);
    mono_runtime_object_init(mono_obj);
    MonoMethod *method = mono_class_get_method_from_name(classe, "test_func", 0);
    if (!method)
    {
        std::cout << "erro ao carregar o metodo.. \n";
        return 0;
    }
    std::cout << "Executando metodo...";
    mono_runtime_invoke(method, mono_obj, nullptr, nullptr);

    mono_jit_cleanup(domain);

    return 0;
}