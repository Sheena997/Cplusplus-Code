
/*
给定两个整数L和R，找到闭区间[L, R]范围内，计算置位位数为质数的整数个数。

（注意，计算置位代表二进制表示中1的个数。例如?21?的二进制表示?10101?有 3 个计算置位。还有，1 不是质数。）

示例 1:

输入: L = 6, R = 10
输出: 4
解释:
6 -> 110 (2 个计算置位，2 是质数)
7 -> 111 (3 个计算置位，3 是质数)
9 -> 1001 (2 个计算置位，2 是质数)
10-> 1010 (2 个计算置位，2 是质数)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation

*/
class Solution {
public:
    
    bool isPrime(int count)
    {
        if (count < 2)
            return false;
        int num = sqrt(count);
        for (int i = 2; i <= num; ++i) 
        {
            if (count % i == 0)
                return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int sum = 0;
        for(int i = L; i <= R; ++i)
        {
           int tmp = i;
           int count = 0;
           while(tmp != 0)
           {
               tmp &= (tmp - 1);
               ++count;
           }
            if(isPrime(count))
                ++sum;
        }
        return sum;
    }
};
