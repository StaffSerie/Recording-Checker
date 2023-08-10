#include <iostream>
#include <unordered_map>
#include <Windows.h>
#include <psapi.h>
#include <conio.h>
#include <string>
#include <cstdlib>

// Define your functions and variables here
// ...

void PrintColoredText(const std::wstring& text, unsigned short color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, color);
    std::wcout << text;
    SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
}

void RunSource1() {
    std::unordered_map<std::wstring, std::wstring> recordingSoftwares = {
{ L"screenstudio", L"ScreenStudio" },
{ L"nvsphelper64.exe", L"Geforce Experience" },
{ L"dxtory.exe", L"Dxtory" },
{ L"camtasia.exe", L"Camtasia" },
{ L"fraps.exe", L"Fraps" },
{ L"screencast.exe", L"Screencast" },
{ L"xsplit.exe", L"XSplit" },
{ L"playclaw.exe", L"PlayClaw" },
{ L"mirillis.exe", L"Mirillis Action" },
{ L"wmcap.exe", L"Bandicam" },
{ L"lightstream.exe", L"Lightstream" },
{ L"bdcam.exe", L"Bandicam"},
{ L"webrtcvad.exe", L"Audacity (recording)" },
{ L"obs64.exe", L"Obs Studio" },
{ L"openbroadcastsoftware.exe", L"Open Broadcaster Software" },
{ L"movavi.screen.recorder.exe", L"Movavi Screen Recorder" },
{ L"icecreamscreenrecorder.exe", L"Icecream Screen Recorder" },
{ L"smartpixel.exe", L"Smartpixel" },
{ L"d3dgear.exe", L"D3DGear" },
{ L"action.exe", L"Action" },
{ L"streamlabs.exe", L"Streamlabs" },
{ L"apowersoftfreescreenrecorder.exe", L"Apowersoft Free Screen Recorder" },
{ L"bandicamlauncher.exe", L"Bandicam (launcher)" },
{ L"hypercam.exe", L"HyperCam" },
{ L"gadwinprintscreen.exe", L"Gadwin PrintScreen" },
{ L"loiloilgamerecorder.exe", L"LoiLo Game Recorder" },
{ L"nchexpressions.exe", L"Express Animate (recording)" },
{ L"captura.exe", L"Captura" },
{ L"vokoscreenNG", L"VokoscreenNG" },
{ L"simple.screen.recorder", L"SimpleScreenRecorder" },
{ L"recordmydesktop", L"RecordMyDesktop" },
{ L"kazam", L"Kazam" },
{ L"gtk-recordmydesktop", L"Gtk-RecordMyDesktop" },
{ L"screenkey", L"Screenkey" },
{ L"pycharm64.exe", L"PyCharm (recording)" },
{ L"jupyter-notebook.exe", L"Jupyter Notebook (recording)" },
// ... (your software list)
    };

    bool found = false;

    DWORD processIds[1024], bytesReturned;
    if (EnumProcesses(processIds, sizeof(processIds), &bytesReturned)) {
        DWORD processCount = bytesReturned / sizeof(DWORD);

        for (DWORD i = 0; i < processCount; ++i) {
            DWORD processId = processIds[i];
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);

            if (hProcess) {
                WCHAR processName[MAX_PATH];
                if (GetModuleFileNameEx(hProcess, NULL, processName, MAX_PATH)) {
                    std::wstring processNameStr = processName;
                    size_t lastBackslash = processNameStr.find_last_of(L"\\");
                    if (lastBackslash != std::wstring::npos) {
                        std::wstring executableName = processNameStr.substr(lastBackslash + 1);
                        std::wstring executablePath = processNameStr.substr(0, lastBackslash + 1);

                        if (recordingSoftwares.find(executableName) != recordingSoftwares.end()) {
                            if (!found) {
                                // Here comes the TurtleMc art and welcome message
                                PrintColoredText(
                                    L"                                                  ,;\n"
                                    L"                                                .'/\n"
                                    L"           `-_                                .'.\'\n"
                                    L"             `;-_                           .' /\n"
                                    L"               `.-.        ,_.-'`'--'`'-._.` .'\n"
                                    L"                 `.`-.    /    .\"'.   _.'  /\n"
                                    L"                   `. '-.'_.._/0 \" 0\\/`    \\{\n"
                                    L"                     `.      |'-^Y^- |     //\n"
                                    L"                      (`\\     \\_.\"._/\\...-;..-.\n"
                                    L"                      `._'._,'` ```    _.:---''`\n"
                                    L"                         ;-....----'''\n"
                                    L"                        /   (\n"
                                    L"                        |  (`    Made by           \n"
                                    L"                        `.^'   StaffSerie              \n"
                                    L"                             play.turtlemc.net                 \n"
                                    , FOREGROUND_GREEN);
                                // Sleep for 3 seconds (3000 milliseconds)
                                Sleep(2000);
                                
                                // Show the username using system command
                                system("echo Hello, %USERNAME%\n\n\n");

                                // Detection message
                                PrintColoredText(
                                    L"We detected this recording software running in the background:\n", FOREGROUND_BLUE);

                                found = true;
                            }
                            PrintColoredText(
                                L"\"" + recordingSoftwares[executableName] + L"\" (PID: " + std::to_wstring(processId) + L")\n",
                                FOREGROUND_GREEN);
                            std::wcout << L"Path: " << executablePath << std::endl;
                        }
                    }
                }
                CloseHandle(hProcess);
            }
        }
    }

    if (!found) {
        system("echo Great, %USERNAME% is not recording!\n\n\n");
    }

    std::wcout << L"\n[!] Click any key to close the window.";
    _getch();
}
// Coded by StaffSerie <3
