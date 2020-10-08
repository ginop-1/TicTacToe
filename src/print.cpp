#include <iostream>

using std::string;
using std::cout;

void signature()
{
    cout << 
    "                     _        _               ___ _             ____           " << "\n"
    " _ __ ___   __ _  __| | ___  | |__  _   _   / ___(_)_ __   ___ |  _ \\         " << "\n"
    "| '_ ` _ \\ / _` |/ _` |/ _ \\ | '_ \\| | | | | |  _| | '_ \\ / _ \\| |_) |    " << "\n"
    "| | | | | | (_| | (_| |  __/ | |_) | |_| | | |_| | | | | | (_) |  __/          " << "\n"
    "|_| |_| |_|\\__,_|\\__,_|\\___| |_.__/ \\__, |  \\____|_|_| |_|\\___/|_|       " << "\n"
    "                                    |___/                                      " << "\n";
}

void wrongValue()
{
    cout << "wrong value, please reinsert: ";
}

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
