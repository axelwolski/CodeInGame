#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; // the number of temperatures to analyse
    double minPos = 5526;
    double minNeg = -273;
    int cptPos = 0;
    int cptNeg = 0;
    cin >> n; cin.ignore();
    if(n==0){
        cout << "0" << endl;
    }
    else{
        for (int i = 0; i < n; i++) {
            double t; // a temperature expressed as an integer ranging from -273 to 5526
            cin >> t; cin.ignore();
            if(0<=t && t<=minPos){
                minPos = t;
                cptPos++;
            }
            else if(t<=0 && t>=minNeg){
                minNeg = t;
                cptNeg++;
            }
        }
        if(cptPos==0){
            cout << minNeg << endl;
        }
        else if(cptNeg==0){
            cout << minPos << endl;
        }
        else if(minNeg> -minPos){
            cout << minNeg << endl;
        }
        else{
            cout << minPos << endl;
        }
    }
}
