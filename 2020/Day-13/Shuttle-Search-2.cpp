#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {

    ifstream infile;
    infile.open(argv[1]);

    string inp;
    int tstamp, id;

    infile >> tstamp;
    infile >> inp;
    
    istringstream iss(inp);
    string token;

    // Chinese remainder theorem:
    // Let 't' be the required timestamp.
    //     aᵢ     nᵢ
    // t ≡ 0  (mod 7)
    // t ≡ 12 (mod 13)
    // t ≡ 55 (mod 59)
    // t ≡ 25 (mod 31)
    // t ≡ 12 (mod 19)
    // 
    // t = ∑aᵢNᵢxᵢ (mod N),
    //      where, N is product of all nᵢ,
    //      Nᵢ is N/nᵢ, xᵢ is inverse of Nᵢ.
     
    unsigned long long N = 1;
    vector<int> a;
    vector<pair<int,int>> n;
    int i = 0;
    while(getline(iss, token, ',')) {
        if (token != "x") {
            id = atoi(token.c_str());
            n.push_back(make_pair(id,i));
            N *= id;
        }
        ++i;
    }
    
    // First one will always be zero. 
    a.push_back(0);
    // Calculating rest of 'a'.
    for (int i = 1; i < n.size(); ++i) {
        int ai = n[i].first - n[i].second;
        while (ai < 0)
            ai += n[i].first;
        a.push_back(ai);
    }
    // Calculating Nᵢ. 
    vector<unsigned long long int> Ni;
    for (int i = 0; i < n.size(); ++i) {
        Ni.push_back(N / n[i].first);
    }

    for (int x : a)
        cout << x << " ";
    cout << endl;

    for (pair<int,int> x : n)
        cout << x.first << " ";
    cout << endl;
    
    for (auto x : Ni)
        cout << x << " ";
    cout << endl;
    
    return 0;
}
