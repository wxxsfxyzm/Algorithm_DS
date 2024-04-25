# 顺序栈的基本运算

## 1. 初始化栈

```c
void InitStack(SqStack &S) {
    S.top = -1; // 初始化栈顶指针
}
```

## 2. 判空操作

```c++
bool StackEmpty(SqStack S) {
    return S.top == -1; // 栈空条件
}
```

## 3. 进栈操作

```c++
bool Push(SqStack &S, ElemType e) {
    if (S.top == MAXSIZE - 1) // 栈满
        return false;
    S.data[++S.top] = e; // 指针先加 1，再入栈
    return true;
}
```

**注意**：当栈不满时，栈顶指针先加 1，再将元素 e 存入栈顶指针所指示的位置。

## 4. 出栈操作

```c++
bool Pop(SqStack &S, ElemType &e) {
    if (S.top == -1) // 栈空
        return false;
    e = S.data[S.top--]; // 先出栈，指针再减 1
    return true;
}
```

## 5. 取栈顶元素

```c++
bool GetTop(SqStack S, ElemType &e) {
    if (S.top == -1) // 栈空
        return false;
    e = S.data[S.top]; // 栈顶元素
    return true;
}
```

**注意 1**：仅为读取栈顶元素，并没有出栈操作，因此原栈顶元素依然保留在栈中。

**注意 2**：这里 `top` 指向的是栈顶元素，所以进栈操作为 `S.data[++S.top] = e`，出栈操作为 `e = S.data[S.top--]`。若栈顶指针指向栈顶元素的下一个位置，则进栈操作为 `S.data[S.top++] = e`，出栈操作为 `e = S.data[--S.top]`。
