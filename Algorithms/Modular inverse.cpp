int extended_euclidean(int a, int b, int& x, int& y) {
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
int modularInverse(int a,int m){
int x, y,a,b;
int g = extended_euclidean(a, m, x, y);
    x = (x % m + m) % m;
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
