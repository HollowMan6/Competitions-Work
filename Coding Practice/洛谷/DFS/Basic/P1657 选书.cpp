// P1657 选书
// 学校放寒假时，信息学奥赛辅导老师有1,2,3……x本书，要分给参加培训的x个人，每人只能选一本书，但是每人有两本喜欢的书。老师事先让每个人将自己喜欢的书填写在一张表上。然后根据他们填写的表来分配书本，希望设计一个程序帮助老师求出所有可能的分配方案，使每个学生都满意。

// 输入输出格式
// 输入格式：
// 第1行：一个数x

// 第2行~第1+x行：每行两个数，表示ai喜欢的书的序号

// 输出格式：
// 只有一个数：总方案数total。

// 输入输出样例
// 输入样例#1： 
// 5
// 1 3
// 4 5
// 2 5
// 1 4
// 3 5
// 输出样例#1： 
// 2

// 说明
// 所有数据：x<=20

#include<iostream>
using namespace std;
int book[50],s,x;
bool flag[50],like[50][50];              //like[i][j]表示第i个人喜欢第j本书。
void so(int i)                           //dfs产生全排列
{
    int j;
    for(j=1;j<=x;j++)
    {
        if(flag[j]&&like[i][j]){         //此书未选且第i个人喜欢这本书
            flag[j]=0;
            book[i]=j;
            if(i==x) s++;
                else so(i+1);            //继续列举第i+1个人的书
            flag[j]=1;                   //还原与回溯
            book[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);         //加快cin、cout（装逼专用）
    cin>>x;
    int i,t1,t2;
    for(i=1;i<=x;i++)                    //读入喜欢列表
    {
        cin>>t1>>t2;
        like[i][t1]=true;
        like[i][t2]=true;
    }
    for(i=1;i<=x;i++)
    {
        flag[i]=true;                   //标记数组初始化
    }
    so(1);
    cout<<s;                            //输出总方案数
    return 0;
}