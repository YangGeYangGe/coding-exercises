# 二叉树的常见算法

### 二叉树的遍历算法
-	先序遍历：先访问本节点，再访问该节点的左孩子和右孩子
-	中序遍历：先访问左孩子，再访问本节点，最后访问右孩子
-	后序遍历：先访问左右孩子，最后访问本节点
-	层次遍历：按照输的每层（高度）进行遍历


树的节点的数据结构常声明为：  
```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}
```

#### (1). 先序遍历
沿着最左侧通路自顶而下访问各个节点，自底而上遍历对应的右子树。<br>
递归版本：
```cpp
void preOrderTraversal(vector<int> &store, TreeNode *root)
{
    if (!root) return;
    store.push_back(root->val);
    preOrderTraversal(store, root->left);
    preOrderTraversal(store, root->right);
}
```

迭代版本
```cpp
void preOrderTraversal(vector<int> &store, TreeNode *root) 
{
    stack<TreeNode *> S;
    S.push(root);
    while (!S.empty()) {
        TreeMpde *currNode = S.top();
        S.pop();
        if (currNode) {
            store.push_back(currentNode->val);
            S.push(currNode->right);
            S.push(currNode->left);
        }
    }
    return;
}
```

#### (2). 中序遍历
```cpp
inOrderTraversal(vector<int> &store, TreeNode *root)
{
    if (!root) return;
    inOrderTraversal(store, root->left);
    store.push_back(root->val);
    inOrderTraversal(store, root->right);
}

```

```cpp
void inorderTraversal(vector<int> &store, TreeNode *root)
{
    stack<TreeNode *> S;
    while (root || !S.empty()) {
        while (root) {
            S.push(root);
            root = root->left;
        }
        TreeNode *curr_node = S.top();
        S.pop();
        store.push_back(curr_node->val);
        root = curr_node->right;
    }
    return;
}

```

#### (3). 后序遍历
```cpp
void postOrderTraversal(vector<int> &store, TreeNode *root)
{
    if (!root) return;
    postOrderTraversal(store, root->left);
    postOrderTraversal(store, root->right);
    store.push_back(root->val);
}
```
```cpp
void postOrderTraversal(vector<int> &store, TreeNode *root) {
    stack<TreeNode *> S;
    S.push(root);
    while(!S.empty()) {
        TreeNode *curr_node = S.top();
        S.pop();
        if(curr_node) {
            store.push_back(curr_node->val);
            S.push(curr_node->left);    //右孩子优先，所以左孩子先入栈
            S.push(curr_node->right);
        }
    }
    std::reverse(store.begin(), store.end());   //逆序列即为所求
    return;
}
```