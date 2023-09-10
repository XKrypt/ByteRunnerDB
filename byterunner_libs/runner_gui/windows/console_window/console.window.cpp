#include "console.window.h"
#include "../../../../imgui/imgui.h"
#include "../../../../imgui/imgui_internal.h"
#include <iostream>

RunnerGuiWindows::ConsoleWindow::ConsoleWindow()
{
}

RunnerGuiWindows::ConsoleWindow::~ConsoleWindow()
{
}

void RunnerGuiWindows::ConsoleWindow::OnUpdate()
{
  ImGuiWindowFlags flags = 0;
  ImGuiID dockspace_id = ImGui::GetID("ConsoleDock");
  ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
  ImGui::DockBuilderSetNodeSize(dockspace_id, ImVec2(ImGui::GetMainViewport()->Size.x, 150));
  bool showWindow = true;
  if (ImGui::Begin("Console", &showWindow, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_HorizontalScrollbar))
  {
    char input[25] = "Olaa";
    ImGui::InputText("Search", input, sizeof(input));
    ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Down, 0.7f, &dockspace_id, nullptr);

    for (size_t i = 0; i < 2; i++)
    {
      ImGui::Text("OlaQui duis excepteur commodo laboris amet enim sunt do eu veniam sint ea labore." + 1);
    }

    if (ImGui::TreeNode("Nó 1"))
    {
      // Conteúdo do nó 1
    ImGui::Selectable("teste");
     if (ImGui::IsItemClicked(1))
      {
        ImGui::OpenPopup("Menu de Contexto");
      }
       ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 10.0f);
      if (ImGui::BeginPopup("Menu de Contexto"))
      {
        if (ImGui::MenuItem("Opção 1"))
        {
          // Lógica para ação da opção 1
        }
        if (ImGui::MenuItem("Opção 2"))
        {
          // Lógica para ação da opção 2
        }
        ImGui::EndPopup();
      }
      ImGui::PopStyleVar();
  
    
      ImGui::TreePop();
    }

    if (ImGui::TreeNode("Nó 2"))
    {
      // Conteúdo do nó 2
      ImGui::TreePop();
    }
  }

  ImGui::DockBuilderFinish(dockspace_id);
  ImGui::End();
}