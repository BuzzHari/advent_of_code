#include <iostream>
#include <fstream>
#include <set>
using namespace std;


int main() {
    
    ifstream infile;
    infile.open("input.txt");

    set<int> mp;
    int val;
    
    while(infile >> val) {
        mp.insert(val);
    }
    int a, b;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (mp.find(2020-*it) != mp.end()) {
            a = *it;
            b = 2020-*it;
            cout << a*b;
            break;
        } 
    }
    return 0;
}
