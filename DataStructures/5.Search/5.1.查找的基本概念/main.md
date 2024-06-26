# 查找

## 查找的基本概念

1. 查找
   - 在数据集合中寻找满足某种条件的数据元素的过程被称为查找。
   - 查找的结果一般分为两种
     - 查找成功，即在数据集合中找到了满足条件的数据元素。
     - 查找失败，即在数据集合中没有找到满足条件的数据元素。
2. 查找表（查找结构）
   - 用于查找的数据集合称为查找表。
   - 它由同一类型的数据元素（或记录）组成，可以是一个数组或链表等数据类型。
     对查找表经常进行的操作有：
     &#9312; 查询某个特定的数据元素是否在查找表中。
     &#9313; 检索满足某种条件的数据元素的各种属性
     &#9314; 插入一个新的数据元素
     &#9315; 删除一个数据元素
3. - 静态查找表
     - 若一个查找表在查找过程中，表的内容不发生变化，即若只涉及上述 &#9312; 和 &#9313; 操作，不需要动态修改查找表，则称该查找表为静态查找表。
     - 适合静态查找表的查找方法有顺序查找、折半查找、散列查找等
   - 动态查找表
     - 若一个查找表在查找过程中，表的内容会发生变化，
     - 适合动态查找表的查找方法有二叉排序树（平衡二叉树、B-树、红黑树）、散列查找等。
4. 关键字
   数据元素中唯一标识该元素的某个数据项的值，使用基于关键字的查找，查找结果应该是唯一的。例如：在由一个学生元素构成的数据数据集合中，学生元素中“学号”这一数据项的值就是关键字，唯一地标识一名学生。
5. 平均查找长度 ASL
   在查找过程中，一次查找的长度指的是需要比较的关键字次数，而平均查找长度（Average Search Length，ASL）是指所有查找过程中进行关键字的比较次数的平均值，其数学定义为
   $$
   ASL = \sum_{i=1}^{n} P_i \cdot c_i
   $$
   其中，n 是查找表的长度， $P_i$ 是查找表中第 $i$ 个数据元素的概率，一般认为每个数据元素的查找概率均等，即 $P_i = \frac{1}{n}$ ； $c_i$ 是查找第 $i$ 个数据元素时所需的比较次数。
   平均查找长度是衡量查找算法效率的重要指标，它的值越小，查找效率越高。
