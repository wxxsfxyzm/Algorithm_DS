# 队列的链式存储结构

队列的链式表示称为链队列，它实际上是一个同时带有队头指针和队尾指针的单链表。头指针指向队头结点，尾指针指向队尾结点，即单链表的最后一个结点（注意与链式存储的不同）

## 队列的链式存储类型

```cpp
typedef struct LinkNode{    // 链队列结点类型
    ElemType data;
    struct LinkNode *next;
}
typedef struct{             // 队列的链式存储结构
    LinkNode *front, *rear; // 队头指针和队尾指针
}LinkQueue;
```

当 `Q.front == nullptr` 且 `Q.rear == nullptr` 时，链式队列为空

出队时，首先判断队列是否为空，若不空，则取出队头元素，将其从链表中摘除，并让 `Q.front` 指向下一个结点（若该结点为最后一个结点，则置 `Q.front` 和 `Q.rear` 都为 `nullptr`）。

入队时，先建立一个新结点，将该结点插入到链表的尾部，并改让 `Q.rear` 指向这个新插入的结点（若原队列为空队列，则令 `Q.front` 也指向该结点）。

不带头结点的链式队列在操作上往往比较麻烦，因此通常将链式队列设计成一个带头节点的单链表，这样插入和删除操作就能够得到统一。

用单链表进行表示的链式队列特别适合于数据元素变动比较大的情形，而且不存在队列满且产生溢出的问题。另外，假如程序中要使用多个队列，与多个栈的情形一样，最好使用链式队列，这样就不会出现存储分配不合理和“溢出”的问题。

## 链式队列的初始化操作

1. 初始化

```cpp
void InitQueue(LinkQueue &Q){
    // use malloc in C
    // Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front = Q.rear = new LinkNode();
    Q.front -> next = nullptr;
}
```

2. 判队空

```cpp
bool isEmpty(LinkQueue Q){
    if (Q.front == Q.rear){}
}
```

3. 入队

```cpp
void EnQueue(LinkQueue &Q, ElemType x){
    // use malloc in C
    // LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    LinkNode *s = new LinkNode();
    s -> data = x;
    s -> next = nullptr;
    Q.rear -> next = s;
    Q.rear = s;
}
```

4. 出队

```cpp
bool DeQueue(LinkQueue &Q, ElemType &x){
    if (Q.front == Q.rear)
        return false;                       // 空队
    LinkNode *p = Q.front -> next;
    x = p -> data;
    Q.front -> next = p -> next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    // use free in C
    // free(p);
    return true;
}
```
