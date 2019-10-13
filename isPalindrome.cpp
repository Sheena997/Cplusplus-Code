/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
OJ链接：https://leetcode-cn.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isChar_Number(char ch)
    {
        if((ch >= 'a' && ch <= 'z') ||  (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        size_t first = 0, last = s.size()-1;
        //先全部转换为小写字母
        for(auto& c: s)
        {
            if(c >= 'A' && c <= 'Z')
                c += 32;
        }
        while(first < last)
        {
            while((first < last) && false == isChar_Number(s[first]))
                ++first;
            while((first < last) && false == isChar_Number(s[last]))
                --last;
            if(first < last)
            {
                if(s[first] == s[last])
                {
                    ++first;
                    --last;
                }
                else
                {
                    return false;
                }
            }
        }
         return true;
    }
};