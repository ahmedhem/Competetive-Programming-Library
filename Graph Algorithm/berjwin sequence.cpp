/* Eulerian path is a pth which traverse all the edges exactly once
 * Eulerain circuits is a node which you can start traversing the graph from it and visist all edges exactly once then go back to this node
 * Eulerian path and Eulerain circuits required there to be all nonzero degree nodes belong only to one component
 * requirement of existence of Eulerain circuits in undirected graph  is that all nodes has even degree
 * requirement of existence of Eulerain path in undirected graph  is that all nodes has even degree or there is exactly two nodes with odd degree (start and end)
 * requirement of existence of Eulerain circuits in directed graph  is that every node has equal indegree and outdegree
 * requirement of existence of Eulerain path in directed graph  is that that every node has equal indegree and outdegree or there is at most
   one vertics with out-in = 1 and at most one node with in-out

 */
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

unordered_map<string, int> e;
const int MAX = 2e5 + 4;
int in[MAX], out[MAX], n,t;
vector<vector<int>> adj(MAX);
vector<int> ans;

void findOutIn() {
    for (int i = 1; i <= t; ++i)
        for (auto to : adj[i])in[to]++, out[i]++;
}

int idx[MAX];
void dfs(int node,int val){
    while(out[node]){
        dfs(adj[node][--out[node]],out[node]-1);
    }
    ans.push_back(val);
}

void Hierholzer() {
    findOutIn();
    string s;

    for (int i = 0; i < n-1; ++i) {
        s+='0';
    }
    dfs(e[s],-1);
}

int main() {
    fast();
    cin >> n;
    if(n==1)return cout<<"01",0;
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        bitset<15> x = i;
        string s=x.to_string();
        reverse(all(s));
        s = s.substr(0, n - 1);

        e[s] = ++t;
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        bitset<15> x = i;
        string s=x.to_string();
        reverse(all(s));
        s = s.substr(0, n - 1);
        int u = e[s];
        s.erase(s.begin());
        string tmp = s + '0';
        string tmp1 = s + '1';
        adj[u].push_back(e[tmp]);
        adj[u].push_back(e[tmp1]);
    }
    Hierholzer();
    ans.pop_back();
    for (int i = 0; i < n-1; ++i) {
        ans.push_back(0);
    }
    reverse(all(ans));

    for (auto i : ans)cout << i;


}