#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

std::string WideCharToAnsi(const wchar_t* wideStr) {
    int size = WideCharToMultiByte(CP_ACP, 0, wideStr, -1, NULL, 0, NULL, NULL);
    std::string result(size, 0);
    WideCharToMultiByte(CP_ACP, 0, wideStr, -1, &result[0], size, NULL, NULL);
    return result;
}

void ExecuteProgram(const wchar_t *executablePath, int timeoutMilliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(timeoutMilliseconds));

    std::string ansiPath = WideCharToAnsi(executablePath);

    HINSTANCE result = ShellExecuteA(NULL, "runas", ansiPath.c_str(), NULL, NULL, SW_SHOWNORMAL);

    TerminateProcess(result, 1);
}

int main(int argc, char **argv) {
    const wchar_t *executablePath = L"C:\\Program Files (x86)\\ASUS\\GameFirst\\GameTurbo.exe";

    int timeoutMilliseconds = 15000;  

    ExecuteProgram(executablePath, timeoutMilliseconds);

    exit(EXIT_SUCCESS);
}


