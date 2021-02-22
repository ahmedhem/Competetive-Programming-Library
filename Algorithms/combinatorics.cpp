#include <bits/stdc++.h>

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
const int MAX=1e3;
ll nck[MAX][MAX], modInv[MAX];

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int mod = 1e9 + 7;

ll modularInverse(ll a, ll m) {
    return binpow(a, m - 2, m);
}


void NcK(ll n, ll k) {
    for (ll i = 0; i <= n; ++i) {
        nck[i][0] = 1;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= k; ++j) {
            nck[i][j] = ((i % mod * nck[i - 1][j - 1] % mod) * modInv[j]) % mod;
        }
    }
}

void generateModInverse(int n) {
    for (int i = 1; i <= n; ++i) {
        modInv[i] = modularInverse(i, mod);
    }
}

ll NpK(ll n, ll k) {
    ll npk[n + 1][k + 1];
    for (ll i = 0; i <= n; ++i) {
        npk[i][0] = 1;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= k; ++j) {
            npk[i][j] = (i * npk[i - 1][j - 1]);
        }
    }
    return npk[n][k];
}

map<int, int> m;

void getPrimeFactors(ll n) {
    ll cnt = 0;
    for (ll i = 2; i <= sqrt(n); ++i) {
        while (n % i == 0)n /= i, m[i]++;
    }
    if (n > 1)m[n]++;
}

int main(){
fast();
}