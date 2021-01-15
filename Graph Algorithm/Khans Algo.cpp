#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<10> MASK;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

void computeInDegree(int n, int inDegree[], vector<vector<int>> &adj) {
    for (int i = 1; i <= n; i++) {
        for (auto e: adj[i])inDegree[e]++;
    }
}

vector<int> KhansAlgo(int n, int inDegree[], vector<vector<int>> &adj) {
    computeInDegree(n,inDegree,adj);
    queue<int>q;
    vector<int>topologicalSort;
    for (int i = 1; i <=n ; ++i) {
        if(!inDegree[i])q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        topologicalSort.push_back(node);
        q.pop();
        for (int i = 0; i < adj[node].size(); ++i) {
            int v=adj[node][i];
            inDegree[v]--;
            if(!inDegree[v])q.push(v);
        }
    }
return topologicalSort;
}