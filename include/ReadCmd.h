#include <iostream>
#include <string>
#include <map>
#include<stack>
#pragma once
 using namespace std;
 //Данный класс содержит в себе строку до символа ";".
 //Данный класс разибрает строку на команды и выполняет их.
class ReadCmd{
private:
    stack<string> brackets;
    string cmd; //считываемая команда (строчка)
    map<string, double> vals; //мапа переменных
    map<string, int> dataTypes;//мапа типов данных
    map<string, int> funcs; //мапа доступных функций
    map<char, int> ops; //мапа доступных операций
    char case_symb(string symb); //функция, возращающая спец. код знака сравнения
    bool should_read_cmd = true;
    char last_func = '0';
public:
    ReadCmd(string cmd_); //конструктор
    ~ReadCmd(); //деструктор
    void Parsing(); //разбор строки на составляющие (функции, переменные, операции)
    void procValue(string type, string cmd_); //обработка объявления переменной
    void changeValue(); //обработка изменения переменной
    void findfun(); //Возвращает определенный флаг если while, for, if, else, else if, print, input,  нет
    int stringToInt(string data); //преобразование строки в int
    double stringToDouble(string data); //преобразование строки в double
    float stringToFloat(string data); //преобразование строки в float
    void doubleCheck(string data);
   // bool isDigit(const char& first_symbol);
    bool isDigit(char first_symbol);
    void procIf();
    void procWhile();
    void procFor();
    void procMain();
    char stringToChar(string data); //преобразование строки в char
    friend ostream &operator<<(ostream &ostr, const ReadCmd &rc); //вывод строки (при исключениях) (можно выводить и номер строки)
};
