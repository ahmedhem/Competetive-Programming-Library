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
