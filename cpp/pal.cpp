#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define print(var) cout << (var) << "\n";
#define print2(a, b) cout << (a) << " " << (b) << "\n";
#define space_print(var) cout << (var) << " ";
#define print_1d(arr) for(auto it0: arr) { space_print(it0); } print("");
#define print_2d(lst) for(auto it1: lst) { print_1d(it1); } print("");
#define print_map(m1) for(auto elem : m1) { space_print(elem.first); print(elem.second); }
#define input_arr(arr) for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) cin >> arr[i];
#define iloop(l) for(ll i = 0; i < l; i++)
#define tests int t; cin >> t; while(t--)


void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// The main block
int main() {

    int V = 5;
    vector<int> adj[V];

    // Vector number should be from 0 to 4
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 

    print_2d(adj);
    
    
    return 0;
}