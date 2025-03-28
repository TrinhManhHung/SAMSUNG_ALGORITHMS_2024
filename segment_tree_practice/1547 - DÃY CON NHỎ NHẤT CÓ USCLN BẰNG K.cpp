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
const int maxn = 1e9 + 1;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

struct segTree{
	int n;
	vi tree;
	
	segTree(int _n){
		n = _n;
		tree.assign(4*_n + 5, maxn);
	}
	
	void update(int i, int l, int r, int pos, int val){
		if(l == r){
			tree[i] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) update(2*i, l, mid, pos, val);
		else update(2*i+1, mid+1, r, pos, val);
		tree[i] = gcd(tree[2*i], tree[2*i+1]);
	}
	
	int get(int i, int l, int r, int k){
		if(l == r) return (tree[i] == k ? 1 : maxn);
		if(tree[i] > k || (l > r)){
			return maxn;
		}
		
		int mid = (l + r) >> 1;
		int left = get(2*i, l, mid, k);
		int right = get(2*i+1, mid+1, r, k);
        
		if(tree[i] == k){
			return min({r-l+1, left, right});
		}
		else return min(left, right);
	}
};

void solve(){
	int n, k; cin >> n >> k;
	segTree t(n);
	int a[n+1];
	FOR(i, 1, n){
		cin >> a[i];
		t.update(1, 1, n, i, a[i]);
	}
	
//	FOR(i, 1, 4*n){
//		cout << t.tree[i] << " ";
//	}
//	cout << endl;
	
	int res = t.get(1, 1, n, k);
	cout << (res == maxn? -1 : res) << endl;
}

int main() {
    faster();
    int t = 1; 
	cin >> t;
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

