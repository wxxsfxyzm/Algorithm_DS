# 反转字符串

## 题目链接

[反转字符串](https://leetcode-cn.com/problems/reverse-string/)

## 题目描述

- 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `char[]` 的形式给出。

- 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 `O(1)` 的额外空间解决这一问题。

## 示例

```
示例 1:

输入: ["h","e","l","l","o"]
输出: ["o","l","l","e","h"]

示例 2:

输入: ["H","a","n","n","a","h"]
输出: ["h","a","n","n","a","H"]
```

## 解法

### 解法 1 STL

直接用库函数 `reverse()` 反转数组。

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
```

**注意**：直接使用库函数 `reverse()` 反转数组，此题失去意义，不推荐。

### 解法 2 双指针

使用双指针，一个指向头部，一个指向尾部，交换两个指针指向的元素。

#### 代码 1

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
```

#### 代码 2

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size()/2; i++, j--) {
            swap(s[i],s[j]);
        }
    }
};
```

**注意**： `swap()`是 C++中的一个库函数，用于交换两个变量的值。在此处非核心代码，可以直接用。

#### `swap` 的两种实现

1. 常见的数值交换方法

```cpp
int tmp = s[i];
s[i] = s[j];
s[j] = tmp;
```

2. 位运算（异或）

```cpp
s[i] ^= s[j];
s[j] ^= s[i];
s[i] ^= s[j];
```
