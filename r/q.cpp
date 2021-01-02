#include<iostream>  
#include <map>

using namespace std; 
  
// main function - 
// where the execution of program begins 
int main() 
{ 
    // prints hello world 
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n, k;
        cin >> n;

        int inp[n];
        map<int, int> ma;
        
        for (int i=0; i< n; i++) {
            cin >> inp[i];
            ma[inp[i]] ++;
        }

        int ans = -1;
        for (auto i : ma) {
            if (i.second == 1) {
                ans = i.first;
                break;
            }
        }

        if (ans != -1) {
            // Now find the location of it in inp
            for (int i=0; i<n; i++) {
                if (inp[i] == ans) {
                    ans = i + 1;
                    break;
                }
            }
        }

        cout << ans << endl;

    }
    
    return 0; 
}
