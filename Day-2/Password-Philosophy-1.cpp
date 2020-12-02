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
    map<char, int> mp;
    while (getline(infile, input)) {
        sscanf(input.c_str(), "%d-%d %c: %s", &min, &max, &ch, pass);
        
        for (int i = 0; pass[i] != '\0'; ++i)
            mp[pass[i]] += 1;

        if (mp[ch] >= min && mp[ch] <= max)
            ++count;
        mp.clear();
    }
    cout << count << "\n";
    return 0;
}
