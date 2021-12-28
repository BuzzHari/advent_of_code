#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {

    ifstream infile;
    infile.open("input.txt");

    int count = 0;

    string input;
    int min, max;
    char ch;
    char pass[100];
    while (getline(infile, input)) {
        sscanf(input.c_str(), "%d-%d %c: %s", &min, &max, &ch, pass);
        
        if (pass[min-1] == ch && pass[max-1] != ch)
            ++count;
        else if (pass[min-1] != ch && pass[max-1] == ch)
            ++count;

    }
    cout << count << "\n";
    return 0;
}
