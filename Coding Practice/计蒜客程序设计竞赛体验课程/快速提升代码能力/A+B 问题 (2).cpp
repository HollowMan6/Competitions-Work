#include <iostream>
#include <string>
using namespace std;
string jjjj(string num1,string num2){
    if(num1.size()<num2.size()){
        string temp=num1;
        num1=num2;
        num2=temp;
    }
    int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;
    while(length1>0){
        a=num1[length1-1]-'0';
        if(length2>0)
            b=num2[length2-1]-'0';
        else
            b=0;
        sum=a+b+flag;
        if(sum>=10){
            num1[length1-1]='0'+sum%10;
            flag=1;
        }else{
            num1[length1-1]='0'+sum;
            flag=0;
        }
        length1--;
        length2--;
    }

    if(1==flag)
        num1="1"+num1;
    return num1;
}
int main(){
    string num1;
    string num2;
    while(cin>>num1>>num2){
        cout<<jjjj(num1,num2);
    }
    return 0;
}