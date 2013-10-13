#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

int tree[111111], l[111111], r[111111], n;

void update(int idx, int val)
{
	for(; idx<=2*n; idx+=idx&-idx) tree[idx]+=val;
}

int read(int idx)
{
	int sum=0;
	for(; idx>0; idx-=idx&-idx) sum+=tree[idx];
	return sum;
}

int main()
{
	int i;
	ll ans=0;
	priority_queue<pair<int, int> > q;
	scanf("%d", &n);
	for(i=1; i<=2*n; i++)
	{
		int x;
		scanf("%d", &x);
		if(l[x])
		{
			r[x]=i;
			q.push(make_pair(-(r[x]-l[x]-1), x));
		}
		else l[x]=i;
	}
	while(!q.empty())
	{
		int x=-q.top().first;
		int id=q.top().second;
		q.pop();
		ans+=(x-(read(r[id])-read(l[id])));
		update(l[id], 1);
		update(r[id], 1);
	}
	printf("%lld", ans);
	return 0;
}
