#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <bitset>

using namespace std;

int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    string str;
    for (size_t i = 0; i < MESSAGE.size(); ++i){
        bitset<7> b(MESSAGE.c_str()[i]);
        str+= b.to_string();
    }
    cerr << str << endl;
    string chuckMessage;
    while(str.length() !=0){
        if(str[0] == '1'){
            chuckMessage.push_back('0');
            chuckMessage.push_back(' ');
            do{
                str.erase(0, 1);
                chuckMessage.push_back('0');
            }while(str[0] == '1');
        }
        else if (str[0] == '0'){
            chuckMessage.push_back('0');
            chuckMessage.push_back('0');
            chuckMessage.push_back(' ');
            do{
                str.erase(0, 1);
                chuckMessage.push_back('0');
            }while(str[0] == '0');
        }
        chuckMessage.push_back(' ');
    }
    chuckMessage.erase(chuckMessage.size()-1,1);
    cout << chuckMessage << endl;
}
