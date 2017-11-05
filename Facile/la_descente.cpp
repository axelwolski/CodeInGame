#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  while (1) {
    int max = 0;
    int indiceMax = 0;
    for (int i = 0; i < 8; i++) {
      int mountainH;
      cin >> mountainH; cin.ignore();
      if(max<mountainH){
        max = mountainH;
        indiceMax = i;
      }
    }
    cout << indiceMax << endl;
  }
}
