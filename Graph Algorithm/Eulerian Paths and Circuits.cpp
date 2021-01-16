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
const int MAX=2e5+4;
int in[MAX],out[MAX],n,m;
vector<vector<int>>adj(MAX);
vector<int>ans;
void findOutIn(){
    for (int i = 1; i <=n ; ++i)
        for(auto to : adj[i])in[to]++,out[i]++;
}
bool checkIfHasEulirianPath(){
    int start=0,end=0;
    for (int i = 1; i <=n ; ++i) {
        if(in[i]-out[i]>1||out[i]-in[i]>1){
            return 0;
        }
        start+=(out[i]-in[i]==1);
        end+=(in[i]-out[i]==1);
    }
    return (start==1&&end==1)||(!start&&!end);
}

void dfs(int node){
    while(out[node]){
        dfs(adj[node][--out[node]]);
    }
    ans.push_back(node);
}
bool Hierholzer(){
    findOutIn();
    if(!checkIfHasEulirianPath())return 0;
    dfs(1);
    return ans.size()==m+1&&ans.back()==1&&*ans.begin()==n;
}
//don't forget to reverse