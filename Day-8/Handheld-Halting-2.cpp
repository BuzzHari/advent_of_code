#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
using namespace std;


// Executes the instructions. 
// Returns <accumlator, isLoop>, basically the acumulator value
// and a bool to indicate wether there's a loop or not. 
pair<int, bool> execute(vector<pair<string,int>> instructions) {

    set<int> executed_instructions;
    bool isLoop = 1;


    int accumulator = 0;
    int ip = 0; // Instruction pointer. 
    
    while (executed_instructions.find(ip) == executed_instructions.end() 
            && ip < instructions.size()) {
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
    
    // This means the instructions ended without a loop. 
    if (ip >= instructions.size())
        isLoop = 0;
    
    return make_pair(accumulator, isLoop);
}

int main(int argc, char **argv) {
   
    ifstream infile;
    infile.open("input.txt");

    string inp;
    char op[4];
    int arg;

    vector<pair<string, int>> instructions;

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
    
    // The idea here is to change each "nop" to "jmp" and "jmp" to "nop" one by one
    // and check if the program terminates. 

    pair<int, bool> accumulator;
    for (int i = 0; i < instructions.size(); ++i) {

        if (instructions[i].first.compare("nop") == 0) {

            instructions[i].first = "jmp";
            accumulator = execute(instructions);
            // Reverting the change. 
            instructions[i].first = "nop";
        }
        else if (instructions[i].first.compare("jmp") == 0) {
            
            instructions[i].first = "nop";
            accumulator = execute(instructions);
            // Reverting the change. 
            instructions[i].first = "jmp";
        }
        else 
            continue;
        
        // No loop found, print the accumulator value and break. 
        if (!accumulator.second) {
            cout << accumulator.first << endl;
            break;
        }
    }

    return 0;
}
