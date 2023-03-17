#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "funcs.h"

std::string removeLeadingSpaces(std::string line)
{
    bool letterFound = false; // bool to check if a letter has been found
    std::string newLine;      // string to hold the new line

    for (int i = 0; i < line.length(); i++) // loop through the line
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

int countChar(std::string line, char c)
{
    int count = 0; // counter for the number of times the character appears in the line

    for (int i = 0; i < line.length(); i++) // loop through the line
    {

        if (line[i] == c) // if the current character is a '{', add one to the indent counter
        {
            i++;
            count++;
        }
       
        
    }

    return count; // return the counter
}

std::string newFile(std::string name)
{
    std::ifstream data_file(name); // open file
    if (data_file.fail())          // if program can't open file
    {
        std::cerr << "File cannot be opened for reading." << std::endl; // error message
        exit(1);                                                        // exit if failed to open the file
    }

    std::string line; // string to hold each line
    std::string newLine;
    std::string newFileString; // string to hold the new file
    int count = 0;             // indent counter
    while (!data_file.eof())   // while the file is open
    {
        std::getline(data_file, line);              // get each line from the input file and stores it into the string "line"
        newLine = removeLeadingSpaces(line) + "\n"; // add the line without any spaces to newFileString with a new line character at the end.
                                                    // add the number of '{' and '}' in the line to the counter
        count -= countChar(newLine, '}');
        if (count > 0)
        {
            for (int i = 0; i < count; i++) // loop through the counter
            {
                newLine.insert(i, "\t"); // add a tab to the new file string for each iteration
            }
        }
        newFileString += newLine;
        count += countChar(newLine, '{');

        // count the number of '{' and '}' in the line and add or subtract from the counter
    }

    return newFileString;
    data_file.close(); // close the file
                       // return the new file string
}