ll *arr;

struct seg_tree {
    // size of seg tree doesn't exceed 4*n
    ll *seg;
    ll *segcnt;

    seg_tree(int n) {
        seg = new ll[n];
        segcnt = new ll[n];
        fill(seg, seg + n, 1e9 + 1);
        fill(segcnt, segcnt + n, 0);

    }    void check(int p, int l, int r) {
        if (!lazy[p])return;
        seg[p] += lazy[p];
        if (l != 1) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p]=0;
    }

    void build(int num, int l, int r) { //nlogn where log n is the height of the tree
        if (l == r) {
            seg[num] = arr[l];
            segcnt[num] = 1;
            return;
        }
        build(2 * num, l, (l + r) / 2);
        build(2 * num + 1, (l + r) / 2 + 1, r);
        ll mn = min(seg[2 * num], seg[2 * num + 1]);
        seg[num] = mn;
        if (mn == seg[num * 2]&&mn == seg[num * 2+1])segcnt[num] = segcnt[num * 2]+segcnt[num*2+1];
        else if (mn == seg[num * 2 + 1])segcnt[num] = segcnt[num * 2 + 1];
        else segcnt[num] = segcnt[num * 2];

    }

    void update(int num, int l, int r, int i, ll v) { // logn
        if (l == r) {
            seg[num] = v;
            segcnt[num] = 1;
            return;
        }
        if (i <= (l + r) / 2)update(num * 2, l, (l + r) / 2, i, v);
        else update(num * 2 + 1, (l + r) / 2 + 1, r, i, v);
        ll mn = min(seg[2 * num], seg[2 * num + 1]);
        seg[num] = mn;
        if (mn == seg[num * 2]&&mn == seg[num * 2+1])segcnt[num] = segcnt[num * 2]+segcnt[num*2+1];
        else if (mn == seg[num * 2 + 1])segcnt[num] = segcnt[num * 2 + 1];
        else segcnt[num] = segcnt[num * 2];
    }
    pair<int,int> check(pair<int,int> a,pair<int,int> b){
        int mn=min(a.first,b.first),le=a.first,re=b.first;
        if(mn==le&&mn==re)return {mn,a.second+b.second};
        else if(mn==le)return {mn,a.second};
        else return {mn,b.second};

    }
    pair<int,int> get(int p, int l, int r, int x, int y) {
        if (l >= x && r <= y)return {seg[p],segcnt[p]};// |x   |l     r|    y|
        if (l > y || r < x)return {1e9 + 1,0};//|x    y| |l    r|  or |l   r|  |x   y|
        return check(get(2 * p, l, (l + r) / 2, x, y),get(2 * p + 1, (l + r) / 2 + 1, r, x, y));


    }
};
