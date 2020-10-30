onst ll MAX = 305 + 5, INF = INT_MAX;
ll cap[MAX * MAX * 10];
int eToe[MAX][MAX];
ll weight[MAX], maxLift[MAX], ans[MAX * MAX * 10], head[MAX * MAX * 10], to[MAX * MAX * 10], nxt[MAX * MAX * 10], e = 0;

  void add_edge(ll i, ll j, ll cape) {
      cap[e] = cape;
      to[e] = j;
      nxt[e] = head[i];
      eToe[i][j] = e;
      head[i] = e++;
      cap[e] = 0;
      to[e] = i;
      nxt[e] = head[j];
      eToe[j][i] = e;
      head[j] = e++;
  }

ll find_path(ll start, ll sink) {
    queue<ll> q;
    ll vis[MAX], path[MAX];
    q.push(start);
    clr(vis, 0);
    vis[start] = 1;
    clr(path, -1);
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
          for (int k = head[node]; ~k; k = nxt[k]) {
            int v = to[k];
            if (!vis[v] && cap[k] != 0) {
                q.push(v);
                vis[v] = 1;
                path[v] = node;
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
    if (path[now] == -1) {
        now = sink;
        while (~path[now]) {
            ll prv = path[now];
            ans[now] = prv;
            now = prv;
        }
    }
    if (mn_cap == INF)return 0;
    else return mn_cap;
}

ll maxflow(ll start, ll sink) {
    ll ans = 0;
    while (1) {
        ll capacity = find_path(start, sink);
        if (!capacity)break;
        ans += capacity;
    }
    return ans;
}
