#include "ReadCmd.h"
#define Cmd ReadCmd
using namespace std;

Cmd::ReadCmd(string cmd_) {
    cmd = cmd_;
    map<string, int> funcs = {{"for",     1},
                              {"while",   1},
                              {"if",      1},
                              {"else",    1},
                              {"input",   1},
                              {"print",   1}};
}

Cmd::~ReadCmd() {
    cmd = {};
    vals.clear();
    funcs.clear();
}

void Cmd::Parsing() {
    int i = 0;
    string word = "";
    while(i < cmd.size()){
        int j = i;
        while (j != ' '){
            word.push_back(cmd[j]);
            j++;
        }
        if(funcs.count(word)==1){
            switch (word[0]) {
                case 'i' || 'e':
                   myIf();
                   break;
                case 'f':
                    myFor();
                    break;
                case 'w':
                    myWhile();
                    break;
            }
        }
        else{
            myValue();
        }
        i+=j;
    }
}