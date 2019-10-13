/*给定一个字符串，找到它的第
一个不重复的字符，并返回它的
索引。如果不存在，则返回 -1。
OJ链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int count[256] = {0};
        for(auto ch:s)
        {
            ++count[ch];
        }
        for(int i = 0; i < s.size(); ++i)
        {
            if(count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};