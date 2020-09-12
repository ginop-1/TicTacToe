#include <iostream>

using std::string;
using std::cout;

void Clear()
{
    #if defined _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

void PrintGrid(string grid[8])
{
    Clear();
    cout << "\n"
         << grid[0] << "|" << grid[1] << "|" << grid[2] << "\n"
         << "-----" << "\n"
         << grid[3]<< "|" << grid[4] << "|" << grid[5] << "\n"
         << "-----" << "\n" 
         << grid[6] << "|" << grid[7] << "|" << grid[8] << "\n"
         << "\n" ;
}
