# 顺序查找和折半查找

## 顺序查找

顺序查找又称为线性查找，他对线性表和顺序表都是适用的。对于顺序表，可通过数组下标递增来顺序扫描每个元素；对于链表，可通过指针 `next` 来依次扫描每个元素。顺序查找通常分为对一般的无序线性表的顺序查找和对按关键字有序的线性表的顺序查找。

### 一般的无序线性表的顺序查找

对于一般的无序线性表，顺序查找的过程是：从头到尾依次扫描线性表中的每个元素，直到找到所查找的元素为止。如果查找成功，则返回该元素在表中的位置；如果查找失败，则返回查找失败的信息。

算法如下：

```cpp
typedef struct {
    ElemType *elem;     // 存储空间基址
    int length;         // 当前长度
} SSTable;
int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;   // 哨兵
    for (int i = ST.length; ST.elem[i] != key; --i);// 从后往前查找
    return i;           // 查找成功返回位置，查找失败返回 0
}
```

#### 哨兵的使用

在上述算法中，将 `ST.elem[0]` 设置为哨兵，这样可以避免在查找过程中每次都要判断是否越界，因为设置了哨兵以后可以知道，遍历到哨兵一定是遍历到了最后一个元素。故满足 `i==0` 时，循环一定会跳出。
如果不设置这个哨兵，则遍历时无法知道何时结束，需要在遍历每一个元素时都需要进行一次越界判断。

总而言之，引入“哨兵”可以避免很多不必要的判断语句

#### 查找效率分析

对于有 `n` 个元素的表，给定值 `key` 与表中第 `i` 个元素相等，即定位第 `i` 个元素时，需要进行 `n-i+1` 次关键字的比较，即 $C_i=n-i+1$ 。查找成功时，顺序查找的平均长度为

$$
ASL_{成功}=\sum_{i=1}^{n} P_i(n-i+1)
$$

当每个元素的查找概率相等，即 $P_i=\frac{1}{n}$ 时，有

$$
ASL_{成功}=\sum_{i=1}^{n} P_i(n-i+1)=\frac{n+1}{2}
$$

查找不成功时，与表中各关键字的比较次数为 n+1 ，即 $ASL_{不成功}=n+1$ 。

通常，查找表中记录的查找概率不是军风格的，若能预先得知每个记录的查找概率，则应该按照各记录的查找概率来进行排序，使概率大的记录排在前面，这样可以提高查找效率。

#### 总结

综上，顺序查找的缺点在于当 n 较大时，ASL 的值会较大，降低了效率；优点是对数据元素的存储没有要求，顺序存储和链式存储都可以。其次，对表中记录的有序性也没有要求，无论记录是否按照关键词有序，均可以使用

**注意**：对线性的链表只能顺序查找（链表不能按照索引访问）

### 有序线性表的顺序查找

若在查找之前就知道表是按照关键词有序的，则查找失败时可以不用再比较到表的另一端，可以直接返回查找失败的信息，从而降低顺序查找失败的 ASL。

假设表 L 按照关键词从小到大排列，查找的顺序是从前往后，待查找元素的关键字为 key，当查找到第 i 个元素时，发现第 i 个元素对应的关键字小于 key，但第 i+1 个元素的关键字大于 key，这时就可以判断表中不存在关键字为 key 的元素，直接返回查找失败的信息。

#### 顺序查找的查找效率分析

对于有序表，查找成功时，平均查找长度和一般线性表的顺序查找一样，区别在查找失败时，查找指针一定走到了某个失败结点。这些失败结点是我们虚构的空结点，世界上是不存在的，所以到达失败结点时所查找的长度等于它上面的一个结点所在的层数。
查找不成功的 ASL 在相等查找概率下为：

$$
ASL_{不成功}=\sum_{j=1}^{n} q_j(l_j-1)=\frac{1+2+...+n+n}{n+1}=\frac{n}{2}+\frac{n}{n+1}
$$

其中，$q_j$ 为查找到第 j 个失败结点的概率，在相等查找概率的情形下，它为 $\frac{1}{n+1}$ 。$l_j$ 为第 j 个失败结点所在的层数。

**注意 1**：有序线性表的顺序查找和折半查找的思路不同，有序线性表的顺序查找是通过比较关键字的大小来确定是否继续查找，而折半查找是通过比较关键字的大小来确定查找的范围。

**注意 2**：有序线性表的顺序查找中的线性表可以是链式存储结构

## 折半查找

折半查找又称二分查找，仅适用于有序的顺序表。

### 基本思想

折半查找的思想是：

- 首先将给定值 key 与表中中间位置的元素比较，若相等，则查找成功，返回该元素所在的位置。
- 若不等，则所需查找的元素只能在中间元素以外的前半部分或者后半部分，然后缩小一半查找范围继续查找，直到找到为止，或确定表中没有待查找的元素，则查找失败，返回查找失败的信息。

算法如下：

```cpp
int Binary_Search(SeqList L, ElemType key) {
    int low = 1, high = L.length, mid;
    while (low <= high) {
        mid = (low + high) / 2;                     // 取中间位置
        if (L.elem[mid] == key) return mid;         // 查找成功,返回位置
        else if (L.elem[mid] > key) high = mid - 1; // 缩小查找范围
        else low = mid + 1;                         // 缩小查找范围
    }
    return -1;                                      // 查找失败,返回 -1
}
```

### 折半查找的查找效率分析

折半查找的判定树是一棵平衡二叉树。
用折半查找到给定值的比较次数最多不会超过树的高度，在等概率查找时，查找成功的平均查找长度为：

$$
ASL=\frac{1}{n}\sum_{i=1}^{n} l_i=\frac{1}{n}(1×1+2×2+...+h×2^{h-1})= \frac{n+1}{n}\log_2 {(n+1)}-1≈\log_2 {(n+1)}-1
$$

式中， $l_i$ 为查找到第 i 个元素的比较次数， $h$ 为树的高度，而且元素个数为 n 时，树高 $h=\lceil \log_2{(n+1)} \rceil$ 。
所以折半查找的时间复杂度为 $O(\log_2 n)$ ，平均情况下比顺序查找的效率要高。
