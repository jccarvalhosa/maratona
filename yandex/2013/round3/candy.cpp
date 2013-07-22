#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int x, N, A=0, B=0;
	double sa=0, sb=0;
	cin>>N;
	for(int i=N-1;i>=0;i--) {
		cin>>x;
		if(x==0) N--;
		if(x>0) {
			A++;
			sa += x;
		}
		if(x<0) {
			B++;
			sb += x;
		}
	}
	if(sb==0) printf("%.12lf\n", sa);
	else if(sa==0) printf("%.12lf\n", sb/B);
	else {
		double ans=0;
		for(int tam=0;tam<=A;tam++) {
			double prob=1;
			for(int i=0;i<tam;i++) {
				prob *= A-i;
				prob /= N-i;
			}
			prob *= B;
			prob /= (N-tam);
			ans += prob * (sa*tam/A + sb/B);
		}
		printf("%.12lf\n", ans);
	}
	return 0;
}
