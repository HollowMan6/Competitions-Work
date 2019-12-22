// P1019 单词接龙
// 单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如 beastbeast和astonishastonish，如果接成一条龙则变为beastonishbeastonish，另外相邻的两部分不能存在包含关系，例如atat 和 atideatide 间不能相连。

// 输入输出格式
// 输入格式：
// 输入的第一行为一个单独的整数nn (n \le 20n≤20)表示单词数，以下nn 行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在.

// 输出格式：
// 只需输出以此字母开头的最长的“龙”的长度

// 输入输出样例
// 输入样例#1： 
// 5
// at
// touch
// cheat
// choose
// tact
// a

// 输出样例#1： 
// 23

// 说明
// （连成的“龙”为atoucheatactactouchoose）

// NOIp2000提高组第三题

#include<bits/stdc++.h>

using namespace std;
string str[20];
int use[20], length = 0, n;

int canlink(string str1, string str2) 
{
    for(int i = 1; i < min(str1.length(), str2.length()); i++) 
    {//重叠长度从1开始，直到最短的字符串长度-1（因为不能包含）
        int flag = 1;
        for(int j = 0; j < i; j++)
            if(str1[str1.length() - i + j] != str2[j]) flag = 0;//逐个检测是否相等
        if(flag) return i;//检测完毕相等则立即return
    }
    return 0;//无重叠部分，返回0
}

void solve(string strnow, int lengthnow) 
{
    length = max(lengthnow, length);//更新最大长度
    for(int i = 0; i < n; i++) 
    {
        if(use[i] >= 2) continue;//该字符串使用次数需要小于2
        int c = canlink(strnow, str[i]);//获取重叠长度
        if(c > 0) 
        {//有重叠部分就开始dfs
            use[i]++;
            solve(str[i], lengthnow + str[i].length() - c);
            use[i]--;
        }
    }
}

int main(void) 
{
    cin >> n;
    for(int i = 0; i <= n; i++) use[i] = 0, cin >> str[i];//str[n]为开始字符 
    solve(' '+str[n], 1);//有必要解释一下开始阶段。为了指定第一个字符，而且因为canlink需要重叠部分小于最短长度-1，所以要从前面添加一个无意义充长度的‘ ’。这样就强制了canlink函数比较最后一位。
    cout << length ;
}