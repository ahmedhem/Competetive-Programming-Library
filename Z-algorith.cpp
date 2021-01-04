//Z algorithm is used for pattern matching
/* the algorithm gives for every index i in String S  the maximum prefix starting from 
i is equal to prefix of S
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> ZAlgo(string s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) 
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;
            if (z[k] < r - i + 1) // equality is nonsense
                z[i] = z[k];
            else
            {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}
int main(){
    string s;cin>>s;
    vector<int>z=ZAlgo(s);
    for(int i=0;i<s.size();i++){
            cout<<z[i]<<" ";
    }
}