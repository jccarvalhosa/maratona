#include <iostream>
#include <vector>
using namespace std;

int valid(int x, vector<int> guesses, vector<int> answers) {
	if(x < 1 || x > 1000000000) return 0;
	for(int i=0;i<guesses.size();i++) {
		int g = guesses[i];
		int a = answers[i];
		if(x != g+a && x != g-a) return 0;
	}
	return 1;
}

struct EllysNumberGuessing {
	int getNumber(vector<int> guesses, vector<int> answers) {
		int g = guesses[0];
		int a = answers[0];
		int n1 = g + a;
		int n2 = g - a;
		if(valid(n1, guesses, answers) && valid(n2, guesses, answers)) return -1;
		if(valid(n1, guesses, answers)) return n1;
		if(valid(n2, guesses, answers)) return n2;
		return -2;
	}
};

