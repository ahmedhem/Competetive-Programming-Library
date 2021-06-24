#include "bits/stdc++.h"

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

const int MAX = 1e6 + 5;
int n, l;
/* using binary lifting*/
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

//using sparse table
const ll MAX = 1e6 + 5;
vector<vector<ll>> adj(MAX);
ll n,timer = 0;
int LOG[MAX * 3], st[MAX * 3][30], level[MAX * 3], in[MAX * 3], out[MAX * 3];
vector<int> eular, depth;

void computeLog(int n, int log[]) {
    log[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log[i] = log[i / 2] + 1; //rounded down
    }
}

void sparseTable(int n, int log[], int st[][30], vector<int> &depth) {
    for (int i = 1; i <= n; i++)
        st[i-1][0] = depth[i-1]<depth[i]?i-1:i;
    for (int j = 1; j <= log[n]; j++)
        for (int i = 0; i + (1 << j) <= n; i++) {
            if (st[i][j - 1] != -1 && st[i + (1 << (j - 1))][j - 1] != -1)
                st[i][j] = depth[st[i][j - 1]] < depth[st[i + (1 << (j - 1))][j - 1]] ? st[i][j - 1] : st[i + (1
                        << (j - 1))][j - 1];
        }
}

int min_range(int l, int r, int log[], int st[][30]) {
    int len = r - l + 1;
    int loge = log[len];
    int sum = depth[st[l][loge]] < depth[st[r - (1 << loge) + 1][loge]] ? st[l][loge] : st[r - (1 << loge) + 1][loge];
    return eular[sum];
}

int LCA(int u, int v) {
    if(in[u]>in[v])swap(u,v);
    if(u==v)return u;
    return min_range(in[u], in[v], LOG, st);
}

void dfs(int cur, int prev, int dep) {
    in[cur] = timer++;
    level[cur] = dep;
    eular.push_back(cur);
    depth.push_back(dep);
    for (auto x:adj[cur]) {
        if (x != prev) {
            dfs(x, cur, dep + 1);
            eular.push_back(cur);
            depth.push_back(dep);

        }
    }

}
void preprocess() {
    dfs(0, 0, 0);
    clr(st, -1);
    computeLog(eular.size(), LOG);
    sparseTable(eular.size(), LOG, st, depth);
}
