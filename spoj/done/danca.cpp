#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, T, d, dmin, i, j, ok;
	int alcancado[1000000], pos[1000], dir[1000];
	vector<int> vdist;
	scanf("%d%d", &N, &T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d", &pos[i], &dir[i]);
		pos[i]--;
		alcancado[pos[i]] = 0;
		if(i == 0) d = N;
		else d = (N + dir[i] * (pos[0] - pos[i])) % N;
		vdist.push_back(d);
	}
	sort(vdist.begin(), vdist.end());
	for(i=0;i<T;i++) 
	{
		for(j=0;j<T;j++) alcancado[(pos[j] + N + dir[j] * vdist[i]) % N] = 1;
		ok = 1;
		for(j=0;j<T;j++)
		{
			if(!alcancado[pos[j]]) ok = 0;
			else alcancado[pos[j]] = 0;
		}
		if(ok)
		{
			dmin = vdist[i]; 
			break;
		}
	}
	printf("%d\n", dmin);
	return 0;
}
