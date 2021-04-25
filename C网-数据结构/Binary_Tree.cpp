#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

//���ڵ� 
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;

//���� 
typedef struct Tree{
	struct Node* root;
}tree;

//��ָ�����в������ݣ����������ڣ��򴴽� 
void insert(Tree* tree,int value)
{
	//����һ���ڵ�
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=value;
	node->left=NULL;
	node->right=NULL;
	
	//�����ǿ�������˽ڵ�Ϊ����
	if(tree->root == NULL)
		tree->root=node;
	else//���ǿ��� 
	{
		//����һ����ʱָ�� 
		Node* temp=tree->root;//ָ������
		
		while(temp!=NULL)
		{
			if(value < temp->data)//Сֵ����������
			{
				if(temp->left == NULL)//������Ϊ�� 
				{
					temp->left = node;//����ýڵ� 
					return;//�������� 
				}	
				else
				{
					temp = temp->left;//���¼�����Ѱ
				}	 
			}
			else//��ֵ���ֵ���������� 
			{
				if(temp->right == NULL)//������Ϊ�� 
				{
					temp->right=node;//����ýڵ� 
					return;//�������� 
				}
				else
				{
					temp = temp->right;//���¼�����Ѱ 
				}
			} 
		}	 
	}
	return; 
}

//����������� inorder traversal 
void inorder(Node* node)
{
	if(node!=NULL)
	{
		inorder(node->left);//������ 
		cout<< node->data <<" ";//������� 
		inorder(node->right);//������ 
	}
	return;
}

//����������� preorder traversal
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

//���ĺ������ 
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
	Tree tree;//������ 
	tree.root=NULL;
	
	for(int i=0;i<10;i++)//���� 
		insert(&tree,i);
	for(int i=-9;i<0;i++)//���� 
		insert(&tree,i);
	
	//preorder(tree.root);//������� 
	//inorder(tree.root);//������� 
	//postorder(tree.root);//������� 
	
	return 0;
}
