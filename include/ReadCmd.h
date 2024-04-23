#include <iostream>
#include <string>
#pragma once
 using namespace std;
 //Данный класс содержит в себе строку до символа ";".
 //Данный класс разибрает строку на команды и выполняет их.
class ReadCmd{
private:
    string cmd;
public:
    ReadCmd(string cmd_);
    ~ReadCmd();
    void myFor(int start, int end, int step);
    void myWhile();
    void myIf();
    void findfun(); //Возвращает определенный флаг если while, for,if, else, else if,  нет
    friend ostream &operator<<(ostream &ostr, const ReadCmd &rc);
};
