# 单链表的定义

线性表的链式存储又称单链表

```c
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
```
