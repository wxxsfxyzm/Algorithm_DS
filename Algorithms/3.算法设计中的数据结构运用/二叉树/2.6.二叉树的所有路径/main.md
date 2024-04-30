# 二叉树的所有路径

## 题目链接

[二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)

## 题目描述

- 给定一个二叉树，返回所有从根节点到叶子节点的路径。

- 说明: 叶子节点是指没有子节点的节点。

## 示例

```
示例 1:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
```

## 解法

- 本题要求从根节点到叶子的路径，所以需要前序遍历，这样才方便让父结点指向子节点，找到对应的路径。
- 本题涉及到回溯，因为找到了一条路径以后，要把这条路径记录下来，然后再回到上一个节点，继续找其他路径。
- 递归遍历二叉树，将路径保存在 `path` 中，当遇到叶子节点时，将 `path` 加入到 `res` 中。然后返回上一个结点，继续遍历其他路径。

### 递归

1. 递归函数参数以及返回值
   - 参数：当前结点 `cur`，当前路径 `path`，保存所有路径的 `res`
   - 返回值：无

```cpp
void traversal(TreeNode* cur, vector<int>& path, vector<string>& res)
```

2. 递归终止条件

   1. 一般情况下，递归终止条件是当前结点为空：

   ```cpp
   if (cur == nullptr)
       // Do Something.
       return;
   ```

   2. 但是本题这样写会很麻烦，因为本题找到的是叶子结点，就要开始处理结束逻辑了（把路径放进 result 里面）。所以这里的递归终止条件是当前结点是叶子结点，而叶子结点又分为左右两个孩子结点：

   ```cpp
   if(cur->left == nullptr && cur->right == nullptr)
       // Do Something.
       return;
   ```

   **注意**：这里不需要判断 cur 是否为空的原因是在递归的时候会判断空结点不进入循环。

3. 终止处理逻辑

   - 当前结点是叶子结点时，将路径 `path` 加入到 `res` 中：

   ```cpp
   if (cur->left == nullptr && cur->right == nullptr) {    // 当前结点是叶子结点
       string sPath = "";
       fot (int i = 0; i < path.size() - 1; i++) {         // 将路径转换为字符串
           sPath += to_string(path[i]);
           if (i != path.size() - 1)
               sPath += "->";
       }
       sPath += to_string(path[path.size() - 1]);          // 加入最后一个结点
       res.push_back(sPath);                               // 将路径加入到res中
       return;
   }
   ```

4. 确定单层递归逻辑
   因为是前序遍历，需要先处理根节点，就是我们要记录的路径上的结点，先将根结点加入 path 中：
   ```cpp
   path.push_back(cur->val);
   ```
   然后递归左右孩子结点：
   ```cpp
   if (cur->left) {
       traversal(cur->left, path, result);
   }
   if (cur->right) {
       traversal(cur->right, path, result);
   }
   ```
   最后回溯，将当前结点从路径中删除：
   ```cpp
   if (cur->left) {
       traversal(cur->left, path, result);// 递归左孩子
       path.pop_back();                   // 回溯
   }
   if (cur->right) {
       traversal(cur->right, path, result);// 递归右孩子
       path.pop_back();                    // 回溯
   }
   ```
   **注意**：回溯和递归是一一对应，成组出现的，所以回溯的步骤应该紧跟在递归的后面。而不是在整个逻辑的最后。

#### 代码 1

```cpp
class Solution {
private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
        if(cur->left==nullptr&&cur->right==nullptr){
            string sPath = "";
            for(int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                if (i != path.size() - 1)
                    sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            res.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);// 递归左孩子
            path.pop_back();                   // 回溯
        }
        if (cur->right) {
            traversal(cur->right, path, result);// 递归右孩子
            path.pop_back();                    // 回溯
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == nullptr)
            return result;
        traversal(root, path, result);
        return result;
    }
};
```

#### 代码 2

上述代码可以简化如下：

```cpp
class Solution {
private:
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left) traversal(cur->left, path + "->", result); // 左
        if (cur->right) traversal(cur->right, path + "->", result); // 右
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr)
            return result;
        traversal(root, path, result);
        return result;
    }
};
```

**注意**：

- 注意在函数定义的时候:

  ```cpp
  void traversal(TreeNode* cur, string path, vector<string>& result)
  ```

  定义的是:

  ```cpp
  string path
  ```

  每次都是复制赋值，不用使用引用，否则就无法做到回溯的效果。

- 在上面的代码中，貌似没有看到回溯的逻辑，其实不然，回溯就隐藏在

  ```cpp
  traversal(cur->left, path + "->", result)
  ```

  中的

  ```cpp
  path + "->"
  ```

  每次函数调用完，`path` 依然是没有加上 `"->"` 的，这就是回溯了。
  如果把

  ```cpp
  path + "->"
  ```

  作为函数参数就是可以的，因为并没有改变 `path` 的数值，执行完递归函数之后，`path` 依然是之前的数值（相当于回溯了）

- 如果把代码

  ```cpp
  if (cur->left) traversal(cur->left, path + "->", result); // 左
  ```

  拆开写，就是

  ```cpp
  if (cur->left) {
      path += "->";
      traversal(cur->left, path, result); // 左
  }
  ```

  这样就会改变 `path` 的值，就不是回溯了。
  如果要补上回溯的部分，就要在递归函数调用之后，将 `path` 的值改回来。

  **法 1**：直接裁掉两位

  ```cpp
  if (cur->left) {
      path += "->";
      traversal(cur->left, path, result); // 左
      path = path.substr(0, path.size() - 2); // 回溯
  }
  ```

  **法 2**：使用 `pop_back()` 方法弹出两位

  ```cpp
  if (cur->left) {
      path += "->";
      traversal(cur->left, path, result); // 左
      path.pop_back(); // 回溯 '>'
      path.pop_back(); // 回溯 '-'
    }
  ```

### 迭代

可以用栈和前序遍历的迭代来模拟遍历路径的过程
除了模拟递归需要一个栈，同时还需要一个栈来存放对应的遍历路径。

#### 代码

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> treeSt;// 保存树的遍历节点
        stack<string> pathSt;   // 保存遍历路径的节点
        vector<string> result;  // 保存最终路径集合
        if (root == NULL) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty()) {
            TreeNode* node = treeSt.top(); treeSt.pop(); // 取出节点 中
            string path = pathSt.top();pathSt.pop();    // 取出该节点对应的路径
            if (node->left == NULL && node->right == NULL) { // 遇到叶子节点
                result.push_back(path);
            }
            // 因为是前序遍历，所以进栈顺序先右后左，这样出栈顺序就是先左后右
            if (node->right) { // 右
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left) { // 左
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};
```
