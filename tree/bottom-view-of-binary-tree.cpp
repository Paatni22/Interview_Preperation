

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