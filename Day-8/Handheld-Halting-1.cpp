#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
   
    ifstream infile;
    infile.open("input.txt");

    string inp;
    char op[4];
    int arg;

    vector<pair<string, int>> instructions;
    set<int> executed_instructions;

    while(getline(infile, inp)) {
        if (inp.compare("") == 0)
            break;
                
        sscanf(inp.c_str(), "%s %d", op, &arg);
        //cout << op << " " << arg << endl;
        
        string inst(op);
        instructions.push_back(make_pair(inst, arg)); 

    }

    /*
     *for (int i = 0; i < instructions.size(); ++i)
     *    cout << instructions[i].first << " " << instructions[i].second << endl;
     */
    
    // Executing the instructions. 
    int accumulator = 0;
    int ip = 0; // Instruction pointer. 
    
    while (executed_instructions.find(ip) == executed_instructions.end()) {
        // Executed instruction pointed by ip. 
        
        if (instructions[ip].first.compare("acc") == 0) {
            accumulator += instructions[ip].second;
            executed_instructions.insert(ip);
            ip += 1;
        }
        else if (instructions[ip].first.compare("jmp") == 0) {
            executed_instructions.insert(ip);
            ip += instructions[ip].second;
        }
        else  {
            executed_instructions.insert(ip);
            ip += 1; // nop. just increment ip. 
        }

    }
    
    cout << accumulator << endl;

    return 0;
}
