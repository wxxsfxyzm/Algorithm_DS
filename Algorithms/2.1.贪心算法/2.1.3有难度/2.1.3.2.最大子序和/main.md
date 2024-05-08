# 最大子序和

## 题目链接

[LeetCode](https://leetcode-cn.com/problems/maximum-subarray/)

## 题目描述

给定一个整数数组 `nums` ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

## 示例

```cpp
示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]

输出：6

解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

```

## 思路：暴力

两层循环，第一层 for 就是设置起始位置，第二层 for 循环遍历数组寻找最大值

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) { // 设置起始位置
            count = 0;
            for (int j = i; j < nums.size(); j++) { // 每次从起始位置i开始遍历寻找最大值
                count += nums[j];
                result = count > result ? count : result;
            }
        }
        return result;
    }
};
```

- 时间复杂度：$O(n^2)$
- 空间复杂度：$O(1)$

## 思路：贪心算法

- 局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，因为负数加上下一个元素 “连续和”只会越来越小。
- 全局最优：选取最大“连续和”

局部最优的情况下，并记录最大的“连续和”，可以推出全局最优。

从代码角度上来讲：遍历 `nums`，从头开始用 `count` 累积，如果 `count` 一旦加上 `nums[i]` 变为负数，那么就应该从 `nums[i+1]` 开始从 `0` 累积 `count` 了，因为已经变为负数的 `count`，只会拖累总和。

这相当于是暴力解法中的不断调整最大子序和区间的起始位置。

如何才能得到最大“连续和”呢？（区间的终止位置如何调整？）

区间的终止位置，其实就是如果 `count` 取到最大值了，及时记录下来了。例如如下代码：

```cpp
if (count > result) result = count;
```

这样相当于是用 `result` 记录最大子序和区间和（变相的算是调整了终止位置）

### 代码实现

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) { // 取区间累计的最大值（相当于不断确定最大子序终止位置）
                result = count;
            }
            if (count <= 0) count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
        }
        return result;
    }
};
```

- 时间复杂度：O(n)
- 空间复杂度：O(1)

**注意 1**：将 `result` 初始化为整型最小值，是因为当输入用例全都是负数的时候，要保证 result 能被正确地更新（被最大的值覆盖）。
如果初始化为 0，那么当输入用例全都是负数的时候，result 将始终为 0，无法被更新。

**注意 2**：是连续和为负选择起始位置，而不是遇到负数就选择起始位置。因为连续和为负数，说明这个区间的和不可能是最大的，所以应该选择下一个元素作为起始位置。而只是遇到负数但是和还是正数的话，说明这个区间的和还有可能是最大的，所以不应该选择下一个元素作为起始位置。

## 思路：动态规划

[最大子序和](../../../2.3.动态规划/2.3.5.子序列问题/2.3.5.2.连续子序列/2.3.5.2.3.最大子序列的和/main.md#思路动态规划)
