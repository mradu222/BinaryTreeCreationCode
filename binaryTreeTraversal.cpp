#include<iostream>
using namespace std;
#include<queue>
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int num){
        this->data = num;
        this->left = NULL;
        this->right = NULL;
    }
};
//Take Input LevelWise
Node* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    //dynamically allocation of root Node
    Node* root = new Node(rootData);
    //using queue to level wise traversal
    queue<Node*> pendingNodes;
    pendingNodes.push(root);//root node pushed into queue
    while(pendingNodes.size() != 0){//process continued till the queue size is zero
        Node* front = pendingNodes.front();//front of queue is stored
        pendingNodes.pop();
        cout<<"Enter the left child of "<<front->data<<endl;
        int leftChildData;//left child of current node is taken
        cin>>leftChildData;
        if(leftChildData != -1){//if the value of left child is nor -1 that is it is not Null
            Node* child = new Node(leftChildData);
            front->left = child;//value assigned to the left part and pushed to queue
            pendingNodes.push(child);

        }
        //do similar work for right subtree
        cout<<"Enter the right child of "<<front->data<<endl;
        int rightChildData;//right child of current node is taken
        cin>>rightChildData;
        if(rightChildData != -1){//if the value of right child is not -1 that is it is not Null
            Node* child = new Node(rightChildData);
            front->right = child;//value assigned to the right part and pushed to queue
            pendingNodes.push(child);

        }
    }
    return root;
}
void preOrder(Node* root) {
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node* root) {
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = NULL;
    root = takeInputLevelWise();
    cout<<"Inorder traversal is: ";
    inOrder(root);
    cout<<endl;
    cout<<"Preorder traversal is:";
    preOrder(root);
    cout<<endl;
    cout<<"portOrder traversal is:";
    postOrder(root);
}