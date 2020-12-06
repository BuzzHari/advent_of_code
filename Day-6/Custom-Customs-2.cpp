#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;

int main() {

    ifstream infile;
    infile.open("input.txt");

    string inp;
    char questions[27];
    memset(questions, 0, 27*sizeof(char));
    int sum = 0;
    // Using bitsets to represent the questions.

    // q is question set for each person in the group.
    bitset<32> q(0);
    // group_q is the answerd questions for all the group
    // after performing AND operation on all sub sequent 'q' set. 
    // In the end the number of set bits in group_q will give the
    // count of the comman questions answered. 
    bitset<32> group_q;
    group_q.set();
    while(getline(infile, inp)) {
        if (inp != "") {
            
            for (int i = 0; i < inp.size(); ++i) {
                q[inp[i]-'a'] = 1;
            }
            group_q &= q;
            q.reset();
        }
        else {
            sum += group_q.count();
            group_q.set();
        }
        
    }
    cout << sum << "\n";
    return 0;
}

