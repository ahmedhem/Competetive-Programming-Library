
/*         ****************Centroid Decompestion ***************************
 * Very imnportant link https://www.quora.com/q/threadsiiithyderabad/Centroid-Decomposition-of-a-Tree
 *  the the main idea of the DS is to convert the given tree into a tree with max height equal to log(N) and to make the size of each subtree not exceeded n/2.
 *   it constructed in  NlogN why ? because first you get the centroid of the tree which gives you that every children of it has max n/2 nodes, then you get the centroid of each subtree of those children
 * which every grand children has max n/2/2 nodes and so on, so the total traversing is equal to n+n/2+n/4+n/6..... Harmonic Series.
 *  Given a tree  calcluate the number of paths equal to k
 *  solution  : first you get the centroid tree then traverse from each centroid into his decendants  and calcluate the number of paths which this centroid is the lca of the path
 *  to do that and to avoid the overlapping problem just calculate every subtree of the centroid first then add it's values to the counter  so that every nodes calcluated once and added once
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long int ll;


const int N = int(2e5);
vector<vector<int>> g(N), c(N); // main tree and decompo tree
int sub[N]; // subtree size
int blocked[N], k, cRoot, cnt[N]; // blocked is use for not going up ,cnt is for counting  number of nodes in each depth
ll ans;
int nn; // to get the size of eadh subtree

void subTreeSize(int u, int p) {
    sub[u] = 1;
    nn++;
    for (auto it  : g[u])
        if (it != p && !blocked[it])
            subTreeSize(it, u), sub[u] += sub[it];
}

int getCentroid(int u, int p) {
    for (auto it  : g[u])
        if (it != p && sub[it] > nn / 2 && !blocked[it])
            return getCentroid(it, u);
    return u;
}

void decompose(int root, int depth, int p) {
    nn = 0;
    subTreeSize(root, root);
    int centroid = getCentroid(root, root);
    int u = centroid;
    /* construct the tree */
    if (p == -1)cRoot = centroid;
    else {
        c[centroid].push_back(p);
        c[p].push_back(centroid);
    }
    blocked[u] = 1;
    for (auto it  : g[u]) {
        if (!blocked[it])
            decompose(it, depth + 1, centroid); // go depth
    }
}

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

int calulate(int u, int p, int depth) {
    if (depth > k)return 0;
    int ans = cnt[k - depth];
    for (auto i : g[u]) {
        if (p != i && !blocked[i]) {
            ans += calulate(i, u, depth + 1);
        }
    }
    return ans;
}

void add(int u, int p, int depth) {
    if (depth > k)return;
    cnt[depth]++;

    for (auto i : g[u]) {
        if (p != i && !blocked[i]) {
            add(i, u, depth + 1);
        }
    }
}

void findAns(int root) {
    blocked[root] = 1;
    cnt[0]++;
    for (auto i : g[root]) {
        if (!blocked[i]) {
            ans += calulate(i, root, 1); //calcluate the paths from eacdh node in the sub tree to the centroid
            add(i, root, 1); // add the values of the sub tree
        }
    }
    for (int i = 0; i < N && cnt[i]; ++i) {
        cnt[i] = 0; // clear the depth and go down
    }
    for (auto i : c[root])if (!blocked[i])findAns(i);
}

int main() {
    fast();
    int n;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    decompose(0, 0, -1);
    memset(blocked, 0, sizeof(blocked));
    findAns(cRoot);
    cout << ans;
}
