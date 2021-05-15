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

const int MAX=1e5;
ll weight[MAX],head[MAX],to[MAX],nxt[MAX],e=0;

void add_edge(ll i, ll j, ll cost) {
    weight[e] = cost;
    to[e] = j;
    nxt[e] = head[i];
    head[i] = e++;
}
void traverse_over_children(int node){

for(int e=head[node];~e;e=nxt[e]){

}

}
