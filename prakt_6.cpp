#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <list>
using namespace std;
bool check(list<char> word)
{
    int num = 0;
    bool isWorld = true;
    for (char c : word)
    {
        if (!isalpha(c))
        {
            isWorld = false;
        }
    }
    return isWorld;
}
int functionCount()
{
    char line[100];
    printf("Введите строку\n");
    gets_s(line);
    int numberWords = 0;
    bool isWord = false;
    list<char> word;
    for (char s: line)
    {
        if (s != ' ')
        {
            if (!isWord)
            {
                isWord = true;
            }
            else
            {
                word.push_back(s);
            }
        }
        else 
        {
            isWord = false;
            if (!word.empty())
            {
                if (check(word))
                {
                    numberWords++;
                }
            }
            word.clear();

        }
    }
    return numberWords;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int numberWords = functionCount();
    cout << "Слов в строке - " << numberWords << endl;
}