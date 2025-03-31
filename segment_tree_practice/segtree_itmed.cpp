// https://oj.vnoi.info/problem/segtree_itmed

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
const ll mi = LLONG_MIN;

struct segmentTree{
	int n;
	vll tree;
	
	segmentTree(int _n){
		n = _n;
		tree.assign(4*n+5, 0);
	}
	
	void update(int i, int l, int r, int pos, ll val){
		if(l == r) {
			tree[i] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) update(2*i, l, mid, pos, val);
		else update(2*i+1, mid+1, r, pos, val);
		tree[i] = max(tree[2*i], tree[2*i+1]);
	}
	
	ll get(int i, int l, int r, int u, int v){
		if(r < u || l > v){
			return mi;
		}
		if(u <= l && r <= v){
			return tree[i];
		}
		int mid = (l + r) >> 1;
		return max(get(2*i, l, mid, u, v), get(2*i+1, mid+1, r, u, v)); 
	}
};

void solve(){
	int n, k; cin >> n >> k;
	segmentTree t(n);
	ll a[n+1];
	FOR(i, 1, n){
		cin >> a[i];
	}

	ll dp[n+1] = {0}; //dp[i]: max money neu su dung den mon qua i
	FOR(i, 1, n){
		dp[i] = max(0ll, t.get(1, 1, n, max(1, i-k), max(1, i-1))) + a[i];
		t.update(1, 1, n, i, dp[i]);
	}
	
	ll res = *max_element(dp+1, dp+n+1);
	cout << max(res, 0ll) << endl;
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
