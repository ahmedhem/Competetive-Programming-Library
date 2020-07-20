
vector<vector<int>> adj(MAX, vector<int>(MAX, 1e8));
int OO = 1e9;

void floyd() {
    for (int i1 = 1; i1 <= n; ++i1) {
        adj[i1][i1] = 0;
    }

    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (adj[j][i] > adj[j][k] + adj[k][i]) {
                    adj[j][i] = adj[j][k] + adj[k][i];
                }
            }
    }
}
/****maxMini*******/

void floyd() {
    for (int i1 = 1; i1 <= n; ++i1) {
        adj[i1][i1] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                adj[j][i] = max(adj[j][i], min(adj[j][k], adj[k][i]));
            }
        }
    }
}
/****miniMAX*******/

void floyd() {
    for (int i1 = 1; i1 <= n; ++i1) {
        adj[i1][i1] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                adj[j][i] = min(adj[j][i], max(adj[j][k], adj[k][i]));
            }
        }
    }
}
