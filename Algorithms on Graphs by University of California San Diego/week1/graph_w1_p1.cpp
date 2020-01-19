#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll reach(vector<vector<ll> > &adj,bool vis[], int x, int y) {
  vis[x]=true;
  if(x==y)return 1;
  ll ans=0;
  for(auto k:adj[x]){
      if(vis[k])continue;
      ans=(ans|reach(adj,vis,k,y));
  }
  return ans;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll> > adj(n, vector<ll>());
  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  ll x, y;
  cin >> x >> y;
  bool vis[n+2];memset(vis,false,sizeof(vis));
  cout << reach(adj,vis, x - 1, y - 1);
}
