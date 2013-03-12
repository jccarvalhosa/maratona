#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n = 2000;

int main() {
	srand(time(NULL));
	int i;
	vector<char> pn(26), nm(n);
	for(i=0;i<26;i++) pn[i] = 'a'+i;
	random_shuffle(pn.begin(), pn.end());
	for(i=0;i<n;i++) nm[i] = 'a' + rand() % 26;
	printf("1\n");
	for(i=0;i<26;i++) printf("%c", pn[i]);
	printf(" 500\n");
	for(i=0;i<n;i++) printf("%c", nm[i]);
	printf("\n");
	return 0;
}
