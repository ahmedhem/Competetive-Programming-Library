
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl "\n"
 
void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
 
void computeLog(int n, vector<int> &log) {
    log[1]=0;
    for (int i = 2; i <= n; ++i) {
        log[i] = log[i / 2] + 1; //rounded down
    }
}
 
void sparseTable(int n, vector<int> &log, vector<vector<int>> &ST) {
    for (int i = 1; i <= log[n]; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
        }
    }
}
 
int min_range(int l, int r, vector<int> &log, vector<vector<int>> &ST) {
    int len = r - l + 1;
    int loge = log[len];
    int sum=min(ST[loge][l], ST[loge][r - (1 << loge) + 1]);
    return sum;
}
 