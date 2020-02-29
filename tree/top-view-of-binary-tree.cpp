#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void top_view(node* root)
{
	queue<pair<node*,int>> q;
	q.push(make_pair(root,0));
	map<int,int> mp;
	while(!q.empty())
	{
		node *curr = q.front().first;
		int x_disp = q.front().second;
		q.pop();
		if(mp.count(x_disp)==0)
		{
			//cout<< curr->val<<" ";
			mp[x_disp] = curr->val;
			
		}
		if(curr->left)	q.push(make_pair(curr->left,x_disp-1));
		if(curr->right)	q.push(make_pair(curr->right,x_disp+1));

	}
	for(auto i:mp)
		cout<<i.second<<" ";
	cout<<endl;
	
}
int main()
{
	vector<int> v={4,2,6,1,3,5,8,7};
	node *root = makeBST(v);

	inorder(root);
	cout << endl;
	
	top_view(root);
	


}
