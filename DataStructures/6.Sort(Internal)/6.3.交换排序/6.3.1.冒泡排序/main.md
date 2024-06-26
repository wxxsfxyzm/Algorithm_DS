# 冒泡排序

冒泡排序较为简单，一般不会单独考察。

## 基本思想

- 冒泡排序的基本思想是：从后往前（或从前往后）两两比较相邻元素的值，若发现逆序则交换，直到没有逆序的相邻元素为止。这被称为第一趟冒泡，结果是将最小的元素交换到待排序列的第一个位置（或将最大的元素交换到待排序列的最后一个位置），关键字最小的元素像气泡一样逐渐上浮到顶端。（或关键字最大的元素如石头一般下沉到水底）。下一趟冒泡时，前一趟确定的最小元素不再参与比较，待排序列减少一个元素，直到所有元素排好序。
- 这样最多需要 $n-1$ 趟冒泡，每趟冒泡最多需要比较 $n-i$ 次，其中 $i$ 是当前趟数。

## 代码

```cpp
void BubbleSort(Elemtype a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                flag=true;
            }
            if(!flag) return;       // 若某趟冒泡没有发生交换，则说明已经有序
        }
    }
}
```

## 性能分析

1. 空间效率：冒泡排序是原地排序，空间复杂度为 $O(1)$。

2. 时间效率：当初始序列有序时，显然第一趟冒泡后 flag 依然为 false（本趟冒泡没有元素交换），从而直接跳出循环，比较次数为 n-1，移动次数为 0，从而最好情况下的时间复杂度为 $O(n)$；最坏情况下，初始序列逆序，需要进行 $n-1$ 趟冒泡，每趟冒泡的过程要进行 $n-i$ 次比较和移动，而且每次比较厚都必须移动元素 3 次来交换元素位置
   比较次数为：

   $$
   \sum_{i=1}^{n-1}(n-i)=\frac{n(n-1)}{2}
   $$

   移动次数为:

   $$
   \sum_{i=1}^{n-1}3(n-i)=\frac{n(n-1)}{2}
   $$

   从而最坏情况下的时间复杂度为 $O(n^2)$，其平均时间复杂度也为 $O(n^2)$。

3. 稳定性：冒泡排序是稳定的排序算法，当 i>j 且 a[i]=a[j] 时，不会交换 a[i] 和 a[j] 的位置。
   **注意**：冒泡排序中所产生的有序子序列一定是全局有序的（不同于直接插入排序），也就是说，有序子序列中的所有元素的关键字一定小于或大于无序子序列中所有元素的关键字，这样每趟排序都会将一个元素放置在其最终的位置上。
