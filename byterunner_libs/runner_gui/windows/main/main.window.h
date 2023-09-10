#pragma once
#include <GLFW/glfw3.h>
#include "../console_window/console.window.h"
namespace RunnerGuiWindows{

	

	class MainWindow
	{
	public:
	    ConsoleWindow ConsoleWindow;
		MainWindow(GLFWwindow* mainWindow);
		~MainWindow();
		void	GuiLoop();
	private:
		GLFWwindow* mainWindow;

	};

	static RunnerGuiWindows::MainWindow *activeMainWindow;
}

