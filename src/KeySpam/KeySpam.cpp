#include <iostream>
#include <Windows.h>


int get_size_char(char* userch) {
    int out = 0;
    for (char* c = userch; *c != '\0'; c++, out++);

    return out;
}


void keSpam(char* userin) {
    INPUT ip;
    int count = 0;
    int count_num = 0;
    int len = get_size_char(userin);
    int i = 0;
    memset(&ip, 0, sizeof(ip));

    Sleep(5000);

    while (true) {
        if (count >= 5) {
            count = 0;
            Sleep(5000);
        }

        for (i = 0; i < len; i++) {            
            ip.type = INPUT_KEYBOARD;
            ip.ki.wVk = VkKeyScanA(userin[i]);
            SendInput(1, &ip, sizeof(INPUT));

            count_num++;
            std::cout << "Key Pressed: " << count_num << std::endl;
        }
        count++;

        ip.ki.wVk = 0x0D;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
    }

}


int main()
{
    char userin[100];

    std::cout << "      Created By: EH" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    std::cout << "Enter any letter: ";
    std::cin.getline(userin, sizeof(userin));
    keSpam(userin);

    system("pause");

    return 0;
}
