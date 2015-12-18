#include <cstdio>
#include <cstring>
int n, m, ans;
int g[7][7];
int MAX(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
void dfs(int x, int y, int cnt)
{
    if(x >= n)//表示已经搜索完毕
    {
        ans = MAX(ans,cnt);
        return;
    }
    if(y >= m)//列出界，表示当前行已经搜索完毕
    {
        dfs(x+1,0,cnt);//重新从下一行的0开始
        return;
    }
    if(g[x][y] == 1)//若当前位置已经有棋子
    {
        dfs(x,y+1,cnt);//则从下一个重新开始搜索
        return;
    }
    dfs(x,y+1,cnt);
    int t, flag = 0;
    for(t = x-1; t >= 0; t--)//下面的两个for是查找同一列是否存在
    {                        //前面已经有炮和炮架
        if(g[t][y])
        {
            break;
        }
    }
    for(int i = t-1; i >= 0; i--)
    {
        if(g[i][y])
        {
            if(g[i][y] == 2)
            {
                flag = 1;
            }
            break;
        }
    }
    if(flag)
    {
        return;//如果存在上面说得情况，就返回上一层
    }
    for(t = y-1; t >= 0; t--)//下面的两个for是查找同一行是否存在
    {                        //前面已经有炮和炮架
        if(g[x][t])
            break;
    }
    for(int j = t-1; j >= 0 ; j--)
    {
        if(g[x][j])
        {
            if(g[x][j] == 2)
            {
                flag = 1;
            }
            break;
        }
    }
    if(flag)
    {
        return;//如果存在上面说得情况，就返回上一层
    }
    g[x][y] = 2;//表示此处暂放一个炮
    dfs(x,y+1,cnt+1);
    g[x][y] = 0;//回溯
}
int main()
{
    int Q, u, v, i;
    while(~scanf("%d%d%d",&n,&m,&Q))
    {
        memset(g,0,sizeof(g));
        for(i = 0; i < Q; i++)
        {
            scanf("%d%d",&u,&v);
            g[u][v] = 1; //表示开始此处已经有棋子
        }
        ans = 0;
        dfs(0, 0, 0);
        printf("%d\n",ans);
    }
    return 0;
}
