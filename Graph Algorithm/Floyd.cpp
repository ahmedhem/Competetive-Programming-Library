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
const int MAX = 2e5;
int n ;
vector<vector<int>> adj(MAX, vector<int>(MAX, 1e8));
int OO = 1e9;

void floyd() {
    for (int i1 = 1; i1 <= n; ++i1) {
        adj[i1][i1] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (adj[j][i] > adj[j][k] + adj[k][i]) {
                    adj[j][i] = adj[j][k] + adj[k][i];
                }
            }
    }
}
/****maxMini*******/

void floyd() {
    for (int i1 = 1; i1 <= n; ++i1) {
        adj[i1][i1] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                adj[j][i] = max(adj[j][i], min(adj[j][k], adj[k][i]));
            }
        }
    }
}
/****miniMAX*******/

void floyd() {
    for (int i1 = 1; i1 <= n; ++i1) {
        adj[i1][i1] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                adj[j][i] = min(adj[j][i], max(adj[j][k], adj[k][i]));
            }
        }
    }
}
