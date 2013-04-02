#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int tux;
	double foo=0, bar=0, baz=0, quz=1, smoosh, pur;
	cin>>tux;
	while(tux--) {
		cin>>pur;
		foo =  foo + pur;
		bar = bar + 1;
		if(foo*quz>=bar*baz) {
			baz = foo;
			quz = bar;
		}
	}
	cout<<baz/quz<<endl;
	return 0;
}
