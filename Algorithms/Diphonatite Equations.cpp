// gcd(a,b) = gcd(|a|,b) = gcd(a,|b|) = gcd(|a|,|b|);


/*for a diophantite equation ax +by=c
 * if(c not divislbe by gcd(a,b) then there is no answer
 * if a = b = 0 then there is infinite solutions and it's called degenerate case
 * if we need minimum a+b :
    * If a<b, we need to select smallest possible value of k.
    * If a>b, we need to select the largest possible value of k.
    * If a=b, all solution will have the same sum x+y.
*/

/*congurance
 *file:///C:/Users/Ahmed%20Magdy/Downloads/11_Number_Theory_Diophantine_equation_and_Congruence.pdf
 */

/*
 * to find more than one solution add x to  k * b / g and y to y * a/g
 */

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

/** iterative ***/
int gcditerative(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int gcd(int a, int b, int &x, int &y) {
    if (a < 0) {
        int d = gcd(-a, b, x, y);
        x *= -1;
        return d;
    }
    if (b < 0) {
        int d = gcd(a, -b, x, y);
        y *= -1;
        return d;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


/* diophantite equation ax+by = c  */
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
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

int main(){
    fast();

}
/*************************/
// solve ax = b mod(n)
// we can solve modular inverse using this code
// 4^-1 mod(x) is means what number multplied by 4 equal to 1 mod x or in another word 4 = 1 (mod(x));
int findxCongurance(int a,int b,int n){
    vector<int>solu;
    int x,y;
    int g = gcd(a,n,x,y);
    if(b%g)return 0;
    x = x * (b/g);
    x = (x+n)%n;
    for (int i = 0; i < g; ++i) {
        solu.push_back((x+(n/g)*i)%n);
    }
    sort(all(solu));
}