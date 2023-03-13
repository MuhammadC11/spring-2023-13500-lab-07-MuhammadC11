#include <iostream>
#include <string>
#include <cctype>
#include "funcs.h"

std::string removeLeadingSpaces(std::string line)
{
    bool letterFound = false;
    std::string newLine;
    for (int i = 0; i < line.length(); i++)
    {

        if (letterFound) // if a letter has been found, add the rest of the line. usually happens after the first few iterations until a letter is found
        {
            newLine += line[i];
        }
        else if (isspace(line[i])) // if the current character is a space, skip the iteration and do nothing.
        {
            continue;
        }
        else
        {
            letterFound = true; // if a letter is not found yet and the current character is not a spsace, set letterFound to true and add the character to newLine.
            newLine += line[i];
        }
    }

    return newLine; // return the new line
}
