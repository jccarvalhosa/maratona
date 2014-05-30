#include <cstdio>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	set<string> w, l;
	for(int i=0;i<n-1;i++) {
		string a, b;
		cin>>a>>b;
		l.insert(b);
		if(w.count(b)) w.erase(b);
		if(!l.count(a)) w.insert(a);
	}
	cout << (*w.begin()) << endl;
	return 0;
}
