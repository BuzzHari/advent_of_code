#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
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
    int id, max_id = -1;
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
        // Updating max seat id.
        max_id = max(max_id, id);
    }

    cout << max_id;
    return 0;
}

