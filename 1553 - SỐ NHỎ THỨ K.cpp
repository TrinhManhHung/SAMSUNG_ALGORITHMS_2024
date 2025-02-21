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
const int maxn = 100000;
//
//int a[maxn+5];
//vi segTree[4*maxn+5];
//
//void build(int v, int tl, int tr){
//	if(tl == tr){
//		segTree[v].pb(a[tl]);
//	}
//	else{
//		int mid = (tl + tr) / 2;
//		build(2*v, tl, mid);
//		build(2*v+1, mid+1, tr);
//		merge(segTree[2*v].begin(), segTree[2*v].end(), segTree[2*v+1].begin(), segTree[2*v+1].end(), back_inserter(segTree[v]));
//	}
//}
//
//int query(int v, int tl, int tr, int l, int r, int K){
//	if(l > r) return 0;
//	if(tl == l && tr == r){
//		return segTree[v].end() - upper_bound(segTree[v].begin(), segTree[v].end(), K);
//	}
//	else{
//		int mid = (tl + tr) / 2;
//		return query(2*v, tl, mid, l, min(mid, r), K) + query(2*v+1, mid+1, tr, max(mid+1, l), r, K);
//	}
//}
//
//void solve() {
//	int n; cin >> n;
//	FOR(i, 1, n) cin >> a[i];
//	build(1, 1, n);
//	
//	int q; cin >> q;
//	while(q--){
//		int u, v, K; cin >> u >> v >> K;
//		cout << query(1, 1, n, u, v, K) << endl;
//	}	
//}

void solve1(){
	int n, q; cin >> n >> q;
	int b[n+1];
	FOR(i, 1, n) cin >> b[i];
	while(q--){
		int u, v, K; cin >> u >> v >> K;
		vi tmp(b+u, b+v+1);
		sort(tmp.begin(), tmp.end());
		cout << tmp[K-1] << endl;
	}
}

int main() {
    faster();
//    int t; cin >> t;
//    while (t--) {
        solve1();
//    }
    return 0;
}

/** HungLam

	  (\(\
	 ( 0.0)
	o_(")(")
**/
