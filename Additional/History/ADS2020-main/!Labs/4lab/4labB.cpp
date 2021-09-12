#include <bits/stdc++.h>
#define ll long long
#define sep " "
using namespace std;

static int cnt = 0;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
        {
            node = new Node(data);
            return node;
        }
        if (node->data == data)
            return node;
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }

    void inOrder(Node *node)
    {
        static int cnt = 0;
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    int nodeCount(Node *node)
    {
        if (node->left == NULL && node->right == NULL)
            return 1;
        int left, right;
        if (node->left != NULL)
            left = nodeCount(node->left);
        else
            left = 0;
        if (node->right != NULL)
            right = nodeCount(node->right);
        else
            right = 0;
        return left + right + 1;
    }

    int heightOfTree(Node *node)
    {
        int left, right;
        if (node->left != NULL)
            left = heightOfTree(node->left);
        else
            left = -1;
        if (node->right != NULL)
            right = heightOfTree(node->right);
        else
            right = -1;
        int mx = max(left, right);
        return mx + 1;
    }

    Node *findMin(Node *node)
    {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node *findMax(Node *node)
    {
        while (node->right != NULL)
            node = node->right;
        return node;
    }

    Node *deleteNode(Node *node, int data)
    {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else
        {
            if (node->left == NULL && node->right == NULL)
                return NULL;
            else if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            else
            {
                Node *tmp = findMax(node->left);
                node->data = tmp->data;
                node->left = deleteNode(node->left, tmp->data);
            }
        }
        return node;
    }
};

int main()
{
    BST *bst = new BST();
    // bst->root = bst->insert(bst->root, 15);
    int n;
    // freopen("test1.txt", "r", stdin);
    cin >> n;
    while (n != 0)
    {
        bst->root = bst->insert(bst->root, n);
        cin >> n;
    }

    cout << bst->nodeCount(bst->root);

    return 0;
}