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

6. 假设一颗二叉树中各结点的值互不相同，其先序遍历序列和中序遍历序列分别存于两个一维数组 `A[1...n]` 和 `B[1...n]` 中，试编写算法建立该二叉树的二叉链表。

- 由先序和中序遍历序列可以唯一确定一颗二叉树。
- 算法的实现步骤如下：
  1. 根据先序序列确定树的根结点
  2. 根据根结点在中序序列中的位置（LNR）划分出二叉树的左、右子树包含哪些结点，然后根据左、右子树结点在先序序列中的次序确定子树的根节点，即回到步骤 1.
     如此重复上述步骤，直到每颗子树仅有一个结点（该子树的根节点）为止。

```c++
BiTree PreInCreateTree(
    ElemType A[], ElemType B[], int l1, int h1, int l2, int h2){
    BiTree p = (BiTree)malloc(sizeof(BiTNode));  // 生成根结点
    p->data = A[l1];                            // 根结点数据
    int i;
    for(i = l2; B[i] != p->data; i++);          // 在中序序列中找到根结点
    int llen = i - l2;                          // 左子树结点个数
    int rlen = h2 - i;                          // 右子树结点个数
    if(llen)                                    // 有左子树
        p->lchild = PreInCreateTree(A, B, l1 + 1, l1 + llen, l2, i - 1);
    else                                        // 无左子树
        p->lchild = nullptr;
    if(rlen)                                    // 有右子树
        p->rchild = PreInCreateTree(A, B, h1 - rlen + 1, h1, i + 1, h2);
    else                                        // 无右子树
        p->rchild = nullptr;
    return p;                                   // 返回根结点
}
```

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

8. 假设二叉树采用二叉链表存储结构存储，试设计一个算法，计算一颗给定二叉树的所有双分支结点个数

- 双分支结点：左右孩子均不为空的结点。
- 采用后序遍历算法，遍历到叶子结点时，若该结点是双分支结点，则计数器加 1。

- 计算一颗二叉树 b 中所有双分支结点个数的递归模型 `f(b)` 如下：
  - 若 b 为空，则 f(b) = 0
  - 若 b 为双分支结点，则 f(b) = f(b->lchild) + f(b->rchild) + 1
  - 其他情况：若 b 为单分支结点或叶子结点，则 f(b) = f(b->lchild) + f(b->rchild)

```c++
int DsonNodes(BiTree b){
    if(!b)                              // 空树
        return 0;                       // 双分支结点个数为 0
    else if(b->lchild && b->rchild)     // 双分支结点
        return DsonNodes(b->lchild) + DsonNodes(b->rchild) + 1;
    else                                // 单分支结点或叶子结点
        return DsonNodes(b->lchild) + DsonNodes(b->rchild);
}
```

9. 假设树 B 是一颗采用二叉链表存储结构的二叉树，设计一个算法，把树中所有结点的左、右子树进行交换

- 采用递归算法实现交换左右子树的操作，交换左右子树的操作是一个后序遍历的过程。

```c++
void swap(BiTree T){
    if(T){                              // 非空树
        swap(T->lchild);                // 交换左子树
        swap(T->rchild);                // 交换右子树
        BiTree temp = T->lchild;        // 交换左右子树
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
```

10. 假设二叉树采用二叉链表存储结构存储，设计一个算法，求先序遍历序列中第 `k (1 ≤ k ≤ 二叉树中结点个数)` 个结点的值。

- 设置一个全局变量 `i` （初值为 1 ），来表示进行先序遍历时，当前访问的是第几个结点。然后可以借用[先序遍历](../3.2.二叉树/3.2.3.二叉树的遍历/3.2.3.1.前序遍历/main.md#先序前序遍历二叉树-nlr)的代码模型，先序遍历二叉树。当二叉树 b 为空时，返回特殊字符 `#` ，当 `k == i` 时，该节点即为要找的结点，返回 `b->data` ；当 `k != i` 时，递归遍历左子树，若找到则返回该值，否则继续递归遍历右子树。

对应的递归模型如下：

- 若 b 为空，则返回特殊字符 `#`
  `f(b,k)='#'`
- 若 k == i，则返回 b->data
  `f(b,k)=b->data`
- 否则，递归遍历左子树，若找到则返回该值，否则继续递归遍历右子树
  `f(b,k)=((ch=f(b->lchild,k))!=' '?f(b->rchild,k)`

```c++
int i = 1;                          // 计数器
ElemType PreNode(BiTree b, int k){
    if(!b)                          // 空树
        return '#';                 // 返回特殊字符
    if(k == i)                      // 第 k 个结点
        return b->data;             // 返回结点值
    i++;                            // 计数器加 1
    ch = PreNode(b->lchild, k);     // 递归遍历左子树
    if(ch != '#')                   // 找到
        return ch;                  // 返回结点值
    return PreNode(b->rchild, k);   // 继续递归遍历右子树
}
```

11. 已知二叉树以二叉链表存储结构存储，设计一个算法，对于书中每个元素值为 x 的结点，删去以它为根的子树，并释放相应的空间。

- 要删除以元素值 x 为根的子树，只要能删除其左、右子树，就可以释放值为 x 的根节点，因此宜采用后序遍历。

- 算法思想：删除值为 x 的结点，意味着应将其父结点的左（右）子女指针置空，用层次遍历易于找到某节点的父结点。本题要求删除树中每个元素值为 `x` 的结点的子树，因此要遍历完整颗二叉树。

算法实现如下：

```c++
void DeleteXTree(BiTree &T){
    if(T){                              // 非空树
        DeleteXTree(T->lchild);          // 删除左子树
        DeleteXTree(T->rchild);          // 删除右子树
        delete(T);                        // 释放根结点
    }
}

void Search(BiTree &T, ElemType x){
    BiTree Q[];                         // 队列
    if(T){
        if(T->data == x){               // 找到值为 x 的结点
            DeleteXTree(T);             // 删除以 x 为根的子树
            return;
        }
        InitQueue(Q);                   // 初始化队列
        EnQueue(Q, T);                  // 根结点入队
        while(!isEmpty(Q)){
            DeQueue(Q, p);              // 出队列
            if(p->lchild){              // 左孩子非空
                if(p->lchild->data == x){   // 找到值为 x 的结点
                    DeleteXTree(p->lchild); // 删除以 x 为根的子树
                    p->lchild = nullptr;    // 左孩子置空
                    return;
                } else
                    EnQueue(Q, p->lchild);      // 左孩子入队
            }
            if(p->rchild){              // 右孩子非空
                if(p->rchild->data == x){   // 找到值为 x 的结点
                    DeleteXTree(p->rchild); // 删除以 x 为根的子树
                    p->rchild = nullptr;    // 右孩子置空
                    return;
                } else
                    EnQueue(Q, p->rchild);      // 右孩子入队
            }
        }
```

12. 在二叉树中查找值为 `x` 的结点，若找到则输出该结点的所有祖先结点，假设值为 `x` 的结点不多于一个。

- 算法思想：采用非递归后续遍历，最后访问根结点，访问到值为 `x` 的结点时，栈中的结点即为该结点的祖先结点，依次出栈输出即可。

算法实现如下：

```c++
typedef struct{
    BiTree t;       // 结点指针
    bool flag;      // 访问标记
} stack;            //tag=0表示左子树被访问，tag=1表示右子树被访问

void Search(BiTree T, ElemType x){
    stack s[MAXSIZE];       // 栈
    int top = -1;           // 栈顶指针
    BiTree p = T;           // 结点指针
    while(p || top != -1){
        while(p && p->data != x){  // 找到值为 x 的结点
            s[++top].t = p;         // 结点入栈
            s[top].flag = false;    // 标记为未访问
            p = p->lchild;          // 左孩子
        }
        if(p->data == x){           // 找到值为 x 的结点
            cout << "祖先结点为：";
            for(int i = 0; i <= top; i++)
                cout << s[i].t->data << " ";
            cout << endl;
            return;
        }
        if(s[top].flag == true){    // 右子树被访问
            top--;                  // 出栈
            p = nullptr;            // 置空
        } else {
            s[top].flag = true;     // 标记为已访问
            p = s[top].t->rchild;   // 右孩子
        }
    }
}
```
