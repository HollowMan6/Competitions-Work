#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ver[n][m];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>ver[i][j];
    for(i=0;i<m;i++){
        for(j=n-1;j>=0;j--){
            if(j==0)
                cout<<ver[j][i];
            else
            	cout<<ver[j][i]<<" ";
            }
        cout<<endl;
    }
}