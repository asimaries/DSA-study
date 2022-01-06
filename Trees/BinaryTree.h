#ifndef Binary_Tree_H
#define Binary_Tree_H

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

template <typename T>
void printArr(vector<T> &a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n";
}

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.in", "w", stdout);
#endif
}

// printTree(root, 0, true)
void printTree(Node *root, int space = 0, bool side = true)
{
    if (root == NULL)
        return;

    space++;
    printTree(root->right, space, true);
    for (int i = 1; i < space; i++)
    {
        printf("    ");
    }
    if (side == true)
        printf("/ ");
    else
        printf("\\ ");
    printf("%d\n", root->val);

    printTree(root->left, space, false);
}

void pre_order(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << ' ';
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    cout << root->val << ' ';
    in_order(root->right);
}

void post_order(Node *root)
{
    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->val << ' ';
}

int tree_Height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(tree_Height(root->left), tree_Height(root->right)) + 1;
}

#endif