#include <bits/stdc++.h>
using namespace std;
string s, t;
const int MAX=2e5;
int f[MAX];
void search() {
	int len = 0;
	for (int i = 0; i < s.size(); ++i) {
		while (len>0 && s[i] != t[len])
			len = f[len - 1];
		if (s[i] == t[len])
			++len;
		if (len == t.size()) {
			cout << i - len + 1 << endl;
			len = f[len - 1];
		}
	}
}
void build() {
	int len = 0;
	f[0] = 0;
	for (int i = 1; i < t.size(); ++i) {
		while (len>0 && t[i] != t[len])
			len = f[len - 1];
		if (t[i] == t[len])
			++len;
		f[i] = len;
	}
}
int main() {
	//   01234567890123456789012345
    cout<<(' '-'A');
	return 0;
}
