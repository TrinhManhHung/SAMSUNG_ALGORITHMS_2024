// https://oj.vnoi.info/problem/segtree_itds1

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
const int inf = 1e9+1;

ll a[maxn+1];

struct segmentTree{
	int n;
	vector<multiset<int>> tree;
	
	segmentTree(int _n){
		n = _n;
		tree.resize(4*n + 5);
	}
	
	void build(int i, int l, int r){
		if(l == r){
			tree[i].insert(a[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);
		tree[i].insert(tree[2*i].begin(), tree[2*i].end());
		tree[i].insert(tree[2*i+1].begin(), tree[2*i+1].end());
	}
	
	void update(int i, int l, int r, int pos, int oldVal, int curVal){
		tree[i].erase(tree[i].find(oldVal));
		tree[i].insert(curVal);
		if(l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid){
			update(2*i, l, mid, pos, oldVal, curVal);
		} else{
			update(2*i+1, mid+1, r, pos, oldVal, curVal);	
		}
	}
	
	int get(int i, int l, int r, int u, int v, int k){
		if(r < u || l > v){
			return inf;
		}
		if(u <= l && r <= v){
			auto val = tree[i].lower_bound(k);
			if(val == tree[i].end()) return inf;
			else return *val;
		}
		int mid = (l + r) >> 1;
		return min(get(2*i, l, mid, u, v, k), get(2*i+1, mid+1, r, u, v, k)); 
	}
};

void solve(){
	int n, q; cin >> n >> q;
	segmentTree t(n);

	FOR(i, 1, n){
		cin >> a[i];
	}
	t.build(1, 1, n);
	
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int i, val; cin >> i >> val;
			t.update(1, 1, n, i, a[i], val);
			a[i] = val;
		}
		else{
			int l, r, k; cin >> l >> r >> k;
			int res = t.get(1, 1, n, l, r, k);
			if(res == inf) res = -1;
			cout << res << endl;
		}
	}
}
int main() {
    faster();
    int t = 1; 
//	cin >> t;
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
