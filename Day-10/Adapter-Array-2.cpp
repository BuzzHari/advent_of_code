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
    int max_value = adapters[adapters.size()-1]; 
    adapters.push_back(max_value + 3);
    
    // no_of_paths[i]:  the number of possible paths to adapter 'i'. 
    long long no_of_paths[max_value+3 + 1] = {0};
    no_of_paths[0] = 1;
    for (int i = 1; i < adapters.size(); ++i) {
    
        if (adapters[i]-1 >= 0) 
            no_of_paths[adapters[i]] += no_of_paths[adapters[i]-1];

        if (adapters[i]-2 >= 0) 
            no_of_paths[adapters[i]] += no_of_paths[adapters[i]-2];

        if (adapters[i]-3 >= 0) 
            no_of_paths[adapters[i]] += no_of_paths[adapters[i]-3];

    } 
    
    cout << "Ans: " << no_of_paths[max_value+3] << endl;

    return 0;
}
