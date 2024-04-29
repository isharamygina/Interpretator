//RULES
//Перед названием переменных необходимо употребить тип данных (только int, float, double, char)
//for(int start, int end, int step){...}
//while(<переменная> <знак> <переменная> <знак &&, ||> <...>){...}
//if (<переменная> <знак> <переменная> <знак &&, ||> <...>){...}
//Только после if: else(<переменная> <знак> <переменная> <знак &&, ||> <...>){...}
//Доступные операции (+,-,*,/,%)
//чтобы выполнить операцию над переменной, нужно сначала ее объявить, причем при объявлении после и перед равно нужны пробелы

#include <iostream>
#include <fstream>
#include "ReadCmd.h"
using namespace std;

int main(){
    string cmd;
    ifstream fin;
    fin.open("hello.txt"); // окрываем файл для чтения
    if (!fin.is_open()) {
        cout << "ERROR OPEN!";
    }

    else{
        while (getline(fin, cmd))
        {
            ReadCmd rc(cmd);
            rc.Parsing();
        }
    }
    fin.close();     // закрываем файл
}