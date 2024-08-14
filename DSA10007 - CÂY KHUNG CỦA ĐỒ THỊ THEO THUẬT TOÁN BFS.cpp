#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
#define pb push_back

int n, m, u;
vector<int> adj[1005];
vector<pair<int, int>> res;
bool visited[1005];
bool checkHaveTree;

void Init(){
	//memset
	for(int i =0; i <=1000; i++) adj[i].clear();
	res.clear();
	memset(visited, false, sizeof(visited));
	checkHaveTree = false;
	//init
	cin >> n >> m >> u;
	for(int i =1; i <=m; i++){
		int x, y ; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

void DFS(int x){
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while(!q.empty()){
		int top = q.front(); q.pop();
		for(auto y : adj[top]){
			if(!visited[y]){
				res.pb({top, y});
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		Init();
		DFS(u);
		if(res.size() != n - 1){
			cout << -1 << endl;
		}
		else{
			for(auto x : res){
				cout << x.first << " " << x.second << endl;
			}
		}
	}
	return 0;
}
