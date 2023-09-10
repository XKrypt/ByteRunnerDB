#pragma once
#include "../runner_window.h"

namespace RunnerGuiWindows
{
    class ConsoleWindow : public RunnerWindow
    {
    private:
        /* data */
    public:
        ConsoleWindow(/* args */);
        ~ConsoleWindow();

        void OnUpdate() override;
    };
}