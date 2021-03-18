// you can use binarylifting also for find the kth child if every node has one child
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
vector<vector<int>> adj(MAX), jump(MAX, vector<int>(l,-1));
int n, m, parent[MAX];

void dfs(int node, int p) {
    parent[node] = p;
    for (int i = 0; i < adj[node].size(); ++i) {
        int v = adj[node][i];
        if (v != p)dfs(v, node);
    }
}

int findKthAncestor(int node, int k) {
    for (int i = ceil(log2(n)); i >= 0; --i) {
        if (~jump[node][i] && (1 << i) <= k) {
            node = jump[node][i];
            k = k - (1 << i);
        }
    }
    return node;
}

void BinaryLifting() {

    for (int i = 1; i <= n; ++i) {
        jump[i][0] = child[i];
    }
    for (int i = 1; i <= ceil(log2(n)); ++i) {
        for (int j = 1; j <= n; ++j) {
            if (jump[j][i - 1] != -1) jump[j][i] = jump[jump[j][i - 1]][i - 1];
        }
    }
}
