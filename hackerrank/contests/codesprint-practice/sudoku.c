#define f(i,n)for(int i=0;i<=n;i++)
#define H[i][j]
#define v(a,b,x,s)l[a][x]s c[b][x]s q[n[a][b]][x]
#define r return
k,K,C,s[9][9],l[9][10],c[9][10],q[9][10],n[9][9];S(int i,int j){if(i>8)r 1;if(j>8)r S(i+1,0);if(s H)r S(i,j+1);f(I,9)if(I&&v(i,j,I,+)<1){s H=I;v(i,j,I,=)=1;if(S(i,j+1))r 1;v(i,j,I,=)=0;}s H=0;r 0;}main(){scanf("%d",&K);while(K--){f(i,8)f(j,9)l H=c H=q H=0;f(i,8)f(j,8){scanf(" %c",&C);n H=i/3*3+j/3;s H=C-48;if(s H)v(i,j,s H,=)=1;}S(0,0);f(i,8)f(j,8)printf("%d%c",s H,j<8?32:10);}}
