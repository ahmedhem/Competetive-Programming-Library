//
// Created by FAhma on 7/20/2020.
//
int vis[101] = {0};
vector<vector<edg>>adj;
struct edg {
    int w, to;

    bool operator<(const edg &e) const {
        return e.w < w;
    }
};

int prim() {
    priority_queue<edg> pq;
    pq.push({0, 1});
    int total = 0;

    while (!pq.empty()) {
        int node = pq.top().to;
        int w = pq.top().w;
        pq.pop();
        if (vis[node])continue;
        vis[node] = 1;
        total += w;
        if (node != 1)edges.push_back({w, node});
        for (int i = 0; i < adj[node].size(); ++i) {
            edg v = adj[node][i];
            if (!vis[v.to]) {
                pq.push(v);
            }
        }
    }
    if (edges.size() != n - 1)return -1;
    return total;
}
