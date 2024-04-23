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
    ReadCmd(string cmd);
    ~ReadCmd();
};
