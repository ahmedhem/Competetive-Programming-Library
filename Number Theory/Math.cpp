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
int nth_gemotric_progression(int a,int r,int n ){
    return a * pow(r,n-1);
}
int sum_gemotric_progression(int a,int r,int n ){
    return (a * pow(r,n) - 1) / (r-1);
}
int main(){
    fast();

}
