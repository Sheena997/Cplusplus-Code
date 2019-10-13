/*给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例?1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
*/
class Solution {
public:
    string reverseWords(string s) {
        for(string:: iterator it = s.begin(), end = s.begin() + 1;end < s.end();  ++end)
        {
            if(*end == ' ')
            {
                reverse(it, end);
                it = end + 1;
            }
            else if(end + 1 == s.end())
            {
                reverse(it, end+1);
            }
        }
        return s;
    }
};
