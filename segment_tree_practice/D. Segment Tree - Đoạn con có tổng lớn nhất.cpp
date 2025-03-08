//https://codeforces.com/gym/458672/problem/D

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

struct node{
	ll max, pre, suf, sum;
	node(ll _max, ll _pre, ll _suf, ll _sum){
		max = _max;
		pre = _pre;
		suf = _suf;
		sum = _sum;
	}
};

struct segTree{
	int n;
	vector<node> tree;
	segTree(int _n){
		n = _n;
		tree.assign(4*n + 5, node(0, 0, 0, 0));
	}
	
	void update(int i, int l, int r, int pos, ll val){
		if(l == r){
			tree[i] = node(max(val, 0ll), max(val, 0ll), max(val, 0ll), val);
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) update(2*i, l, mid, pos, val);
		else update(2*i+1, mid+1, r, pos, val);
		
		tree[i].max = max({tree[2*i].max, tree[2*i+1].max, tree[2*i].suf + tree[2*i+1].pre});
		tree[i].pre = max(tree[2*i].pre, tree[2*i].sum + tree[2*i+1].pre);
		tree[i].suf = max(tree[2*i+1].suf, tree[2*i+1].sum + tree[2*i].suf);
		tree[i].sum = tree[2*i].sum + tree[2*i+1].sum;
	}
};
void solve() {
    int n, m; cin >> n >> m;
    
    segTree T(n);
    
    FOR(i, 1, n){
    	ll x; cin >> x;
    	T.update(1, 1, n, i, x);
	}
	while(m--){
		int pos; ll val; cin >> pos >> val;
		T.update(1, 1, n, pos, val);
		cout << T.tree[1].max << endl;
	}
}

int main() {
    faster();
//    int t;
//    cin >> t;
//    while (t--) {
        solve();
//    }
    return 0;
}