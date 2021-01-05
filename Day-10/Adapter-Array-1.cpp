#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv) {

    ifstream infile;
    infile.open(argv[1]);
    
    vector<int> adapters;
    int inp;
    
    adapters.push_back(0);
    while( infile >> inp) 
        adapters.push_back(inp);

    sort(adapters.begin(), adapters.end());

    int one_jolts = 0, two_jolts = 0, three_jolts = 1;
    int device_rating = adapters[adapters.size()-1] + 3;

    for (int i = 0; i < adapters.size()-1; ++i) {

        if (adapters[i+1] - adapters[i] == 1)
            ++one_jolts;
        else if (adapters[i+1] - adapters[i] == 2)
            ++two_jolts;
        else if (adapters[i+1] - adapters[i] == 3)
            ++three_jolts;
        else {
            cout << "This case should'nt happen, something wrong\n";
            return 0;
        }
    }
    
    cout << "One jolts: " << one_jolts << endl;
    cout << "Two jolts: " << two_jolts << endl;
    cout << "There jolts: " << three_jolts << endl;

    cout << "Ans: " << one_jolts * three_jolts << endl;

    return 0;

}
