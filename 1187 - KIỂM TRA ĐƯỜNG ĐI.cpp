//KIỂM TRA ĐƯỜNG ĐI
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

int n, m;
int parent[1005];

int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}
void Union(int u, int v){
	int root_u = Find(u);
	int root_v = Find(v);
	if(root_u == root_v) return;
	if(root_u < root_v){
		parent[root_v] = root_u;
	}
	else parent[root_u] = root_v;
}

void Solve(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) parent[i] = i;
	for(int i=1; i<=m; i++){
		int x, y; cin >> x >> y;
		Union(x, y);
	}
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		x = Find(x);
		y = Find(y);
		if(x == y) cout << "YES\n";
		else cout << "NO\n";
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}

