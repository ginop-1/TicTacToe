#include <iostream>
#include <random>
#include <string>
#include <algorithm>

using namespace std;

void PrintGrid(string*);
void CPUmove(string*, string, string);
bool CheckWin(string*, string);

int main()
{
    string grid[9], playerXO, CPUXO; int startplayer, playermove, cpumove;
    for (int i=0; i<9; i++) grid[i] = " "; // cleaning array
    cout << "Welcome to the tris game, the initial player will be random\n\n" << "Choose beetween X or O: ";
    while (true) 
    {
        cin >> playerXO;
        if (playerXO == "X" || playerXO == "x" || playerXO == "O" || playerXO == "o") break;
        else cout << "wrong value, please reinsert: ";
    }
    for_each(playerXO.begin(), playerXO.end(), [](char & c) 
    { 
        c = toupper(c); // Upper up string
    }); 
    if (playerXO == "X") CPUXO = "O";
    else CPUXO = "X";
    PrintGrid(grid);
    srand (time(NULL)); startplayer = rand() % 2 + 0; // selecting random number (0 or 1) for starting player
    while (true)
    {
        if (startplayer == 0) 
        {
            cout << "it's your turn, choose a box\n";
            while (true) 
            {
                cin >> playermove;
                playermove--;
                if (grid[playermove] != " ") cout << "this box is already filled, please insert a valid value: ";
                else 
                {
                    grid[playermove] = playerXO; 
                    break;
                }
            }
            PrintGrid(grid);
            if (CheckWin(grid, playerXO)) 
            {
                cout << "Congrats, you have won!";
                break;
            } 
            startplayer = 1;
        }
        if (startplayer == 1)
        {
            CPUmove(grid, CPUXO, playerXO);
            cout << "CPU turn\n";
            PrintGrid(grid);
            startplayer = 0;
        }
    }
}

void PrintGrid(string grid[8])
{
    cout << "\n"
         << grid[0] << "|" << grid[1] << "|" << grid[2] << endl
         << "-----" << endl
         << grid[3]<< "|" << grid[4] << "|" << grid[5] << endl
         << "-----" << endl 
         << grid[6] << "|" << grid[7] << "|" << grid[8] << endl
         << "\n" ;
}

bool CheckWin(string grid[8], string XorO)
{
    if (grid[0] == XorO && grid[1] == XorO && grid[2] == XorO) return true; // first row
    if (grid[3] == XorO && grid[4] == XorO && grid[5] == XorO) return true; // second row
    if (grid[6] == XorO && grid[7] == XorO && grid[8] == XorO) return true; // third row
    if (grid[0] == XorO && grid[3] == XorO && grid[6] == XorO) return true; // first column
    if (grid[1] == XorO && grid[4] == XorO && grid[7] == XorO) return true; // second column
    if (grid[2] == XorO && grid[5] == XorO && grid[8] == XorO) return true; // third column
    if (grid[0] == XorO && grid[4] == XorO && grid[8] == XorO) return true; // first oblique
    if (grid[2] == XorO && grid[4] == XorO && grid[6] == XorO) return true; // second oblique
}

void CPUmove(string grid[8], string XorO, string enemyXO)
{
        // Can i win? lez find out man
    // ROWS
    if (grid[0] == XorO && grid[1] == XorO ) grid[2] = XorO; return;
    if (grid[1] == XorO && grid[2] == XorO ) grid[0] = XorO; return;
    if (grid[0] == XorO && grid[2] == XorO ) grid[1] = XorO; return;
    if (grid[3] == XorO && grid[4] == XorO ) grid[5] = XorO; return;
    if (grid[4] == XorO && grid[5] == XorO ) grid[3] = XorO; return;
    if (grid[3] == XorO && grid[5] == XorO ) grid[4] = XorO; return;
    if (grid[6] == XorO && grid[7] == XorO ) grid[8] = XorO; return;
    if (grid[7] == XorO && grid[8] == XorO ) grid[6] = XorO; return;
    if (grid[6] == XorO && grid[8] == XorO ) grid[7] = XorO; return;
    // COLUMNS
    if (grid[0] == XorO && grid[3] == XorO ) grid[6] = XorO; return;
    if (grid[1] == XorO && grid[4] == XorO ) grid[7] = XorO; return;
    if (grid[2] == XorO && grid[5] == XorO ) grid[8] = XorO; return;
    if (grid[0] == XorO && grid[6] == XorO ) grid[3] = XorO; return;
    if (grid[1] == XorO && grid[7] == XorO ) grid[4] = XorO; return;
    if (grid[2] == XorO && grid[8] == XorO ) grid[5] = XorO; return;
    if (grid[3] == XorO && grid[6] == XorO ) grid[0] = XorO; return;
    if (grid[4] == XorO && grid[7] == XorO ) grid[1] = XorO; return;
    if (grid[5] == XorO && grid[8] == XorO ) grid[2] = XorO; return;

}