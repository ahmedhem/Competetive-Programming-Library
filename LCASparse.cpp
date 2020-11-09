#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

struct Adj {
    int head[N], nxt[M], to[M], ne, n;
    void init(int n) {
        memset(head, -1, (n + 1) * sizeof(head[0]));
        ne = 0;
        this->n = n;
    }
    void addEdge(int f, int t) {
        nxt[ne] = head[f];
        to[ne] = t;
        head[f] = ne++;
    }
    void addBiEdge(int f, int t) {
        addEdge(f, t);
        addEdge(t, f);
    }
    int addNode() {
        head[++n] = 0;
        return n;
    }
}tree;

vector<int> node2index, index2node, depth;

void initDFS(int n){
    depth.resize(n + 1);
    node2index.resize(n + 1);
}

void dfs(int u, int p = 0, int dpth = 0, Adj &adj = tree){
    node2index[u] = index2node.size();
    index2node.push_back(u);
    depth[u] = dpth;
    neig(adj, u, e, v){
        if(v == p)  continue;
        dfs(v, u, dpth + 1);
        index2node.push_back(u);
    }
}

int sparseTable[N][20], logs[N];

void buildSPT(){
    logs[0] = -1;
    for(int i = 0;i < index2node.size();i++) {
        logs[i + 1] = logs[i] + !(i & (i + 1));
        sparseTable[i][0] = i;
    }

    for(int j = 1;(1 << j) < index2node.size();j++){
        for(int i = 0;i + (1 << j) < index2node.size();i++){
            // sparseTable[i][j] = sparseTable[i][j - 1] ⋃ sparseTable[i + (1 << (j - 1))][j - 1]
            // 2^j = 2^(j - 1) + 2^(j - 1), jump of size 2^(j - 1) + another jump of 2^(j - 1) after the end of the first jump
            int a = sparseTable[i][j - 1];
            int b = sparseTable[i + (1 << (j - 1))][j - 1];
            sparseTable[i][j] = (depth[index2node[a]] < depth[index2node[b]] ? a : b);
        }
    }
}

int getRMQ(int l, int r){
    int d = r - l + 1;
    int log = logs[d];

    int a = sparseTable[l][log];
    int b = sparseTable[r - (1 << log) + 1][log];

    return (depth[index2node[a]] < depth[index2node[b]] ? a : b);
}

int getLCA(int u, int v) {
    int l = node2index[u];
    int r = node2index[v];

    if(l > r)   swap(l, r);

    return index2node[getRMQ(l, r)];
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;  cin >> n;

    tree.init(n);

    //The tree is 1-based
    for (int i = 0;i < n - 1;i++) {
        int u, v;   cin >> u >> v;
        tree.addBiEdge(u, v);
    }

    initDFS(n);
    dfs(1);
    buildSPT();

    //LCA Test
//    for(int u = 1;u <= n;u++){
//        cout << u << ": ";
//        for(int v = 1;v <= n;v++){
//            cout << getLCA(u, v) << " ";
//        }
//        cout << endl;
//    }
};
