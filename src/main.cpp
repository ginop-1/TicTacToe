#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include "func.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    while (true) 
    {
        // SETUP PART
        string grid[] {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        PrintGrid(grid);
        for (auto i=0; i<=8; i++) grid[i] = " "; // it sets all grid's boxes to a blank space
        cout << "Welcome to the tris game!" << endl
            << "the initial player will be random" << endl
            << "Choose a game mode: 1 vs PC (1) or 1 vs 1 (2):" << endl;
        int gameMode;
        while (true)
        {
            cin >> gameMode;
            if (gameMode == 1 || gameMode == 2) break;
            wrongValue();
        }
        cout << "Now choose between X or O: ";
        string playerXO, CPUXO;
        while (true) 
        {
            cin >> playerXO;
            if (playerXO == "X" || playerXO == "x" || playerXO == "O" || playerXO == "o") break;
            wrongValue();
        }
        if (playerXO == "x" || playerXO == "X") playerXO = "X";
        else playerXO = "O"; 
        if (playerXO == "X") CPUXO = "O";
        else CPUXO = "X";
        
        bool startplayer;
        srand((int)time(0));
        startplayer = (rand() % 2);
        int playermove = 0;

        // GAME LOGIC PART
        while (true)
        {
            if (startplayer) // PLAYER 1 TURN
            {
                if (isGridFull(grid)) break;
                if (gameMode == 1) cout << "it's your turn, choose a box\n";
                else cout << "It's player 1 turn, choose a box\n";
                moveAndCheck(grid, playerXO, playermove);
                PrintGrid(grid);
                if (CheckWin(grid, playerXO)) 
                {
                    if (gameMode == 1) 
                    {
                        cout << "Congrats, you have won! \n\n";
                        break;
                    }
                    else 
                    {
                        cout << "player 1 win! \n\n";
                        break;
                    }
                } 
                startplayer = false;
            }
            if (startplayer == false && gameMode == 2) // PLAYER 2 TURN
            {
                if (isGridFull(grid)) break;
                cout << "it's P2 turn, choose a box\n";
                moveAndCheck(grid, CPUXO, playermove);
                PrintGrid(grid);
                if (CheckWin(grid, CPUXO))
                {
                    cout << "player2 wins! \n\n";
                    break;
                }
                startplayer = true;
            } 
            else
            {
                if (isGridFull(grid)) break;  // CPU TURN
                cout << "CPU turn\n";
                CPUmove(grid, CPUXO, playerXO);
                PrintGrid(grid);
                if (CheckWin(grid, CPUXO))
                {
                    cout << "the CPU wins! \n\n";
                    break;
                }
                startplayer = true;
            }
        }
        char playAgain;
        cout << "Play again? y/n:  ";
        while (true)
        {
            cin >> playAgain;
            if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') break;
            wrongValue();
        }
        if (playAgain == 'y' || playAgain == 'Y') continue;
        else 
        {  
        cout << "press return to exit...";
        cin.ignore(); cin.get(); // this makes the program wait for "return" key
        Clear();
        break;
        }      
    }
    return 0;
}

string moveAndCheck(string grid[8], string PlayerXO, int playermove)
{
    while (true) 
    {
        cin >> playermove;
        playermove--;
        if (grid[playermove] != " ") cout << "this box is already filled, please insert a valid value: ";
        else 
        {
            grid[playermove] = PlayerXO; 
            return PlayerXO;

        }
    }
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
    return false;
}

bool isGridFull(string grid[8])
{
    for (auto i=0; i<=8; i++)
    {
        if (grid[i] == " ") 
        {
            return false;
        }
    }
    cout << "Thid is a draw! ";
    return true;
}