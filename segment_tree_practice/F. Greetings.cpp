//https://codeforces.com/contest/1915/problem/F

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

int a[maxn+5];
vi segTree[4*maxn+5];

void build(int v, int tl, int tr){
	if(tl == tr){
		segTree[v].pb(a[tl]);
	}
	else{
		int mid = (tl + tr) / 2;
		build(2*v, tl, mid);
		build(2*v+1, mid+1, tr);
		merge(segTree[2*v].begin(), segTree[2*v].end(), segTree[2*v+1].begin(), segTree[2*v+1].end(), back_inserter(segTree[v]));
	}
}

int query(int v, int tl, int tr, int l, int r, int K){
	if(l > r) return 0;
	if(tl == l && tr == r){
		return segTree[v].end() - upper_bound(segTree[v].begin(), segTree[v].end(), K);
	}
	else{
		int mid = (tl + tr) / 2;
		return query(2*v, tl, mid, l, min(mid, r), K) + query(2*v+1, mid+1, tr, max(mid+1, l), r, K);
	}
}

bool cmp(pii a, pii b){
	return a.fi > b.fi;
}

void solve() {
	int n; cin >> n;
	FOR(i, 1, n){
		a[i] = 0;
	}
	FOR(i, 1, 4*n) segTree[i].clear();
	
	vector<pii> v;
	FOR(i, 1, n){
		int x, y; cin >> x >> y;
		v.pb({x, y});
	}
	sort(v.begin(), v.end(), cmp);
	FOR(i, 1, n){
		a[i] = v[i-1].se;
	}
	build(1, 1, n);
	
	ll res = 0;
	FOR(i, 1, n-1){
		res += query(1, 1, n, i+1, n, a[i]);
	}
	cout << res << endl;
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