#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    int arretes[L][2];
    vector<int> arretesOk;
    int sortie[E];

    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        arretes[i][0]=N1;
        arretes[i][1]=N2;
    }

    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        sortie[i] = EI;
    }

    for (int i = 0; i < L; i++) {
        for(int j = 0; j < E; j++) {
            if(arretes[i][1] == sortie[j]){
                arretesOk.push_back(arretes[i][0]);
                arretesOk.push_back(arretes[i][1]);
                break;
            }
            else if(arretes[i][0]==sortie[j]){
                arretesOk.push_back(arretes[i][0]);
                arretesOk.push_back(arretes[i][1]);
                break;
            }
        }
    }

    // game loop
    int cpt = 0;
    bool find = false;
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        for(int i=0; i< arretesOk.size(); i+=2){
            int first = arretesOk[i];
            int second = arretesOk[i+1];
            if(SI == first){
                cout << first << " " << second << endl;
                find = true;
                break;
            }
            else if(SI == second){
                cout << first << " " << second << endl;
                find = true;
                break;
            }
        }
        if(find==true){
            find == false;
        }
        else{
            cout << arretesOk[cpt] << " " << arretesOk[cpt+1] << endl;
            cpt+=2;
        }
    }
}
