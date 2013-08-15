#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, C, X1, Y1, X2, Y2;
	int i, a, b, antes, depois;
	vector<int> v1, v2;
	scanf("%d%d", &N, &C);
	for(i=0;i<N;i++)
	{
		scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
		v1.push_back(min(X1, X2));
		v2.push_back(max(X1, X2));
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	while(C--)
	{
		scanf("%d%d", &a, &b);
		antes = int(lower_bound(v1.begin(), v1.end(), a) - v1.begin());
		depois = int(v2.end() - upper_bound(v2.begin(), v2.end(), b));
		printf("%d\n", antes + depois);
	}
	return 0;
}
