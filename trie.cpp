#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n))
typedef bitset<10> MASK;
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
const int MAX=26;
struct trie{
    trie* childs[MAX];
    trie(){
        memset(childs,0,sizeof(childs));
    }
    void insert(char* str){
        if(*str==0)return;
        if(childs[*str-'0']==0)childs[*str-'0']=new trie();
         childs[*str-'0']->insert(str+1);
    }
    bool isExists(char* str){
//        cout<<*str<<" ";
        if(*str==0)return true;
        if(childs[*str-'0']==0)return false;
         childs[*str-'0']->isExists(str+1);
    }
};

int main() {
    fast();
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    trie t;
    t.insert("abcd");
    cout<<t.isExists("abcde");
}
