#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
using namespace std;


map<string, int> bags;
map<int, vector<pair<int, int>>> rules;

long dfs(int vertex, const vector<pair<int,int>>& edges, int visited[]);

int main(int argc, char **argv) {

    ifstream infile;
    infile.open("input.txt");

    string inp;

    string token; 
    int vertex, edge, bag_cnt;
    string vertex_bag, edge_bag;
    
    int cnt_flag;
    while(getline(infile, inp)) {
        if (inp.compare("") == 0)
            break;
        
        istringstream in;
        in.str(inp);
        // Extracting the name of the bag,
        // which will be the vertex. 
        vertex_bag = "";
        for (int i = 0; i < 2; ++i) {
            in >> token;
            vertex_bag += token;
        }
       
        // Basically assigning each bag a numerical value. 
        if (bags.find(vertex_bag) == bags.end()) 
            bags[vertex_bag] = bags.size()+1;
        
        // Get the number assigned to the bag.  
        vertex = bags[vertex_bag];
        
        // Initializing the vertex to 0 edges. 
        rules[vertex];
        // Discard " bags contain".
        in >> token;
        in >> token;
        // Extracting all the bags with their counts
        // The flag is to make sure to extract the count, 
        // and then the name of the bag.
        cnt_flag = 1; 
        token = "";
        while(in >> token) {
            if (cnt_flag) { 
                // "no other bag" case, 
                //  token will contain "no"
                if (token.compare("no") == 0)
                    break;
                bag_cnt = stoi(token);
                cnt_flag = 0;
            }
            else {
                // Get bag name. 
                edge_bag = "";
                edge_bag += token;
                in >> token;
                edge_bag += token;

                // Discard  "bag," "bags,"..etc.
                in >> token; // bags/bag
                // Assign a number to the bag, if it hasn't 
                // been proccessd yet. 
                if (bags.find(edge_bag) == bags.end()) 
                    bags[edge_bag] = bags.size()+1;

                edge = bags[edge_bag];

                // Insert in rules. Basically the adjancey list. 
                rules[vertex].push_back(make_pair(edge, bag_cnt));
                
                // Reseting the count flag for the next bag if it's there. 
                cnt_flag = 1;
            }
        }
    }

    /*
     *for (auto it = bags.begin(); it != bags.end(); ++it) 
     *    cout << it->first << " - " << it->second << "\n";
     *
     *for (auto it = rules.begin(); it != rules.end(); ++it) {
     *    cout << it->first << "-->";
     *    for (int i = 0; i < it->second.size(); ++i, cout << " ") 
     *        cout << "(" << it->second[i].first << "," << it->second[i].second << ")";
     *    cout << "\n";
     *}
     */
     
    string my_bag = "shinygold";
    int my_bag_id = bags[my_bag];
    
    
    int visited[bags.size()+1] = {0};
    
    long ret = dfs(my_bag_id, rules[my_bag_id], visited);
    cout << ret;

    return 0;

}


long dfs(int vertex, const vector<pair<int,int>>& edges,int visited[]) {
    
    long num = 0;
    // mark node visited. 
    visited[vertex] = 1;
    //cout << vertex << " ";
    for (int i = 0; i < edges.size(); ++i) {
        num += edges[i].second;
        num += edges[i].second * dfs(edges[i].first, rules[edges[i].first], visited);
    }
    return num;
}

