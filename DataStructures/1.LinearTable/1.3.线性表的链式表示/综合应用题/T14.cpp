#include <bits/stdc++.h>
using namespace std;

struct LNode {
    int data; // 数据域，根据实际需求可以改为其他类型
    LNode* next; // 指向下一个节点的指针
};

typedef LNode* LinkList; // LinkList是指向LNode的指针

class Solution {
public:
    LinkList Get_Common(LinkList A, LinkList B) {
        // A、B是递增有序的单链表，本算法求出A、B的公共元素产生单链表C
        LNode* p = A->next, * q = B->next, * r, * s;
        LinkList C = new LNode;
        r = C;
        while (p != nullptr && q != nullptr) {
            if (p->data < q->data) {
                p = p->next;
            }
            else if (p->data > q->data) {
                q = q->next;
            }
            else {
                s = new LNode;
                s->data = p->data;
                r->next = s;
                r = s;
                p = p->next;
                q = q->next;
            }
        }
        r->next = nullptr;
        return C;
    }
};

int main() {
    Solution S;
    LinkList A, B;
    LinkList C = S.Get_Common(A, B);

    return 0;
}