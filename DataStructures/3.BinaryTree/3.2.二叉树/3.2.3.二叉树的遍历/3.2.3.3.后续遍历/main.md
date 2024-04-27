# 后序遍历

后序遍历(PostOrder)的操作过程如下：

- 若二叉树为空，则什么也不做，否则：
  1. 后序遍历左子树
  2. 后序遍历右子树
  3. 访问根结点

对应的递归算法如下：

```c++
void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);    // 后序遍历左子树
        PostOrder(T->rchild);    // 后序遍历右子树
        visit(T);               // 访问根结点
    }
}
```

非递归算法如下：

```c++
void PostOrder(BiTree T) {
    InitStack(S);
    BiTree p = T;
    BiTree r = nullptr;
    while (p || !IsEmpty(S)) {
        if (p) {                                // 当没有走到最左边时候，一直向左走
            Push(S, p);                         // 根指针进栈
            p = p->lchild;                      // 走到最左边
        }
        else {                                  // 当走到最左边时候，开始出栈
            GetTop(S, p);                       // 取栈顶元素
            if (p->rchild && p->rchild != r) {  // 如果右子树存在且未被访问
                p = p->rchild;                  // 转向右
                Push(S, p);                     // 右子树根指针进栈
                p = p->lchild;                  // 再走到最左
            }
        else {                                  // 如果右子树不存在或者已经被访问
            Pop(S, p);                          // 取栈顶元素
                visit(p);                       // 访问栈顶元素
                r = p;                          // 标记已访问
                p = nullptr;                    // 置空，下次循环不会再访问
            }
        }
    }
}
```
