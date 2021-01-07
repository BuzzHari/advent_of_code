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
    int tstamp;
    int id, ans_id, diff, min_diff = 1e9;

    infile >> tstamp;
    infile >> inp;
    
    istringstream iss(inp);
    string token;
    while(getline(iss, token, ',')) {
        
        if (token != "x") {
            id = atoi(token.c_str());
            
            diff = id - (tstamp % id);
            if (diff < min_diff) {
                min_diff = diff;
                ans_id = id;
            }
        }
    }
    
    cout << "ID: " << ans_id << endl;
    cout << "Ans: " << ans_id * min_diff << endl;
    
    return 0;

}
