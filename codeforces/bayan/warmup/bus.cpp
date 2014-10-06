#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
using namespace std;

string bus[] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+",
};

int main() {
	int n;
	cin>>n;
	while(n > 0) {
		for(int i=1;i<=4;i++) {
			if(!n) break;
			for(int j=0;j<bus[i].size();j++) {
				if(bus[i][j] == '#') {
					bus[i][j] = 'O';
					n--;
					break;
				}
			}
		}
	}
	for(int i=0;i<6;i++) cout << bus[i] << endl;
	return 0;
}
