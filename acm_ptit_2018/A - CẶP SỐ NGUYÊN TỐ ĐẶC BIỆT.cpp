/*
https://www.spoj.com/PTIT/problems/PTIT018A/
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
int isPrime[maxn + 5];
int cnt[maxn+5];

void prepare(){
	FOR(i, 1, maxn) isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	
	FOR(i, 2, 1000){
		if(isPrime[i]){
			for(int j =i*i; j <=maxn; j +=i) isPrime[j] = 0;		
		}
	}
	
	FOR(i, 6, maxn){
		cnt[i] = cnt[i-1];
		if(isPrime[i] && isPrime[i-6]) cnt[i]++;
	}
}

void solve(){
	int l, r; cin >> l >> r;
	cout << cnt[r] - cnt[l+5] << endl;
}

int main(){
    faster();
    prepare();
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

