#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;

void decode(char ch, int& lower_half, int& upper_half) {

    if (ch == 'F' || ch == 'L') {
        upper_half = (lower_half+upper_half)/2;
    }
    else if (ch == 'B' || ch == 'R') {
        lower_half = ceil((lower_half+upper_half)/2.0);
    }
}

int main(int argc, char **argv) {

    ifstream infile;
    infile.open("input.txt");
    //infile.open(argv[1]);

    string inp;
    int row, col, i;
    int lower_half = 0, upper_half = 127;
    int id;
    set<int> id_list;
    while (getline(infile, inp)) {
        // Decoding Row.
        lower_half = 0, upper_half = 127;
        for (i = 0; i < 6; ++i){
            decode(inp[i], lower_half, upper_half);
        }
        if (inp[i] == 'F')
            row = lower_half;
        else 
            row = upper_half;

        // Decoding Column.
        ++i;
        lower_half = 0, upper_half = 7;
        for (; i < 9; ++i) {
            decode(inp[i], lower_half, upper_half);
        }

        if (inp[i] == 'L')
            col = lower_half;
        else 
            col = upper_half;


        // Calculating seat id.
        id = row*8L + col;
        id_list.insert(id);
    }

    // All the possible seat ids: 0-1023. 
    // My seat wasn't at the very back nor 
    // at the very front, so it's not in row 0 and row 127
    // 'i' is my possible seat id.
    int my_seat;
    for (i = 8; i <= 1016; ++i) {
        if (id_list.find(i+1) != id_list.end() && id_list.find(i-1) != id_list.end())
            if (id_list.find(i) == id_list.end()) {
                my_seat = i;
                break;
            }
    }

   cout << my_seat << endl;
            
    return 0;
}

