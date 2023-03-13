#include <iostream>
#include <string>
#include <cctype>
#include "funcs.h"

int main()
{
    std::string line = "    hello";
    std::cout << removeLeadingSpaces(line);
    return 0;
}