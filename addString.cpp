/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
OJ链接：https://leetcode-cn.com/problems/add-strings/
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int count = 0;
        int last1 = num1.size()-1, last2 = num2.size()-1;
        string add;
        while(last1 >= 0 || last2 >= 0)
        {
            int a1, a2;
            int addret;
            if(last1 >= 0)
            {
                a1 = num1[last1] - '0';
                --last1;
            }   
            else
            {
                a1 = 0;
            }
             if(last2 >= 0)
             {
                 a2 = num2[last2] - '0';
                 --last2;
             } 
            else
            {
                 a2 = 0;
            }
            addret = a1 + a2 + count;
            if(addret >= 10)
            {
                count = 1;
                addret -= 10;
            }
            else
            {
                count = 0;
            }
            add += ('0' + addret);
               
        }
        if(count == 1)
            add += '1';
        reverse(add.begin(), add.end());
        return add;
    }
};