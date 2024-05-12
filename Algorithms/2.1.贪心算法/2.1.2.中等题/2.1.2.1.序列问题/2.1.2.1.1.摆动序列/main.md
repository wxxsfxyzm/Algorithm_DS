# 摆动序列

## 题目链接

[摆动序列](https://leetcode-cn.com/problems/wiggle-subsequence/)

## 题目描述

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如，[1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

## 示例

```plaintext
示例 1:

输入: [1,7,4,9,2,5]

输出: 6

解释: 整个序列均为摆动序列。

示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]

输出: 7

解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为 [1,17,10,13,10,16,8]。

示例 3:

输入: [1,2,3,4,5,6,7,8,9]

输出: 2
```

## 思路：贪心 [解析](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.md#%E6%80%9D%E8%B7%AF-1%E8%B4%AA%E5%BF%83%E8%A7%A3%E6%B3%95)

贪心：让峰值尽可能的保持峰值，然后删除单一坡度上的节点

1. 局部最优：删除单调坡度上的节点（不包括单调坡度两端的节点），那么这个坡度就可以有两个局部峰值。
2. 整体最优：整个序列有最多的局部峰值，从而达到最长摆动序列。
3. 举不出反例

在计算是否有峰值的时候，设遍历的下标为 `i` ，`preDiff` 存储前一对元素的差值，`curDiff` 存储当前一对元素的差值。这两个变量用于检测数组中的 "摆动"，即当 `preDiff` 和 `curDiff` 的符号不同，表示数组在这两对元素之间发生了摆动。例如，如果 `preDiff` 是正数，`curDiff` 是负数，那么表示数组在这两对元素之间从上升转为下降，反之亦然。
具体来说，计算 `prediff(nums[i] - nums[i-1])` 和 `curdiff(nums[i+1] - nums[i])`，如果 `prediff < 0 && curdiff > 0` 或者 `prediff > 0 && curdiff < 0` 此时就有波动就需要统计。

考虑三种情况：

1. 情况一：上下坡中有平坡
2. 情况二：数组首尾两端
3. 情况三：单调坡中有平坡

### 代码实现

```cpp
// 贪心实现
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};
```

## 思路：动态规划

可以考虑用动态规划的思想来解决这个问题。

很容易可以发现，对于我们当前考虑的这个数，要么是作为山峰（即 nums[i] > nums[i-1]），要么是作为山谷（即 nums[i] < nums[i - 1]）。

设 dp 状态 dp[i][0]，表示考虑前 i 个数，第 i 个数作为山峰的摆动子序列的最长长度
设 dp 状态 dp[i][1]，表示考虑前 i 个数，第 i 个数作为山谷的摆动子序列的最长长度
则转移方程为：

dp[i][0] = max(dp[i][0], dp[j][1] + 1)，其中 0 < j < i 且 nums[j] < nums[i]，表示将 nums[i]接到前面某个山谷后面，作为山峰。
dp[i][1] = max(dp[i][1], dp[j][0] + 1)，其中 0 < j < i 且 nums[j] > nums[i]，表示将 nums[i]接到前面某个山峰后面，作为山谷。
初始状态：

由于一个数可以接到前面的某个数后面，也可以以自身为子序列的起点，所以初始状态为：dp[0][0] = dp[0][1] = 1。

### 代码实现

```cpp

class Solution {
public:
int dp[1005][2];
int wiggleMaxLength(vector<int>& nums) {
    memset(dp, 0, sizeof dp);
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < nums.size(); ++i) {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
        }
    }
    return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};
```

- 时间复杂度：O(n^2)
- 空间复杂度：O(n)
