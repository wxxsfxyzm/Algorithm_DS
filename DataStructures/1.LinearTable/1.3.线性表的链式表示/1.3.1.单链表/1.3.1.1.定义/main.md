# 单链表的定义

线性表的链式存储又称单链表，它是通过一组任意的存储单元来存储线性表中的数据元素。为了建立数据元素之外的线性关系，对每个链表结点，除了存放元素自身的信息外，还需要存放一个指示其后继结点的指针。单链表的结构如下表所示

| data | next |
| ---- | ---- |

其中，data 为数据域，存放数据元素；next 为指针域，存放后继结点的地址。

单链表的存储结构定义如下：

教材定义：

```c
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
```

力扣定义：

```c++
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
