#include "main.window.h";
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../imgui/imconfig.h"
#include "../imgui/backends/imgui_impl_vulkan.h"
#include "../console_window/console.window.h"

RunnerGuiWindows::MainWindow::MainWindow(GLFWwindow* mainWindow)
{
	this->mainWindow = mainWindow;
	RunnerGuiWindows::activeMainWindow = this;

}

RunnerGuiWindows::MainWindow::~MainWindow()
{
}

void RunnerGuiWindows::MainWindow::GuiLoop()
{

	ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive] = ImVec4(0.231, 0.231, 0.231, 1);
	ImGui::GetStyle().Colors[ImGuiCol_Tab] = ImVec4(0.471, 0.471, 0.471, 1);
	ImGui::GetStyle().Colors[ImGuiCol_TabUnfocused] = ImVec4(0.361, 0.361, 0.361, 1);
	ImGui::GetStyle().Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.361, 0.361, 0.361, 1);
	ImGui::GetStyle().Colors[ImGuiCol_TabActive] = ImVec4(0.188, 0.188, 0.188, 1);
	ImGui::GetStyle().Colors[ImGuiCol_TabHovered] = ImVec4(0.4, 0.4, 0.4, 1);

	ImGui::GetStyle().Colors[ImGuiCol_DockingPreview] = ImVec4(0, 0, 0, 1);
	ImGui::GetStyle().Colors[ImGuiCol_DragDropTarget] = ImVec4(0, 0, 0, 1);
	ImGui::GetStyle().Colors[ImGuiCol_DockingEmptyBg] = ImVec4(1, 1, 1, 1);


	ImGui::BeginMainMenuBar();
	if (ImGui::BeginMenu("File")) {
		if (ImGui::MenuItem("Open runner project")) {

		}
		if (ImGui::MenuItem("Build and export")) {

		}
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("Edit")) {
		if (ImGui::MenuItem("Cut")) {

		}
		if (ImGui::MenuItem("Copy")) {

		}
		if (ImGui::MenuItem("Paste")) {

		}
		ImGui::EndMenu();
	}
	ImGui::EndMainMenuBar();

	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::SetNextWindowViewport(viewport->ID);

	ImGuiWindowFlags window_flags = 0;
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

	window_flags |= ImGuiWindowFlags_NoTitleBar;
	window_flags |= ImGuiWindowFlags_NoScrollbar;
	window_flags |= ImGuiWindowFlags_NoScrollWithMouse;

	window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
	window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

	bool open = true;
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_NoDocking);
	if (ImGui::Begin("MainDockSpace", nullptr, window_flags)) {
		// Crie um DockSpace
		ImGuiID dockspaceId = ImGui::GetID("MainDockSpace");
		ImGui::DockSpace(dockspaceId, ImVec2(0.0f, 0.0f));


		ConsoleWindow.OnUpdate();

		ImGui::PopStyleVar(2);
	}
	ImGui::End();



}


