#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    int i, n, mpar, mimpar, jpar, jimpar, num;
    while(scanf("%d", &n) && n)
    {
        mpar = 0;
        mimpar = 0;
        jpar = 0;
        jimpar = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d", &num);
            if(num % 2 == 0) mpar++;
            else mimpar++;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d", &num);
            if(num % 2 == 0) jpar++;
            else jimpar++;
        }
        printf("%d\n", n - min(mpar, jimpar) - min(mimpar, jpar));      
    }
    return 0;
}



