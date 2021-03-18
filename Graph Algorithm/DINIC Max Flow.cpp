#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

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

struct edge {
    int to, cap, rev, flow;
};
const int MAX = 500;
int level[MAX], idx[MAX];
vector<vector<edge>> adj(MAX);

void addEdge(int u, int v, int c) {
    edge a = {v, c, (int) adj[v].size(), 0};
    edge b = {u, 0, (int) adj[u].size(), 0};
    adj[u].push_back(a);
    adj[v].push_back(b);
}

int dfs(int u, int t, int flow) {
    if (u == t)return flow;
    for (int i = idx[u]; i < adj[u].size(); idx[u]++, i++) {
        edge &e = adj[u][i];
        if (level[e.to] == level[u] + 1 && e.flow < e.cap) {
            int f = dfs(e.to, t, min(flow, e.cap - e.flow));
            if (f > 0) {
                e.flow += f;
                adj[e.to][e.rev].flow -= f;
                return f;
            }
        }
    }
    return 0;
}

bool bfs(int s, int t) {
    clr(level, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i : adj[node]) {
            if (level[i.to] == -1 && i.flow < i.cap) {
                q.push(i.to);
                level[i.to] = level[node] + 1;
            }
        }
    }
    return level[t] != -1;
}

int dinic(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
        clr(idx, 0);
        int augmantedPath;
        augmantedPath = dfs(s, t, INT_MAX);
        while (augmantedPath) {
            ans += augmantedPath;
            augmantedPath = dfs(s, t, INT_MAX);
        }
    }
    return ans;
}