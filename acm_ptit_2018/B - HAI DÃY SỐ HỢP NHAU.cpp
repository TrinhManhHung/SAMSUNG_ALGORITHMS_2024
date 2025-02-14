/*
https://www.spoj.com/PTIT/problems/PTIT018B/
*/
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
const int maxn = 1e6;

void solve(){
	int n; cin >> n;
	int a[n+1], b[n+1];
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	FOR(i, 1, n){
		if(a[i] > b[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	
}

int main(){
    faster();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/** HungLam

	  (\(\
	 ( 0.0)
	o_(")(")
**/

