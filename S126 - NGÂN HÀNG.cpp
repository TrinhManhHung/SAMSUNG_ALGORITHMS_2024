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

void solve() {
	int n, q; cin >> n >> q;
	int a[n+1];
	ll pre[n+1]; pre[0] = 0;
	FOR(i, 1, n){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	FOR(i, 1, n){
		pre[i] = pre[i-1] + a[i];
	}
	
	while(q--){
		ll money; cin >> money;
		int maxStudents = upper_bound(pre+1, pre+n+1, money) - pre - 1;
		cout << maxStudents << " ";
		FOR(i, 1, n-maxStudents+1){
			if(pre[i+maxStudents-1] - pre[i-1] > money){
				cout << a[i-1] << endl;
				break;
			}
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

