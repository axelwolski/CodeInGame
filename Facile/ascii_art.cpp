#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
    vector<string> alphaAscii;

    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    for (int i = 0; i < H; i++) {
            string ROW;
            getline(cin, ROW);
            alphaAscii.push_back(ROW);
    }

    string ascii;
    for(int i=0; i<T.size(); i++){
        char c = toupper(T[i]);
        if((c < 'A') or (c>'Z')){
         c = '?';
        }
        int posLettre = alphabet.find(c);
        for (int j = 0; j < H; j++) {
            string s_line = alphaAscii[j].substr(posLettre*L, L);
            ascii += s_line;
        }
    }

    for(int i=0; i<H; i++){
        for(int x=0; x<T.size(); x++){
            for(int j=0; j<L; j++){
                cout << ascii[j+i*L+x*L*H];
            }
        }
        cout << endl;
    }
}
