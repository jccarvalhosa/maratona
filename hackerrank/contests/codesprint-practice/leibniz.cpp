#include<cstdio>
int main(){int t,n;scanf("%d",&t);while(t--){scanf("%d",&n);double a=0;while(n--)a+=(1.0-n%2*2)/(2*n+1);printf("%.15lf\n",a);}return 0;}
