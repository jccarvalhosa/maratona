#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	vector<int> mao;
	while(scanf("%d%d%d", &A, &B, &C) && A)
	{
		mao.clear();
		mao.push_back(A);
		mao.push_back(B);
		mao.push_back(C);
		sort(mao.begin(), mao.end());
		if(mao[0] == mao[1] && mao[1] == mao[2])
		{
			if(mao[0] == 13) printf("*\n");
			else printf("%d %d %d\n", mao[0]+1, mao[1]+1, mao[2]+1);
		}
		else if(mao[0] == mao[1])
		{
			if(mao[2] != 13) printf("%d %d %d\n", mao[0], mao[1], mao[2]+1);
			else printf("%d %d %d\n", 1, mao[0]+1, mao[1]+1);
		}
		else if(mao[1] == mao[2])
		{
			if(mao[0] != mao[1]-1) printf("%d %d %d\n", mao[0]+1, mao[1], mao[2]);
			else if(mao[1] != 13) printf("%d %d %d\n", mao[1], mao[2], mao[0]+2);
			else printf("1 1 1\n");
		}
		else printf("1 1 2\n");
	}

	return 0;
}
