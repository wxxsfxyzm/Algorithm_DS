# 左叶子之和

## 题目链接

[左叶子之和](https://leetcode-cn.com/problems/sum-of-left-leaves/)

## 题目描述

- 计算给定二叉树的所有左叶子之和。

- 示例：

```
    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
```

## 解法

### 叶子结点的判定

- 只判断当前结点，是无法判断其是否是左叶子结点的，因为左叶子结点是左孩子且没有左右孩子的结点。
- 所以要考虑父结点是否满足条件：

  - 父结点是否有左孩子
  - 父结点的左孩子是否是叶子结点

- 如果该节点的左节点不为空，该节点的左节点的左节点为空，该节点的左节点的右节点为空，则找到了一个左叶子，判断代码如下：

```cpp
if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
    // 左叶子节点处理逻辑
}
```

### 递归

1. 确定递归函数的参数和返回值

   - 参数：当前结点 `node`
   - 返回值：左叶子之和

   ```cpp
   int sumOfLeftLeaves(TreeNode* node)
   ```

2. 确定终止条件

   - 如果遍历到空结点，那么没有左叶子

   ```cpp
   if (node == nullptr)
       return 0;
   ```

   - 只有当前遍历的结点是父结点，才能判断其子结点是不是叶子。所以如果当前结点是叶子结点，那么其必定没有叶子

   ```cpp
   if(root == nullptr)
       return 0;
   if(root->left == nullptr && root->right == nullptr)
       return 0;
   ```

3. 确定单层递归的逻辑

   - 当遇到左叶子节点的时候，记录数值，然后通过递归求取左子树左叶子之和，和 右子树左叶子之和，相加便是整个树的左叶子之和。

   ```cpp
   int leftValue = sumOfLeftLeaves(root->left);    // 左
   if (root->left && !root->left->left && !root->left->right) {
       leftValue = root->left->val;
   }
   int rightValue = sumOfLeftLeaves(root->right);  // 右

   int sum = leftValue + rightValue;               // 中
   return sum;
   ```

4. 代码实现

- 先处理根节点，不符合递归条件的（没有子树）直接返回 0（无左叶子）。然后递归合法结点的左子树，再递归右子树。每次递归到左孩子就做出处理，将其值加入到左叶子之和中，然后向右递归，处理右子树的左叶子之和，加入到右子树之和中，在完成当轮递归后，返回该节点左右子树的左叶子之和。

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {                           // 在这里所有判断都是对父结点判断的
        if (root == nullptr)                                        // 终止条件: 父结点为空则直接返回
            return 0;
        if (root->left == nullptr && root->right == nullptr)        // 终止条件: 这是一个叶子结点，不是父结点
            return 0;
        // 对所有的非空的且有孩子的结点进行遍历
        int leftValue = sumOfLeftLeaves(root->left);    // 递归左子树
        if (root->left &&                               // 左子树就是一个左叶子的情况
            !root->left->left &&                        // 当前节点有左孩子且左孩子没有左右孩子
            !root->left->right) {                       // 这样的左孩子就是左叶子
            leftValue = root->left->val;                // 记录左叶子的值
        }
        int rightValue = sumOfLeftLeaves(root->right);  // 递归右子树
        int sum = leftValue + rightValue;               // 将左右子树的左叶子之和相加
        return sum;                                     // 返回当前树的左叶子之和
    }
};
```

5. 精简代码

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftValue = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            leftValue = root->left->val;
        }
        return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```
