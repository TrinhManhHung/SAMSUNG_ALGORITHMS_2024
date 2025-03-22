#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int INF = 1e7;

int V, E, M;
vi adj[15];
vi color(15);

void init(){
	FOR(v, 1, 10){
		adj[v].clear();
		color[v] = 0;
	}
	
	cin >> V >> E >> M;
	FOR(i, 1, E){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
}

bool canColor(int v, int c){
	for(auto u : adj[v]){
		if(color[u] == c) return false;
	}
	return true;
}

bool graphColoring(int v){
	if(v == V+1) return true;
	
	FOR(c, 1, M){
		if(canColor(v, c)){
			color[v] = c;
			if (graphColoring(v + 1)) return true;
			color[v] = 0;
		}
	}
	return false;
}

void solve(){
	init();
	cout << (graphColoring(1) ? "YES\n" : "NO\n");	
}

int main() {
    faster();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/