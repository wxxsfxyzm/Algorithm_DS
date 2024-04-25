# 单链表的基本操作

## 1.采用头插法建立单链表

头插法建立单链表的过程是：依次读入数据元素，每读入一个数据元素，就将其插入到链表的头结点之后，使其成为新的头结点。

C 语言使用 malloc 分配内存空间，C++使用 new 分配内存空间。

单链表的定义见[单链表的定义](../1.3.1.1.定义/main.md#单链表的定义)

```c++
LinkList CreateListHead(LinkList &L, int n) {
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

## 2.采用尾插法建立单链表

若希望单链表中的数据元素的顺序与输入的顺序一致，可以采用尾插法建立单链表。

尾插法建立单链表的过程是：依次读入数据元素，每读入一个数据元素，就将其插入到链表的尾结点之后，使其成为新的尾结点。

```c++
LinkList CreateListTail(LinkList &L, int n) {
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
