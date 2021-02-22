//https://www.hackerearth.com/challenges/competitive/may-circuits/algorithm/make-n00b_land-great-again-circuits/description/
/*
 * to solve the D*K problem we will use the root as the common depth to multiply and to solve the values that will increase the answer add minus the distance between every node F[i] and the root to it's children
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
typedef double dd;
#define aint(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<10> MASK;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int mx = 0;

const int MAX = 1e6 + 10;
int n, m, q, X[MAX], F[MAX], D[MAX], in[MAX], out[MAX], t = 1, ans[MAX], c[MAX];
ll BITX[MAX], BITD[MAX], need[MAX], dep[MAX];
vector<vector<int>> tree(MAX), buss(MAX);

void add(int i, ll val, ll bit[]) {
    int x = i;
    while (x <= t + 1) {
        bit[x] += val;
        x |= (x + 1);
    }
}

void updateRange1(int a, int b, ll val, ll bit[]) { // with one element query
    add(a, val, bit);
    add(b + 1, -val, bit);
}

ll get(int i, ll bit[]) {
    ll x = i, sum = 0;
    while (x > 0) {
        sum += bit[x];
        x = (x & (x + 1)) - 1;
    }
    return sum;
}


void dfs(int i, int p) {
    in[i] = t++;
    for (auto v : tree[i]) {
        if (v != p) {
            dep[v] = dep[i] + 1;
            dfs(v, i);
        }
    }
    out[i] = t++;
}

void ParralelBinarySearch(int l, int r, vector<int> &owners) {
    if (owners.empty())return;
    if (l > r)return;
    int mid = (l + r) / 2;


    for (int i = mid; i >= 0; --i) { // add the wanted values from 0 to mid
        if (!c[i]) {
            updateRange1(in[F[i]], out[F[i]], 0ll + X[i] - 1ll * dep[F[i]] * D[i], BITX); // add
            updateRange1(in[F[i]], out[F[i]], D[i], BITD);
            c[i] = 1;
        } else break;
    }
    for (int i = mid + 1; i < q; ++i) { // add the unwanted values from 0 to mid
        if (c[i]) {
            updateRange1(in[F[i]], out[F[i]], 0ll - X[i] + 1ll * dep[F[i]] * D[i], BITX); //substract
            updateRange1(in[F[i]], out[F[i]], -D[i], BITD);
            c[i] = 0;
        } else break;
    }

    vector<int> winners, losers;
    for (int i = 0; i < owners.size(); ++i) {
        ll total = 0;
        for (auto v: buss[owners[i]]) {
            total += get(in[v], BITX);
            total += 1ll * dep[v] * get(in[v], BITD);
        }
        if (total >= need[owners[i]]) {
            ans[owners[i]] = mid + 1;
            winners.push_back(owners[i]);
        } else losers.push_back(owners[i]);
    }

    owners.clear();
    ParralelBinarySearch(mid + 1, r, losers);
    ParralelBinarySearch(l, mid - 1, winners);
}

int main() {
    fast();
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        v--;
        tree[i].push_back(v);
        tree[v].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        v--;
        buss[v].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        cin >> need[i];
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> F[i] >> X[i] >> D[i];
        F[i]--;
    }
    clr(ans, -1);
    dfs(0, -1);
    vector<int> v;
    for (int i = 0; i < m; ++i) {
        v.push_back(i);
    }
    ParralelBinarySearch(0, q - 1, v);

    for (int i = 0; i < m; ++i) {
        if (~ans[i])cout << ans[i] << endl;
        else cout << "rekt" << endl;

    }
}
