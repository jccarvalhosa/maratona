#include <cstdio>
#include <iostream>
#include <string>
using namespace std;


int main() {
	int A, B, flaga, flagb, i;
	string a, b;
	cin>>a>>b;
	A = a.size();
	B = b.size();
	if(A != B) printf("NO");
	else {
		for(i=0;i<A && a[i]=='0';i++) ;
		flaga = (i==A);
		for(i=0;i<B && b[i]=='0';i++) ;
		flagb = (i==B);
		if(flaga == flagb) printf("YES");
		else printf("NO");
	}
	return 0;
}
