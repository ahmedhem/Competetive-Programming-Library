
const int MAX = 2e5 + 9;

int  ans[MAX], sqroot, cnt[MAX];

struct query {//never touched
    int idx, l, r, block_idx;

    query() {};

    query(int l, int r, int idx) {
        this->l = l, this->r = r, this->idx = idx, block_idx = l / sqroot;
    }

    bool operator<(const query &x) const {
        if (x.block_idx == block_idx)return r < x.r;
        return block_idx < x.block_idx;
    }

};
void add(int i, int &result) {
    cnt[i]++;
    if (cnt[i])result++;
}

void remove(int i, int &result) {
    cnt[i]--;
    if (cnt[i])result--;
}
void process(query queries[], int n) { //never touched
    sort(queries , queries  + n);

    int curL = 1, curR = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        while (curL < queries[i].l) remove(curL++, cur);
        while (curL > queries[i].l) add(--curL, cur);
        while (curR < queries[i].r) add(++curR, cur);
        while (curR > queries[i].r) remove(curR--, cur);
        ans[queries[i].idx] = cur;
    }

}
int main() {
    fast();
    int n;
    cin >> n;
    sqroot = sqrt(n);
    query Quries[n];
    for (int i = 0; i < n; ++i) {
        int u,v;
        Quries[i] = query(u, v, i);
    }
    process(Quries, n);

}
