#include<bits/stdc++.h>
using namespace std;
#include "Btrees.cpp"

void inOrder(BinaryTreeNode<int>*root){//LEFT THEN NODE THEN RIGHT
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//NUM NODES
int numNodes(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+ numNodes(root->left)+numNodes(root->right);
}
//LEVELWISE INPUT
BinaryTreeNode<int>* takeInputLevelWise(){
    cout<<"Enter rootData"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<"Enter Left child of "<<front->data<<endl;
        int Lchild;
        cin>>Lchild;
        if(Lchild!= -1){
             BinaryTreeNode<int>* Lnode = new BinaryTreeNode<int>(Lchild);
             front->left = Lnode;
             q.push(Lnode);
        }
        cout<<"Enter Right child of "<<front->data<<endl;
        int Rchild;
        cin>>Rchild;
        if(Rchild!= -1){
             BinaryTreeNode<int>* Rnode = new BinaryTreeNode<int>(Rchild);
             front->right = Rnode;
             q.push(Rnode);
        }
    }
    return root;
}

//LEVEL WISE PRINT
void printLevelWise(BinaryTreeNode<int>*root){
if(root == NULL){
    return;
}
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<" ,";
            q.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data<<" ,";
            q.push(front->right);
        }
        cout<<endl;

    }
}

BinaryTreeNode<int>* takeInput(){
cout<<"Enter data"<<endl;
int rootData;
cin>>rootData;
if(rootData == -1){
    return NULL;
}
BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
BinaryTreeNode<int>*leftChild = takeInput();
BinaryTreeNode<int>*rightChild = takeInput();
root->left = leftChild;
root->right = rightChild;
return root;
}

void printTree(BinaryTreeNode<int>* root){
if(root == NULL){
    return;
}
cout<<root->data<<": ";
if(root->left!=NULL){
    cout<<"L"<<root->left->data<<" ";
}
if(root->right!=NULL){
    cout<<"R"<<root->right->data<<" ";
}
cout<<endl;
printTree(root->left);
printTree(root->right);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
/*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

root->left = node1;
root->right = node2;*/
BinaryTreeNode<int>*root = takeInputLevelWise();
inOrder(root);
}
