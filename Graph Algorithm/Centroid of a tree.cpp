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

const int MAX = 2e5 + 5;;
int n, sbSize[MAX]; //size of sub tree;
vector<vector<int>> adj(MAX),CentroidTree(MAX);

int computesbSize(int u, int p) {
    sbSize[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (p != v)sbSize[u] += computesbSize(v, u);
    }
    return sbSize[u];
}

int findCentroid(int u, int p) {
    int toBeTraversed, mx = -1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (v != p && sbSize[v] > mx)mx = sbSize[v], toBeTraversed = v;
    }
    if (mx <= n / 2&&n-sbSize[u]<=n/2)return u;
    return findCentroid(toBeTraversed, u);
}


int main() {
    fast();
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    computesbSize(1, -1);
    cout << findCentroid(1, -1);
}

