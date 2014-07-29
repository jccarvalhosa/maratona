#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1&&m==1) printf("1\n");
	else printf("%.16f\n",1.0/n+1.0*(n-1)*(m-1)/n/(n*m-1));
	return 0;
}
