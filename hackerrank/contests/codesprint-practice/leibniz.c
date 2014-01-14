main(t,n){scanf("%d",&t);while(t--){scanf("%d",&n);double a=0;while(n--)a+=(n&1?-.5:.5)/(n+.5);printf("%.15lf\n",a);}}
