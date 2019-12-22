#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
	string A,B;
	int ReverseA[1000+5];
	int ReverseB[1000+5];
	int a[1000+5];
	memset(a,0,sizeof(a));
	cin>>A>>B;
	int lenA = A.length();
	int lenB = B.length();
	// 得到逆转数组 
	for(int i=0;i<lenA;i++)
		ReverseA[i] = A[lenA-i-1]-'0';
	for(int i=0;i<lenB;i++)
		ReverseB[i] = B[lenB-i-1]-'0';
	// 计算 
	for(int i=0;i<lenA;i++)
		for(int j=0;j<lenB;j++){
			a[i+j] += ReverseA[i]*ReverseB[j];
			// 处理进位 
			if(a[i+j]>=10){
				a[i+j+1] += a[i+j]/10;
				a[i+j] %= 10;
			}
		}
	// 控制输出 
	bool flag = false;
	for(int i=lenA+lenB;i>=0;i--){
		if(a[i] && !flag || i==0)  // 答案为 0 的特殊情况 
			flag = true;
		else if(!a[i] && !flag)
			continue;	
		cout<<a[i];
	}
	return 0;
}