#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    int tmpX = initialTX;
    int tmpY = initialTY;

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        string directionX = "";
        string directionY = "";
        cin >> remainingTurns; cin.ignore();

        if(lightY < tmpY){
            directionY = "N";
            tmpY--;
        }
        else if(lightY > tmpY){
            directionY = "S";
            tmpY++;
        }

        if(lightX < tmpX){
            directionX = "W";
            tmpX--;
        }
        else if(lightX > tmpX){
            directionX = "E";
            tmpX++;
        }
        
        cout << directionY << directionX << endl;
    }
}
