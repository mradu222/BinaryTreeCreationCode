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


//take input and print recursively
void printTree(Node* root){
    if(root == NULL){//Base CAse
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){//checking if left not null then print it's data
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);//recursively calling left and right subtree
    printTree(root->right);
}
Node* takeInput(){
    int rootData;
    cout<<"enter Data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    //dynamically creating node which call constructore of the same class 
    Node* root = new Node(rootData);
    //recursively calling over left subtree
    Node* leftChild = takeInput();
    Node* rightChild = takeInput();
    root->left = leftChild;//now alloting left and right child to the root node
    root->right = rightChild;
    return root;

}


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


//print LevelWise
void printLevelWise(Node* root) {
    if(root == NULL){
        return;
    }
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        Node* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left != NULL){
            cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        else{
            cout<<"L:-1,";
        }
        if(front->right != NULL){
            cout<<"R:"<<front->right->data;
            pendingNodes.push(front->right);
        }
        else{
            cout<<"R:-1";
        }
        cout<<endl;
        
    }
}
int main(){
    Node* root = takeInputLevelWise();
    printTree(root); 
    printLevelWise(root);
}