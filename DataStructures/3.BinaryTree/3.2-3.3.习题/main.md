# 综合练习题目

1. 若某非空二叉树的先序序列和后序序列正好相反，则该二叉树的形态是怎样的？

- 先序序列：NLR，后序序列：LRN，要使 NLR=NRL（后序序列反序）成立，L 或 R 必须为空，即该二叉树是一棵单支树。这样的二叉树每层只有一个结点，即二叉树的高度等于结点数。

2. 若某非空二叉树的先序序列和后序序列正好相反，则该二叉树的形态是怎样的？

- 先序序列：NLR，后序序列：LRN，要使 NLR=LRN 成立，L 和 R 应该均为空，所以满足该条件的二叉树只有一个根结点。

3. ♥ 编写后续遍历二叉树的非递归算法

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

**注意**：每次出栈访问完一个结点就相当于遍历完以该结点为根的子树，需要将 p 置为空，以便下次循环不会再访问该结点。

4. 试给出二叉树的自下而上，自右向左的层次遍历算法。

- 一般的二叉树层次遍历是自上而下，自左向右，这里的遍历顺序正好相反。
- 算法思想：利用原先的层次遍历算法，出队列的同时将各结点的指针入栈，在所有结点入栈以后再从栈顶开始依次访问，即为所求的算法。
- 具体实现如下：
  - 将根结点入队
  - 把一个元素出队列，遍历这个元素
  - 依次把这个元素的左孩子、右孩子入队列
  - 若队列不空，重复 2-3 步骤，否则结束

```c++
void InvertLevelOrder(BiTree T) {
    Stack s;
    Queue q;
    if(T){                              // 树不为空
        InitStack(s);                   // 初始化栈
        InitQueue(q);                   // 初始化队列
        EnQueue(q, T);                  // 根结点入队
        while(!IsEmpty(q)){             // 队列不空
            DeQueue(q, p);              // 出队列
            Push(s, p);                 // 结点指针入栈
            if(p->lchild)               // 左孩子入队
                EnQueue(q, p->lchild);
            if(p->rchild)               // 右孩子入队
                EnQueue(q, p->rchild);
        }
        while(!IsEmpty(s)){             // 栈不空
            Pop(s, p);                  // 出栈
            visit(p);                   // 访问结点
        }
    }
}
```

5. 假设二叉树按二叉链表形式存储，设计一个非递归算法，求二叉树的高度。

- 采用层次遍历的算法，设置变量 `level` 记录当前结点所在的层数，设置变量 `last` 指向当前层的最右结点，每次层次遍历出队时与 `last` 指针比较，若两者相等，则层数+1，并让 `last` 指向下一层的最右结点，直到遍历完成。 `level` 的值即为二叉树的高度。

```c++
int BiTreeDepth(BiTree T){
    if(!T)                          // 空树
        return 0;                   // 高度为 0
    int front = -1, rear = -1,      // 队列的头尾指针
        last = 0, level = 0;        // last 指向当前层的最右结点，level 记录层数
    BiTree Q[MAXSIZE];              // 队列
    Q[++rear] = T;                  // 根结点入队
    BiTree p;                       // 结点指针
    while(front < rear){            // 队列不空
        p = Q[++front];             // 出队列
        if(p->lchild)               // 左孩子入队
            Q[++rear] = p->lchild;
        if(p->rchild)               // 右孩子入队
            Q[++rear] = p->rchild;
        if(front == last){          // 当前层遍历完毕
            last = rear;            // last 指向下一层的最右结点
            level++;                // 层数+1
        }
    }
    return level;                   // 返回高度
}
```

6. 暂空

7. 二叉树按二叉链表形式存储，写一个判别给定二叉树是否是完全二叉树的算法。

- 根据完全二叉树的定义，具有 n 个结点的完全二叉树与满二叉树中编号从 1 ~ n 的结点一一对应。
- 采用层次遍历算法，将所有结点加入队列（包括空结点）。遇到空结点时，查看其后是否有非空结点。若有，则二叉树不是完全二叉树。

```c++
bool IsComplete(BiTree T){
    InitQueue(Q);                   // 初始化队列
    if(!T)                          // 空树
        return true;                // 是完全二叉树
    EnQueue(Q, T);                  // 根结点入队
    while(!IsEmpty(Q)){             // 队列不空
        DeQueue(Q, p);              // 出队列
        if(p){                      // 非空结点
            EnQueue(Q, p->lchild);  // 左孩子入队
            EnQueue(Q, p->rchild);  // 右孩子入队
        }
        else{                       // 空结点
            while(!IsEmpty(Q)){     // 查看其后是否有非空结点
                DeQueue(Q, p);      // 出队列
                if(p)               // 有非空结点
                    return false;   // 不是完全二叉树
            }
        }
    }
    return true;                    // 是完全二叉树
}
```
