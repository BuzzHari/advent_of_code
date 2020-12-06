#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

int main() {

    ifstream infile;
    infile.open("input.txt");

    string inp;
    char questions[27];
    memset(questions, 0, 27*sizeof(char));
    int sum = 0;
    while(getline(infile, inp)) {
        if (inp != "") {
            
            for (int i = 0; i < inp.size(); ++i) {
                if (questions[inp[i]-'a'] == 0) {
                    ++sum;
                    questions[inp[i]-'a'] = 1;
                }
            }
            
        }
        else {
            memset(questions, 0, 27*sizeof(char));
        }
    }
    cout << sum << "\n";
    return 0;
}

