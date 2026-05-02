#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        right = left = nullptr;
    }
};

static int idx = -1;

TreeNode *buildTree(vector<int> &nums)
{
    idx++;

    if (nums[idx] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(nums[idx]);
    root->left = buildTree(nums);  // left subtree
    root->right = buildTree(nums); // right subtree

    return root;
}

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " -> ";
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;

    q.push(root);

    while (q.size() > 0)
    {
        TreeNode *curr = q.front();

        q.pop();

        cout << curr->data << " ";

        if (curr->left != nullptr)
            q.push(curr->left);

        if (curr->right != nullptr)
            q.push(curr->right);
    }
}

int main()
{
    vector<int> nums = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    TreeNode *root = buildTree(nums);
    // cout << root->right->left->data<<" "<<endl;

    // preorder(root);
    // postorder(root);
    // inorder(root);
    levelOrder(root);
    return 0;
}