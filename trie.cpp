#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> trie;
vector<bool> e; // to check for that is the end of a given word;
void insert(string &s)
{
    int n = s.size(), cur = 0;
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (trie[cur][c] == -1)
        {
            int to = trie.size();
            trie.push_back(vector<int>(26, -1));
            trie[cur][c] = to;
            e.push_back(false);
        }
        cur = trie[cur][c];
    }
    e[cur] = true;
}
bool find(string &s)
{
    int n = s.size(), cur = 0;
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        if (trie[cur][c] == -1)return false;
        
        cur = trie[cur][c];
    }
    return e[cur];
}
int main()
{
    e.push_back(false);
    trie.push_back(vector<int>(26,-1));
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        insert(s);
    }
    int q;cin>>q;
    while(q--){
        string s;cin>>s;
        cout<<find(s)<<endl;
    }
}