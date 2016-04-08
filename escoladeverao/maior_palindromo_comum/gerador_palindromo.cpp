#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int M = 50000;
int N = 10;

int randomIntByMod(int n) { return (1ll * rand() * ((int)1e9 + 7)) % n; }

string randomStringBySize(int n) {
	string s = "";
	for(int i=0;i<n;i++) s += 'a' + randomIntByMod(26);
	return s;
}

string randomString() { return randomStringBySize(randomIntByMod(M)+1); }

string randomPalindrome() {
	string s = randomString();
	for(int i=0;i<s.size()/2;i++) s[s.size()-i-1] = s[i];
	return s;
}

string randomStringBySolution(string s) {
	int n = s.size(); 
	int l = randomIntByMod(M+1-n);
	int r = randomIntByMod(M+1-n-l);
	return randomStringBySize(l) + s + randomStringBySize(r);
}
string randomStringBySolutionBySize(string s, int m) {
	int n = s.size(); 
	int l = randomIntByMod(m+1-n);
	int r = m-n-l;
	return randomStringBySize(l) + s + randomStringBySize(r);
}

void generateTestByType(int type) {
	int n;
	string s;

	switch(type) {

		case 1:
			cout<<3<<endl;
			cout<<"cabbac"<<endl;
			cout<<"aaaaaaaaaaaaabba"<<endl;
			cout<<"bbbbbaabba"<<endl;
			return;

		case 2:
			cout<<2<<endl;
			cout<<"a"<<endl;
			cout<<"b"<<endl;
			return;

		case 3: 
			N = 5;
			M = 10;
			n = randomIntByMod(N) + 1;
			cout<<n<<endl;
			s = randomPalindrome();
			for(int i=0;i<n;i++) cout << randomStringBySolution(s) << endl;
			N = 10;
			M = 50000;
			return;

		case 4:
			cout<<10<<endl;
			for(int i=0;i<10;i++) cout<<string(M, 'a')<<endl;
			return;

		case 5:
			n = randomIntByMod(N) + 1;
			cout<<n<<endl;
			for(int i=0;i<n;i++) cout << randomString() << endl;
			return;

		case 6:
			n = randomIntByMod(N) + 1;
			cout<<n<<endl;
			s = randomPalindrome();
			for(int i=0;i<n;i++) cout << randomStringBySolution(s) << endl;
			return;
		
		case 7:
			cout<<N<<endl;
			s = randomPalindrome();
			for(int i=0;i<N;i++) cout << randomStringBySolutionBySize(s, M) << endl;
			return;

		default:
			return;
	}
}

int main() {
	srand(time(NULL));
	for(int i=1;i<=15;i++) {
		char name[55];
		sprintf(name, "testcases/palindromo.in%d", i);
		freopen(name, "w", stdout);
		if(i==1) generateTestByType(1);
		else if(i==2) generateTestByType(2);
		else if(i < 6) generateTestByType(3);
		else if(i == 6) generateTestByType(4);
		else if(i<10) generateTestByType(5);
		else if(i<13) generateTestByType(6);
		else generateTestByType(7);
		fclose(stdout);
	}
}
