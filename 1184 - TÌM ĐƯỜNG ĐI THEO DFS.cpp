//TÌM ĐƯỜNG ĐI THEO DFS

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
void DFS(int u){
	used[u] = true;
	for(auto x : adj[u]){
		if(!used[x]){
			truoc[x] = u;
			DFS(x);
		}
	}
}
int main(){
	int test; cin >> test;
	while(test--){
		nhap();
		DFS(s);
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

