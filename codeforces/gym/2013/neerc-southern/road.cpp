#include <iostream>
using namespace std;
const int M=333333;

int N, v[M], ini[M], fim[M], best[M];

int trybegin(int pos) {
	for(int i=pos;i<N;i++) if(v[i] <= i-pos) return i-1;
	return N-1;
}

int tryend(int pos) {
	int i=pos, f=N-1;
	if(best[f] <= pos) return f;
	while(i<f-1) {
		int m = (i+f)/2;
		if(best[m] <= pos) i=m;
		else f=m;
	}
	return i;
}


int main() {
	cin>>N;
	for(int i=0;i<N;i++) cin>>v[i];
	int n=0, pos=0;
	int f=N-1;
	for(int i=N-1;i>=0;i--) {
		f = min(f, i);
		while(f>=0 && v[f] >= i-f+1) f--;
		best[i] = f+1;
	}
	while(pos<N) {
		int pf = trybegin(pos);
		int pi = tryend(pos);
		if(pf > pi) {
			ini[n] = pos;
			fim[n] = pf;
			pos = pf+1;
		}
		else {
			ini[n] = pi;
			fim[n] = pos;
			pos = pi+1;
		}
		n++;
	}
	cout << n << endl;
	for(int i=0;i<n;i++) cout << ini[i]+1 << " " << fim[i]+1 << endl;
	return 0;
}
