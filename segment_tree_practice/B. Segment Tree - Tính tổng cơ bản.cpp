//https://codeforces.com/gym/458672/problem/B

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<ll>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 200000;

int n, q;
int a[maxn+5];

struct segTree{
	int n;
	vi tree;
	
	segTree(int _n){
		n = _n;
		tree.assign(4*n+5, 0);
	}
	
	void update(int i, int l, int r, int pos, int val){
		if(l == r){
			tree[i] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid){
			update(2*i, l, mid, pos, val);
		}
		else update(2*i+1, mid+1, r, pos, val);
		tree[i] = tree[2*i] + tree[2*i+1];
	}
	
	ll get(int i, int l, int r, int u, int v){
		if(u > r || v < l) return 0;
		if(u <= l && r <= v){
			return tree[i];
		}
		int mid = (l+r) >> 1;
		return get(2*i, l, mid, u, v) + get(2*i+1, mid+1, r, u, v);
	}
};

void solve(){
	cin >> n >> q;
	
	segTree t(n);
	
	FOR(i, 1, n){
		cin >> a[i];
		t.update(1, 1, n, i, a[i]);
	}
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int x, v; cin >> x >> v;
			t.update(1, 1, n, x, v);
		}
		else{
			int l, r; cin >> l >> r;
			cout << t.get(1, 1, n, l, r) << endl;
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