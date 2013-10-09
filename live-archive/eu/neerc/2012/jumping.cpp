#include <iostream>
using namespace std;

int p, a, b, c;

void add(int x, int n=1) {
	int m = x>0?x:-x;
	for(int i=0;i<n;i++) {
		cout<<" "<<(p+=x);
		if(m==1) a--;
		if(m==2) b--;
		if(m==3) c--;
	}
}

int main() {
	int T;
	while(cin>>T && !cin.eof()) while(T--) {
		cin>>a>>b>>c;
		cout<<(p=0);
		int k = c/3;
		if(c%3==0) {
			add(3, k);
			add(1);
			add(-3, k);
			add(1);
			add(3, k);
		}
		else {
			add(3, k+1);
			add(-2);
			add(-3, k);
			add(1);
			add(3, k);
			if(c==0) add(2);
			else {
				add(3);
				add(-1);
				add(2);
			}
		}
		add(1, a-1);
		k = b/2;
		add(2, k);
		if(b==k) add(1);
		else {
			add(2);
			add(-1);
		}
		add(-2, k);
		cout<<endl;
	}
	return 0;
}
