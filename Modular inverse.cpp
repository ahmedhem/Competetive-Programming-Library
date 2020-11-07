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
