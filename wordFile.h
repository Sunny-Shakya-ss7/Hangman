#ifndef WORDFILE_H
#define WORDFILE_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

class wordFile
{
    public:
        int num;
        wordFile();

        string LoadRandomWord();
        string Hint();

        virtual ~wordFile();

    protected:

    private:
};

#endif // WORDFILE_H
