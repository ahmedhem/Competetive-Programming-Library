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
int disc[MAX], low[MAX], lowTime[MAX], Time = 0, AP[MAX], c = 0, comp[MAX];
vector<vector<int>> adj(MAX);
vector<vector<int>> comps;
vector<pair<int, int>> bridges;
stack<int> st;

void tarjan(int u, int p) {
    int children = 0;
    low[u] = disc[u] = ++Time;
    st.push(u);
    for (int &v : adj[u]) {
        if (v == p) continue; // we don't want to go back through the same path.
        // if we go back is because we found another way back
        if (!disc[v]) { // if V has not been discovered before
            children++;
            tarjan(v, u); // recursive DFS call
            if (disc[u] < low[v]) // condition to find a bridge
                bridges.push_back({u, v});
            if (disc[u] <= low[v]) // condition #1
                AP[u] = 1;
            low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
        } else // if v was already discovered means that we found an ancestor
            low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
    }
    if (disc[u] == low[u]) {
        vector<int> component;
        c++;
        while (st.top() != u) {
            int v = st.top();
            st.pop();
            component.push_back(v);
            comp[v] = c;
        }
        comps.push_back(component);
    }
}

int main() {

}