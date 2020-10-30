int inTime[N], lowTime[N], dfsTime, inStack[N], compID[N], cmpID;
int n, ne, head[N], nxt[M], to[M], cost[M];
stack<int> stk;
//vector<vector<int>> comps;
vector<pair<int, int>> bridges;

void tarjan(int u, int p){
    inTime[u] = lowTime[u] = ++dfsTime;
    inStack[u] = 1;
    stk.push(u);
    for(int e= head[u],~e,e=nxt[e]){
      int v=to[e];
        if (inTime[v] == 0)
            dfs(v, u, adj);

        if (v == p || inStack[v] == 0){
            if(v != p)
                bridges.push_back({u, e});
            continue;
        }

        lowTime[u] = min(lowTime[u], lowTime[v]);
    }

    if(inTime[u] == lowTime[u]){
        vector<int> component;
        while(true){
            int v = stk.top();
            stk.pop();
            inStack[v] = 0;
            compID[v] = cmpID;
            component.push_back(v);
            if(v == u)  break;
        }
//        comps.push_back(component);
        cmpID++;
    }
}
for (auto p : bridges) {
    int u = p.first;
    int v = to[p.second];
    int c = cost[p.second];
//        cout << compID[u] << " " << compID[v] << " " << c << endl;
    tree.addBiEdge(compID[u], compID[v], c);
//        cout << u + 1 << " " << v + 1 << endl;
}
