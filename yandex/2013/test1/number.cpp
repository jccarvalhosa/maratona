#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	int i, p, n;
	char c;
	fin>>s;
	n = s.size();
	for(i=3;i>=0;i--) {
		for(c='1';;c++) {
			p = s.find(c);
			if(p != -1 && n-p-1 >= i) break; 
		}
		fout<<c;
		n = n-p-1;
		s = s.substr(p+1, n);
	}
	return 0;
}
