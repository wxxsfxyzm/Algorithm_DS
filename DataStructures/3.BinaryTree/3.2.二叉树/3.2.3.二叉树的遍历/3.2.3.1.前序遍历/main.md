# 先序/前序遍历二叉树 NLR

先序遍历(PreOrder)的操作过程如下：

- 若二叉树为空，则什么也不做，否则：
  1. 访问根节点
  2. 先序遍历左子树
  3. 先序遍历右子树

对应的递归算法如下：

```c++
void PreOrder(BiTree T) {
    if (T) {
        visit(T);           // 访问根节点
        PreOrder(T->lchild);    // 先序遍历左子树
        PreOrder(T->rchild);    // 先序遍历右子树
    }
}
```

非递归算法如下：

```c++
void PreOrder(BiTree T) {
    InitStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S)) {
        if (p) {
            visit(p);           // 访问根节点
            Push(S, p);         // 根指针进栈
            p = p->lchild;      // 走到最左边
        }
        else {
            Pop(S, p);          // 取栈顶元素
            p = p->rchild;      // 转向右
        }
    }
}
```
