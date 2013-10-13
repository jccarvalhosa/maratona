#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int back(int &x, int &y, int &r, int &c, string s) {
	int oldx, oldy;
	if(s == "LU") {
		if(y > r/2) {
			oldx = x + c;
			oldy = y - r/2;
		} else {
			oldx = c - x + 1;
			oldy = r/2-y+1;
		}
	}
	if(s=="LD") {
		if(y > r/2) {
			oldx = c - x + 1;
			oldy = r - y + 1;
		} else {
			oldx = c+x;
			oldy = y;
		}
	}
	if(s == "RU") {
		if(y > r/2) {
			oldx = x;
			oldy = y - r/2;
		} else {
			oldx = 2*c - x + 1;
			oldy = r/2-y+1;
		}
	}
	if(s=="RD") {
		if(y > r/2) {
			oldx = 2*c - x + 1;
			oldy = r-y+1;
		} else {
			oldx = x;
			oldy = y;
		}
	}
	x = oldx;
	y = oldy;
	r /= 2;
	c *= 2;
}

const int K=21;
const int M=1024;

int main() { 
	string rot[K];
	for(int i=0;i<K;i++) cin>>rot[i];
	for(int i=1;i<=M;i++) {
		int r=1<<K, c=1;
		int x=1, y=i; 
		for(int i=K-1;i>=0;i--) back(x, y, r, c, rot[i]);
		cout<<x<<endl;
	}
	return 0;
}

