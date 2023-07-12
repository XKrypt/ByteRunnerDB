# Encontre o caminho para o Mono
set(Mono_INCLUDE_DIRS "/usr/include/mono-2.0")

# Defina a biblioteca Mono
find_library(Mono_LIBRARY NAMES mono-2.0 mono)

# Verifique se o Mono foi encontrado
if(NOT Mono_INCLUDE_DIRS)
    message(WARNING "Diretórios de inclusão do Mono não encontrados. Certifique-se de que o Mono esteja instalado e configurado corretamente.")
endif()

if(NOT Mono_LIBRARY)
    message(WARNING "Biblioteca do Mono não encontrada. Certifique-se de que o Mono esteja instalado e configurado corretamente.")
endif()

# Defina a variável Mono_FOUND como verdadeira se o Mono for encontrado
if(Mono_INCLUDE_DIRS AND Mono_LIBRARY)
    set(Mono_FOUND TRUE)
endif()

# Se o Mono for encontrado, forneça as informações de importação
if(Mono_FOUND)
    set(Mono_INCLUDE_DIRS "${Mono_INCLUDE_DIRS}")
    set(Mono_LIBRARIES "${Mono_LIBRARY}")
    set(Mono_INCLUDE_DIR "${Mono_INCLUDE_DIRS}")
    set(Mono_LIBRARY_DIR "${Mono_LIBRARY}")
    set(Mono_FOUND TRUE)

    # Crie um alvo de importação para o Mono
    add_library(Mono::Mono INTERFACE IMPORTED)
    message("Incluindo mono includes")
    include_directories(Mono_INCLUDE_DIR)
    set_property(TARGET Mono::Mono PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Mono_INCLUDE_DIR})
    set_property(TARGET Mono::Mono PROPERTY INTERFACE_LINK_LIBRARIES ${Mono_LIBRARIES})
endif()