// P1605 迷宫 

// 【问题描述】
// 给定一个N*M方格的迷宫，迷宫里有T处障碍，障碍处不可通过。给定起点坐标和
// 终点坐标，问: 每个方格最多经过1次，有多少种从起点坐标到终点坐标的方案。在迷宫
// 中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍。

// 【数据规模】
// 1≤N,M≤5

// 【输入】
// 第一行N、M和T，N为行，M为列，T为障碍总数。第二行起点坐标SX,SY，终点坐标FX,FY。接下来T行，每行为障碍点的坐标。

// 【输出】
// 给定起点坐标和终点坐标，问每个方格最多经过1次，从起点坐标到终点坐标的方案总数。

// 输入输出样例
// 输入样例#1： 
// 2 2 1
// 1 1 2 2
// 1 2
// 输出样例#1： 
// 1

#include <iostream>
#include <cstdio>
using namespace std;
bool G[15][15],VIS[15][15];
int n,m,d[5]={-1,0,1,0,-1};
int nx,ny,ex,ey,CNT;
void dfs(int x,int y)
{
    if (x ==ex&&y ==ey)//如果到终点
    {
        CNT++;//路径加一
        return;//回去继续查找
    } 
    for (int k=0;k<4;k++)
    {
        int l=x+d[k];int r=y+d[k+1];
        if (l>=1&&r>=1&&l<=n&&r<=m&&!G [l][r]&&!VIS [l][r]) 
        {
            VIS [l][r]=true;
            dfs (l,r);
            VIS [l][r]=false;
        }
    }
    return; 
}
int main ()
{
    int t,zx,zy;
    cin>>n>>m>>t>>nx>>ny>>ex>>ey;
    G[nx][ny]=true;
    while(t--)
    {
        cin>>zx>>zy;
        G[zx][zy]=true;
    } 
    dfs (nx,ny);
    cout<<CNT;
    return 0; 
} 