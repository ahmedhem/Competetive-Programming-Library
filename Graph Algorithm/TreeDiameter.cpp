
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

const int MAX = 2e4 + 10;
int l = ceil(log2(MAX));
vector<vector<int>> adj(MAX);
int n, start, e, fStart[MAX], fEnd[MAX];

void findFarth(int node, int p, int dep, int &val, int &mxDist) {
    if (dep > mxDist) {
        mxDist = dep;
        val = node;
    }
    for (int i = 0; i < adj[node].size(); ++i) {
        int v = adj[node][i];
        if (v != p)findFarth(v, node, dep + 1, val, mxDist);
    }
}
int main(){
    fast()
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx = -1;
    findFarth(1, -1, 0, start, mx);
    mx = -1;
    findFarth(start, -1, 0, e, mx);
    cout<<start<<" "<<e<<" "<<mx;
}