// P1706 全排列问题
// 输出自然数1到n所有不重复的排列，即n的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

// 输入输出格式
// 输入格式：
// n(1≤n≤9)

// 输出格式：
// 由1～n组成的所有不重复的数字序列，每行一个序列。每个数字保留5个常宽。

// 输入输出样例
// 输入样例#1： 
// 3
// 输出样例#1： 
//     1    2    3
//     1    3    2
//     2    1    3
//     2    3    1
//     3    1    2
//     3    2    1

#include <stdio.h>
int n, a[10],b[10];
void search(int m)
{
	int i,j;
	if (m == n)
	{
		for(j=0;j<n;j++)
			printf("%5d",a[j]);
		printf("\n");
	}
	else
		for(i=1;i<=n;i++)
		{
			if(b[i]==0)
        	{
            	a[m]=i;
         		b[i]=1;
            	search(m+1);
            	b[i]=0;
        	}
		}

}

int main()
{
	int m = 0;
	scanf("%d",&n);
	search(m);
	getchar();
	getchar();
	return 0;
}