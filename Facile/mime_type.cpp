#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    vector<string> tabEXT;
    vector<string> tabMT;
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        tabEXT.push_back(EXT);
        tabMT.push_back(MT);
    }

    vector<string> ex;
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
        ex.push_back(FNAME);
    }

    for (int i = 0; i < Q; i++) {
        size_t pos = ex[i].rfind('.');
        if( pos != -1){
            string tmp = ex[i].substr(pos+1);
            auto found = find(begin(tabEXT), end(tabEXT), tmp);
            if(end(tabEXT)!=found){
                auto index = distance( begin(tabEXT), found );
                cout << tabMT[index] << endl;
            }
            else{
                cout << "UNKNOWN" << endl;
            }
        }
        else{
           cout << "UNKNOWN" << endl;
        }
    }
}
