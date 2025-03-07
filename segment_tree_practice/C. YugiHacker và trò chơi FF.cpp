//https://codeforces.com/gym/458672/problem/C

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

int n, q;

pii cal(pii a, pii b) {
    ll x1 = max(a.fi, a.se);
    ll x2 = max(b.fi, b.se);
    ll y1 = min(a.fi, a.se);
    ll y2 = min(b.fi, b.se);
    return {max(min(x1, x2), max(y1, y2)), max(x1, x2)};
}

struct segTree{
	int n;
	vector<pii> tree;
	segTree(int _n){
		n = _n;
		tree.assign(4*n+5, {0, 0});
	}
	
	void update(int i, int l, int r, int pos, ll val){
		if(l == r){
			tree[i] = {1, val};
			return;
		}
		else{
			int mid = (l + r) >> 1;
			if(pos <= mid) update(2*i, l, mid, pos, val);
			else update(2*i+1, mid+1, r, pos, val);
			tree[i] = cal(tree[2*i], tree[2*i+1]); 
		}
	}
	
	pii get(int i, int l, int r, int u, int v){
		if(u > r || v < l) return {1, 1};
		if(u <= l && r <= v) return tree[i];
		
		int mid = (l + r) >> 1;
		pii tmp1 = get(2*i, l, mid, u, v);
		pii tmp2 = get(2*i+1, mid+1, r, u, v);
		return cal(tmp1, tmp2);
	}
};

ll mulMod(ll a, ll b, ll MOD) {
    ll res = 0;
    a %= MOD;
    while (b) {
        if (b & 1) {
            res = (res + a) % MOD;
        }
        a = (a * 2) % MOD;
        b >>= 1;
    }
    
    return res;
}

void solve(){
	cin >> n;
	
	segTree t(n);
	
	FOR(i, 1, n){
		ll val; cin >> val;
		t.update(1, 1, n, i, val);
	}
	cin >> q;
	while(q--){
		int type; cin >> type;
		if(type == 0){
			int pos; ll val; cin >> pos >> val;
			t.update(1, 1, n, pos, val);
		}
		else{
			int l, r; ll MOD; cin >> l >> r >> MOD;
			pii res = t.get(1, 1, n, l, r);
//			SHOW2(res.fi, res.se);
			cout << mulMod(res.fi, res.se, MOD) << endl;
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