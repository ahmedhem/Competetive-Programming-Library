/***********************tarjan for Directed graph*********************/
const int MAX = 1e5 + 5;
map<string, int> freq;
int cnt = 0, DL[MAX], DH[MAX], vis[MAX];
vvi adj(MAX);
stack<int> s;
int inS[MAX];
vvi comps;
int c = 0, maxi = 0;

void tarjan(int node) {
    DL[node] = DH[node] = cnt++;
    s.push(node);
    inS[node] = 1;
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); ++i) {
        int v = adj[node][i];
        if (!vis[v]) {
            tarjan(v);
DL[node] = min(DL[node], DL[v]);
        } else if (inS[v])DL[node] = min(DL[node], DH[v]);
    }
    if (DL[node] == DH[node]) {
        int x = -1;
        c++;
        comps.push_back(vector<int>());
        while (x != node) {
            x = s.top(), s.pop(), inS[x] = 0;
            comps.back().push_back(x);
        }
        maxi = max(maxi, (int) comps.back().size());
    }
}
/***********************tarjan for unDirected graph*********************/
const int MAX = 1e5 + 5;
int cnt = 0, DL[MAX], DH[MAX], vis[MAX], inS[MAX],par[MAX],ch=0;
vvi adj(MAX), comps;
stack<int> s;
ll mod = 1e9 + 7;
set<int>st ;
vi ans;

void tarjan(int node) {
    DL[node] = DH[node] = cnt++;
    s.push(node);
    inS[node] = 1;
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); ++i) {
        int v = adj[node][i];
        if (!vis[v]) {
            if(par[node]==-1)ch++;
            par[v]=node;
            tarjan(v);
            DL[node] = min(DL[node], DL[v]);
            if(DH[node] == DL[node] && node != par[node])
        bridges.push_back({par[node], node});

            if(DL[v]>=DH[node]&&par[node]!=-   1)st.insert(node);//AP
        } else if (v != par[node])DL[node] = min(DL[node], DH[v]);
    }

}
