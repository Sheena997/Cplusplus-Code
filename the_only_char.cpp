/*找出字符串中第一个只出现一次的字符
输入描述:
输入一个非空字符串

输出描述:
输出第一个只出现一次的字符，如果不存在输出-1
示例1
输入
asdfasdfo
输出
o
oj链接：https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking*/


#include <iostream>
#include <string>

using namespace std;
int the_only_char(const string& s)
{
    int count[256] = {0};
    for(int i = 0; i < s.size(); ++i)
    {
        count[s[i]] += 1;
    }
     for(int i = 0; i < s.size(); ++i)
    {
        if(count[s[i]] == 1)
            return i;
    }
    return -1;
}
int main()
{
    string s;
    while (cin >> s)
    {
        int i = the_only_char(s);
        if(i == -1)
            cout << i << endl;
        else
            cout<< s[i] <<endl;
    }
   
    return 0;
}