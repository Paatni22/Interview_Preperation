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
void left_view_dfs(node* root,int currLevel,int &level)
{
	if(root == NULL)	return;
	if(currLevel > level )
	{
		cout<< root->val<<" ";
		level = currLevel;
	}
	left_view_dfs(root->left,currLevel+1,level);
	
	left_view_dfs(root->right,currLevel+1,level);
}
void left_view_bfs(node* root)
{
	queue<pair<node*,int>> q;
	q.push(make_pair(root,1));
	int explored_level = 0;
	while(!q.empty())
	{
		node *curr = q.front().first;
		int currLevel = q.front().second;
		q.pop();
		if(currLevel > explored_level)
		{
			cout<< curr->val<<" ";
			explored_level = currLevel;
		}
		if(curr->left)	q.push(make_pair(curr->left,currLevel+1));
		if(curr->right)	q.push(make_pair(curr->right,currLevel+1));

	}
	cout<<endl;
}
int main()
{
	vector<int> v={4,2,6,1,3,5,7,8};
	node *root = makeBST(v);

	inorder(root);
	cout << endl;
	int level = 0;
	left_view_dfs(root,1,level);
	cout << endl;
	left_view_bfs(root);


}
