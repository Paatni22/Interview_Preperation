#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
	int val;
	node *left,*right;
};

void inorder(node * root)
{
	if(root==NULL)	return;
	inorder(root->left);
	cout<< root->val<<" ";
	inorder(root->right);

}

node * new_Node(int value)
{
	node *curr = new node();
	curr->val = value;
	curr->right = curr->left = NULL;
	return curr;
}

node* makeBST(vector<int> v)
{
	node * root = new_Node(v[0]);
	int n = v.size();
	for(int i=1;i<n;i++)
	{
		node* curr = new_Node(v[i]);
		node * temp = root;
		while(true)
		{
			if(temp->val > v[i])
			{
				if(temp->left)	temp = temp->left;
				else{
					temp->left = curr;break;
				}
			}
			else
			{
				if(temp->right)	temp = temp->right;
				else
				{
					temp->right = curr; break;
				}

			}
		}
	}
	return root;

}
bool leaf(node* root)
{

	return root && !root->left && !root->right;
}
void dfs(node* root,int &ans)
{
	if(root==NULL)	return;
	if(leaf(root->left))	ans+=root->left->val;
	else	dfs(root->left,ans);
	dfs(root->right,ans);
}
int main()
{
	vector<int> v={4,2,6,1,3,5,8,7};
	node *root = makeBST(v);

	inorder(root);
	cout << endl;
	int ans=0;
	dfs(root,ans);
	cout<<ans<<endl;
}
