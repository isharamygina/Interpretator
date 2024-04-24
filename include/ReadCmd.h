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
    map<string, double> vals; //мапа переменных//может надо перекинуть в ReadBlock и затем унаследовать сюда????
    map<string, int> dataTypes;//мапа типов данных
    map<string, int> funcs; //мапа доступных функций
    map<char, int> ops; //мапа доступных операций
public:
    ReadCmd(string cmd_); //конструктор
    ~ReadCmd(); //деструктор
    void Parsing(); //разбор строки на составляющие (функции, переменные)
    void myValue(string type); //обработка объявления переменной
    void changeValue(); //обработка изменения переменной
    void myFor(); //обработка for
    void myWhile();//обработка while
    void myIf(); // обработка if-else_if-else
    void findfun(); //Возвращает определенный флаг если while, for, if, else, else if, print, input,  нет
    int stringToInt(string data); //преобразование строки в int
    double stringToDouble(string data); //преобразование строки в double
    float stringToFloat(string data); //преобразование строки в float
    char stringToChar(string data); //преобразование строки в char
    friend ostream &operator<<(ostream &ostr, const ReadCmd &rc); //вывод строки (при исключениях) (можно выводить и номер строки)
};
