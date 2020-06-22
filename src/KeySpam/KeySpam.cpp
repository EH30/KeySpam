#include <iostream>
#include <Windows.h>


void keSpam() {
    INPUT ip;
    int count = 0;
    int count_num = 0;

    Sleep(5000);
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    while (true) {
        if (count == 5) {
            count = 0;
            Sleep(5000);
        }

        ip.ki.wVk = 0x45;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));

        ip.ki.wVk = 0x0D;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));

        count++;
        count_num++;

        std::cout << "Key Pressed: " << count_num << std::endl;
    }

}


int main()
{
    std::cout << "      Created By: EH" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    keSpam();
    return 0;
}
