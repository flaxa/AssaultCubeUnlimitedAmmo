// AssaultCubeUnlimitedAmmo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>


int main()
{
    int PID;
    int setAmmo = 20;
    int ammo;

    uintptr_t playerBaseAddress = 0x50F4F4;
    uintptr_t ammoOffset = 0x150;
    uintptr_t pointerToAmmo;

    std::cout << "What is the PID: ";
    std::cin >> PID;

    HANDLE assaultCube = OpenProcess(PROCESS_ALL_ACCESS,FALSE,PID);


    ReadProcessMemory(assaultCube, (LPCVOID)playerBaseAddress, &pointerToAmmo, sizeof(uintptr_t), NULL);
    while (GetAsyncKeyState(0x41) == 0)
    {
        
        if (WriteProcessMemory(assaultCube, (LPVOID)(pointerToAmmo + ammoOffset), &setAmmo, sizeof(int), NULL) == FALSE) {
            std::cout << "Error Code: " << GetLastError() << std::endl;
            EXIT_FAILURE;

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
    
    CloseHandle(assaultCube);
    EXIT_SUCCESS;
}

