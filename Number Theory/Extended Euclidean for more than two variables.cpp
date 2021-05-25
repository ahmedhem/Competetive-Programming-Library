#include <bits/stdc++.h>

using namespace std;
#define sz(x) x.size()
typedef long long ll;

//	O(n * log(m)) Memory & Time; coefficients.size() <= n, coefficients[i] <= m
ll Extended_Euclidean(deque<ll> &coefficients, deque<ll> &variables) {
    int m = sz(coefficients);
    if (!coefficients.back()) {
        int cnt = 0;
        for (int i = 0; i < m; i++)
            if (!coefficients[i]) {
                cnt++;
                variables[i] = 0;
            }
        if (cnt == m - 1) {
            variables[0] = 1;
            return coefficients[0];
        }
        deque<ll> new_coefficients, new_variables;
        for (int i = 0; i < m; i++)
            if (coefficients[i]) {
                new_coefficients.push_back(coefficients[i]);
                new_variables.push_back(variables[i]);
            }
        ll g = Extended_Euclidean(new_coefficients, new_variables);
        for (int i = 0; !new_variables.empty(); i++)
            if (coefficients[i]) {
                variables[i] = new_variables.front();
                new_variables.pop_front();
            }
        return g;
    }
    deque<ll> new_coefficients = coefficients;
    new_coefficients.push_front(new_coefficients.back());
    new_coefficients.pop_back();
    for (int i = 1; i < m; i++)
        new_coefficients[i] %= new_coefficients[0];
    variables.push_front(variables.back());
    variables.pop_back();
    ll g = Extended_Euclidean(new_coefficients, variables);
    for (int i = 1; i < m; i++)
        variables[0] -= coefficients[i - 1] / coefficients.back()
                        * variables[i];
    variables.push_back(variables.front());
    variables.pop_front();
    return g;
}

int main() {
    int n;
    ll d;
    cin >> n >> d;
    deque<ll> c(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    ll g = Extended_Euclidean(c, v);
    if (d % g)
        cout << "impossible";
    else
        for (ll &x:v)cout << x * d / g << ' ';
    return 0;
}
/****************************/
#include "bits/stdc++.h"
// (max number of iterations for gcd is equal to fibo number )
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

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a < 0) {
        ll d = gcd(-a, b, x, y);
        x *= -1;
        return d;
    }
    if (b < 0) {
        ll d = gcd(a, -b, x, y);
        y *= -1;
        return d;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = gcd(b, a % b, y, x);
    y -=  x * (a / b);
    return d;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

/*
 *  we use this fact as the way to get our answer : gcd(a,b,c) = gcd( gcd(a,b), c)
 *  so we split the  problem to small problems and combine them to get our answer
 *  our base case when the current size of the array equal 2
 *  after we calculate the x,y for the equation w * gcd(a,b) + c*z = d we recursevly solve the problem  which consist of all elements except the last element but multiply the answer of this small problem by x
 *  solve(l,r) = x * solve(l,r-1) + z * y
 */
void extendedMultivaraiables(vector<ll> &arr, vector<ll> &prefix, ll l, ll r, vector<ll> &ans, ll c, ll coff) {
    if (r - l + 1 == 2) {
        ll x, y, g;
        find_any_solution(arr[0], arr[1], c, x, y, g);
        x *= coff;
        y *= coff;
        ans[l] = x;
        ans[r] = y;
        return;
    }
    ll x, y, g;
    find_any_solution(prefix[r - 1], arr[r], c, x, y, g);
    x *= coff;
    y *= coff;
    ans[r] = y;
    extendedMultivaraiables(arr, prefix, l, r - 1, ans, prefix[r - 1], x);
}
void solve(){
    ll n, c;
    cin >> n >> c;
    vector<ll> arr;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    /**
     * prefix used to calculate gcd
     * ans used to the answer obviously  :")
     */
    vector<ll> ans(n), prefix(n);
    ll gc = 0;
    for (ll i = 0; i < n; ++i) {
        gc = prefix[i] = __gcd(gc, arr[i]);
    }


    if (c % gc)cout << "Impossible";
    else {
        /** divide by gcd to simplify the code **/
        for (ll i = 0; i < n; ++i) {
            arr[i] /= gc;
        }
        c /= gc;

        extendedMultivaraiables(arr, prefix, 0, n - 1, ans, c, 1);

        for (auto i : ans)
            cout << i << " ";
    }
}
int main() {
    fast();
//    freopen("in.txt","r",stdin);
    solve();
}

