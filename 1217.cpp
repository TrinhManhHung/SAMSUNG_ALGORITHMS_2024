//DIJKSTRA đồ thị vô hướng

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<int, int>> adj[1005];
bool used[1005];
int V, E, s;
void Init(){
	memset(used, false, sizeof(used));
	for(int i =1; i <= 1000; i++)  adj[i].clear();
	
	cin >> V >> E >> s;
	for(int i =1; i <=E; i++){
		int x, y, z; cin >> x >> y >> z;
		adj[x].pb({y, z});
		adj[y].pb({x, z});
	}
}

const int inf = 1e9;
void dijkstra(){
	vector<int> d(V+1, inf);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	//<do dai, canh>
	d[s] = 0;
	Q.push({0, s});
	while(!Q.empty()){
		auto top = Q.top(); Q.pop();
		
		int kc = top.first;
		int u = top.second;
		used[u] = true;
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(!used[v]){
				if(d[v] > d[u] + w){
					d[v] = d[u] + w;
					Q.push({d[v], v});
				}
			}
		}
	}
	for(int i =1; i <=V; i++) cout << d[i] << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Init();
		dijkstra();
	}
	return 0;
}
