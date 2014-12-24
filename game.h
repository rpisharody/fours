#ifndef __GUARD__game
#define __GUARD__game

#include <string>

std::string get_word(const char* filename, int nWord = 4);
bool analyze(std::string, const std::string&, int nWord = 4);

#endif
