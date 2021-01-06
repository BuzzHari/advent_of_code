#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const char LEFT_DIRECTION[4] = {'N', 'W', 'S', 'E'};
map<char, int> L_D;
const char RIGHT_DIRECTION[4] = {'N', 'E', 'S', 'W'};
map<char, int> R_D;

void proccessInstruction(string inp, int& east, int& north, char& direction) {
    
    char inst;
    int inst_value;
    sscanf(inp.c_str(), "%c%d", &inst, &inst_value);
    
    switch(inst) {
        case 'N': {
                      north += inst_value;
                      break;
                  }
        case 'S': {
                      north -= inst_value;
                      break;
                  }
        case 'E': {
                      east += inst_value;
                      break;
                  }
        case 'W': {
                      east -= inst_value;
                      break;
                  }
        case 'L': {
                      int i = inst_value / 90;
                      direction = LEFT_DIRECTION[(i+L_D[direction]) % 4];
                      break;
                  }
        case 'R': {
                      int i = inst_value / 90;
                      direction = RIGHT_DIRECTION[(i+R_D[direction]) % 4];
                      break;
                  }
        case 'F': {
                      if (direction == 'N')
                          north += inst_value;
                      else if (direction == 'E')
                          east += inst_value;
                      else if (direction == 'S')
                          north -= inst_value;
                      else 
                          east -= inst_value;

                      break;
                  }

    }
}

int main(int argc, char **argv) {

    ifstream infile;
    infile.open(argv[1]);

    L_D['N'] = 0;
    L_D['W'] = 1;
    L_D['S'] = 2;
    L_D['E'] = 3;

    R_D['N'] = 0;
    R_D['E'] = 1;
    R_D['S'] = 2;
    R_D['W'] = 3;
    
    string inp;

    // Intial Postion.
    // Negative east is west, and negative north is south. 
    int east = 0, north = 0;
    // Intial Direction. 
    char direction = 'E';

    while(infile >> inp) {
        proccessInstruction(inp, east, north, direction);
        cout << east << " " << north << " " << direction << endl;
    }
    
    int man_distance = abs(east) + abs(north); 
    cout << "Ans: " << man_distance << endl;
    return 0;
}
