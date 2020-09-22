#ifndef LIB
#define LIB

#include <string>

void PrintGrid(std::string*);
void wrongValue();
std::string moveAndCheck(std::string*, std::string, int);
bool isMoveCorrect(std::string*, std::string, int);
std::string CPUmove(std::string*, std::string, std::string);
bool CheckWin(std::string*, std::string);
bool isGridFull(std::string*);
void Clear();

#endif