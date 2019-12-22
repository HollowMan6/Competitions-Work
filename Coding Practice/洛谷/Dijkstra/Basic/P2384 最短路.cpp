// P2384 最短路
// 给定n个点的带权有向图，求从1到n的路径中边权之积最小的简单路径。
// 输入输出格式
// 输入格式：
// 第一行读入两个整数n，m，表示共n个点m条边。 接下来m行，每行三个正整数x，y，z，表示点x到点y有一条边权为z的边。
// 输出格式：
// 输出仅包括一行，记为所求路径的边权之积，由于答案可能很大，因此输出它模9987的余数即可。

// 对于20%的数据，n<=10。

// 对于100%的数据，n<=1000，m<=1000000。边权不超过10000。

// 输入输出样例
// 输入样例#1： 
// 3 3
// 1 2 3 
// 2 3 3 
// 1 3 10
// 输出样例#1： 
// 9

#include<bits/stdc++.h>//万能头

using namespace std;
const int maxn=1000+10;
int n,m;
int d[maxn][maxn],dis[maxn],piao[maxn];//d用来存储图,piao数组代码中会解释

int  dijkstra(int s,int t)
{//开始dijkstra 表示起始点，t表示终止点
    int u;//中转点
    int minn;
    for(int i=1;i<=n;i++)
        dis[i]=d[s][i];
    piao[s]=1;
    dis[s]=0;//初始化
    for(int i=2;i<=n;i++)
	{
        minn=2147483647-1;
        u=s;
		for(int j=1;j<=n;j++)
			if(piao[j]==0&&dis[j]<minn)
				minn=dis[j],u=j;//找到最近的点
		piao[u]=1;
		for(int j=1;j<=n;j++)//遍历，如果乘积比之间要小，也就是路程比之前的短，就更新
			if(dis[j]>dis[u]*d[u][j])
				dis[j]=dis[u]*d[u][j];
    }
    return dis[t];//返回最短路
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        	d[i][j]=100000.0;
    for(int i=1;i<=m;i++)
	{
    	int u,v,x;
    	cin>>u>>v>>x;
    	d[u][v]=d[v][u]=x;//因为是个无向图，还有在这里我是采用的邻接矩阵来存储
    }
	printf("%d",dijkstra(1,n)%9987);//输出dijkstra的结果，要记得取% %%%%

    return 0;
}