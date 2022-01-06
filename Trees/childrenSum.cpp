#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
void printArr(vector<T> &a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n";
}

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
}

int isSumProperty(Node *root)
{
    int left_val = 0, right_val = 0;
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 1;

    else
    {
        if (root->left != NULL)
        {
            left_val = root->left->data;
        }
        if (root->right != NULL)
        {
            right_val = root->right->data;
        }
        if ((root->data == left_val + right_val) &&
            isSumProperty(root->left) && isSumProperty(root->right))
        {
            return 1;
        }
        else
            return 0;
    }
}

int isSumPropertyi(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left && curr->right)
        {
            if (curr->data != curr->left->data + curr->right->data)
            {
                return false;
            }
            q.push(curr->left);
            q.push(curr->right);
        }
        else if (!curr->left && curr->right)
        {
            if (curr->data != curr->right->data)
            {
                return false;
            }
            q.push(curr->right);
        }
        else if (curr->left && !curr->right)
        {
            if (curr->data != curr->left->data)
            {
                return false;
            }
            q.push(curr->left);
        }
    }
    return true;
}

int main()
{
    // inout();
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->right->left = new Node(6);
    // root->right->left = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);

    // Node *root = new TreeeNode(70);

    // Node *root = new Node(10);
    // root->left = new Node(6);
    // root->right = new Node(8);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(11);
    // root->right->right->right = new Node(12);

    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->left->left = new Node(30);

    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(10);
    root->right->right = new Node(2);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(3);
    root->right->left->right = new Node(10);

    cout << isSumProperty(root);
    cout << isSumPropertyi(root);

    return 0;
}