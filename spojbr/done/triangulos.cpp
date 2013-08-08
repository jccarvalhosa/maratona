#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	vector<int> v;
	int maior, delta;
	scanf("%d%d%d", &A, &B, &C);
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	sort(v.begin(), v.end());
	if(v[2] >= v[0] + v[1]) printf("n\n");
	else
	{
		delta = v[2]*v[2] - v[1]*v[1] - v[0] * v[0];
		if(delta < 0) printf("a\n");
		if(delta == 0) printf("r\n");
		if(delta > 0) printf("o\n");
	}
	return 0;
}
