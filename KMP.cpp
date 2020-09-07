
    string pat="peek a boo";
    string str="you speek a bootiful language";
    int lps[pat.size()]={0};
    for (int i =1,j=0; i <pat.size() ; ++i) {
        if(pat[i]!=pat[j])j=0;
        if(pat[i]==pat[j])lps[i]=++j;

    }

    for (int k = 0,i=0; k <str.size() ; ++k) {
        if(str[k]!=pat[i])i=lps[i];
        if(str[k]==pat[i])i++;
        if(i==pat.size())cout<<k-(pat.size()-1)<<" ",i=lps[i-1];
    }
