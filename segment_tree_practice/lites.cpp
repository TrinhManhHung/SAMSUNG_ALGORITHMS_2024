//https://oj.vnoi.info/problem/lites

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

struct segmentTree{
	int n;
	vi lazy;
	vector<pii> tree; //<p1: soden bat, p2: soden tat>
	
	segmentTree(int _n){
		n = _n;
		tree.assign(4*n + 5, {0, 0});
		lazy.assign(4*n + 5, 0);
	}
	
	void pushDown(int i){
		if(lazy[i]){
			swap(tree[2*i].fi, tree[2*i].se);
			swap(tree[2*i + 1].fi, tree[2*i + 1].se);
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}
		
		lazy[i] = 0;
	}
	
	void build(int i, int l, int r){
		if(l == r){
			tree[i] = {0, 1}; 
			return;
		}
		
		int mid = (l + r) >> 1;
		
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);
		
		tree[i].fi = tree[2*i].fi + tree[2*i+1].fi;
		tree[i].se = tree[2*i].se + tree[2*i+1].se;
	}


	void update(int i, int tl, int tr, int l, int r){
		if(r < tl || l > tr) return;
		
		if(l <= tl && tr <= r){
			swap(tree[i].fi, tree[i].se);
			lazy[i] ^= 1;
			return;
		}
		
		int mid = (tl + tr) >> 1;
		
		pushDown(i);
		update(2*i, tl, mid, l, r);
		update(2*i+1, mid+1, tr, l, r);
		
		tree[i].fi = tree[2*i].fi + tree[2*i+1].fi;
		tree[i].se = tree[2*i].se + tree[2*i+1].se;
	}
	
	int get(int i, int tl, int tr, int l, int r){
		if(r < tl || l > tr) return 0;
		
		if(l <= tl && tr <= r) return tree[i].fi;
		
		int mid = (tl + tr) >> 1;
		pushDown(i);
		return get(2*i, tl, mid, l, r) + get(2*i+1, mid + 1, tr, l, r);
	}
};

void solve(){
	int n, m; cin >> n >> m;
	
	segmentTree seg(n);
	seg.build(1, 1, n);

	FOR(i, 1, m){
		int type, s, e; cin >> type >> s >> e;
		
		if(type == 0) seg.update(1, 1, n, s, e);
		
		else cout << seg.get(1, 1, n, s, e) << endl;
	}
}

int main(){
    faster();
    if(fopen("HungHot.inp", "r")){
    	freopen("HungHot.inp", "r", stdin);
    	freopen("HungHot.out", "w", stdout);
	}
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam
	  (\(\
	 ( 0.0)
	o_(")(")
**/

