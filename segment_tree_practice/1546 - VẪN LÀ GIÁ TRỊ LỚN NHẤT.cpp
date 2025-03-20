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
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 100000;

struct segTree{
	int n;
	vi tree, lazy;
	
	segTree(int _n){
		n = _n;
		tree.assign(4*n+5, 0);
		lazy.assign(4*n+5, 0);
	}
	
	void pushDown(int i){
		tree[2*i] += lazy[i];
		tree[2*i+1] += lazy[i];
		lazy[2*i] += lazy[i];
		lazy[2*i+1] += lazy[i];
			
		lazy[i] = 0;
	}
	
	void update(int i, int l, int r, int u, int v, int k){
		if(v < l || u > r) return;
//		pushDown(i, l, r);
		if(u <= l && r <= v){
			tree[i] += k;
			lazy[i] += k;
			return;
		}
		int mid = (l + r) >> 1;
		pushDown(i);
		update(2*i, l, mid, u, v, k);
		update(2*i+1, mid+1, r, u, v, k);
		tree[i] = max(tree[2*i], tree[2*i+1]);
	}
	
	int get(int i, int l, int r, int u, int v){
		if(v < l || u > r) return 0;
		if(u <= l && r <= v){
			return tree[i];
		}
		int mid = (l+r) >> 1;
		pushDown(i);
		return max(get(2*i, l, mid, u, v), get(2*i+1, mid+1, r, u, v));
	}
};

void solve(){
	int n, q; cin >> n >> q;
	segTree t(n);
	
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int u, v, k; cin >> u >> v >> k;
			t.update(1, 1, n, u, v, k);
		}
		else{
			int u, v; cin >> u >> v;
			cout << t.get(1, 1, n, u, v) << endl;
		}
	}
}

int main() {
    faster();
//    int t; cin >> t;
//    while (t--) {
        solve();
//    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/
