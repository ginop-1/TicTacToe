#include <iostream>

using std::string;
 
bool isMoveCorrect(string grid[8], string XorO, int a, int b, int c)
{
    if (grid[a]==XorO && grid[b]==XorO && grid[c]==" ") return true;
    return false;
}

string CPUmove(string grid[8], string XorO, string enemyXO)
{
        // TRY TO WIN IF POSSIBLE 
    
    // ROWS
    if (isMoveCorrect(grid, XorO, 0, 1 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 1, 2 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 0, 2 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 3, 4 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 5 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 3, 5 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 6, 7 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 7, 8 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 6, 8 ,7)) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (isMoveCorrect(grid, XorO, 0, 3 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 1, 4 ,7)) { grid[7] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 5 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 0, 6 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 1, 7 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 8 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 3, 6 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 7 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 5, 8 ,2)) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (isMoveCorrect(grid, XorO, 0, 4 ,4)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 4 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 0, 8 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 2, 6 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 6 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, XorO, 4, 8 ,0)) { grid[0] = XorO; return XorO; }
    
    // TRY TO NOT LOSE IF POSSIBLE
    
    // ROWS
    if (isMoveCorrect(grid, enemyXO, 0, 1 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 1, 2 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 0, 2 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 3, 4 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 5 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 3, 5 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 6, 7 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 7, 8 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 6, 8 ,7)) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (isMoveCorrect(grid, enemyXO, 0, 3 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 1, 4 ,7)) { grid[7] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 5 ,8)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 0, 6 ,3)) { grid[3] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 1, 7 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 8 ,5)) { grid[5] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 3, 6 ,0)) { grid[0] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 7 ,1)) { grid[1] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 5, 8 ,2)) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (isMoveCorrect(grid, enemyXO, 0, 4 ,4)) { grid[8] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 4 ,6)) { grid[6] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 0, 8 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 2, 6 ,4)) { grid[4] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 6 ,2)) { grid[2] = XorO; return XorO; }
    if (isMoveCorrect(grid, enemyXO, 4, 8 ,0)) { grid[0] = XorO; return XorO; }
    
    // OTHER MOVES
    
    for (auto i=0; i<=8; i+=2)
    {
        if (grid[i] == " ") 
        {
            grid[i] = XorO;
            return XorO;
        }
        if (i == 8) i=1;
    }
    return " "; 
}
