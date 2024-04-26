#include "ReadCmd.h"
using namespace std;

ReadCmd::ReadCmd(string cmd_) {
    cmd = cmd_;
    map<string, int> dataTypes = {{"int",1},
                              {"double", 1},
                              {"float",  1},
                              {"char",   1}};
    map<string, int> funcs = {{"for",   1},
                              {"while", 1},
                              {"if",    1},
                              {"else",  1},
                              {"input", 1},
                              {"print", 1}};
    map<char, int> ops = {{'+', 1},
                          {'-', 1},
                          {'*', 1},
                          {'/', 1},
                          {'%', 1}};
}

ReadCmd::~ReadCmd() {
    cmd = {};
    vals.clear();
    funcs.clear();
}

void ReadCmd::Parsing() {
    int i = 0;
    string word = "";
    while (cmd[i]!= ' ' || cmd[i]!='(') {
        word.push_back(cmd[i]);
        i ++;
    }
    if (funcs.count(word) == 1) {
        switch (word[i]) {
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
    } else {
        myValue(word);
    }
}

void ReadCmd::myValue(string type) {
    int i = 0;
    string name= "";
    string data= "";
    if (dataTypes.count(type) == 1){
        switch (type[0]) {
            case 'i': {
                for (int i = type.size() + 1; cmd[i] != ' '; i++) {
                    name.push_back(cmd[i]);
                }
                while (cmd[i] != '=') {
                    i++;
                    if (i > cmd.size()) {
                        throw length_error("No symbol = in assignment");
                    }
                }
                i++;
                for (i; cmd[i] != ';'; i++) {
                    data.push_back(cmd[i]);
                }
                int intData = stringToInt(data);
                vals.insert(pair<string, int>(name, intData));
                break;
            }

            case 'd': {
                for (int i = type.size() + 1; cmd[i] != ' '; i++) {
                    name.push_back(cmd[i]);
                }
                while (cmd[i] != '=') {
                    i++;
                    if (i > cmd.size()) {
                        throw length_error("No symbol = in assignment");
                    }
                }
                i++;
                for (i; cmd[i] != ';'; i++) {
                    data.push_back(cmd[i]);
                }
                int doubleData = stringToDouble(data);
                vals.insert(pair<string, int>(name, doubleData));
                break;
            }

            case 'f': {
                for (int i = type.size() + 1; cmd[i] != ' '; i++) {
                    name.push_back(cmd[i]);
                }
                while (cmd[i] != '=') {
                    i++;
                    if (i > cmd.size()) {
                        throw length_error("No symbol = in assignment");
                    }
                }
                i++;
                for (i; cmd[i] != ';'; i++) {
                    data.push_back(cmd[i]);
                }
                int floatData = stringToFloat(data);
                vals.insert(pair<string, int>(name, floatData));
                break;
            }
            case 'c': {
                for (int i = type.size() + 1; cmd[i] != ' '; i++) {
                    name.push_back(cmd[i]);
                }
                while (cmd[i] != '=') {
                    i++;
                    if (i > cmd.size()) {
                        throw length_error("No symbol = in assignment");
                    }
                }
                i++;
                for (i; cmd[i] != ';'; i++) {
                    data.push_back(cmd[i]);
                }
                int charData = stringToChar(data);
                vals.insert(pair<string, int>(name, charData));
                break;
            }

            default: //значит это операция над переменной
            {
                string val1 = "";
                string val2 = "";
                char op;
                for (int i; cmd[i]!= ' '; i++){
                    name.push_back(cmd[i]);
                }
                while(cmd[i]!= '=') {
                    i++;
                    if (i > cmd.size()) {
                        throw length_error("No symbol = in operation");
                    }
                }
                i++;
                auto found = vals.find(val1);
                for(i; found==vals.cend(); i++) {
                    if (i > cmd.size()) {
                        throw length_error("Value error in operation");
                    }
                    val1.push_back(cmd[i]);
                    found = vals.find(val1);
                }
                i+=2;
                if (ops.count(cmd[i]) == 1) {op = cmd[i];}
                else {throw logic_error ("Syntaxis operation error");}
                i++;
                found = vals.find(val2);
                for(i; found==vals.cend(); i++) {
                    if (i > cmd.size()) {
                        throw length_error("Value error in operation");
                    }
                    val2.push_back(cmd[i]);
                    found = vals.find(val1);
                }
                found = vals.find(name);
                switch (op) {

                    case '+':
                        if (found == vals.cend()) {
                            vals.insert(pair<string, int>(name, vals.find(val1)->second + vals.find(val2)->second));
                        } else {
                            vals.find(name)->second = vals.find(val1)->second + vals.find(val2)->second;
                        }
                        break;
                    case '-':
                        if (found == vals.cend()) {
                            vals.insert(pair<string, int>(name, vals.find(val1)->second - vals.find(val2)->second));
                        } else {
                            vals.find(name)->second = vals.find(val1)->second - vals.find(val2)->second;
                        }
                        break;

                    case '*':
                        if (found == vals.cend()) {
                            vals.insert(pair<string, int>(name, vals.find(val1)->second * vals.find(val2)->second));
                        } else {
                            vals.find(name)->second = vals.find(val1)->second * vals.find(val2)->second;
                        }
                        break;

                    case '/':
                        if (found == vals.cend()) {
                            if (vals.find(val2)->second != 0) {
                                vals.insert(pair<string, int>(name, vals.find(val1)->second / vals.find(val2)->second));
                            } else { throw logic_error("Div 0"); }
                        } else {
                            if (vals.find(val2)->second != 0) {
                                vals.find(name)->second = vals.find(val1)->second / vals.find(val2)->second;
                            } else { throw logic_error("Div 0"); }
                        }
                        break;

                    case '%':
                        if (found == vals.cend()) {
                            vals.insert(pair<string, int>(name,
                                                          int(vals.find(val1)->second) % int(vals.find(val2)->second)));
                        } else {
                            vals.find(name)->second = int(vals.find(val1)->second) % int(vals.find(val2)->second);
                        }
                        break;
                }
            }
        }
    }
}
int ReadCmd::stringToInt(string data)
{
	int res = 0;
	for (char i: data)
	{
		if (i < '0' || i > '9')
			throw invalid_argument("Expected int");
		res = res * 10 + i-'0';
	}
	return res;
}

char ReadCmd::stringToChar(string data)
{
	if (data.size() > 1)
		throw invalid_argument("Expected one symbol");
	return data[0];
}
bool ReadCmd::isDigit(const char& first_symbol)
{
	if ((first_symbol <= '9' && first_symbol >= '0') || first_symbol == '.')
		return true;
	return false;
}

void ReadCmd::doubleCheck(string data)
{
	int e = 0;
	int dot = 0;
	
	for (char i : data)
	{
		if (i == 'e') e++;
		if (i == '.') dot++;
	}
	if (e > 1 || dot > 1 || data.find('e') < data.find('.'))
	{
		throw invalid_argument("The mistake in a digit");
	}
	if (data[data.length() - 1] == 'e')
	{
		throw invalid_argument("The mistake in a digit");
	}
	for (size_t j = 0; j < data.length(); j++)
		if (!(isDigit(data[j]) || data[j] == 'e' || data[j] == '+' || data[j] == '-'))
		{
			throw invalid_argument("The mistake in a digit");
		}
	
}

double ReadCmd::stringToDouble(string data)
{
	doubleCheck(data);
	double res = 0.0, sign = 1.0;

if (data.find('.') != -1 && data.find('e') == -1) {//there is dot

	double beforepoint = 0, afterpoint = 0;
	string beforepoint_s, afterpoint_s;
	size_t p = data.find('.');//position of the dot

	for (size_t i = 0; i < p; i++) { beforepoint_s += data[i]; }
	for (size_t i = p + 1; i < data.size(); i++) { afterpoint_s += data[i]; }

	beforepoint = stringToDouble(beforepoint_s);
	afterpoint = stringToDouble(afterpoint_s);

	afterpoint /= pow(10, afterpoint_s.size());

	res = beforepoint + afterpoint;

}

else if (data.find('e') != -1) {//there is e

	double beforeE = 0.0, afterE = 0.0;
	string beforeE_s, afterE_s;

	size_t p = data.find('e');

	for (size_t i = 0; i < p; i++) { beforeE_s += data[i]; }
	for (size_t i = p + 1; i < data.size(); i++) { afterE_s += data[i]; }

	beforeE = stringToDouble(beforeE_s);
	afterE = stringToDouble(afterE_s);

	if (afterE > 0) res = beforeE * pow(10.0, afterE);
	else {
		res = beforeE;
		for (size_t i = 0; i < (-1.0 * afterE); i++) { res /= 10; }
	}
}

else { //no dot, no e

	if (data[0] == '~' || data[0] == '-') {

		for (size_t i = 1; i < data.size(); i++) {
			res = res * 10.0 + static_cast<double>(data[i] - '0');
		}
		res *= -1.0;
	}

	else {

		for (size_t i = 0; i < data.size(); i++) {
			res = res * 10.0 + static_cast<double>(data[i] - '0');
		}
	}
}

return res; 
}

