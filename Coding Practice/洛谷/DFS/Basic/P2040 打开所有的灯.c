// P2040 打开所有的灯 
// 题目背景
// pmshz在玩一个益(ruo)智(zhi)的小游戏，目的是打开九盏灯所有的灯，这样的游戏难倒了pmshz。。。

// 题目描述
// 这个灯很奇(fan)怪(ren)，点一下就会将这个灯和其周围四盏灯的开关状态全部改变。现在你的任务就是就是告诉pmshz要全部打开这些灯。

// 例如
// 0  1  1
// 1  0  0
// 1  0  1
// 点一下最中间的灯【2,2】就变成了
// 0  0  1
// 0  1  1
// 1  1  1
// 再点一下左上角的灯【1,1】就变成了
// 1  1  1
// 1  1  1
// 1  1  1
// 达成目标。最少需要2步。
// 输出2即可。

// 输入输出格式
// 输入格式：
// 九个数字，3*3的格式输入，每两个数字中间只有一个空格，表示灯初始的开关状态。（0表示关，1表示开）

// 输出格式：
// 1个整数，表示最少打开所有灯所需要的步数。

// 输入输出样例
// 输入样例#1： 
// 0 1 1
// 1 0 0
// 1 0 1

// 输出样例#1： 
// 2

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int a[5][5],ans=9;//初值付为9 不解释; 
bool bool_kg()//判断是否灯都是开着的; 
{
    for(register int i=1;i<=3;i++)
        for(register int j=1;j<=3;j++)
            if(a[i][j]==0)
                return 0;
    return 1;
}
void kg(int s)
{
    if(s>ans) return;//此处剪枝(也可以认为是边界),若为if(s>=9)必定超时,只需要判定是否超过最小值; 
    if(bool_kg()==1){ans=min(ans,s);return;}//应为有if(s>ans),所以此处写ans=s也可以; 
    for(register int i=1;i<=3;i++)//没错,开始枚举; 
    for(register int j=1;j<=3;j++)//每个点都枚举一次,让后不断再试其他的点,知道满足要求; 
    {
        a[i][j]=1-a[i][j];
        if(i+1<=3)a[i+1][j]=1-a[i+1][j];
        if(i-1>=1)a[i-1][j]=1-a[i-1][j];
        if(j+1<=3)a[i][j+1]=1-a[i][j+1];
        if(j-1>=1)a[i][j-1]=1-a[i][j-1];
        //四个方向的灯都变化; 
        kg(s+1);
        a[i][j]=1-a[i][j];
        if(i+1<=3)a[i+1][j]=1-a[i+1][j];
        if(i-1>=1)a[i-1][j]=1-a[i-1][j];
        if(j+1<=3)a[i][j+1]=1-a[i][j+1];
        if(j-1>=1)a[i][j-1]=1-a[i][j-1];
        //若不成立就消除变化; 
    }
    return;
}
int main()
{
    for(register int i=1;i<=3;i++)
    for(register int j=1;j<=3;j++)
        scanf("%d",&a[i][j]);   
    kg(0);//从0步开始快乐地枚举吧! 
    printf("%d",ans);

    return 0;
}