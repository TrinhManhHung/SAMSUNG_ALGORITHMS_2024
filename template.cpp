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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define COUNT_ONE(x) __builtin_popcountll((x))
#define COUNT_LEAD_ZERO(x) __builtin_clzll((x))
#define COUNT_TRAIL_ZERO(x) __builtin_ctzll((x))
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const ll MOD = 998244353;
const int maxn = 200000;

//Modulo
ll addMod(ll a, ll b){
	return (a + b) % MOD;
}

ll subMod(ll a, ll b){
	return (a - b + MOD) % MOD;
}

ll mulMod(ll a, ll b){
	if(b == 0) return 0;
	if(b == 1) return a;
	ll half = mulMod(a, b / 2);
	
	ll res = (half + half) % MOD;
	if(b & 1) res = (res + a) % MOD;
	
	return res;
}

ll powMod(ll a, ll b){
	if(b == 0) return 1;
	ll half = powMod(a, b / 2);
	
	ll res = half * half % MOD;
	if(b & 1) res = res * a % MOD;
	
	return res;
}

//To Hop Chap k Cua n
const int maxn = 200005;
const ll MOD = 998244353;

ll frac[maxn], finv[maxn]; //frac[n]: n!, finv[n]: (n!)^(MOD-2)

ll powMod(ll x, ll k){
    if(k == 0) return 1;
    ll half = powMod(x, k/2);
    half = (half * half) % MOD;
    return (k & 1) ? (half * x) % MOD : half;
}

void prepare(){
	frac[0] = 1;
	FOR(i, 1, maxn-1) frac[i] = frac[i-1] * i % MOD;
	finv[maxn-1] = powMod(frac[maxn-1], MOD-2); finv[0] = 1;
	FOD(i, maxn-2, 1) finv[i] = finv[i+1] * (i+1) % MOD;  
}

ll comb(int k, int n){ //C(k, n)
	return k > n? 0 : frac[n] * finv[k] % MOD * finv[n-k] % MOD;
}
//Chia Can
int n;
int block = sqrt(n);

bool cmp(pair<pii, int> a, pair<pii, int> b){
 
    int pa = a.fi.se / block;
    int pb = b.fi.se / block;
    
    if(pa != pb) return pa < pb;
    else{
        return (pa % 2 == 0? a.fi.fi < b.fi.fi : a.fi.fi > b.fi.fi);
    } 
}

//Fenwick Tree
struct FenwickTree{
	int n;
	vll tree;
	
	FenwickTree(int _n){
		n = _n;
		tree.assign(n + 5, 0);
	}
	
	void update(int pos, int val){
		for(; pos <= n; pos += (pos & -pos)){
			tree[pos] += val;
		}
	}
	
	ll get(int pos){
		ll res = 0;
		for(; pos > 0; pos -= (pos & -pos)){
			res += tree[pos];
		}
		return res;
	}
};

//Segment Tree
struct SegmentTree{
	int n;
	vll tree, lazy;
	
	SegmentTree(int _n){
		n = _n;
		tree.assign(4*n + 5, 0);
		lazy.assign(4*n + 5, 0);
	}
	
	void pushDown(int id, int tl, int tr){
		if(lazy[id] == 0) return;
		
		int tm = (tl + tr) >> 1;
		
		tree[2*id] += lazy[id] * (tm - tl + 1);
		tree[2*id+1] += lazy[id] * (tr - tm);
		lazy[2*id] += lazy[id];
		lazy[2*id+1] += lazy[id];
		
		lazy[id] = 0;
	}
	
	void update(int id, int tl, int tr, int u, int v, int val){
		if(tl > v || tr < u) return;
		if(u <= tl && tr <= v){
			tree[id] += val * (tr - tl + 1);
			lazy[id] += val; 
			return;
		}
		
		pushDown(id, tl, tr);
		int tm = (tl + tr) >> 1;
		update(2*id, tl, tm, u, v, val);
		update(2*id+1, tm+1, tr, u, v, val);
		
		tree[id] = tree[2*id] + tree[2*id+1]; //pushUp
	}
	
	ll get(int id, int tl, int tr, int u, int v){
		if(tl > v || tr < u) return 0ll;
		if(u <= tl && tr <= v) return tree[id];
		
		pushDown(id, tl, tr);
		int tm = (tl + tr) >> 1;
		ll L = get(2*id, tl, tm, u, v);
		ll R = get(2*id+1, tm+1, tr, u, v);
		
		return L + R;
	}
};

//Hash (String s danh so tu 1)
int n;

const int maxn = 200000;
const int MOD = 1e9 + 7;
const int BASE = 256;

string s;
ll hs[maxn + 5]; //hs[i] = ma hash cua xau s[1...i]
ll pw[maxn + 5]; //pw[i] = 256^i
ll invPw[maxn + 5]; //invPw[i] = pw[i] ^ (MOD - 2)

ll powMod(ll a, ll b){
	if(b == 0) return 1;
	ll half = powMod(a, b / 2);
	
	ll res = half * half % MOD;
	if(b & 1) res = res * a % MOD;
	
	return res;
}

void prepare(){
	pw[0] = 1;
	FOR(i, 1, maxn) pw[i] = pw[i-1] * BASE % MOD;
	
	FOR(i, 0, maxn){
		invPw[i] = powMod(pw[i], MOD - 2);
	}
}

ll calcHash(string s){
	FOR(i, 1, s.sz - 1){
		hs[i] = hs[i-1] + s[i] * pw[i-1];
		hs[i] %= MOD;
	}
	return hs[s.sz - 1];
}

ll calcSegmentHash(int l, int r){
	return (hs[r] - hs[l-1] + MOD) % MOD * invPw[l-1] % MOD;
}

//DSU: Moi TPLT Luu Nut Cha, So Luong Dinh, So Luong Canh
struct DSU{
	int n;
	vi parent, size, edge;
	
	DSU(int _n){
		n = _n;
		parent.assign(n+5, 0);
		size.assign(n+5, 0);
		edge.assign(n+5, 0);
		FOR(i, 1, n){
			parent[i] = i;
			size[i] = 1;
			edge[i] = 0;
		}
	}
	
	int Find(int u){
		if(parent[u] == u) return u;
		return parent[u] = Find(parent[u]);
	}
	
	bool Union(int u, int v){
		u = Find(u);
		v = Find(v);

		if(u == v){
			edge[u]++;
			return false;
		}
		if(size[u] > size[v]){
			parent[v] = u;
			
			size[u] += size[v];
			edge[u] += edge[v] +1;
			
			size[v] = 0;
			edge[v] = 0;
		} else{
			parent[u] = v;
			
			size[v] += size[u];
			edge[v] += edge[u] +1;
			
			size[u] = 0;
			edge[u] = 0;
		}
		return true;
	}

};

//Dijkstra
int n;
vector<pii> adj[1005];

int dijkstra(int sta, int end){
	vi dist(n+1, INF);
	
	priority_queue<pii, vector<pii>, greater<pii>> Q; //<dist, vertex>
	dist[sta] = 0;
	Q.push({0, sta});
	
	while(!Q.empty()){
		auto top = Q.top(); Q.pop();
		
		int cur_dist = top.fi;
		int u = top.se;
		
		for(auto it : adj[u]){
			int v = it.fi;
			int w = it.se;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				Q.push({dist[v], v});
			}
		}		
	}
	
	return dist[end];	
}

//Topo Sorting: Ap Dung Cho Directed Acyclic Graph
int n;
vi in_degree, topo;
vvi adj;

void kahn(){
	queue<int> Q;
	
	FOR(u, 1, n){
		if(in_degree[u] == 0) Q.push(u);
	}
	
	while(!Q.empty()){
		auto u = Q.front(); Q.pop();
		topo.pb(u);
		for(auto v : adj[u]){
			in_degree[v]--;
			if(!in_degree[v]) Q.push(v);
		}
	}
}

int main(){
    faster();
    int t = 1;
//    cin >> t;
    while(t--){
        HuyenMay();
    }
    return 0;
}
