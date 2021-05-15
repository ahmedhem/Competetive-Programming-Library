
const int MAX = 100000 + 10;
ll seg[4 * MAX], lazy[4 * MAX];

void add(int p, int l, int r) {
    seg[p] += lazy[p] * (r - l + 1);
    if (l != r) {
        lazy[p * 2] += lazy[p];
        lazy[p * 2 + 1] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int x, int y, int val) {
    add(p, l, r);
    if (l >= x && r <= y) {
        seg[p] += (ll) val * (r - l + 1); //notice that we add the whole sum to the segment not only the val
        if (l != r) {
            lazy[p * 2] += val;
            lazy[p * 2 + 1] += val;
        }
        return;
    }
    if (l > y || r < x)return;
    int mid = (l + r) / 2;
    update(p * 2, l, mid, x, y, val);
    update(p * 2 + 1, mid + 1, r, x, y, val);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

ll get(int p, int l, int r, int x) {
    add(p, l, r);
    if (l == r)return seg[p];
    int mid = (l + r) / 2;
    if (x > mid)return get(p * 2 + 1, mid + 1, r, x);
    else return get(p * 2, l, mid, x);
}

ll get(int p, int l, int r, int x, int y) {
    add(p, l, r);
    if (l >= x && r <= y)return seg[p];
    if (l > y || r < x)return 0;
    int mid = (l + r) / 2;
    return get(p * 2, l, mid, x, y) + get(p * 2 + 1, mid + 1, r, x, y);
}

int main() {
    fast();
    int n, q;
    cin >> n >> q;

    while (q--) {
        int p;
        cin >> p;
        if (p == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 0, n - 1, l, r - 1, v);
        } else {
            int x;
            cin >> x;
            cout << get(1, 0, n - 1, x, x) << endl;
        }
    }
}
