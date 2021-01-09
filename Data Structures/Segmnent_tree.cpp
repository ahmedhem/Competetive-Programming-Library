ll *arr;

struct seg_tree {
    // size of seg tree doesn't exceed 4*n
    ll *seg;
    ll *lazy;
    seg_tree(int n) {
        seg = new ll[n];
        segcnt = new ll[n];
        fill(seg, seg + n, 1e9 + 1);
        fill(lazy, lazy  + n, 0);
    }
    void  check(int p, int l, int r) {
        if (!lazy[p])return;
        seg[p] += lazy[p];
        if (l != 1) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p]=0;
    }

    void build(int num, int l, int r) { //nlogn where log n is the height of the tree
        check(num,l,r);
        if (l == r) {
            seg[num] = arr[l];
            return;
        }
        build(2 * num, l, (l + r) / 2);
        build(2 * num + 1, (l + r) / 2 + 1, r);
        ll mn = min(seg[2 * num], seg[2 * num + 1]);
        seg[num] = mn;
        return seg;

    }

    void update(int num, int l, int r, int i, ll v) { // logn
        check(num,l,r);

        if (l == r) {
            seg[num] = v;
            return;
        }
        if (i <= (l + r) / 2)update(num * 2, l, (l + r) / 2, i, v);
        else update(num * 2 + 1, (l + r) / 2 + 1, r, i, v);
        ll mn = min(seg[2 * num], seg[2 * num + 1]);
        seg[num] = mn;
        return seg;
    }

    int get(int p, int l, int r, int x, int y) {
        check(num,l,r);
        if (l >= x && r <= y)return seg[p];// |x   |l     r|    y|
        if (l > y || r < x)return 1e9 + 1;//|x    y| |l    r|  or |l   r|  |x   y|
        return min(get(2 * p, l, (l + r) / 2, x, y),get(2 * p + 1, (l + r) / 2 + 1, r, x, y));


    }
};
/***************iterative**********/
void update(int u, int x){
	while(u < NN){
		B[u] += x;
  		u += u & (-u);
	}
}

int calc(int u){
	int ss = 0 ;
	while(u > 0){
		ss += B[u];
		u -= u & (-u);
	}
	return ss;
}
/********************/

