#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		int ans=0;
		string s;
		cin>>s;
		int n = s.size();
		for(int tam=1;tam<=n;tam++) {
			int c[27] = {0};
			for(int i=0;i<tam;i++) c[s[i]-'a']++;
			int ni = 0;
			for(int i=0;i<='z'-'a';i++) if(c[i]&1) ni++;
			if(ni <= 1) ans++;
			for(int f=tam;f<n;f++) {
				int i = f-tam;
				c[s[i]-'a']--;
				c[s[f]-'a']++;
				if(s[f] != s[i]) {
					if(c[s[i]-'a'] & 1) ni++;
					else ni--;
					if(c[s[f]-'a'] & 1) ni++;
					else ni--;
				}
				if(ni <= 1) ans++;
			}
		}
		cout<<"Case "<<t<<": "<<ans<<endl;
	}
}
