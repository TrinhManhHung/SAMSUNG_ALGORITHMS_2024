//DFS tren do thi vo huong

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m, s;
vector<int> adj[1005];
bool used[1005];
void nhap(){
	memset(used, false, sizeof(used));
	for(int i=1; i<=1000; i++) adj[i].clear();
	
	cin >> n >> m >> s;
	for(int i=1; i<=m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i=1; i<= n; i++) sort(adj[i].begin(), adj[i].end());
}
void DFS(int u){
	cout << u << " ";
	used[u] = true;
	for(auto x : adj[u]){
		if(!used[x]){
			DFS(x);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		nhap();
		DFS(s);
		cout << "\n";
	}
	return 0;
}

