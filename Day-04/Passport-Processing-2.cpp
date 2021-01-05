#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

int valid(char *field, char *value) {

    if (strcmp(field, "byr")==0) {
        int val = atoi(value);
        if (val >= 1920 && val <= 2002)
            return 1;

        //cout << "byr FAIL\n";
    }
    if (strcmp(field, "iyr")==0) {
        int val = atoi(value);
        if (val >= 2010 && val <= 2020)
            return 1;

        //cout << "iyr FAIL\n";
    }
    if (strcmp(field, "eyr")==0) {
        int val = atoi(value);
        if (val >= 2020 && val <= 2030)
            return 1;

        //cout << "eyr FAIL\n";
    }
    if (strcmp(field, "hgt")==0) {
        int val;
        char height[3]; 
        sscanf(value, "%d%s", &val,height);
        //cout << val << " " << height;
        if (strcmp(height, "") != 0) {
            if (height && strcmp(height,"cm")==0)
                if (val >= 150 && val <= 193)
                    return 1;
            if (height && strcmp(height,"in")==0)
                if (val >= 59 && val <= 76)
                    return 1;
        }
        //cout << "hgt FAIL\n";
    }
    if (strcmp(field, "hcl")==0) {
        int flag = 1;
        if (strlen(value) == 7 && value[0] == '#') {
            for (int i = 1; value[i] != '\0'; ++i) {
                if ( (value[i] >= '0' && value[i] <= '9') || (value[i] >= 'a' && value[i] <= 'f'))
                    continue;
                flag = 0;
                break;
            }
            if (flag)
                return 1;
        }
        //cout << "hcl FAIL\n";
    }
    if (strcmp(field, "ecl")==0) {
        
        if (strcmp(value, "amb") == 0)
            return 1;
        if (strcmp(value, "blu") == 0)
            return 1;
        if (strcmp(value, "brn") == 0)
            return 1;
        if (strcmp(value, "gry") == 0)
            return 1;
        if (strcmp(value, "grn") == 0)
            return 1;
        if (strcmp(value, "hzl") == 0)
            return 1;
        if (strcmp(value, "oth") == 0)
            return 1;
        //cout << "ecl FAIL\n";
    }
    if (strcmp(field, "pid")==0) {
        int flag = 1;
        if (strlen(value) == 9) {
            for (int i = 0; i < 9; ++i) {
                if (value[i] >= '0' && value[i] <= '9')
                    continue;
                flag = 0;
                break;
            }
        }
        else 
            flag = 0;
        
        if (flag)
            return 1;

        //cout << "pid FAIL\n";
    }
    return 0;
}

int main(int argc, char** argv) {

    ifstream infile;
    infile.open("input.txt");
    
    string inp, inp2;
    int valid_count = 0;
    int num_fields=0;

    char field[1000];
    char value[1000];
    
    while(getline(infile, inp)) {
        if (inp != "") {
            istringstream in;
            in.str(inp);
            while(in >> inp2) {
                sscanf(inp2.c_str(),"%[^:]:%s",field, value);
                if (valid(field, value)) 
                    ++num_fields;
            }
        }
        else {
            if (num_fields == 7)
                ++valid_count;
            num_fields = 0;
        }
    }

    cout <<  valid_count;
    return 0;
}
