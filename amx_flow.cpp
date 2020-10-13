#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define aint(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<10> MASK;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> vvi;

//set iterator can be increamnted and decreamnted
void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int MAX = 1000;
int cap[MAX][MAX];

int find_path(int start, int sink, vvi &adj) {
    queue<int> q;
    int vis[MAX], path[MAX];
    q.push(start);
    clr(vis,0);
    vis[start] = 1;
    clr(path, -1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int j = 0; j < adj[node].size(); ++j) {
            int v = adj[node][j];
            if (!vis[v] && cap[node][v] != 0) {
                q.push(v);
                vis[v] = 1;
                path[v] = node;
                if (v == sink)break;

            }
        }
    }
    int mn_cap = INT_MAX, now = sink;
    while (~path[now]) {
        int prv = path[now];
        mn_cap = min(mn_cap, cap[prv][now]);
        now = prv;
    }
    now = sink;
    while (~path[now]) {
        int prv = path[now];
        cap[prv][now] -= mn_cap;
        cap[now][prv] += mn_cap;
        now = prv;
    }
    if (mn_cap == INT_MAX)return 0;
    else return mn_cap;

}

int maxflow(int start, int sink, vvi &adj) {
    int ans = 0;
    while (1) {
        int capacity = find_path(start, sink, adj);
        if (!capacity)break;
        ans += capacity;
    }
    return ans;
}

int main() {
    fast();
    vvi adj(MAX);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[1].push_back(3);
    cap[1][2]=1;
    cap[1][3]=1;
    cap[2][3]=2;
    cap[3][4]=4;
    cout<<maxflow(1,4,adj);
    return 0;

}
