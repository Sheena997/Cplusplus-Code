
/*
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字?N?。在每个玩家的回合，玩家需要执行以下操作：

选出任一x，满足0 < x < N 且?N % x == 0?。
用 N - x替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回?True，否则返回 false。假设两个玩家都以最佳状态参与游戏。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divisor-game/
*/

/*
  改题目最终的赢家就是最后使N=2的那个人，因为爱丽丝是先手，当N为偶数时，爱丽丝和鲍勃每次都选1最后爱丽丝会使N=2，
  故爱丽丝会赢。当N为奇数时鲍勃就会赢。
*/
class Solution {
public:
    bool divisorGame(int N) {
        if(N % 2 != 0)
            return false;
        else
            return true;
    }
};

