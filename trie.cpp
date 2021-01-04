#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct vertex
{
    int next[26];
    bool leaf = 0;
    vertex()
    {
        fill(begin(next), end(next), -1);
    }
};
vector<vertex> trie(1);

void insert(string &s)
{
    int n = s.size(), cur = 0;
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (trie[cur].next[c] == -1)
        {
            int to = trie.size();
            trie[cur].next[c] = to;
            trie.emplace_back();
        }
        cur = trie[cur].next[c];
    }
    trie[cur].leaf = true;
}
bool find(string &s)
{
    int n = s.size(), cur = 0;
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (trie[cur].next [c]== -1)
            return false;

        cur = trie[cur].next[c];
    }
    return trie[cur].leaf;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        insert(s);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        cout << find(s) << endl;
    }
}
/***************another implementaion *********/
const int MAXN = 1e5, MOD = 1e9 + 7, sigma = 255;

int  to[(int)1e6/255][sigma],term[MAX],sz = 1, q;
vector<vector<int>> pat(MAXN);

void add_str(string s, int id) {
    int cur = 0;
    for (auto c: s) {
        if (!to[cur][c - 0]) {
            to[cur][c - 0] = sz++;
        }
        cur = to[cur][c - 0];
    }
    pat[cur].push_back(id);
    term[cur] = cur;
}
