#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    
    ifstream infile;
    infile.open("input.txt");

    vector<int> arr;
    int val;
    
    while(infile >> val)
        arr.push_back(val);
    
    sort(arr.begin(), arr.end());
    int a, b;

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i+1, k = arr.size()-1; j < k ; ++j) {
            while(j < k && (arr[i] + arr[j] + arr[k]) > 2020)
                --k;

            if (j < k && arr[i] + arr[j] + arr[k] == 2020) {
                cout << arr[i]*arr[j]*arr[k];
                return 0;
            }
            
        }
    }
    return 0;
}
