# 单链表的基本操作

## 1. 采用头插法建立单链表

头插法建立单链表的过程是：依次读入数据元素，每读入一个数据元素，就将其插入到链表的头结点之后，使其成为新的头结点。

C 语言使用 `malloc` 分配内存空间，C++使用 `new` 分配内存空间。

单链表的定义见[单链表的定义](../1.3.1.1.定义/main.md#单链表的定义)

```c++
LinkList CreateListHead(LinkList &L, int n) {   // 头插法建立单链表
    LNode *s;                                   // s 为新结点
    // Use malloc in C
    // L = (LinkList)malloc(sizeof(LNode));
    // Use new in C++
    L = new LNode;                              // 创建头结点
    L->next = nullptr;                          // 初始为空链表
    for (int i = 0; i < n; i++) {
        // s = (LNode *)malloc(sizeof(LNode));
        s = new LNode;                          // 创建新结点
        s->data = i;                            // 给新结点赋值（赋值可以由外部输入）
        s->next = L->next;                      // 将新结点插入到表头
        L->next = s;                            // 头结点指向新结点
    }
    return L;                                   // 返回头结点
}
```

**注意**：使用头插法建立单链表时，插入的顺序与输入的顺序相反。每个结点插入的时间为`O(1)`，共插入`n`个结点，时间复杂度为`O(n)`。

## 2. 采用尾插法建立单链表

若希望单链表中的数据元素的顺序与输入的顺序一致，可以采用尾插法建立单链表。

尾插法建立单链表的过程是：依次读入数据元素，每读入一个数据元素，就将其插入到链表的尾结点之后，使其成为新的尾结点。

```c++
LinkList CreateListTail(LinkList &L, int n) {   // 尾插法建立单链表
    LNode *s, *r;                               // r 为表尾指针
    // Use malloc in C
    // L = (LinkList)malloc(sizeof(LNode));
    // Use new in C++
    L = new LNode;                              // 创建头结点
    r = L;                                      // r 指向尾结点
    for (int i = 0; i < n; i++) {
        // Use malloc in C
        // s = (LNode *)malloc(sizeof(LNode));
        // Use new in C++
        s = new LNode;                          // 创建新结点
        s->data = i;                            // 给新结点赋值（赋值可以由外部输入）
        r->next = s;                            // 将新结点插入到表尾
        r = s;                                  // r 指向新的尾结点
    }
    r->next = nullptr;                          // 尾结点指针置空
    return L;                                   // 返回头结点
}
```

**注意**：因为附设了一个指向表尾结点的指针，故时间复杂度和头插法相同。

## 3. 按序号查找结点值

在单链表中从第一个结点出发，顺指针 `next` 域逐个向下搜素，直到找到第 `i` 个结点为止，否则返回最后一个结点的指针域 `nullptr`。

按序号查找结点值的时间复杂度为`O(n)`。

```c++
LNode *GetElem(LinkList L, int i) {             // L 为带头结点的单链表的头指针
    int j = 1;                                  // 计数器，初始为 1
    LNode *p = L->next;                         // p 指向第一个结点
    if (i == 0) return L;                       // 若 i 为 0，则返回头结点
    if (i < 1) return nullptr;                  // 若 i 无效，则返回 nullptr
    while (p && j < i) {                        // 顺指针向后查找
        p = p->next;                            // 指向下一个结点
        j++;                                    // 计数器增加 1
    }
    return p;                                   // 返回第 i 个结点
}
```

## 4. 按值查找结点

在单链表中从第一个结点出发，顺指针 `next` 域逐个向下搜素，直到找到数据域值为 `e` 的结点为止，若某个结点的值等于给定值 `e` ，返回该结点的指针；否则若整个单链表中没有值为给定值的结点，则返回最后一个结点的指针域 `nullptr`。

按值查找结点的时间复杂度为`O(n)`。

```c++
LNode *LocateElem(LinkList L, ElemType e) {     // L 为带头结点的单链表的头指针
    LNode *p = L->next;                         // p 指向第一个结点
    while (p && p->data != e) {                 // 顺指针向后查找
        p = p->next;                            // 指向下一个结点
    }
    return p;                                   // 返回结点指针
}
```

## 5. 插入结点

插入结点操作将值为 `x` 的新结点插入到单链表的第 `i` 个位置上。先检查插入位置的合法性，然后查找待插入位置的前驱结点，即第 `i-1` 个结点，再在其后插入新结点。

再给定的结点后面插入新结点的时间复杂度仅为`O(1)`,但由于查找第 `i-1` 结点所需的时间复杂度为 `O(n)` ，因此插入结点的总计时间复杂度为`O(n)`。

关键代码：

```c
p=GetElem(L,i-1);  //查找第i-1个结点
s->next=p->next;   //新结点指向第i个结点
p->next=s;        //第i-1个结点指向新结点
```

算法实现：

```c++
LinkList ListInsert(LinkList &L, int i, ElemType x) {  // 在带头结点的单链表 L 中的第 i 个位置插入值为 x 的新结点
    LNode *p = GetElem(L, i - 1);                      // 查找第 i-1 个结点
    if (!p) return nullptr;                             // i 值不合法
    LNode *s = new LNode;                               // 创建新结点
    s->data = x;                                        // 赋值
    s->next = p->next;                                  // 新结点指向第 i 个结点
    p->next = s;                                        // 第 i-1 个结点指向新结点
    return L;                                           // 返回头结点
}
```

**扩展**：对某一结点进行前插操作：前插操作可以转化为后插操作

关键代码：

```c
// 先交换指针域，再交换数据域
s->next=p->next;   //新结点指向第i个结点
p->next=s;        //第i-1个结点指向新结点
temp=p->data;     //交换数据域
p->data=s->data;
s->data=temp;
```

## 6. 删除结点

删除结点操作将单链表中的第 `i` 个结点删除。先检查删除位置的合法性，然后查找待删除位置的前驱结点，即第 `i-1` 个结点，再删除第 `i` 个结点。

假设结点 `*p` 为找到的待删除结点的前驱结点，结点 `*q` 为待删除结点，为实现这一逻辑关系的变化，仅需修改 `*p` 的指针域，即将 `*p->next` 指向 `*q->next`，然后释放结点 `*q` 的空间。

删除结点的时间复杂度为`O(1)`，但查找第 `i-1` 结点所需的时间复杂度为 `O(n)` ，因此删除结点的总计时间复杂度为`O(n)`。

关键代码：

```c
p=GetElem(L,i-1);  //查找第i-1个结点
q=p->next;         //q指向第i个结点
p->next=q->next;   //删除第i个结点
free(q);           //释放结点空间
```

算法实现：

```c++
LinkList ListDelete(LinkList &L, int i) {              // 在带头结点的单链表 L 中删除第 i 个结点
    LNode *p = GetElem(L, i - 1);                      // 查找第 i-1 个结点
    if (!p) return nullptr;                             // i 值不合法
    LNode *q = p->next;                                 // q 指向第 i 个结点
    if (!q) return nullptr;                             // i 值不合法
    p->next = q->next;                                  // 删除第 i 个结点
    delete q;                                           // 释放结点空间
    return L;                                           // 返回头结点
}
```

**扩展**：删除结点 p
要删除结点 p，可以先将其后继结点的值赋予其自身，再删除 p 的后继结点
关键代码：

```c
q=p->next;         //q指向第*p的后继结点
p->data=q->data;   //将*p的后继结点的值赋予*p（交换数据域）
p->next=q->next;   //令q结点断链
free(q);           //释放q的结点空间
```

算法实现：

```c++
LinkList DeleteNode(LinkList &L, LNode *p) {           // 在带头结点的单链表 L 中删除结点 p
    if (!p) return nullptr;                            // p 为空
    LNode *q = p->next;                                // q 指向 p 的后继结点
    if (!q) return nullptr;                            // p 为尾结点
    p->data = q->data;                                 // 将 p 的后继结点的值赋予 p
    p->next = q->next;                                 // 令 q 结点断链
    delete q;                                          // 释放 q 的结点空间
    return L;                                          // 返回头结点
}
```

## 7. 求表长

求表长操作返回带头结点的单链表的长度，即链表中数据元素的个数。为此需要设置一个计数器，从头结点开始，依次遍历链表中的每个结点，直到遇到尾结点为止。

# 总结

单链表是一种常用的数据结构，其操作的时间复杂度与链表的长度成正比。熟练掌握单链表的基本操作，对于理解其他链表结构的操作有很大帮助。
