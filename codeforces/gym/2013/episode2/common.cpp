#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[111111], b[111111];
int ca[300], cb[300];

int main()
{
	while(scanf("%[^\n]", a) != EOF)
	{
		getchar();
		scanf("%[^\n]", b);
		getchar();
		memset(ca,0,sizeof(ca));
		memset(cb,0,sizeof(cb));
		int la = strlen(a);
		int lb = strlen(b);
		for(int i=0;i<la;i++) ca[a[i]]++;
		for(int i=0;i<lb;i++) cb[b[i]]++;
		for(int i=0;i<300;i++) for(int j=0;j<min(cb[i],ca[i]);j++) printf("%c", i);
		cout << endl;
	}
	return 0;
}
