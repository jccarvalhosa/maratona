#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6+1;
int v[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int s[2], swapCount=0;
	int a, b;
	bool canSwap = true;
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i-1]) {
			if (swapCount == 0) {
				s[0] = i-1;
				swapCount = 1;
			}
			else if (swapCount == 1) {
				s[1] = i;
				swapCount = 2;
			}
			else {
				canSwap = false;
				break;
			}
		}
	}
	if (swapCount == 0) {
		cout << "yes" << endl;
		return 0;
	}
	if (canSwap) {

		if (swapCount == 1) {
			swapCount = 2;
			s[1] = s[0] + 1;
		}

		a = s[0], b = s[1];

		if (b > n-1)
			canSwap = false;
		else if (v[a] < v[b])
			canSwap = false;
		else if (a > 0 && v[a - 1] > v[b])
			canSwap = false;
		else if (b < n-1 && v[b + 1] < v[a])
			canSwap = false;
		else if (a != b-1 && (v[a + 1] < v[b] || v[b - 1] > v[a]))
			canSwap = false;
		else {
			cout << "yes" << endl;
			cout << "swap " << a + 1 << " " << b + 1 << endl;
			return 0;
		}
	}

	bool canRev = true, revStarted = false, revEnded = false;
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			if (revEnded) {
				canRev = false;
				break;
			}
			if (!revStarted) {
				revStarted = true;
				s[0] = i - 1;
			}
		} else if (revStarted && !revEnded) {
			revEnded = true;
			s[1] = i - 1;
		}
	}

	if (!revEnded) {
		s[1] = n-1;
	}

	a = s[0], b = s[1];

	if (a > 0 && v[a - 1] > v[b])
		canRev = false;
	if (b < n-1 && v[b + 1] < v[a])
		canRev = false;
	if (a != b-1 && (v[a + 1] < v[b] || v[b - 1] > v[a]))
		canRev = false;

	if (canRev) {
		cout << "yes" << endl;
		cout << "reverse " << a + 1 << " " << b + 1 << endl;
	} else {
		cout << "no" << endl;
	}
	return 0;
}
