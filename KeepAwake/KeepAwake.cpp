// KeepAwake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <thread>

using namespace std::literals::chrono_literals;

void wait_awake(std::stop_token st)
{

    auto res = SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED);
    if (res == 0)
    {
        std::cerr << "das ging schief!";
    }
    else
    {
        while (!st.stop_requested())
            std::this_thread::sleep_for(10s);
    }

}


int main()
{
    std::cout << "setting ""system required"" execution state!\n";

    auto t = std::jthread(wait_awake);
    
    std::cin.ignore();

    std::cout << "exiting...\n";
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
