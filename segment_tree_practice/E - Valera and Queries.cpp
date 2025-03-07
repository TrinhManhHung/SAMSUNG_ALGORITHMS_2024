//https://codeforces.com/contest/369/problem/E

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
const int maxn = 300000;

int n, q;
int a[maxn+5], b[maxn+5];

struct segTree{
	int n;
	vvi seg;
	
	segTree(int _n){
		n = _n;
		seg.assign(4*n + 5, vi(0));
	}
	
	void build(int i, int l, int r){
		if(l == r){
			seg[i].pb(a[l]);
			return;
		}	
		int mid = (l+r) >> 1;
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);
		//merge and sort
		merge(seg[2*i].begin(), seg[2*i].end(),
			seg[2*i+1].begin(), seg[2*i+1].end(),
			back_inserter(seg[i]));
	}
	
	int get(int i, int l, int r, int u, int v, int p) {
        if (u > r || v < l) return 0; // Không giao nhau
        if (u <= l && r <= v) { // Ðo?n hi?n t?i n?m hoàn toàn trong [u, v]
            return seg[i].size() - (lower_bound(seg[i].begin(), seg[i].end(), p) - seg[i].begin());
        }
        int mid = (l + r) >> 1;
        return get(2 * i, l, mid, u, v, p) + get(2 * i + 1, mid + 1, r, u, v, p);
    }
};

void solve(){
	cin >> n >> q;
	vector<pii> v(n+1);
	FOR(i, 1, n){
		cin >> v[i].fi >> v[i].se;
	}
	sort(v.begin()+1, v.begin()+n+1);
	
	FOR(i, 1, n){
		a[i] = v[i].se;
		b[i] = v[i].fi;
	}
	
	segTree tree(n);
	tree.build(1, 1, n);
	
	
	while(q--){
		ll ans = 0;
		int m; cin >> m;
		int curLeft = 1;
		FOR(i, 1, m){
			int p; cin >> p;
			int u = curLeft;
			int v = upper_bound(b+1, b+n+1, p) - b - 1;
			if(u > v) continue;
			curLeft = v+1;
			ans += tree.get(1, 1, n, u, v, p);
//			SHOW1(v);
//			cout << tree.get(1, 1, n, u, v, p) << endl;
		}
		cout << ans << endl;
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