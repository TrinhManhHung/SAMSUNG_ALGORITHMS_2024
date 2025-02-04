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
#define INF 1e9
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
int n, k; 
int tong, res;
int a[20];

void Try(int i, int cnt, int cursum){
	if(i > n) return;
	if(cursum + a[i] == tong){
		if(cnt == k-1){
			res++;
			return;
		}
		else Try(i+1, cnt+1, 0);
	}
	Try(i+1, cnt, cursum + a[i]);
}
void solve(){
	cin >> n >> k;
	int sum = 0;
	FOR(i, 1, n){
		cin >> a[i];
		sum += a[i];
	}
	res = 0;
	if(abs(sum) % k != 0) {
		cout << 0 << endl;
	}
	else{
		tong = sum / k;
		Try(1, 0, 0);
		cout << res << endl;
	}
}

int main(){
    faster();
//    int t; cin >> t;
//    while(t--){
        solve();
//    }
    return 0;
}

/** HungLam

	  (\(\
	 ( 0.0)
	o_(")(")
**/
