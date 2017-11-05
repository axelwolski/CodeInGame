#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void getVoisin(int x, int y, int width, int height, vector<string> mat)
{
    int xR = -1;
    int yR = -1;
    int xD = -1;
    int yD = -1;

    for(int i = x+1; i<width; i++){
        if(mat[y][i] == '0'){
            xR = i;
            yR = y;
            break;
        }
    }
    for(int i = y+1; i<height; i++){
        if(mat[i][x] == '0'){
            xD = x;
            yD = i;
            break;
        }
    }
    cout << x << " " << y << " " << xR << " " << yR << " " << xD << " " << yD << endl;
}

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    vector<string> batterie;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        batterie.push_back(line);
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(batterie[i][j] == '.') {
                continue;
            }
            getVoisin(j,i,width, height, batterie);
        }
    }
    return 0;
}
