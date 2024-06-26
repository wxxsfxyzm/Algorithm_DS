# 线性表的定义

线性表是具有相同数据类型的 n (n ≥ 0) 个数据元素的*有限序列*。n = 0 时，称为空表。
若用 L 命名线性表，则其一般表示为：
L = ($a_1$, $a_2$, ..., $a_i$, ..., $a_n$)
其中，L 为表名，ai 是表中的元素，i 是元素的序号，n 是表的长度。
特别的，a1 称为表头元素，an 称为表尾元素。
除第一个元素外，每个元素有且仅有一个直接前驱；除最后一个元素外，每个元素有且仅有一个直接后继。

以上就是线性表的逻辑特性，这种线行有序的逻辑结构正是线性表名字的由来。

因此，线性表的特点有下：

- 表中元素的个数有限
- 表中元素具有逻辑上的循序性，表中元素有先后次序
- 表中元素都是数据元素，每个元素都是单个元素
- 表中元素的*数据类型*相同，这意味着每个元素都占据*相同大小*的存储空间
- 表中元素具有抽象性，即仅讨论元素间的*逻辑关系*，而不考虑元素的具体内容

**注意 1**： 线性表是一种逻辑结构，表示元素之间一对一的相邻关系，顺序表和链表是指存储结构，两者属于*不同层面的概念*，不能混为一谈。

**注意 2**：线性表的元素个数是有限的，但是线性表的长度是可以无限的，因为线性表的长度是指线性表中元素的个数，而不是线性表的存储空间大小。

**注意 3**：线性表的元素类型是相同的，但是元素的类型可以是任意的，例如整型、浮点型、字符型、结构体等。

**注意 4**：线性表的元素是具有逻辑上的次序关系的，但是元素的次序是从**1**开始的，而不是从**0**开始的。
