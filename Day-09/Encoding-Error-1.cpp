#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char **argv) {
    
    ifstream infile;
    infile.open(argv[1]);

    int inp;
    const int PREAMBLE = 25;
    
    vector<int> numbers; 
    set<int> st;  
    int counter = PREAMBLE;
    while(counter--) {
        infile >> inp;
        numbers.push_back(inp);
        st.insert(inp);
    }

    while (infile >> inp)  {
        int flag = 0;
        
        for (int i = 0; i < numbers.size(); ++i) {
            int other_num = abs(inp - numbers[i]);
            if (st.find(other_num) != st.end()) {
                flag = 1;
                break;
            }
            if (flag)
                break;
        }
        
        if (!flag) {
            cout << "Ans: " << inp;
            break;
        }
        else  {
            numbers.push_back(inp);
            st.insert(inp);
        }

        int to_delete = numbers[0];
        numbers.erase(numbers.begin());
        st.erase(to_delete);
   }
   
   return 0;
       
}

