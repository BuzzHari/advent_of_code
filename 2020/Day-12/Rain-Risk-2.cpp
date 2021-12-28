#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

const char LEFT_DIRECTION[4] = {'N', 'W', 'S', 'E'};
map<char, int> L_D;
const char RIGHT_DIRECTION[4] = {'N', 'E', 'S', 'W'};
map<char, int> R_D;

double getRadians(int degree) {
    double radians = (1.0 * M_PI * degree) / 180.0;
    return radians;
}

void rotate(int& x, int& y, double radians) {
    // Source: https://stackoverflow.com/a/34374437/8212647 
    double temp_x = x;
    double temp_y = y;
    cout << radians << endl;
    x = round(temp_x*cos(radians)-temp_y*sin(radians));
    y = round(temp_x*sin(radians)+temp_y*cos(radians));
}

void proccessInstruction(string inp, int& east, int& north, int& waypoint_east, int& waypoint_north) {
    
    char inst;
    int inst_value;
    sscanf(inp.c_str(), "%c%d", &inst, &inst_value);
    
    switch(inst) {
        case 'N': {
                      waypoint_north += inst_value;
                      break;
                  }
        case 'S': {
                      waypoint_north -= inst_value;
                      break;
                  }
        case 'E': {
                      waypoint_east += inst_value;
                      break;
                  }
        case 'W': {
                      waypoint_east -= inst_value;
                      break;
                  }
        case 'L': {
                      double radians = getRadians(inst_value);
                      rotate(waypoint_east, waypoint_north, radians);
                      break;
                  }
        case 'R': {
                      double radians = getRadians(inst_value);
                      rotate(waypoint_east, waypoint_north, -radians);
                      break;
                  }
        case 'F': {
                      east += inst_value*waypoint_east;
                      north += inst_value*waypoint_north;
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
    // Intial Waypoint.
    // Negative waypoint_east is waypoint west and negative waypoint_north is 
    // waypoint south. 
    int waypoint_east = 10, waypoint_north = 1;

    while(infile >> inp) {
        proccessInstruction(inp, east, north, waypoint_east, waypoint_north);
        cout << east << " " << north << " " << waypoint_east << " " << waypoint_north << endl;
    }
    
    int man_distance = abs(east) + abs(north); 
    cout << "Ans: " << man_distance << endl;
    return 0;
}
