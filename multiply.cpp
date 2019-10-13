/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
OJ：https://leetcode-cn.com/problems/multiply-strings/*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0"|| num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        int num[n1 + n2 +1] = {0};
        for(int i = n1 - 1; i >= 0; --i)
        {
            for(int j = n2 -1; j >= 0; --j)
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
        int count = 0;
        for(int i = n1 + n2 -1; i >= 0; --i)
        {
            num[i] += count;
            count = num[i] / 10;
            num[i] %= 10;
        }
        string s;
        int sum = 0;
        while(sum < n1 + n2 && num[sum] == 0)
        {
            ++sum;
        }
        for(; sum < n1 + n2; ++sum)
            s += num[sum] + '0';
        return s;
    }
};