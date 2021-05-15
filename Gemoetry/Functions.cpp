long double dist(ll x, ll y, ll x1, ll y1) {
    return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
}

pair<long double, long double> getPoll(ll x, ll y, ll x1, ll y1, long double d) {
    long double dd = dist(x, y, x1, y1);
    long double t = d / dd;
    return {1.0 * x * (1.0 - t) + t * x1, 1.0 * y * (1.0 - t) + t * y1};
}