# 综合练习题目

1. 若某非空二叉树的先序序列和后序序列正好相反，则该二叉树的形态是怎样的？

    - 先序序列：NLR，后序序列：LRN，要使 NLR=NRL（后序序列反序）成立，L 或 R 必
      须为空，即该二叉树是一棵单支树。这样的二叉树每层只有一个结点，即二叉树的高
      度等于结点数。

2. 若某非空二叉树的先序序列和后序序列正好相反，则该二叉树的形态是怎样的？

    - 先序序列：NLR，后序序列：LRN，要使 NLR=LRN 成立，L 和 R 应该均为空，所以满
      足该条件的二叉树只有一个根结点。

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

    **注意**：每次出栈访问完一个结点就相当于遍历完以该结点为根的子树，需要将 p
    置为空，以便下次循环不会再访问该结点。

4. 试给出二叉树的自下而上，自右向左的层次遍历算法。

    - 一般的二叉树层次遍历是自上而下，自左向右，这里的遍历顺序正好相反。
    - 算法思想：利用原先的层次遍历算法，出队列的同时将各结点的指针入栈，在所有结
      点入栈以后再从栈顶开始依次访问，即为所求的算法。
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

    - 采用层次遍历的算法，设置变量 `level` 记录当前结点所在的层数，设置变量
      `last` 指向当前层的最右结点，每次层次遍历出队时与 `last` 指针比较，若两者
      相等，则层数+1，并让 `last` 指向下一层的最右结点，直到遍历完成。 `level`
      的值即为二叉树的高度。

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

6. 假设一颗二叉树中各结点的值互不相同，其先序遍历序列和中序遍历序列分别存于两个
   一维数组 `A[1...n]` 和 `B[1...n]` 中，试编写算法建立该二叉树的二叉链表。

    - 由先序和中序遍历序列可以唯一确定一颗二叉树。
    - 算法的实现步骤如下：
        1. 根据先序序列确定树的根结点
        2. 根据根结点在中序序列中的位置（LNR）划分出二叉树的左、右子树包含哪些结
           点，然后根据左、右子树结点在先序序列中的次序确定子树的根节点，即回到
           步骤 1. 如此重复上述步骤，直到每颗子树仅有一个结点（该子树的根节点）
           为止。

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

    - 根据完全二叉树的定义，具有 n 个结点的完全二叉树与满二叉树中编号从 1 ~ n 的
      结点一一对应。
    - 采用层次遍历算法，将所有结点加入队列（包括空结点）。遇到空结点时，查看其后
      是否有非空结点。若有，则二叉树不是完全二叉树。

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

8. 假设二叉树采用二叉链表存储结构存储，试设计一个算法，计算一颗给定二叉树的所有
   双分支结点个数

    - 双分支结点：左右孩子均不为空的结点。
    - 采用后序遍历算法，遍历到叶子结点时，若该结点是双分支结点，则计数器加 1。

    - 计算一颗二叉树 b 中所有双分支结点个数的递归模型 `f(b)` 如下：
        - 若 b 为空，则 f(b) = 0
        - 若 b 为双分支结点，则 f(b) = f(b->lchild) + f(b->rchild) + 1
        - 其他情况：若 b 为单分支结点或叶子结点，则 f(b) = f(b->lchild) +
          f(b->rchild)

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

9. 假设树 B 是一颗采用二叉链表存储结构的二叉树，设计一个算法，把树中所有结点的左
   、右子树进行交换

    - 采用递归算法实现交换左右子树的操作，交换左右子树的操作是一个后序遍历的过程
      。

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

10. 假设二叉树采用二叉链表存储结构存储，设计一个算法，求先序遍历序列中第
    `k (1 ≤ k ≤ 二叉树中结点个数)` 个结点的值。

    - 设置一个全局变量 `i` （初值为 1 ），来表示进行先序遍历时，当前访问的是第几
      个结点。然后可以借
      用[先序遍历](../3.2.二叉树/3.2.3.二叉树的遍历/3.2.3.1.前序遍历/main.md#先序前序遍历二叉树-nlr)的
      代码模型，先序遍历二叉树。当二叉树 b 为空时，返回特殊字符 `#` ，当
      `k == i` 时，该节点即为要找的结点，返回 `b->data` ；当 `k != i` 时，递归遍
      历左子树，若找到则返回该值，否则继续递归遍历右子树。

    - 对应的递归模型如下：

        - 若 b 为空，则返回特殊字符 `#` `f(b,k)='#'`
        - 若 k == i，则返回 b->data `f(b,k)=b->data`
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

11. 已知二叉树以二叉链表存储结构存储，设计一个算法，对于书中每个元素值为 x 的结
    点，删去以它为根的子树，并释放相应的空间。

    - 要删除以元素值 x 为根的子树，只要能删除其左、右子树，就可以释放值为 x 的根
      节点，因此宜采用后序遍历。

    - 算法思想：删除值为 x 的结点，意味着应将其父结点的左（右）子女指针置空，用
      层次遍历易于找到某节点的父结点。本题要求删除树中每个元素值为 `x` 的结点的
      子树，因此要遍历完整颗二叉树。

    - 算法实现如下：

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
        }
    }
    ```

12. 在二叉树中查找值为 `x` 的结点，若找到则输出该结点的所有祖先结点，假设值为
    `x` 的结点不多于一个。

    - 算法思想：采用非递归后续遍历，最后访问根结点，访问到值为 `x` 的结点时，栈
      中的结点即为该结点的祖先结点，依次出栈输出即可。

    - 算法实现如下：

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

    **注意**：因为查找的过程就是后序遍历的过程，因此使用的栈的深度不超过树的深度
    。

13. 设一棵二叉树的结点结构为(LLINK, INFO, RLINK)，ROOT 为指向根结点的指针，p 和
    q 分别为指向该二叉树中任意两个结点的指针，试编写算法 ANSCESTOR(ROOT, p, q,
    r)，找到结点 p 和 q 的最近公共祖先结点 r。

    - 算法思想：后序遍历最后访问根节点，即在递归算法中，根是压在栈底的。本题要找
      p 和 q 的最近公共祖先结点 r，不失一般性，设 p 在 q 的左边，本算法的思想即
      为采用后序非递归算法，栈中存放二叉树的结点的指针，当访问到某一个结点时，栈
      中所有的元素均为该元素的祖先。后序遍历必然先遍历到结点 p，栈中元素均为 p
      的祖先。先将栈复制到另一辅助栈中，再继续遍历到结点 q 时，将栈中元素（此时
      全都为 q 的祖先）从栈顶开始逐个到辅助栈中去匹配，第一个匹配到的结点即为最
      近公共祖先结点。

    - 算法实现如下：

    ```c++
    typedef struct {
        BiTree t;       // 结点指针
        bool flag;      // 访问标记
    } stack;            // tag=0表示左子树被访问，tag=1表示右子树被访问

    stack s[], s1[];        // 声明工作栈和辅助栈

    BiTree ANSCESTOR(BiTree ROOT, BiTree *p, BiTree *q){
    // 本算法求二叉树中p和q指向结点的最近公共结点
        top = 0,bt = ROOT;
        while(bt!=nullptr || top!=0){
            while(bt!=nullptr){
                s[++top].t = bt;
                s[top].flag = false;
                bt = bt->lchild;
            }                                        // 沿左分支向下
            while(top!=0 && s[top].flag==true){
            // 假定p在q的左侧，遇到p时，栈中元素均为p的祖先
                if(s[top].t==*p){
                    for(int i=1;i<=top;i++){
                        s1[i]=s[i];                 // 复制栈
                        top1=top;
                    }                               // 将栈s的元素转入辅助栈s1保存
                    if(s1[top1].t==*q)              // 找到q结点
                        for(int i=top;i>0;i--){     // 将栈中元素的树节点到s1中去匹配
                            for(int j=top1;j>0;j--)
                                if(s[i].t==s1[j].t)
                                    return s[i].t;      // 返回最近公共祖先结点
                        }
                        top--;
                } // while
                if(top!=0){
                    s[top].flag=true;
                    bt=s[top].t->rchild;
                }                                     // 沿右分支向下
            } // while
        }
        return nullptr;                               // p和q不在同一子树中
    }
    ```

14. 假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树 b 的宽度（即具有
    结点数最多的那一层的结点个数）

    - 算法思想：采用层次遍历的方法求出所有结点的层次，并将所有结点和对应的层次放
      在一个队列中，然后通过扫描队列求出各层的结点总数，最大的层结点总数即为二叉
      树的宽度。

    - 算法实现如下：

    ```c++
    typedef struct {
        BiTree data[MaxSize]        // 保存队列中的结点指针
        int level[MaxSize];         // 保存队列中的结点层次
        int front, rear;            // 队头和队尾指针
    }Qu;

    int BTWidth(BiTree b){
        BiTree p;
        int k, max, i, n;
        Qu.front = Qu.rear = -1;    // 初始化队列
        Qu.rear++;
        Qu.data[Qu.rear] = b;       // 根节点指针入队
        Qu.level[Qu.rear] = 1;      // 根节点层次为 1
        while(Qu.front<Qu.rear){
            Qu.front++;             // 出队
            p = Qu.data[Qu.front];  // 出队结点
            k = Qu.level[Qu.front]; // 出队结点的层次
            if(p->lchild){          // 左孩子非空
                Qu.rear++;          // 左孩子入队
                Qu.data[Qu.rear] = p->lchild;
                Qu.level[Qu.rear] = k + 1;
            }
            if(p->rchild){          // 右孩子非空
                Qu.rear++;          // 右孩子入队
                Qu.data[Qu.rear] = p->rchild;
                Qu.level[Qu.rear] = k + 1;
            }
        }
        max = 0;                    // 最大宽度
        i = 0;                      // 当前层的结点数
        k = 1;                      // k 表示从第一层开始查找
        while(i<=Qu.rear){// i 扫描队列中所有的元素
            n = 0;                  // n 统计第 k 层的结点个数
            while(i<=Qu.rear&&Qu.level[i]==k){
                n++;                // 第 k 层的结点数加 1
                i++;                // 继续扫描
            }
            k=Qu.level[i];          // k 指向下一层
            if(n>max)               // 更新最大宽度
                max = n;
        }
        return max;                 // 返回最大宽度
    }
    ```

    **注意**：本体队列中的结点，在出队后仍需要保留在队列中，以便求二叉树的宽度，
    所以设置的队列采用非环形队列，否则出队后可能被其他结点覆盖，无法再求二叉树的
    宽度。

15. 设有一颗满二叉树（所有结点值均不同），已知其先序序列为 `pre`，设计一个算法，
    求其后序序列 `post`。

    - 算法思想：对一般二叉树，仅根据先序或后序序列，不能确定另一个遍历序列。但对
      满二叉树，任意一个结点的左、右子树均含有相等的结点数，同时，先序序列的第一
      个结点作为后序序列的最后一个结点，由此得到将先序序列 pre[l1...h1]转换为后
      序序列 post[l2...h2]的递归模型如下：

        - f(pre,l1,h1,post,l2,h2) = Do Nothing h1<l1 时
        - f(pre,l1,h1,post,l2,h2) = post[h2] = pre[l1] 其他情况
            - 取中间位置 half = (h1-l1)/2;
            - 将 pre[l1+1...l1+half] 左子树转换为 post[l2...l2+half-1],
            - 即 f(pre,l1+1,l1+half,post,l2,l2+half-1)
            - 将 pre[l1+half+1...h1] 右子树转换为 post[l2+half...h2-1],
            - 即 f(pre,l1+half+1,h1,post,l2+half,h2-1)

        其中，post[h2] = pre[l1] 表示后序序列的最后一个结点（根结点）等于先序序
        列的第一个结点（根结点）。相应的算法如下：

    ```c++
    void PreToPost(ElemType pre[], ElemType post[], int l1, int h1, int l2, int h2){
        int half;
        if(h1>=l1){
            post[h2] = pre[l1];                 // 根结点
            half = (h1-l1)/2;                   // 中间位置
            PreToPost(pre, post, l1+1, l1+half, l2, l2+half-1);  // 左子树
            PreToPost(pre, post, l1+half+1, h1, l2+half, h2-1);  // 右子树
        }
    }
    ```

    例如，有以下代码：

    ```c++
    ElemType *pre = "ABCDEFG";
    ElemType post[MAXSIZE];
    PreToPost(pre, post, 0, 6, 0, 6);
    // cout
    for(int i = 0; i < 7; i++)
        cout << post[i];
    cout << endl;
    ```

    输出结果为：

    ```plaintext
    CDBFGEA
    ```

16. 设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针
    为`head`。

17. 试设计判断两棵二叉树是否相似的算法。所谓二叉树 T1 和 T2 相似，指的是 T1 和
    T2 都是空树或者都只有一个根结点，或者 T1 的左子树和 T2 的左子树相似，且 T1
    的右子树和 T2 的右子树相似。

18. 写出在中序线索二叉树中查找指定结点在后序的前驱结点的算法。

19. 【2014 统考真题】二叉树的带权路径长度（WPL）是二叉树中所有叶结点的带权路径长
    度之和。给定一棵二叉树 T，采用二叉链表存储结构存储，结点结构为：

    | left | weight | right |
    | ---- | ------ | ----- |

    其中叶节点的 weight 域保存该结点的权值，root 为指向 T 的根节点的指针。请设计
    求 T 的 WPL 的算法，要求：

    1. 给出算法的基本思想。
    2. 给出二叉树结点的数据类型定义
    3. 根据设计思想，写出代码，关键之处给出注释

20. 【2017 统考真题】请设计一个算法，将给定的表达式树（二叉树）转换为等价的中缀
    表达式（通过括号反应操作符的计算顺序）并输出。例如，当下列两棵表达式树作为算
    法的输入时：

    ```plaintext
         *               +
       /   \           /   \
      +     *         *     -
     / \   / \       / \     \
    a   b c   -     a   b     -
               \             / \
                d           c   d
    ```

    输出的等价中缀表达式应为：

    ```plaintext
    (a+b)*(c*(-d))
    ```

    和

    ```plaintext
    (a*b)+(-(c-d))
    ```

    二叉树的结点定义如下：

    ```c++
    typedef struct node{
        char data[10];                  // 存储操作数或操作符
        struct node *lchild, *rchild;
    } BTree;
    ```

    要求：

    1. 给出算法的基本思想。
    2. 根据设计思想，写出代码，关键之处给出注释。
