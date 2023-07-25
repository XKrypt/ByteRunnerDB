#ifndef CLI_RUNNER
#define CLIRUNNER

namespace CliRunner
{
    void createProject(std::string &projectName);
    void runDevProject();
    std::string getCurrentRunningFolder();
} // namespace CliRunner

#endif