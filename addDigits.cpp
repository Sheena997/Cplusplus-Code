/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

示例:

输入: 38
输出: 2 
解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于2 是一位数，所以返回 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-digits
*/

class Solution {
public:
    int addDigits(int num) {
        int ret = 0;
        if(num < 10)
            return num;
        while(num >= 10)
        {
            int sum = 0;
            while(num)
            {
                sum += num % 10;
                num /= 10;
            }
            ret = sum;
            num = ret;
        }
        return ret;
    }
};




