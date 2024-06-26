# 顺序栈的实现

栈是一种操作受限的线性表，只能在栈顶进行插入和删除操作。栈的实现有两种方式，一种是顺序栈，另一种是链栈。顺序栈是用数组实现的栈，链栈是用链表实现的栈。

## 顺序栈的定义

采用顺序存储的栈被称为顺序栈，他利用一组地址连续的存储单元依次存放自栈底到栈顶的元素，同时附设一个指针 top 指示栈顶元素在栈中的位置。

栈的顺序存储类型可描述为：

```c
#define MAXSIZE 100 // 定义栈中元素的最大个数
typedef struct {
    ElemType data[MAXSIZE]; // 存放栈中元素
    int top; // 栈顶指针
} SqStack;
```

- 栈顶指针`S.top`指示栈顶元素在栈中的位置，若栈为空，则`S.top=-1`；
- 栈顶元素`S.data[S.top]`，即栈顶元素的位置；
- 进栈操作：栈不满时，栈顶指针加 1，将元素 e 存入栈顶指针所指示的位置；
- 出栈操作：栈不空时，将栈顶元素返回，并将栈顶指针减 1。
- 栈空条件：`S.top == -1`；
- 栈满条件：`S.top == MAXSIZE - 1`。
- 栈的长度：`S.top + 1`。

**注意 1**：由于顺序表的入栈操作受到数组上界的约束，当对栈的最大使用空间估计不足时，有可能发生栈上溢，此时应当及时向用户报告信息，以便及时处理，避免出错。

**注意 2**：栈和队列的判空，判满条件，会因给定的实际条件不同而发生变化，上面的方法以及接下来的代码实现只是在栈顶指针设定的条件下的相应方法，而其它情况应当以具体情况为准。

## 共享栈

利用栈底位置相对不变的特性，可让两个顺序栈共享一个一维数组空间，将两个栈的栈底分别设置在共享空间的两端，两个栈顶向共享空间的中间延申。

共享栈式为了更有效地利用存储空间，两个栈的共享空间相互调剂，只有在整个存储空间都被占满时才会发生上溢，其存取操作的时间复杂度为 `O(1)` 。
