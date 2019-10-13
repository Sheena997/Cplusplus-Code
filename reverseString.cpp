/*给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string-ii
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        for(string::iterator it = s.begin(); it < s.end(); it += 2*k)
        {
            if(it + k < s.end())
                reverse(it, it + k);
            else
                reverse(it, s.end());
        }
        return s;
    }
};
