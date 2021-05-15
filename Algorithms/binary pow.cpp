long long binpow(long long a, long long b, long long m) {
    long long ret = 1;
    while (b) {
        if (b & 1)ret = (ret * a) % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}
