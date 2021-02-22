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
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<10> MASK;

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
const int MAX = 2e5 + 9;

int  ans[MAX], sqroot, cnt[MAX];

struct query {//never touched
    int idx, l, r, block_idx;

    query() {};

    query(int l, int r, int idx) {
        this->l = l, this->r = r, this->idx = idx, block_idx = l / sqroot;
    }

    bool operator<(const query &x) const {
        if (x.block_idx == block_idx)return r < x.r;
        return block_idx < x.block_idx;
    }

};
void add(int i, int &result) {
    cnt[i]++;
    if (cnt[i])result++;
}

void remove(int i, int &result) {
    cnt[i]--;
    if (cnt[i])result--;
}
void process(query queries[], int n) { //never touched
    sort(queries , queries  + n);

    int curL = 1, curR = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        while (curL < queries[i].l) remove(curL++, cur);
        while (curL > queries[i].l) add(--curL, cur);
        while (curR < queries[i].r) add(++curR, cur);
        while (curR > queries[i].r) remove(curR--, cur);
        ans[queries[i].idx] = cur;
    }

}
int main() {
    fast();
    int n;
    cin >> n;
    sqroot = sqrt(n);
    query Quries[n];
    for (int i = 0; i < n; ++i) {
        int u,v;
        Quries[i] = query(u, v, i);
    }
    process(Quries, n);

}
