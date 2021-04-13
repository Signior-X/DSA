#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define print(var) cout << (var) << "\n";
#define print2(a, b) cout << (a) << " " << (b) << "\n";
#define space_print(var) cout << (var) << " ";
#define print_arr(arr) for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) space_print(arr[i]); print("")
#define print_vec(vec) for(int i = 0; i < vec.size(); i++) space_print(vec[i]); print("")
#define print_2darr(arr) for(int j = 0; j < sizeof(arr)/sizeof(arr[0]); j++) { print_arr(arr[j]); } print("")
#define print_2dvec(vec) for(int j = 0; j < vec.size(); j++) { print_vec(vec[j]); } print("")
#define print_map(m1) for(auto elem : m1) { space_print(elem.first); print(elem.second); }
#define input_arr(arr) for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) cin >> arr[i];

// The main block
int main() {

    string s;
    s = "ababcdba";

    // creating a dp 2d array of length l*l and values 0
    int l = s.length();
    int ar[l][l] = {};

    // Now we want to have the highest length subsequence
    // so every single character in itself is 1
    for(int i=0; i<l; i++) ar[i][i] = 1;

    // Loop in upper triangluar matrix in order with the matrix
    
    for(int diff = 1; diff < l; diff++) {
        int i = 0;

        while((i+diff) < l) {
            int j = i + diff;

            if(s[i] == s[j]) {
                // This can create a palindrome
                ar[i][j] = 2 + ar[i+1][j-1];
            } else {
                // Not a match choose maxx
                ar[i][j] = max(ar[i+1][j], ar[i][j+1]);
            }

            i++;
        }
    }


    print_2darr(ar);
    return 0;
}