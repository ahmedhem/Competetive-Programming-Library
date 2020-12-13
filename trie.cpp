
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
    trie t;
    t.insert("abcd");
    cout<<t.isExists("abcde");
}
