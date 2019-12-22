// P2299 Mzc和体委的争夺战
// mzc家很有钱（开玩笑），他家有n个男家丁（做过前三弹的都知道）。但如此之多的男家丁吸引来了我们的体委（矮胖小伙），他要来与mzc争夺男家丁。

// mzc很生气，决定与其决斗，但cat的体力确实有些不稳定，所以他需要你来帮他计算一下最短需要的时间。

// 输入输出格式
// 输入格式：
// 第一行有两个数n,m.n表示有n个停留站，m表示共有m条路。

// 之后m行，每行三个数a_i; b_i; c_i; ,表示第a_i个停留站到第b_i个停留站需要c_i的时间。（无向）

// 输出格式：
// 一行，输出1到n最短时间。

// 输入输出样例

// 输入样例#1： 
// 5 8
// 1 2 3
// 2 3 4
// 3 4 5
// 4 5 6
// 1 3 4
// 2 4 7
// 2 5 8
// 1 5 100

// 输出样例#1： 
// 11

// 说明
// n <= 2500;m <= 2*10^5
// 时间限制1s。

#include<iostream>
#include<cstring>

using namespace std;

int a[2501][2501],vis[10001],dis[10001];
int main()
{
    memset(a,0x7f,sizeof(a));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(z<a[x][y])          //判重，貌似此题不需要
        {
            a[x][y]=z;       //**无向图**
            a[y][x]=z;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dis[i]=a[1][i];         //初始化
    }
    dis[1]=0;
    for(int i=1;i<=n;i++)   //开始dijkstra算法
    {
        int k=0;
        int minn=0x7fffff;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0&&dis[j]<minn)
            {
                minn=dis[j];
                k=j;
            }
        }
        if(k==0) break;
        vis[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(dis[k]+a[k][j]<dis[j]) dis[j]=dis[k]+a[k][j];
        }
    }
    cout<<dis[n];

    return 0;
}