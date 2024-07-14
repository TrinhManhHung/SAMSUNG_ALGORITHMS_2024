//Liet ke dinh tru

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int n, m;
vector<int> adj[1005];
bool used[1005];
vector<int> res;
int cnt;
void Nhap(){
	res.clear();
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		adj[i].clear();
		used[i] = false;
	}
	for(int i=1; i<=m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}
void DFS(int u){
	used[u] = true;
	cnt++;
	for(auto x : adj[u]){
		if(!used[x])
			DFS(x);
	}
}
void Solve(){
	//xet rieng i = 1
		cnt = 0;
		memset(used, false, sizeof(used));
		used[1] = true;
		DFS(2);
		if(cnt != n-1) res.pb(1);
	for(int i=2; i<=n; i++){
		cnt = 0;
		memset(used, false, sizeof(used));
		used[i] = true;
		DFS(1);
		if(cnt != n-1) res.pb(i);
	}
	for(auto x : res) cout << x << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Nhap();
		Solve();
	}
	return 0;
}

