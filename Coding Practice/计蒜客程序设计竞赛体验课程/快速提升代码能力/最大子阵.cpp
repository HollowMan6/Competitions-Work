#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 510
int num[maxn][maxn];
int sum[maxn][maxn];
int dp_sum(int *a,int n)
{
	int ret=a[1],dp[maxn];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
	dp[i]=max(a[i],dp[i-1]+a[i]);
	ret=max(dp[i],ret); 
	}
	return ret;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&num[i][j]);
		sum[i][j]=sum[i-1][j]+num[i][j];
	}
	int maxnum=num[1][1];
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
		int tem[maxn];
		memset(tem,0,sizeof(tem));
		for(int k=1;k<=m;k++)
		tem[k]=sum[j][k]-sum[i-1][k];
		maxnum=max(maxnum,dp_sum(tem,m));
	}
	printf("%d\n",maxnum);
}