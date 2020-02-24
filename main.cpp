#include <iostream>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "wordFile.h"

using namespace std;

class HangMan{

private:
    char ch='\0',dummy[50];
    char letters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',};
    string word,message;
    int wLen,count=0,lives=7;
    bool v=true,Full=false;
    int n;

public:

    HangMan(string word)
    {
        cout << "\n Lives Left: ";
        for(int x=0; x<lives; x++) {cout << "* ";}  cout << endl;
//___________________________________FIRST BLOCK_____________________________________________________________

        cout << endl;
        structHorizontal();
        cout << "|\t    HANG MAN\t       |" << endl;
        structHorizontal();
//___________________________________SECOND BLOCK (HANGMAN)__________________________________________________

        cout << "|\t     _____\t       |" << endl << "|\t       |\t       |" << endl;
        if(lives == 0) {cout << "|\t       |\t       |\n|\t       O\t       |\n|\t      /|\\\t       |\n|\t      / \\\t       |\n";}
        else if(lives == 1) {cout << "|\t       |\t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t      / \\\t       |\n";}
        else if(lives == 2) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t      / \\\t       |\n";}
        else if(lives == 3) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t      /  \t       |\n";}
        else if(lives == 4) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t        \t       |\n";}
        else if(lives == 5) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /| \t       |\n|\t         \t       |\n";}
        else if(lives == 6) {cout << "|\t        \t       |\n|\t        \t       |\n|\t       | \t       |\n|\t         \t       |\n";}
        else if(lives == 7) {cout << "|\t        \t       |\n|\t        \t       |\n|\t         \t       |\n|\t         \t       |\n";}
        cout << "|\t   +-------+\t       |" << endl;
        structHorizontal();
//___________________________________THIRD BLOCK_____________________________________________________________

        cout << "|\tAvailable Letters      |" << endl;
        structHorizontal();
//___________________________________FOURTH BLOCK  (LETTERS)_________________________________________________

        cout << "|  ";
        for(int i=0; i<26; i++)
        {
            if(i == 13) {cout << "  |" << endl << "|   ";}
            cout << letters[i] << " ";
        }
        cout << " |" << endl;
        structHorizontal();
//___________________________________FIFTH BLOCK  (GUESS)____________________________________________________

        n = (32 - ((word.length()*3)+2)) / 2;
        cout << "|\t Guess the word\t       |" << endl << "|\t\t\t       |" << endl << "|";
        for(int i=0; i<n; i++) {cout << " ";}
        for(int i=0; i<word.length(); i++)
        {
            cout << " - ";
        }
        for(int i=0; i<n; i++) {cout << " ";}
        if(word.length() % 2 != 0) {cout << " ";}
        cout << "|" << endl;
        structHorizontal();
    }

    void structHorizontal()
    {
        for(int i=0; i<32; i++)
        {
            if(i==0 || i==31) {cout << "+";}
            else {cout << "-";}
        }
        cout << endl;
    }

    inline void enterGuess()
    {
        cout << "\n Enter your guess: ";
        cin >> ch;
    }

    void gameStructure(string word,string hint)
    {
        int wLen = word.length();
        char temp[wLen+1];
        strcpy(temp,word.c_str());
        while(count != 7)
        {
            for(int i=0; i<wLen; i++)
            {
                if(dummy[i] == '-') {Full=false; break;}
                else {Full=true;}
            }

            if(Full == true)
            {
                cout << "\n\n\t-------------------------------------- !!!!!! CONGRATULATION !!!!!! --------------------------------------\t\n\n" << endl << "\t\t\t\t\t    YOU GUESSED THE WORD : " << dummy << endl;
                break;
            }
            else
            {
                cout << "\n HINT: " << hint << endl;
                enterGuess();
                system("cls");
                alertRepeatedCharacters(ch,letters);
                if(v == false) {goto TOP;}
                errorCount(ch,word);
                if(v == true)
                {
                    TOP:
                    cout << "\n Lives Left: ";
                    for(int x=0; x<lives; x++) {cout << "* ";}  cout << endl;
//___________________________________FIRST BLOCK_____________________________________________________________

                    cout << endl;
                    structHorizontal();
                    cout << "|\t    HANG MAN\t       |" << endl;
                    structHorizontal();
//___________________________________SECOND BLOCK (HANGMAN)__________________________________________________

                    cout << "|\t     _____\t       |" << endl << "|\t       |\t       |" << endl;
                    if(lives == 0) {cout << "|\t       |\t       |\n|\t       O\t       |\n|\t      /|\\\t       |\n|\t      / \\\t       |\n";}
                    else if(lives == 1) {cout << "|\t       |\t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t      / \\\t       |\n";}
                    else if(lives == 2) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t      / \\\t       |\n";}
                    else if(lives == 3) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t      /  \t       |\n";}
                    else if(lives == 4) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /|\\\t       |\n|\t        \t       |\n";}
                    else if(lives == 5) {cout << "|\t        \t       |\n|\t        \t       |\n|\t      /| \t       |\n|\t         \t       |\n";}
                    else if(lives == 6) {cout << "|\t        \t       |\n|\t        \t       |\n|\t       | \t       |\n|\t         \t       |\n";}
                    else if(lives == 7) {cout << "|\t        \t       |\n|\t        \t       |\n|\t         \t       |\n|\t         \t       |\n";}
                    cout << "|\t   +-------+\t       |" << endl;
                    structHorizontal();
//___________________________________THIRD BLOCK_____________________________________________________________

                    cout << "|\tAvailable Letters      |" << endl;
                    structHorizontal();
//___________________________________FOURTH BLOCK  (LETTERS)_________________________________________________

                    available_letters(letters,ch);
                    structHorizontal();
//___________________________________FIFTH BLOCK  (GUESS)____________________________________________________

                    n = (32 - ((wLen*3)+2)) / 2;
                    cout << "|\t Guess the word\t       |" << endl << "|\t\t\t       |" << endl << "|";
                    for(int i=0; i<n; i++) {cout << " ";}
                    for(int i=0; i<wLen; i++)
                    {
                        if(ch == word[i])
                        {
                            dummy[i] = ch;
                            cout << " " << dummy[i] << " ";
                        }
                        else {cout << " " << dummy[i] << " ";}
                    }
                    for(int i=0; i<n; i++) {cout << " ";}
                    if(word.length() % 2 != 0) {cout << " ";}
                    cout << "|" << endl;
                    structHorizontal();
                }
            }
        }
        cout << "\n\n******************************************************** GAME OVER *****************************************************\n" << endl;
        if(count == 7) {cout << "\t\t\t\t\t\t   Word was: " << word << endl << "\n************************************************************************************************************************";}
    }

    void dummyInitialize(int wLen)
    {
        int i;
        for(i=0; i<wLen; i++) {dummy[i] = '-';}
        dummy[i] = '\0';
    }

    void available_letters(char letters[],char ch)
    {
        for(int i=0; i<26; i++) {if(letters[i] == ch) {letters[i] = ' ';}}
        cout << "|  ";
        for(int i=0; i<26; i++)
        {
            if(i == 13) {cout << "  |" << endl << "|   ";}
            cout << letters[i] << " ";
        }
        cout << " |" << endl;
    }

    void errorCount(char ch,string word)
    {
        int len=0,found=0;
        while(len!=word.length())
        {
            if(ch!=word[len]) {len++;}
            else
            {
                found++;
                break;
            }
        }
        if(found == 0)
        {
            count++;
            lives--;
        }
    }

    void alertRepeatedCharacters(char ch, char letters[])
    {
        for(int i=0; i<26; i++)
        {
            if(ch == letters[i]) {v = true; break;}
            else {v = false;}
        }
        if(v == false) {cout << "\n\n Already selected letter / Unavailable Letter \n\n Please enter letters which are available" << endl;}
    }
};

int main()
{
    cout << " *--------------------------------------------------------------------------------------------------------------------*\n" << endl;
    cout << "\t\t\t\t\tW E L C O M E    T O    H A N G M A N" << endl;
    cout << "\n *--------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << " +--------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\n    Rules:-" << endl;
    cout << "\n\t- you will have 7 chances to guess the word" << endl;
    cout << "\n\t- enter one guess letter" << endl;
    cout << "\n\t- only uppercase letters are allowed" << endl;
    cout << "\n\t- entering letters which are not part of the word results in deduction in life" << endl;
    cout << "\n\t- check available letters before entering your guess" << endl;
    cout << "\n +--------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\n\n\n\t\t\t\t\t       ";
    system("PAUSE");
    system("cls");
    wordFile W;
    string word = W.LoadRandomWord();
    string hint = W.Hint();
    HangMan obj(word);
    obj.dummyInitialize(word.length());
    obj.gameStructure(word,hint);
    return 0;
}

/*----------------------- STRUCTURE OF GAME ------------------------

+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|              _____              |
|                |                |
|                |                |
|                O                |
|               /|\               |
|               / \               |
|            +-------+            |
+---------------------------------+
|        Available Letters        |
+---------------------------------+
|    A B C D E F G H I J K L M    |
|    N O P Q R S T U V W X Y Z    |
+---------------------------------+
|         Guess the word          |
|                                 |
|  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  |
+---------------------------------+
*/
