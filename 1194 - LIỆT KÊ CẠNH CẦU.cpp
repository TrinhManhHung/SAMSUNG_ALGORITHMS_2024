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
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 1000;

int n, m;
vvi adj(1005);
vector<pii> edges;
bool used[1005];

void dfs(int u, int x, int y){
	used[u] = true;
	for(auto v : adj[u]){
		if(!used[v]){
			if((u == x && v == y) || (u == y && v == x)) continue;
			dfs(v, x, y);
		}
	}
}

int tplt(int x, int y){
	int res = 0;
	FOR(i, 1, n){
		if(!used[i]){
			res++;
			used[i] = true;
			dfs(i, x, y);
		}
	}
	return res;
}

void init(){
	cin >> n >> m;
	edges.clear();
	FOR(i, 1, n){
		adj[i].clear();
		used[i] = false;
	}
	FOR(i, 1, m){
		int x, y; cin >> x >> y;
		if(y < x) swap(x, y);
		adj[x].pb(y);
		adj[y].pb(x);
		edges.pb({x, y});
	}
}
void solve(){
	init();
	int tpltCnt = tplt(0, 0);
//	cout << tpltCnt << endl;
	
	for(auto x : edges){
		memset(used, false, sizeof(used));
		int tpltCur = tplt(x.fi, x.se);
		if(tpltCur > tpltCnt){
			cout << x.fi << " " << x.se << " ";
		}
	}
	cout << endl;
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