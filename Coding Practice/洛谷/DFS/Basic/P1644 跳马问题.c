// P1644 跳马问题
// 题目描述

// 中国象棋半张棋盘如图1所示。马自左下角(0,0)向右上角（m，n）跳。规定只能往右跳，不准往左跳。比如图1中所示为一种跳行路线，并将路径总数打印出来。

// 输入输出格式
// 输入格式：
// 只有一行：两个数n，m

// 输出格式：
// 只有一个数：总方案数total。

// 输入输出样例
// 输入样例#1： 
// 4 8
// 输出样例#1： 
// 37
// 说明
// 所有数据：n，m<=18

#include<stdio.h>
int m,n;
int ans=0;
const int dx[4]={1,2,2,1};
const int dy[4]={2,1,-1,-2};

void dfs(int x,int y)
{
    if(x==m&&y==n)
         ans++;
	if(x<0||y<0||x>m||y>n)
        return ;
    else for(int i=0;i<4;i++)
    {
         dfs(x+dx[i],y+dy[i]);
     }
}

int main(void)
{
    scanf("%d %d",&n,&m);
    dfs(0,0);
    printf("%d",ans);
}