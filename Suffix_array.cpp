#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl "\n"
 
void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
void countSort(vector<int> &p, vector<int> &c) {
    int n = c.size();
    vector<int> cnt(n), pos(n), new_p(n);
    for (int i = 0; i < c.size(); ++i) {
        cnt[c[i]]++;
    }
    pos[0] = 0;
    for (int i = 1; i < n; ++i) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        new_p[pos[c[p[i]]]] = p[i];
        pos[c[p[i]]]++;
    }
    p = new_p;
 
}
 
void SuffixArray(vector<int> &p, vector<int> &c, string &s) {
    int n = s.size();
    vector<pair<char, int>> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) p[i] = a[i].second;
    c[a[0].second] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i - 1].first)c[p[i]] = c[p[i - 1]]; else c[p[i]] = c[p[i - 1]] + 1;
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0; i < n; ++i) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        countSort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            pair<int, int> right = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> left = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            c_new[p[i]] = c_new[p[i - 1]] + (left != right);
        }
        c = c_new;
        k++;
    }
 
}
 
void LCP(vector<int> &p, vector<int> &c, string &s, vector<int> &lcp) {
    int n = p.size(), k = 0;
    for (int i = 0; i < n - 1; ++i) {
        int pos = c[i];
        int j = p[pos - 1];
        while (s[i + k] == s[j + k])k++;
        lcp[pos] = k;
        k = max(k - 1, 0);
    }
}