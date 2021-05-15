/*
 *  least segnificant bit (lsb)is the last bit from zero ex/ 101(1)00 , 1011110100(1)
 *  2's complement  of a number is equal to the negative of that number . you get it by flipping the bits after the (lsb) 101100->010100
 * to get the lsb just & the number with it's negative number x&(-x) = last bit
 * to remove the last bit x - (x&(-x))
 * let lsp= c , and the number after remove lsp is x then every node number store the summetion of c number after x for , example / 6 = 0110 store the summetion of the next two numbers after index 4 in the array
 * to build the tree , iterate over all indices and add it's value to the every node which affects to , every node it's affect to is next node in binary representaion o(nlog(n))
 * ot get value of node x which means from 0 to x , add to the sum from node x to it's parent untill root o(log(n)
 * https://cs.stackexchange.com/questions/33014/range-update-range-query-with-binary-indexed-trees
 *
 *
 *
 */


const int MAX = 3e5;
int BIT[MAX], BIT1[MAX], BIT2[MAX], arr[MAX], n;


void add(int i, int val, int bit[]) {
    int x = i;
    while (x <= n) {
        bit[x] += val;
        x += (x & (-x)); // move to the next node
    }
}

void updateRange1(int a, int b, int val) { // with one element query
    add(a, val, BIT);
    add(b + 1, -val, BIT);
}

void updateRange2(int a, int b, int val) { // with range query
    add(a, val, BIT1);
    add(b + 1, -val, BIT1);
    add(a, (a - 1) * val, BIT2);
    add(b + 1, -val * b, BIT2);
}

int get(int i, int bit[]) {
    int x = i, sum = 0;
    while (x > 0) {
        sum += bit[x];
        x -= (x & (-x)); // move to the parent
    }
    return sum;
}
int getRange2(int a,int b){
    return get(b,BIT)-get(a-1,BIT);
}
int getRange1(int a, int b) {
    a--;
    int l = get(a, BIT1) * a - get(a, BIT2);
    int r = get(b, BIT1) * b - get(b, BIT2);
    return r - l;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        updateRange2(i + 1, i + 1, arr[i]);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << getRange(a, b) << endl;
    }
}

int main() {
    fast();
    int t = 1;
    while (t--) {
        solve();
    }
}