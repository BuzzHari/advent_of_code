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
    
    int Right[5] = {1,3,5,7,1};
    int Down[5] = {1,1,1,1,2};

    int x = 0, y = 0, right, down;
    long long count = 0, ans = 1;

    for (int i = 0; i < 5; ++i) {
        right = Right[i];
        down = Down[i];
        while (x < rows)  {
            if (forest[x][y] == '#')
                ++count;

            x += down;
            y = (y+right)%cols;
        }
        cout << count << endl;
        ans *= count;
        x = y = count = 0;
    }

    cout << ans;
    return 0;
}
