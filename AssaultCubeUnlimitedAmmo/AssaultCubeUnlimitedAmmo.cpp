// AssaultCubeUnlimitedAmmo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>


int main()
{
    int PID;
    std::cout << "What is the PID: ";
    std::cin >> PID;

    uintptr_t playerBaseAddress = 0x50F4F4;

    uintptr_t ammoOffset = 0x150;

    int setAmmo = 20;

    HANDLE assaultCube = OpenProcess(PROCESS_ALL_ACCESS,FALSE,PID);


    uintptr_t pointerToAmmo;

    int ammo;

    ReadProcessMemory(assaultCube, (LPCVOID)playerBaseAddress, &pointerToAmmo, sizeof(uintptr_t), NULL);
    ReadProcessMemory(assaultCube, (LPCVOID)(pointerToAmmo + ammoOffset), &ammo, sizeof(int), NULL);
    WriteProcessMemory(assaultCube, (LPVOID)(pointerToAmmo + ammoOffset), &setAmmo, sizeof(int), NULL);
    std::cout << ammo;



    //WriteProcessMemory(assaultCube,ammoAddress, &setAmmo, sizeof(int), NULL);

    CloseHandle(assaultCube);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
