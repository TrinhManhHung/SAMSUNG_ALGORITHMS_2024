//https://codeforces.com/gym/458672/problem/F

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
	vi tree; //moi node se luu so so 1 trong doan [l, r]
	segTree(int _n){
		n = _n;
		tree.assign(4*n + 5, 0);
	}
	
	void update(int i, int l, int r, int pos, int val){
		if(l == r){
			tree[i] = (val != -1? val : 1-tree[i]);
			return;
		}
		else{
			int mid = (l + r) >> 1;
			if(pos <= mid) update(2*i, l, mid, pos, val);
			else update(2*i+1, mid+1, r, pos, val);
			tree[i] = tree[2*i] + tree[2*i+1];
		}
	}
	
	int find(int i, int l, int r, int k){
		if(l == r){
			return l;
		}
		int mid = (l+r) >> 1;
		if(k > tree[2*i]) find(2*i+1, mid+1, r, k-tree[2*i]);
		else find(2*i, l, mid, k);
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
		int type; cin >> type;
		if(type == 1){
			int x; cin >> x;
			T.update(1, 1, n, x, -1);
		}
		else{
			int k; cin >> k;
			cout << T.find(1, 1, n, k) << endl;
		}
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