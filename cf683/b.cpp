#include<iostream>  
  
using namespace std; 


int main() 
{ 
    int t = 0;
    cin >> t;

    while (t-- > 0)
    {

        int n = 0, m = 0;
        cin >> n >> m;

        int arr[n][m];
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        int negv = 0, minv = 101, sumv = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = arr[i][j];

                if(val < 0) negv++;

                sumv += abs(val);

                minv = min(minv, abs(val));
            }
        }

        if (negv % 2 ==0)
            cout << sumv << endl;
        else
            cout << (sumv - 2*minv) << endl;

    }
    
      
    return 0; 
}
