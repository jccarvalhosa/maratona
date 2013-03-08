#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;

int conv(char c) {
	if(c <= 'C') return 2;
	if(c <= 'F') return 3;
	if(c <= 'I') return 4;
	if(c <= 'L') return 5;
	if(c <= 'O') return 6;
	if(c <= 'S') return 7;
	if(c <= 'V') return 8;
	return 9;
}

ll pd[10][21];
string name[10];

char find(string word, int n, int k) {
	ll sum=0;
	if(n == 0) return word[k-1];
	for(int i=0;i<word.size();i++) {
		if(sum + pd[conv(word[i])][n] >= k) return find(name[conv(word[i])], n-1, k-sum);
		sum += pd[conv(word[i])][n];
	}
}

int main() {
	int T, t, n, i, j, k;
	string word;
	memset(pd, 0, sizeof(pd));
	name[2] = "TWO";
	name[3] = "THREE";
	name[4] = "FOUR";
	name[5] = "FIVE";
	name[6] = "SIX";
	name[7] = "SEVEN";
	name[8] = "EIGHT";
	name[9] = "NINE";
	for(i=2;i<=9;i++) pd[i][0] = 1;
	for(n=1;n<=20;n++) for(i=2;i<=9;i++) for(j=0;j<name[i].size();j++) pd[i][n] += pd[conv(name[i][j])][n-1];
	scanf("%d", &T);
	for(t=1;t<=T;t++) {
		printf("Case %d: ", t);
		cin >> word >> n >> k;
		cout << find(word, n, k) << endl;
	}
	return 0;
}
