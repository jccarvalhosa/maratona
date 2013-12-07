#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	while(cin>>T && T)	{
		int H=-1, v=0;
		while(T--) {
			int l, w, h;
			cin>>l>>w>>h;
			if(h==H) v = max(v, l*w*h);
			if(h>H) {
				v = l*w*h;
				H=h;
			}
		}
		cout<<v<<endl;
	}
	return 0;
}
