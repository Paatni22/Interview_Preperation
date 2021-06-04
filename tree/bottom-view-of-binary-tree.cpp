

void bottomView(Node *root)
{
   // Your Code Here
   queue<pair<Node*,int>> q;
   map<int,int> mp;
   q.push(make_pair(root,0));
   while(!q.empty())
   {
       Node* curr = q.front().first;
       int x_disp = q.front().second;
       mp[x_disp] = curr->data;
       q.pop();
       if(curr->left)   q.push(make_pair(curr->left,x_disp-1));
       if(curr->right)   q.push(make_pair(curr->right,x_disp+1));
       
   }
   for(auto a:mp)
    cout<<a.second<<" ";
}


// void dfs(Node* root,int x_disp,int level,map<int,pair<int,int>> &mp)
// {
// 	if(root==NULL)	return;

// 	if(mp.count(x_disp))
// 	{
// 		if(mp[x_disp].second <= level)
// 			mp[x_disp] = make_pair(root->data,level);
// 	}
// 	else
// 		mp[x_disp] = make_pair(root->data,level);
// 	dfs(root->left,x_disp-1,level+1,mp);
// 	dfs(root->right,x_disp+1,level+1,mp);
// }
// void bottomView(Node *root)
// {
//    // Your Code Here
// 	map<int,pair<int,int>> mp;
// 	dfs(root,0,0,mp);
// 	for(auto a:mp)
// 		cout<< a.second.first<<" ";
   
// }