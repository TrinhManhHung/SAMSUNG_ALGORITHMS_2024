//Tim duong di theo BFS

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m, s, t;
vector<int> adj[1005];
bool used[1005];
int truoc[1005];
void nhap(){
	memset(used, false, sizeof(used));
	for(int i=1; i<=1000; i++){
		adj[i].clear();
		truoc[i] = i;
	}
	
	cin >> n >> m >> s >> t;
	for(int i=1; i<=m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
	for(int i=1; i<= n; i++) sort(adj[i].begin(), adj[i].end());
}
void BFS(int u){
	queue<int> q;
	q.push(u);
	used[u] = true;
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(auto x : adj[top]){
			if(!used[x]){
				q.push(x);
				truoc[x] = top;
				used[x] = true;
			}
		}
	}
}
int main(){
	int test; cin >> test;
	while(test--){
		nhap();
		BFS(s);
		if(truoc[t] == t) cout << -1;
		else{
			int tmp = t;
			vector<int> road;
			while(truoc[tmp] != tmp){
				road.pb(tmp);
				tmp = truoc[tmp];
			}
			road.pb(tmp);
			reverse(road.begin(), road.end());
			for(auto x : road) cout << x << " ";
		}
		cout << "\n";
	}
	return 0;
}
