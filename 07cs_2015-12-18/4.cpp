#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 100005
using namespace std;

int n,m,cxx;
long long ans;
int cnt[maxn];

void solve()
{
    int i,j,t,m=n;
    memset(cnt,0,sizeof(cnt));
    t=sqrt(n*1.0+0.5);
    for(i=2;i<=t;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                cnt[i]++;
            }
        }
    }
    if(n!=1) ans=6;
    else ans=1;
    for(i=1;i<=t;i++)
    {
        if(cnt[i]) ans=ans*6*cnt[i];
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m%n!=0) printf("0\n");
        else
        {
            n=m/n;
            solve();
            printf("%d\n",ans);
        }
    }
    return 0;
}
