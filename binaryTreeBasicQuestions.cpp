//You are given a Binary tree. You have to count and return the number of leaf nodes present in it.
void inOrder(BinaryTreeNode<int> *root, int &count) {
    if(root == NULL){
        return;
    }
    inOrder(root->left,count);
    if(root->left == NULL && root->right == NULL){
        count++;
    }
    inOrder(root->right , count);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int count = 0;
    inOrder(root,count);
    return count;
}


//find height of a given binary tree
int height(Node* root) {
    // Write our code here
    if(root == NULL){
        return 0;
    }
    int heightLeft = height(root->left);
    int heightRight = height(root->right);
    if(heightLeft>heightRight){
        return heightLeft+1;
    }
    else{
        return heightRight+1;
    }
}


//find Diameter of a binaryTree->no. of nodes on the longest path b/w two end nodes either root node of leaf node
int height(struct Node* root) {
    if(root == NULL){
        return 0;
    }
    int heightLeft = height(root->left);
    int heightRight = height(root->right);
    int ans = max(heightLeft, heightRight)+1;
    return ans;
}
int diameter(struct Node* root) {
    if(root==NULL){
        return 0;
    }
    int c1 = diameter(root->left);
    int c2 = diameter(root->right);
    int c3 = height(root->left)+height(root->right)+1;
    int ans = max(c1, max(c2,c3));
    return ans;
}


//optimized code for complexity O(n)
class Solution {
  private:
    int height(struct Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }

        int left = height(node ->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.

    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    int diameter(Node* root) {

        return diameterFast(root).first;

    }
};


//Check for Balanced Tree
//Given a binary tree, find if it is height balanced or not. 
//A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.
class Solution{
    private:
    int height( Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }

        int left = height(node ->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left)-height(root->right))<=1;
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};
//Optimized Code
class Solution{
    private:
    int height( Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }

        int left = height(node ->left);
        int right = height(node->right);

        int ans = max(left, right) + 1;
        return ans;
    }
    public:
    pair<bool,int> isBalancedFast(Node* root){
        if(root==NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
            
        }
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second)<=1;
        pair<bool,int> ans;
        ans.second = max(left.second, right.second)+1;
        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
        //  Your Code here
        /*if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left)-height(root->right))<=1;
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }*/
    }
};


//Given two binary trees, the task is to find if both of them are identical or not
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if(r1 == NULL && r2 != NULL){
            return false;
        }
        if(r1 != NULL && r2 == NULL){
            return false;
        }
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool val =(r1->data == r2->data);
        if(left && right && val){
            return true;
        }
        else{
            return false;
        }
    }
};



//SUM TREE
//Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.
//An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree

class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root){
        //BAse CAse
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }
        //as we have to check all nodes other than the leaf node so make it a base condition
        if(root->left == NULL && root->right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }
         
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool cond = root->data == left.second+right.second;
        pair<bool,int> ans;
        if(leftAns && rightAns && cond){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};