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

struct node {
    int from, to, cost;
};
const int MAX = 1e3 + 5;
int SP[MAX], pre[MAX];

bool negative=0;
bool bellmanford(vector<node> &adj, int source, int n) {
    clr(pre, -1);
    negative=0;
    fill(SP,SP+n+3,1e9);
    SP[source]=0;
    for (int k = 1; k <=n ; ++k) {
        adj.push_back({0, k,0});
    }
    for (int i = 0; i < n; ++i) {//we used n instead of n-1 to check the negative cycles
        for (int j = 0; j < adj.size(); ++j) {
            node edg = adj[j];
            if (SP[edg.to] > SP[edg.from] + edg.cost) {
                SP[edg.to] = SP[edg.from] + edg.cost;
                pre[edg.to] = edg.from;//for the path
                if(i==n-1)negative=1;
            }
        }
    }

    //to know the nodes which affected by negative cyles run bellman again on a copy of the distance arr and compare
    // nodes , if the cost changed then it's in a negative cycle
    return negative;
}
