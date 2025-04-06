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
#define pii pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define INF INT_MAX
const int maxn = 1e5;
const ll MOD = 998244353;

ll sum(int n){
	return 1ll * n * (n-1) / 2;
}

struct DSU{
	int parent[maxn+5];
	int size[maxn+5];
	DSU(int n){
		FOR(i, 1, n){
			parent[i] = i;
			size[i] = 1;
		}
	}
	
	int Find(int u){
		if(parent[u] == u) return u;
		return parent[u] = Find(parent[u]);
	}
	
	bool Union(int u, int v){
		u = Find(u);
		v = Find(v);
		if(u == v) return false;
		if(size[u] >= size[v]){
			parent[v] = u;
			size[u] += size[v];
			size[v] = 0;
		}else {
			parent[u] = v;
			size[v] += size[u];
			size[u] = 0; 
		}
		return true;	
	}
};
void solve(){
	int n, m; cin >> n >> m;
	DSU dsu(n);
	FOR(i, 1, m){
		int u, v; cin >> u >> v;
		dsu.Union(u, v);
	}
	
	ll res = 0;
	FOR(i, 1, n){
//		cout << dsu.size[i] << " ";
		res += sum(dsu.size[i]);
	}
//	cout << res << endl;
	cout << (res == m? "YES\n" : "NO\n");
}

int main() {
    faster();
    if(fopen("HungHot.inp", "r")){
    	freopen("HungHot.inp", "r", stdin);
    	freopen("HungHot.out", "w", stdout);
	}
    int t = 1; 
	cin >> t;
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

