#include <bits/stdc++.h>
#include "../DSA_Git/Linked_List/SLL.h"
using namespace std;

Node *getmid(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *list1, Node *list2)
{
    if (list1 == NULL || list2 == NULL)
    {
        return (list1 != NULL) ? list1 : list2;
    }

    Node *c1 = list1, *c2 = list2;
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (c1 != NULL && c2 != NULL)
    {
        if (c1->data < c2->data)
        {
            prev->next = c1;
            c1 = c1->next;
        }
        else
        {
            prev->next = c2;
            c2 = c2->next;
        }
        prev = prev->next;
    }
    prev->next = (c1 != NULL) ? c1 : c2;
    return dummy->next;
}

Node *mergeSort_List(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *mid = getmid(head);
    Node *newHead = mid->next;
    mid->next = NULL;
    Node *l1 = mergeSort_List(head);
    Node *l2 = mergeSort_List(newHead);

    return merge(l1, l2);
}

bool check(Node *head)
{
    while (head->next->next)
    {
        if (head->data > head->next->data)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

inline void solve()
{
    Node *head = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pushBack(head, x);
    }
    printList(head);
    head = mergeSort_List(head);
    // cout << check(head) <<endl;
    printList(head);
    // cout << getmid(head)->data;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    // int t;
    // scanf("%d", &t);
    // while (t--)
    {
        solve();
    }
    return 0;
}
