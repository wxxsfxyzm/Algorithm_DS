# 单链表的基本操作

## 1.采用头插法建立单链表

头插法建立单链表的过程是：依次读入数据元素，每读入一个数据元素，就将其插入到链表的头结点之后，使其成为新的头结点。

```c++

LinkList CreateListHead(LinkList &L, int n) {
    LNode *s;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    for (i = 0; i < n; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = i;
        s->next = L->next;
        L->next = s;
    }
    return L;
}
```

## 2.采用尾插法建立单链表

尾插法建立单链表的过程是：依次读入数据元素，每读入一个数据元素，就将其插入到链表的尾结点之后，使其成为新的尾结点。

```c++

LinkList CreateListTail(LinkList &L, int n) {
    LNode *s, *r;
    int i;
    L = (LinkList)malloc(sizeof(LNode));
    r = L;
    for (i = 0; i < n; i++) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = i;
        r->next = s;
        r = s;
    }
    r->next = nullptr;
    return L;
}
```
