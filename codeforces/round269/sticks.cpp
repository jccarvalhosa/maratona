#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[10];

int main() {
	for(int i=0;i<6;i++) {
		int x;
		cin>>x;
		cnt[x]++;
	}
	for(int leg=1;leg<=9;leg++) for(int body=1;body<=9;body++) for(int head=body-1;head>=1;head--) {
		cnt[leg] -= 4;
		cnt[body] -= 1;
		cnt[head] -= 1;
		if(cnt[leg] == 0 && cnt[body] == 0 && cnt[head] == 0) {
			cout << "Bear" << endl;
			return 0;
		}
		cnt[leg] += 4;
		cnt[body] += 1;
		cnt[head] += 1;

	}
	for(int leg=1;leg<=9;leg++) for(int body=1;body<=9;body++) {
		int head = body;
		cnt[leg] -= 4;
		cnt[body] -= 1;
		cnt[head] -= 1;
		if(cnt[leg] == 0 && cnt[body] == 0 && cnt[head] == 0) {
			cout << "Elephant" << endl;
			return 0;
		}
		cnt[leg] += 4;
		cnt[body] += 1;
		cnt[head] += 1;

	}
	cout << "Alien" << endl;
	return 0;
}
