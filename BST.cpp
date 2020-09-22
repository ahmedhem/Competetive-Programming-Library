#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<13> MASK;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> vvi;

//set iterator can be increamnted and decreamnted
void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

struct BST {
    BST *left;
    BST *right;
    BST *parent;

    int val;

    BST(int n, BST *p) {
        left = 0;
        right = 0;
        parent = p;
        val = n;
    }

    BST *insert(BST *cur, BST *p, int n) {
        if (cur == 0) {
            cur = new BST(n, p);
            return cur;
        }
        if (n > cur->val) cur->right = insert(cur->right, cur, n);
        else {
            cur->left = insert(cur->left, cur, n);
        }
        return cur;
    }

    BST *mnBranch(BST *cur) {
        BST *node = cur;
        while (node && node->left != 0)node = node->left;
        return node;
    }

    BST *checkIfLeft(BST *b) {
        BST *node = b;
        while (node->parent != 0 && node->parent->left != node) {
            node = node->parent;
        }
        if (node->parent != 0 && node->parent->left != node)return node->parent;
        return 0;
    }

    BST *succesor(BST *cur) { //smallest key >cur->val
        if (cur->right == 0) {
            if (checkIfLeft(cur) == 0)return cur;
            else return checkIfLeft(cur);
        };
        return mnBranch(cur->right);
    }

    BST *traverse(BST *cur) {
        if (cur == 0)return cur;
        cur->left = traverse(cur->left);
        cout << cur->val << " ";

        cur->right = traverse(cur->right);

        return cur;
    }

    BST *dlt(BST *node, int n) {
        if (node == 0)return node;
        if (n > node->val)node->right = dlt(node->right, n);
        else if (n < node->val)node->left = dlt(node->left, n);
        else {
            if (node->left == 0) {
                BST *tmp = node->right;
                if (node->parent == 0) {
                    if (node->right->right == 0) {
                        node->val = node->right->val;
                        node->right = dlt(node->right, node->right->val);
                    } else {
                        BST *replace = mnBranch(node->right->right);
                        node->val = replace->val;
                        node->right = dlt(node->right, replace->val);
                    }
                } else {
                    free(node);
                    return tmp;
                }
            } else if (node->right == 0) {
                BST *tmp = node->left;
                if (node->parent == 0) {
                    if (node->left->right == 0) {
                        node->val = node->left->val;
                        node->left = dlt(node->left, node->left->val);
                    } else {
                        BST *replace = mnBranch(node->left->right);
                        node->val = replace->val;
                        node->left = dlt(node->left, replace->val);
                    }
                } else {
                    free(node);
                    return tmp;
                }
            } else {
                BST *replace = mnBranch(node->right);
                node->val = replace->val;
                node->right = dlt(node->right, replace->val);
            }
        }
        return node;
    }
};

int main() {
    BST *b = new BST(10, 0);
    b->insert(b, 0, 11);
    b->traverse(b);
    b->dlt(b, 10);
    b->traverse(b);


    return 0;
}
