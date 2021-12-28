#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {

    ifstream infile;
    infile.open("input.txt");

    vector<string> forest;

    string inp;
    while(getline(infile,inp)) 
        forest.push_back(inp);

    /*
     *for (int i = 0; i < forest.size(); ++i) {
     *    for (int j = 0; j < forest[i].size(); ++j) {
     *        cout << forest[i][j];
     *    }
     *    cout << endl;
     *}
     */
    
    int rows = forest.size();
    int cols = forest[0].size();
    
    int x = 0, y = 0, right, down;
    long long count = 0;

    right = 3;
    down = 1;
    while (x < rows)  {
        if (forest[x][y] == '#')
            ++count;

        x += down;
        y = (y+right)%cols;
    }

    cout << count;
    return 0;
}
