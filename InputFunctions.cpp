#include "Functions.h"


void PressEnter(){


    INPUT PressEnter;
    INPUT KeyUpEnter;
    
    int InputSize = sizeof(INPUT);

    PressEnter.type = INPUT_KEYBOARD;
    PressEnter.ki.wVk = VK_RETURN;
    PressEnter.ki.dwFlags = 0;
    

    KeyUpEnter.type = INPUT_KEYBOARD;
    KeyUpEnter.ki.wVk = VK_RETURN;
    KeyUpEnter.ki.dwFlags = KEYEVENTF_KEYUP;
    
    UINT pressing = SendInput(1, &PressEnter, InputSize);
    
    Sleep(870);
    
    UINT unpressing = SendInput(1, &KeyUpEnter, InputSize);

    if (pressing != 1 || unpressing != 1)
    {
        std::cerr << "Error on Enter Function";
    }
    
}


void FocusOnSearchBar(){

    //Function to press the Ctrl + L command to focus the search bar

    INPUT inputs[4] = {};

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_CONTROL;
    
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'L';

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 'L';
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_CONTROL;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
    
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

}


void WriteSearch(const string& texto) {
    
    for (char letra : texto) {
        
        INPUT inputs[2] = {};
        
        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.wVk = 0;
        inputs[0].ki.wScan = letra;
        inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;

        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.wVk = 0;
        inputs[1].ki.wScan = letra;
        inputs[1].ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;

        SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

        /* Lil PAUSE BETWEEN EACH LETTER --> */ Sleep(50);
        
    }

}
