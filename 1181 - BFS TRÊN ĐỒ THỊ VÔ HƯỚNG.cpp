//BFS TRÊN ĐỒ THỊ VÔ HƯỚNG

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
void BFS(int u){
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()){
		int top = q.front(); q.pop();
		cout << top << " ";
		for(auto x : adj[top]){
			if(!used[x]){
				q.push(x);
				used[x] = true;
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		nhap();
		BFS(s);
		cout << "\n";
	}
	return 0;
}

