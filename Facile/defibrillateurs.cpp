#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

double stringToFloat(string s) {
    size_t i = s.find_first_of(',');
    s[i] = '.';
    return atof(s.c_str());
}

double distance(const double aLon, const double bLon, const double aLat, const double bLat)
{
  double x = (bLon - aLon) * cos((aLat + bLat) / 2);
  double y = bLat - aLat;
  double d = sqrt(pow(x,2) + pow(y,2)) * 6371;
  return d;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();

    double aLon = stringToFloat(LON);
    double aLat = stringToFloat(LAT);

    int N;
    cin >> N; cin.ignore();

    float min = 100000.0;
    string res;

    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        size_t pos = DEFIB.rfind(";");
        string tmp = DEFIB.substr(pos+1);
        float bLat = stringToFloat(tmp);

        string tmp2 = DEFIB.substr(0,pos);
        size_t pos2 = tmp2.rfind(";");
        float bLon = stringToFloat(tmp2.substr(pos2+1));

        size_t posN = DEFIB.find(";");
        string tmpName = DEFIB.substr(posN+1);
        size_t posName = tmpName.find(";");
        string name = tmpName.substr(0, posName);

        float d = distance(aLon, bLon, aLat, bLat);

        if(d < min){
            min = d;
            res = name;
        }
    }
    cout << res << endl;
}
