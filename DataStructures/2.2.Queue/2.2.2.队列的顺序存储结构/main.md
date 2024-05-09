# 队列的顺序存储结构

## 队列的顺序存储结构

队列的顺序存储结构是利用一组地址连续的存储单元依次存储队列中的数据元素。队列的顺序存储结构通常由两个指针（队头指针 front 和队尾指针 rear）和一个一维数组组成。

队头指针 front 指向队头元素，队尾指针 rear 指向队尾元素的下一个位置（可以有不同定义，如：也可以指向队尾元素），对于不同的定义，出队和入队操作的实现也有所不同。

### 队列的顺序存储结构的初始化及操作

```cpp
#define MAXSIZE 100             // 定义队列中元素的最大个数
typedef struct {
    ElemType data[MAXSIZE];     // 用数组存储队列元素
    int front, rear;            // 队头指针和队尾指针
} SqQueue;
```

- 初始状态（队空条件）：Q.front = Q.rear = 0
- 进队操作：队不满时，先送值到队尾元素，再将队尾指针+1
- 出队操作：队不空时，先取队头元素值，再将队头指针+1

**注意**：队列的初始状态下，有 `Q.front == Q.rear == 0` 成立，但该条件能够作为判断队空的条件，但是 `Q.rear == MaxSize` 不能作为判断队满的条件，因为随着 front 指针的向后移动队列中的元素个数可能小于 `MaxSize`。当 front 和 rear 指针都指向最后一个元素时，队列中仅有一个元素，但是仍然满足 `Q.rear == MaxSize`。这时候队列出现上溢出，但是这样的溢出并不是真正的溢出，前面的 data 数组全都空着，所以这是一种“假溢出”。

## 循环队列

循环队列的引入就是为了解决顺序队列假溢出的缺点，将队列的存储空间看作是一个环，即当 rear 指针指向数组的最后一个位置时，若有新元素要入队，则可以将其插入到数组的第一个位置。
当队头指针 `Q.front = MaxSize - 1` 后，在前进一个位置就自动到 0，这可以利用除法取余运算 `%` 实现。

- 初始状态：Q.front = Q.rear = 0
- 队首指针进 1：Q.front = (Q.front + 1) % MaxSize
- 队尾指针进 1：Q.rear = (Q.rear + 1) % MaxSize
- 队列长度：(Q.rear - Q.front + MaxSize) % MaxSize

- 队列的判空条件：Q.front == Q.rear

### 循环队列区分队空和队满的三种处理方式

1. 牺牲一个单元来区分队空和队满，入队时少用一个队列单元，这是一种较为普遍的做法，约定以“队头指针在队尾指针的下一个位置作为队满的标志”

   - 队空条件：Q.front == Q.rear
   - 队满条件：(Q.rear + 1) % MaxSize == Q.front
   - 队列长度：(Q.rear - Q.front + MaxSize) % MaxSize

2. 类型中增设表示元素个数的数据成员。这样队空的条件为 `Q.size == 0`，队满的条件为 `Q.size == MaxSize`，这两种情况都有 `Q.front == Q.rear`。但是这样的做法会增加存储空间的开销。

3. 类型中增设 `tag` 标志，以区分队空和队满。`tag` 等于 0 时，若因删除导致 `Q.front == Q.rear`，则为队空；`tag` 等于 1 时，若因插入导致 `Q.front == Q.rear`，则为队满。这样的做法会增加一个存储空间的开销。

### 循环队列的操作

1. 初始化操作

```cpp
void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;   // 初始化首/队尾指针
}
```

2. 判队空操作

```cpp
bool isEmpty(SqQueue Q){
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}
```

3. 入队操作

```cpp
bool EnQueue(SqQueue &Q, ElemType x){
    if ((Q.rear + 1) % MaxSize == Q.front)  // 队满
        return false;
    Q.data[Q.rear] = x;                     // 新元素入队
    Q.rear = (Q.rear + 1) % MaxSize;        // 队尾指针后移
    return true;
}
```

4. 出队操作

```cpp
bool DeQueue(SqQueue &Q, ElemType &x){
    if (Q.rear == Q.front)                  // 队空
        return false;
    x = Q.data[Q.front];                    // 队头元素出队
    Q.front = (Q.front + 1) % MaxSize;      // 队头指针后移
    return true;
}
```
