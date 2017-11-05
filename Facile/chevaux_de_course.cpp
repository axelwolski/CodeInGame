#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N; cin.ignore();
    auto minDiff=100000000;
    vector<int> tab;
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        tab.push_back(Pi);
    }

    //trie le tableau
    sort(tab.begin(), tab.end());
    
    auto tmp = tab.begin();
    for (auto it=tab.begin()+1; it!=tab.end();++it){
        auto diff = *it-*tmp;
        if(diff < minDiff){
            minDiff = diff;
        }
         tmp++;
    }
    cout << minDiff << endl;
}
