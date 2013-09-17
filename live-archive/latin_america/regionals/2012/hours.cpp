#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int valid[181];

int main() {
	int h=0, m=0, a;
	memset(valid, 0, sizeof(valid));
	valid[0]=1;
	while(h != 60) {
		m++;
		if(m % 12 == 0) {
			h++;
			if(m == 60) m = 0;
		}
		valid[min((6*(m-h)+360)%360, (6*(h-m)+360)%360)]=1;
	}
	while(scanf("%d", &a) != EOF) printf("%c\n", valid[a] ? 'Y': 'N');
	return 0;
}
