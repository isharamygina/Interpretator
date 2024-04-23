#include <iostream>
#include <string>
#include <map>
#pragma once
 using namespace std;
 //Данный класс содержит в себе строку до символа ";".
 //Данный класс разибрает строку на команды и выполняет их.
class ReadCmd{
private:
    string cmd;
public:
    ReadCmd(string cmd_); //конструктор
    ~ReadCmd(); //деструктор
    void Parsing(); //разбор строки на составляющие (функции, переменные)
    void myFor(int start, int end, int step); //обработка for
    void myWhile();//обработка while
    void myIf(); // обработка if-else_if-else
    void findfun(); //Возвращает определенный флаг если while, for, if, else, else if, print, input,  нет
    friend ostream &operator<<(ostream &ostr, const ReadCmd &rc); //вывод строки (при исключениях) (можно выводить и номер строки)
};