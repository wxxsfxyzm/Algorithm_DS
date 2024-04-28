# 深度优先搜索(DFS)

与广度优先搜索不同，深度优先搜索类似于树的先序遍历，如其名称中所含的“深度”一样，它会尽可能“深”地搜索每一个分支。

- 算法基本思想：
  - 从图中某个顶点 v 出发，访问此顶点，然后从 v 的未被访问的邻接点出发深度优先搜索图，直至图中所有和 v 有路径相通的顶点都被访问到。
  - 若此时图中尚有顶点未被访问，则另选图中一个未曾被访问的顶点作为起始点，重复上述过程，直至图中所有顶点都被访问到为止。

算法过程如下：

```cpp
bool visited[MAX_VERTEX_NUM];               // 访问标志数组
void DFSTransverse(Graph G) {               // 深度优先搜索遍历图G
    for (v = 0; v < G.vexnum; v++)          // 访问标志数组初始化
        visited[v] = false;                 // 所有顶点的访问标志设置为未访问
    for (v = 0; v < G.vexnum; v++)          // 依次检查每个顶点
        if (!visited[v])                     // 若顶点v未访问
            DFS(G, v);                       // 从顶点v开始深度优先搜索
}
void DFS(Graph G, int v) {                  // 从顶点v开始深度优先搜索
    visit(v);                               // 访问顶点v
    visited[v] = true;                      // 设置访问标志
    for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
        if (!visited[w])                    // w为v的尚未访问的邻接顶点
            DFS(G, w);                      // 从顶点w开始深度优先搜索
}
```
