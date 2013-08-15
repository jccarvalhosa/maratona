#include <stdio.h>
#include <vector>

using namespace std;

int N, K;
long long int sum;
vector<int> v[100000];

vector<int> merge_sort(int ind, int a, int b)
{
	vector<int> vmerge, vleft, vright;
	int lcount, rcount;
	if(a == b)
	{
		vmerge.push_back(v[ind][a]);
		return vmerge;
	}
	vright = merge_sort(ind, (a+b)/2+1, b);
	vleft = merge_sort(ind, a, (a+b)/2);
	lcount = rcount = 0;
	while(lcount < vleft.size() && rcount < vright.size())
	{
		if(vleft[lcount] > vright[rcount])
		{
			vmerge.push_back(vright[rcount++]);
			sum += vleft.size() - lcount;
		}
		else vmerge.push_back(vleft[lcount++]);
	}
	while(lcount < vleft.size()) vmerge.push_back(vleft[lcount++]);
	while(rcount < vright.size()) vmerge.push_back(vright[rcount++]);
	return vmerge;
}

int main()
{
	int T, i, j, c, valido, ultimo, proximo;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &K);
		for(i=0;i<K;i++) v[i].clear();
		sum = 0;
		for(i=0;i<N;i++)
		{
			scanf("%d", &c);
			v[i % K].push_back(c);
		}
		for(i=0;i<K;i++) v[i] = merge_sort(i, 0, v[i].size()-1);
		valido = 1;
		ultimo = v[0][0];
		for(i=1;i<N;i++)
		{
			proximo = v[i % K][i / K];
			if(proximo < ultimo)
			{
				valido = 0;
				break;
			}
			ultimo = proximo;
		}
		if(valido) printf("%lld\n", sum);
		else printf("impossivel\n");
	}
	return 0;
}
