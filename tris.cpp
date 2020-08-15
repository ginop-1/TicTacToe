#include <iostream>
#include <random>
#include <string>

using namespace std;

void PrintGrid(string*);
string CPUmove(string*, string, string);
bool CheckWin(string*, string);

int main()
{
    string grid[9], playerXO, CPUXO; int startplayer, playermove, cpumove;
    for (int i=0; i<9; i++) grid[i] = " "; // cleaning array
    cout << "\n"
         << "1" << "|" << "2" << "|" << "3" << endl
         << "-----" << endl
         << "4" << "|" << "5" << "|" << "6" << endl
         << "-----" << endl 
         << "7" << "|" << "8" << "|" << "9" << endl
         << "\n" ;
    cout << "Welcome to the tris game, the initial player will be random\n\n" << "Choose beetween X or O: ";
    while (true) 
    {
        cin >> playerXO;
        if (playerXO == "X" || playerXO == "x" || playerXO == "O" || playerXO == "o") break;
        else cout << "wrong value, please reinsert: ";
    }
    if (playerXO == "x") playerXO = "X";
    else playerXO = "O"; 
    if (playerXO == "X") CPUXO = "O";
    else CPUXO = "X";
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
            cout << "CPU turn\n";
            CPUmove(grid, CPUXO, playerXO);
            if (CheckWin(grid, CPUXO))
            {
                cout << "the CPU wins! ";
                break;
            }
            PrintGrid(grid);
            startplayer = 0;
        }
    }
    return 0;
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
    else if (grid[3] == XorO && grid[4] == XorO && grid[5] == XorO) return true; // second row
    else if (grid[6] == XorO && grid[7] == XorO && grid[8] == XorO) return true; // third row
    else if (grid[0] == XorO && grid[3] == XorO && grid[6] == XorO) return true; // first column
    else if (grid[1] == XorO && grid[4] == XorO && grid[7] == XorO) return true; // second column
    else if (grid[2] == XorO && grid[5] == XorO && grid[8] == XorO) return true; // third column
    else if (grid[0] == XorO && grid[4] == XorO && grid[8] == XorO) return true; // first oblique
    else if (grid[2] == XorO && grid[4] == XorO && grid[6] == XorO) return true; // second oblique
    else return false;
}

string CPUmove(string grid[8], string XorO, string enemyXO)
{
        // TRY TO WIN IF POSSIBLE 
    
    // ROWS
    if (grid[0] == XorO && grid[1] == XorO ) { grid[2] = XorO; return XorO; }
    if (grid[1] == XorO && grid[2] == XorO ) { grid[0] = XorO; return XorO; }
    if (grid[0] == XorO && grid[2] == XorO ) { grid[1] = XorO; return XorO; }
    if (grid[3] == XorO && grid[4] == XorO ) { grid[5] = XorO; return XorO; }
    if (grid[4] == XorO && grid[5] == XorO ) { grid[3] = XorO; return XorO; }
    if (grid[3] == XorO && grid[5] == XorO ) { grid[4] = XorO; return XorO; }
    if (grid[6] == XorO && grid[7] == XorO ) { grid[8] = XorO; return XorO; }
    if (grid[7] == XorO && grid[8] == XorO ) { grid[6] = XorO; return XorO; }
    if (grid[6] == XorO && grid[8] == XorO ) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (grid[0] == XorO && grid[3] == XorO ) { grid[6] = XorO; return XorO; }
    if (grid[1] == XorO && grid[4] == XorO ) { grid[7] = XorO; return XorO; }
    if (grid[2] == XorO && grid[5] == XorO ) { grid[8] = XorO; return XorO; }
    if (grid[0] == XorO && grid[6] == XorO ) { grid[3] = XorO; return XorO; }
    if (grid[1] == XorO && grid[7] == XorO ) { grid[4] = XorO; return XorO; }
    if (grid[2] == XorO && grid[8] == XorO ) { grid[5] = XorO; return XorO; }
    if (grid[3] == XorO && grid[6] == XorO ) { grid[0] = XorO; return XorO; }
    if (grid[4] == XorO && grid[7] == XorO ) { grid[1] = XorO; return XorO; }
    if (grid[5] == XorO && grid[8] == XorO ) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (grid[0] == XorO && grid[4] == XorO ) { grid[8] = XorO; return XorO; }
    if (grid[2] == XorO && grid[4] == XorO ) { grid[6] = XorO; return XorO; }
    if (grid[0] == XorO && grid[8] == XorO ) { grid[4] = XorO; return XorO; }
    if (grid[2] == XorO && grid[6] == XorO ) { grid[4] = XorO; return XorO; }
    if (grid[4] == XorO && grid[6] == XorO ) { grid[2] = XorO; return XorO; }
    if (grid[4] == XorO && grid[8] == XorO ) { grid[0] = XorO; return XorO; }
    
        // TRY TO NOT LOSE IF POSSIBLE
    // ROWS
    if (grid[0] == enemyXO && grid[1] == enemyXO ) { grid[2] = XorO; return XorO; }
    if (grid[1] == enemyXO && grid[2] == enemyXO ) { grid[0] = XorO; return XorO; }
    if (grid[0] == enemyXO && grid[2] == enemyXO ) { grid[1] = XorO; return XorO; }
    if (grid[3] == enemyXO && grid[4] == enemyXO ) { grid[5] = XorO; return XorO; }
    if (grid[4] == enemyXO && grid[5] == enemyXO ) { grid[3] = XorO; return XorO; }
    if (grid[3] == enemyXO && grid[5] == enemyXO ) { grid[4] = XorO; return XorO; }
    if (grid[6] == enemyXO && grid[7] == enemyXO ) { grid[8] = XorO; return XorO; }
    if (grid[7] == enemyXO && grid[8] == enemyXO ) { grid[6] = XorO; return XorO; }
    if (grid[6] == enemyXO && grid[8] == enemyXO ) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (grid[0] == enemyXO && grid[3] == enemyXO ) { grid[6] = XorO; return XorO; }
    if (grid[1] == enemyXO && grid[4] == enemyXO ) { grid[7] = XorO; return XorO; }
    if (grid[2] == enemyXO && grid[5] == enemyXO ) { grid[8] = XorO; return XorO; }
    if (grid[0] == enemyXO && grid[6] == enemyXO ) { grid[3] = XorO; return XorO; }
    if (grid[1] == enemyXO && grid[7] == enemyXO ) { grid[4] = XorO; return XorO; }
    if (grid[2] == enemyXO && grid[8] == enemyXO ) { grid[5] = XorO; return XorO; }
    if (grid[3] == enemyXO && grid[6] == enemyXO ) { grid[0] = XorO; return XorO; }
    if (grid[4] == enemyXO && grid[7] == enemyXO ) { grid[1] = XorO; return XorO; }
    if (grid[5] == enemyXO && grid[8] == enemyXO ) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (grid[0] == enemyXO && grid[4] == enemyXO ) { grid[8] = XorO; return XorO; }
    if (grid[2] == enemyXO && grid[4] == enemyXO ) { grid[6] = XorO; return XorO; }
    if (grid[0] == enemyXO && grid[8] == enemyXO ) { grid[4] = XorO; return XorO; }
    if (grid[2] == enemyXO && grid[6] == enemyXO ) { grid[4] = XorO; return XorO; }
    if (grid[4] == enemyXO && grid[6] == enemyXO ) { grid[2] = XorO; return XorO; } 
    if (grid[4] == enemyXO && grid[8] == enemyXO ) { grid[0] = XorO; return XorO; }
    
        // OTHER MOVES
    
    if (grid[4] == " ") { grid[4] = XorO; return XorO; }
    if (grid[0] == " ") { grid[0] = XorO; return XorO; }
    if (grid[2] == " ") { grid[2] = XorO; return XorO; }
    if (grid[6] == " ") { grid[6] = XorO; return XorO; }
    if (grid[8] == " ") { grid[8] = XorO; return XorO; }
}