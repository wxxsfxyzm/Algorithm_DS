# 层次/层序遍历

要进行层序遍历，我们需要借助队列。我们首先将根节点入队，然后不断迭代：每次出队一个节点，将其左右子节点入队。这样我们就可以实现层序遍历。

```cpp
void LevelOrder(BiTree T) {
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while (!IsEmpty(Q)) {
        DeQueue(Q, p);
        visit(p);
        if (p->lchild)
            EnQueue(Q, p->lchild);
        if (p->rchild)
            EnQueue(Q, p->rchild);
    }
}
```
