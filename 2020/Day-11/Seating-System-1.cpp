#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int checkAdjacentSeats(const vector<string> &grid, int row, int col) {
    
    int count = 0;
    // Check up. 
    if (row-1 >= 0)
        if (grid[row-1][col] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    // Check down.
    if (row+1 < grid.size())
        if (grid[row+1][col] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    // Check left. 
    if (col-1 >= 0)
        if (grid[row][col-1] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    // Check right
    if (col+1 < grid[0].size())
        if (grid[row][col+1] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    // Check diagonals. 
    if (row-1 >= 0 && col-1 >= 0) 
        if (grid[row-1][col-1] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;
    
    
    if (row+1 < grid.size() && col+1 < grid[0].size()) 
        if (grid[row+1][col+1] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    if (row-1 >= 0 && col+1 < grid[0].size()) 
        if (grid[row-1][col+1] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    if (row+1 < grid.size() && col-1 >= 0) 
        if (grid[row+1][col-1] == '#')
            if (grid[row][col] == 'L')
                return 0;
            else 
                ++count;

    if (grid[row][col] == 'L')
        return 1;
    else {
        if (count >=4)
            return 1;
        return 0;
    }

}

void simulate(const vector<string>& grid, vector<string>& grid2, int& occupied_seats, int& change_flag) {

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {

            if (grid[i][j] == 'L') {
                if (checkAdjacentSeats(grid, i, j)) {
                    grid2[i][j] = '#';
                    ++occupied_seats;
                    change_flag = 1;
                }
            }

            else if (grid[i][j] == '#') {
                if (checkAdjacentSeats(grid, i, j)) {
                    grid2[i][j] = 'L';
                    --occupied_seats;
                    change_flag = 1;
                }
            }
            else {
                //'.' floor case. Do nothing. 
            }
        }
    }
}

void print(vector<string> &grid) {
    for (string s : grid)
        cout << s << endl;
    cout << endl;
}

int main(int argc, char **argv) {

    ifstream infile;
    infile.open(argv[1]);

    string inp;
    vector<string> grid;

    while(infile >> inp) 
        if (inp != "")
            grid.push_back(inp);
    
    for (string s : grid)
        cout << s << endl;
    cout << endl;
    
    int change_flag = 0;
    int occupied_seats = 0;
    
    vector<string> grid2(grid);
    while (1) {
        simulate(grid, grid2, occupied_seats, change_flag);
        print(grid2);
        cout << "Occupied seats: " << occupied_seats << endl;
        grid.swap(grid2);
        grid2 = grid;
        if (change_flag)
            change_flag = 0;
        else
            break;
    }

    cout << "Ans: " << occupied_seats << endl;
    return 0;
}
