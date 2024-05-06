# 各种排序算法的性能比较

<table>
    <tr>
        <td rowspan="2"><b>算法种类</b></td>
        <td colspan="3"><b>时间复杂度</b></td>
        <td rowspan="2"><b>空间复杂度</b></td>
        <td rowspan="2"><b>是否稳定</b></td>
    </tr>
    <tr>
        <td><b>最好情况</b></td>
        <td><b>平均情况</b></td>
        <td><b>最坏情况</b></td>
    </tr>
    <tr>
        <td>直接插入排序</td>
        <td>$O(n)$</td>
        <td>$O(n^2)$</td>
        <td>$O(n^2)$</td>
        <td>$O(1)$</td>
        <td>稳定</td>
    </tr>
    <tr>
        <td>冒泡排序</td>
        <td>$O(n)$</td>
        <td>$O(n^2)$</td>
        <td>$O(n^2)$</td>
        <td>$O(1)$</td>
        <td>稳定</td>
    </tr>
    <tr>
        <td>简单选择排序</td>
        <td>$O(n^2)$</td>
        <td>$O(n^2)$</td>
        <td>$O(n^2)$</td>
        <td>$O(1)$</td>
        <td>不稳定</td>
    </tr>
    <tr>
        <td>希尔排序</td>
        <td colspan="3"></td>
        <td>$O(1)$</td>
        <td>不稳定</td>
    </tr>
    <tr>
        <td>快速排序</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(n^2)$</td>
        <td>$O(log_2n)$</td>
        <td>不稳定</td>
    </tr>
    <tr>
        <td>堆排序</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(1)$</td>
        <td>不稳定</td>
    </tr>
    <tr>
        <td>2路归并排序</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(nlog_2n)$</td>
        <td>$O(n)$</td>
        <td>稳定</td>
    </tr>
    <tr>
        <td>基数排序</td>
        <td>$O(d(n+r))$</td>
        <td>$O(d(n+r))$</td>
        <td>$O(d(n+r))$</td>
        <td>$O(r)$</td>
        <td>稳定</td>
    </tr>
</table>
