#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5, MOD = 1e9 + 7, sigma = 255;

int term[MAXN], len[MAXN], to[(int)1e6/255][sigma], link[MAXN], sz = 1, q;
vector<vector<int>> pat(MAXN);

void add_str(string s, int id) {
    int cur = 0;
    for (auto c: s) {
        if (!to[cur][c - 0]) {
            to[cur][c - 0] = sz++;

            len[to[cur][c - 0]] = len[cur] + 1;
        }
        cur = to[cur][c - 0];
    }
    pat[cur].push_back(id);
    term[cur] = cur;
}
void push_links() {
    int que[sz];
    int st = 0, fi = 1;
    que[0] = 0;
    while (st < fi) {
        int V = que[st++];
        int U = link[V];
        if (!term[V]) term[V] = term[U];
        for (int c = 0; c < sigma; c++)
            if (to[V][c]) {
                link[to[V][c]] = V ? to[U][c] : 0;
                pat[to[V][c]].insert(pat[to[V][c]].end(), pat[link[to[V][c]]].begin(), pat[link[to[V][c]]].end());
                que[fi++] = to[V][c];
            } else {
                to[V][c] = to[U][c];
                pat[to[V][c]].insert(pat[to[V][c]].end(), pat[to[U][c]].begin(), pat[to[U][c]].end());
            }
    }
}

