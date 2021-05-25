#include "bits/stdc++.h"

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

int mobius(int n) {
    int ans = 1;
    for (int i = 2; i * i << n; ++i) {
        if (n % i == 0) {
            if (n % (i * i) == 0)return 0;
            n /= i;
            ans *= -1;
        }
    }
    if(n>1)ans *=-1;
    return ans;
}
int mobius_range(int n,vector<int>&mobius){
    int prime[n+1];
    mobius.resize(n+1);
    clr(prime,0);
    for (int i = 1; i <=n ; ++i) {
        mobius[i]=1;
    }

    for (int i = 2; i <=n ; ++i) {
        if(!prime[i]){
            for (int j = i; j <=n ; j+=i) {
                prime[j]=1;
                if(j%(i*i)==0)mobius[j]=0;
                mobius[j] *=-1;
            }
        }
        cout<<mobius[i]<<" ";
    }

}
int main() {
    fast();

}

