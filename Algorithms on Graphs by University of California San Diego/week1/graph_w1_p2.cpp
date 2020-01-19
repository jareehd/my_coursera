#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> > &adj,bool vis[],int x){
    vis[x]=true;
    for(auto k:adj[x])
     if(!vis[k])dfs(adj,vis,k);
}
int number_of_components(vector<vector<int> > &adj,int n){
  int res = 0;bool vis[n];memset(vis,false,sizeof(vis));
  for(int i=0;i<n;i++)
   if(!vis[i]){res++;dfs(adj,vis,i);}
  return res;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i=0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  cout << number_of_components(adj,n);
}