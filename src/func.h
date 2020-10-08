#ifndef LIB
#define LIB

#include <string>

// PRINT FUNCTIONS
void PrintGrid(std::string*);
void wrongValue();
void Clear();
void signature();

// CPU FUNCTIONS (isMoveCorrect also used for player turn)
bool isMoveCorrect(std::string*, std::string, int);
std::string CPUmove(std::string*, std::string, std::string);

// CHECKS FUNCTIONS
std::string moveAndCheck(std::string*, std::string, int);
bool CheckWin(std::string*, std::string);
bool isGridFull(std::string*);

#endif