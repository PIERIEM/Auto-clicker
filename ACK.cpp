#include <iostream>
#include <windows.h>

int main()
{
    int N = 0;
    std::cout << "click per seconde : " << std::endl;
    std::cin >> N;
    N = 1000 / N;
    bool wasPressed = false;
    bool active     = false;

    INPUT i = {};       
    i.type = INPUT_MOUSE;
    i.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; 

    INPUT o = {};
    o.type = INPUT_MOUSE;
    o.mi.dwFlags = MOUSEEVENTF_LEFTUP;

    while (true) {
        bool isPressed = GetAsyncKeyState(VK_OEM_COMMA) & 0x8000;
        
        if (isPressed && !wasPressed) {
            active = !active;
        }

        if (active)
        {
            INPUT clicks[2] = {i, o};
            SendInput(2, clicks, sizeof(INPUT));
        }

        wasPressed = isPressed;
        Sleep(N);
    }
}
