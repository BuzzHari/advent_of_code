#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    
    ifstream infile;
    infile.open(argv[1]);

    int inp;
    const int PREAMBLE = 25;
    
    vector<int> all_numbers;
    vector<int> numbers; 
    set<int> st;  
    int counter = PREAMBLE;
    while(counter--) {
        infile >> inp;
        numbers.push_back(inp);
        all_numbers.push_back(inp);
        st.insert(inp);
    }

    int flag = 0;
    long invalid_num = 0;
    while (infile >> inp)  {
        all_numbers.push_back(inp); 
        
        if (!flag) {
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
                cout << "Ans: " << inp << endl;
                invalid_num = inp;
                flag = 1;
            }
            else  {
                numbers.push_back(inp);
                st.insert(inp);
                flag = 0;
            }

            int to_delete = numbers[0];
            numbers.erase(numbers.begin());
            st.erase(to_delete);
        }
    }
    cout << invalid_num << endl;
    int curr_sum = all_numbers[0], start = 0;
    int end;
    for (int i = 1; i <= all_numbers.size()-1; ++i) {
        while(curr_sum > invalid_num && start < i-1) {
            curr_sum = curr_sum - all_numbers[start];
            ++start;
        }

        if (curr_sum == invalid_num) {
            end = i-1;
            break;
        }

        if (i < all_numbers.size())
            curr_sum = curr_sum + all_numbers[i];

    } 
    cout << start << " " << end << endl;
    vector<int> subarr(all_numbers.begin()+start, all_numbers.begin()+end+1);
    sort(subarr.begin(), subarr.end());
    cout << subarr.size() << endl;
    cout <<"Ans:  " << subarr[0] + subarr[subarr.size()-1];
    
    

   
   return 0;
       
}

