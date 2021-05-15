//modular inverse using extended euclidean
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

int findModularinverseusingconguernce(int a,int b,int n){
    int x,y;
    int g = gcd(a,n,x,y);
    if(b%g)return 0;
    x = x * (b/g);
    x = (x+n)%n;
    return x;
}

/***another approach using binary power when m is prime****/
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

int modularInverse(int a,int m){
    return binpow(a,m-2,m);
}
int main()
{
    int n = 10, prime = 17;
    printModIverses(n, prime);
    return 0;
}
