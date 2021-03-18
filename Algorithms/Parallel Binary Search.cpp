
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


const int MAX = 1e5 + 10;
int n, q, num[MAX], u[MAX], v[MAX], ans[MAX],idxNow;
struct state{
    int idx, u ,p, gs;
};
stack<state>s;
struct DSU {
    vector<int> parent;
    vector<int> groupSize;

    DSU(int n) {
        parent.resize(n + 5);
        groupSize.resize(n + 5);
        for (int i = 0; i < n + 5; ++i) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    int findLeader(int node) {
        s.push({idxNow,node,parent[node],groupSize[node]});
        if (parent[node] == node)return node;
        return parent[node] = findLeader(parent[node]);
    }

    int sameGroup(int i, int j) {
        return findLeader(i) == findLeader(j);
    }

    int mergeGroup(int i, int j) {
        int leader1 = findLeader(i);
        int leader2 = findLeader(j);
        if (leader1 == leader2)return 0;
        if (groupSize[leader1] > groupSize[leader2]) {
            parent[leader2] = leader1;
            groupSize[leader1] += groupSize[leader2];
        } else {
            parent[leader1] = leader2;
            groupSize[leader2] += groupSize[leader1];

        }
        return 1;
    }

};


void ParralelBinarySearch(int l, int r, vector<int> &owners, DSU &d, int last) {
    if (owners.empty())return;
    if (l > r)return;
    int mid = (l + r) / 2;
    while (!s.empty()&&s.top().idx>mid){
        int node=s.top().u;
        int p=s.top().p;
        int gs=s.top().gs;
        d.parent[node]=p;
        d.groupSize[node]=gs;
        s.pop();
    }
    for (int i = last + 1 ; i  <=mid ; ++i) {
        if(num[i]==2)continue;
        idxNow=i;
        d.mergeGroup(u[i],v[i]);
    }

    vector<int> winners, losers;
    for (int i = 0; i < owners.size(); ++i) {
        int idx = owners[i];
        if (idx < mid)winners.push_back(idx);
        else {
            if (d.sameGroup(u[idx], v[idx])) {
                ans[idx] = mid + 1;
                winners.push_back(idx);
            } else losers.push_back(idx);
        }
    }
    owners.clear();
    ParralelBinarySearch(mid + 1, r, losers, d, mid);
    ParralelBinarySearch(l, mid - 1, winners, d, mid);
}

void solve() {
    while (!s.empty())s.pop();
    cin >> n >> q;
    for (int i = 0; i < q + 5; i++) {
        ans[i] = -1;
    }
    DSU d(n);
    vector<int> owners;
    for (int i = 0; i < q; ++i) {
        cin >> num[i] >> u[i] >> v[i];
        if (num[i] == 1) {
            idxNow=i;
            d.mergeGroup(u[i], v[i]);
        } else if (d.sameGroup(u[i], v[i])) owners.push_back(i);
    }

    ParralelBinarySearch(0, q - 1, owners, d, q - 1);
    for (int i = 0; i < q; ++i) {
        if (num[i] == 2)cout << ans[i] << endl;
    }
}

int main() {
    fast();
    //  freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
