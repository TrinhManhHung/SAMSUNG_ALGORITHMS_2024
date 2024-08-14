#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod (ll)(1e9 + 7)
#define endl "\n"

const int maxn = 2000000;
ll sumPrime[2000005];

void solve(){
	for(int i =2; i <=maxn; i++){
		//ktra i co phai so nt
		if(sumPrime[i] == 0){
			for(int j =i; j <=maxn; j+=i){
				int k = j;
				while(k % i == 0){
					sumPrime[j] += i;
					k /= i;
				}
			}
		}
	}
}

int main(){
	memset(sumPrime, 0, sizeof(sumPrime));
	solve();
	int t; cin >> t;
	ll res = 0;
	while(t--){
		int n; cin >> n;
		res += sumPrime[n];
	}
	cout << res << endl;
}
