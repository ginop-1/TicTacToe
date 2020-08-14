#include <iostream>
#include <random>
#include <string>

using namespace std;

void PrintGrid(string*);

int main()
{
    string grid[9], playerXO; int startplayer, playermove, cpumove;
    for (int i=0; i<8; i++) grid[i] = " "; // cleaning array
    cout << "Welcome to the tris game, the initial player will be random\n\n" << "Choose beetween X or O: ";
    while (true) 
    {
        cin >> playerXO;
        if (playerXO == "X") break;
        else if (playerXO == "x") break;
        else if (playerXO == "O") break;
        else if (playerXO == "0") break;
        else cout << "wrong value, please reinsert: ";
    }
    PrintGrid(grid);
    srand (time(NULL)); startplayer = rand() % 2 + 0;
    while (true)
    {
        if (startplayer == 0) 
        {
            cout << "it's your turn, choose a box\n";
            cin >> playermove;
            grid[playermove] = playermove;
            PrintGrid(grid);
            
            startplayer = 1;
        }
        if (startplayer == 1)
        {
            cout << "CPU turn\n";
            startplayer = 0;
        }
    }
}

void PrintGrid(string box[8])
{
    cout << box[0] << "|" << box[1] << "|" << box[2] << endl
         << "-----" << endl
         << box[3]<< "|" << box[4] << "|" << box[5] << endl
         << "-----" << endl 
         << box[6] << "|" << box[7] << "|" << box[8] << endl;
}