int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s,t,pat;
    int n=s.size(),m=pat.size();
    int lps[n]={0};
    int i=1,j=0;
    while(i<m){
        if(pat[i]==pat[j]){
            lps[i]=++j;
            i++;
        }else {
            if(!j)lps[i]=0,i++;
            else j=lps[j-1];
        }
    }
    i=0,j=0;
    while(i<n){
        if(pat[j]==s[i]){
            ++j;
            i++;
        }
        if(j==m)cout<<i-(j-1)-1<<" ",j=lps[j-1];
        else if(i<n&&pat[j]!=s[i]) {
            if(!j)i++;
            else j=lps[j-1];
        }
    }

}
