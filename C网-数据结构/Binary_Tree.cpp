#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

//树节点 
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;

//树根 
typedef struct Tree{
	struct Node* root;
}tree;

//向指定树中插入数据，若树不存在，则创建 
void insert(Tree* tree,int value)
{
	//创建一个节点
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=value;
	node->left=NULL;
	node->right=NULL;
	
	//若树是空树，则此节点为树根
	if(tree->root == NULL)
		tree->root=node;
	else//不是空树 
	{
		//创建一个临时指针 
		Node* temp=tree->root;//指向树根
		
		while(temp!=NULL)
		{
			if(value < temp->data)//小值进入左子树
			{
				if(temp->left == NULL)//左子树为空 
				{
					temp->left = node;//放入该节点 
					return;//结束返回 
				}	
				else
				{
					temp = temp->left;//往下继续搜寻
				}	 
			}
			else//大值或等值进入右子树 
			{
				if(temp->right == NULL)//右子树为空 
				{
					temp->right=node;//放入该节点 
					return;//结束返回 
				}
				else
				{
					temp = temp->right;//往下继续搜寻 
				}
			} 
		}	 
	}
	return; 
}

//树的中序遍历 inorder traversal 
void inorder(Node* node)
{
	if(node!=NULL)
	{
		inorder(node->left);//左子树 
		cout<< node->data <<" ";//输出数据 
		inorder(node->right);//右子树 
	}
	return;
}

//树的先序遍历 preorder traversal
void preorder(Node* node)
{
	if(node!=NULL)
	{
		cout<< node->data <<" ";
		preorder(node->left);
		preorder(node->right);
	}
	return;
}

//树的后序遍历 
void postorder(Node* node)
{
	if(node!=NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout<< node->data <<" ";
	}
	return;
} 

int main()
{
	Tree tree;//创建树 
	tree.root=NULL;
	
	for(int i=0;i<10;i++)//插入 
		insert(&tree,i);
	for(int i=-9;i<0;i++)//插入 
		insert(&tree,i);
	
	//preorder(tree.root);//先序遍历 
	//inorder(tree.root);//中序遍历 
	//postorder(tree.root);//后序遍历 
	
	return 0;
}
