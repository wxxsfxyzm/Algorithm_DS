#include <bits/stdc++.h>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, * LinkList;

LinkList DisCreat_2(LinkList& A) {
    LinkList B = new LNode;
    B->next = nullptr;
    LNode* ra = A, * p = A->next, * rb = B;
    A->next = nullptr;
    while (p != nullptr) {
        ra->next = p;
        ra = p;
        p = p->next;
        ra->next = nullptr;
        if (p != nullptr) {
            rb->next = p;
            rb = p;
            p = p->next;
            rb->next = nullptr;
        }
    }
    return B;
}


int main(int argc, char const* argv[])
{
    LinkList A = new LNode;
    A->next = nullptr;
    LinkList B;
    LNode* p = A;
    for (int i = 1; i <= 10; i++) {
        LNode* node = new LNode;
        node->data = i;
        node->next = nullptr;
        p->next = node;
        p = p->next;
    }
    B = DisCreat_2(A);
    p = A->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    p = B->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
