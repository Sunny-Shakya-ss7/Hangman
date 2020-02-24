#include "wordFile.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

wordFile::wordFile()
{
    LoadRandomWord();
    Hint();
}

wordFile::~wordFile()
{
    //dtor
}

string wordFile::LoadRandomWord()
{
    srand(time(0));
    string word;
    vector<string> v;
    ifstream reader;
    reader.open("WORD.txt", ios::in);
    if(reader.is_open())
    {
        while(getline(reader,word)) { v.push_back(word);}
        int randomLine = rand() % v.size();
        num = randomLine;
        word = v.at(randomLine);
        reader.close();
    }
    return word;
}

string wordFile::Hint()
{
    string hint;
    vector<string> h;
    ifstream hinter;
    hinter.open("HINTS.txt", ios::in);
    if(hinter.is_open())
    {
        while(getline(hinter,hint)) { h.push_back(hint);}
        hint = h.at(num);
        hinter.close();
    }
    return hint;
}
