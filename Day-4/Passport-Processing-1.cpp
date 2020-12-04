#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

int main() {

    ifstream infile;
    infile.open("input.txt");
    
    string inp, inp2;
    int valid_count = 0;
    int num_fields=0, cid_flag=0;

    char field[100];
    char value[100];
    
    while(getline(infile, inp)) {
        if (inp != "") {
            istringstream in;
            in.str(inp);
            while(in >> inp2) {
                sscanf(inp2.c_str(),"%[^:]:%s",field, value);
                if(strcmp(field,"cid") == 0) 
                    cid_flag=1;
                ++num_fields;      
            }
        }
        else {
            if (num_fields == 8 || (num_fields == 7 && !cid_flag))
                ++valid_count;
            num_fields = 0;
            cid_flag = 0;
        }
    }

    cout <<  valid_count;
    return 0;
}
