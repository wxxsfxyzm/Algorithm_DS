# 栈的链式存储结构

采用链式存储的栈称为链栈，链栈的优点是便于多个共享存储空间和提高效率，且不存在栈满上溢的情况。通常采用单链表实现，并规定所有操作都是在单链表的表头进行的。这里规定链栈没有头结点，`Lhead` 指向栈顶元素

栈的链式存储结构可以描述为

```cpp
typedef struct LinkNode{    // 链栈结点类型
    ElemType data;
    struct LinkNode *next;
}*LinkStack;
```
