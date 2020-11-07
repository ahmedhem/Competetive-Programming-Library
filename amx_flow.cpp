const ll MAX = 305 + 5, INF = INT_MAX;
ll cap[MAX * MAX * 10];
ll find_path(ll start, ll sink,vector<vector<pair<int,int>>>&adj) {
    queue<ll> q;
    ll vis[MAX], path[MAX];
    q.push(start);
    clr(vis, 0);
    vis[start] = 1;
    clr(path, -1);
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        for (int k = 0;k<adj[node].size();k++) {
            int v = adj[node][k].first;
            if (!vis[v] && adj[node][k].second != 0) {
                q.push(v);
                vis[v] = 1;
                if (v == sink)break;

            }
        }
    }
    ll mn_cap = INF, now = sink;
    while (~path[now]) {
        ll prv = path[now];
        mn_cap = min(mn_cap, cap[eToe[prv][now]]);
        now = prv;
    }
    now = sink;
    while (~path[now]) {
        ll prv = path[now];
        cap[eToe[prv][now]] -= mn_cap;
        cap[eToe[now][prv]] += mn_cap;
        now = prv;
    }
    if (mn_cap == INF)return 0;
    else return mn_cap;
}

ll maxflow(ll start, ll sink,vector<vector<pair<int,int>>>&adj) {
    ll ans = 0;
    while (1) {
        ll capacity = find_path(start, sink,adj);
        if (!capacity)break;
        ans += capacity;
    }
    return ans;
}
