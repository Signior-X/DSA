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

    // So now the task is to find the longest palindrome
    // subtring in linear time
    string st;
    st = "ababcdba";

    string T = "&#";
    for (auto it : st) T = T + it + "#";
    T += "@";

    int lenT = T.length();
    int P[lenT] = {};

    int C = 0, R = 0, mirr = -1;
    int mxl = 1; // The length of the palindrome string
    int mxi = 2; // Mid index of the palindrome string

    for (int i = 1; i < lenT - 1; i++) {
        mirr = 2*C - 1;

        if (i < R) P[i] = min(R-i, P[mirr]);

        while(T[i + (1 + P[i])] == T[i - (1 + P[i])]) P[i] += 1;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        if (P[i] > mxl) {
            mxl = P[i];
            mxi = i;
        }
    }

    print(st);
    print_arr(P);

    // Now assuming the length of substring is odd
    string ans;
    ans += T[mxi];
    int start = mxi - 2, end = mxi + 2;

    if (!(mxl & 1)) {
        // Even
        ans = "";
        start = mxi - 1;
        end = mxi + 1;
    }

    while(ans.length() < mxl) {
        ans = T[start] + ans + T[end];
        start -= 2;
        end += 2;
    }

    print(ans);

    return 0;
}