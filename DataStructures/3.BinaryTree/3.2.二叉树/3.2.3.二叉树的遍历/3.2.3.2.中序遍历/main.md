# 中序遍历 LNR

中序遍历(InOrder)的操作过程如下：

- 若二叉树为空，则什么也不做，否则：
  1. 中序遍历左子树
  2. 访问根结点
  3. 中序遍历右子树

对应的递归算法如下：

```c++
void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);    // 中序遍历左子树
        visit(T);             // 访问根结点
        InOrder(T->rchild);    // 中序遍历右子树
    }
}
```

非递归算法如下：

```c++
void InOrder(BiTree T) {
    InitStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);         // 根指针进栈
            p = p->lchild;      // 走到最左边
        }
        else {
            Pop(S, p);          // 取栈顶元素
            visit(p);           // 访问栈顶元素
            p = p->rchild;      // 转向右
        }
    }
}
```
