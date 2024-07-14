//Noi day

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
void Solve(){
	priority_queue<ll, vector<ll>, greater<ll>> q;
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		ll x; cin >> x;
		q.push(x);
	}
	ll cost = 0;
	while(q.size() != 1){
		ll day1 = q.top(); q.pop();
		ll day2 = q.top(); q.pop();
		ll newDay = day1 + day2;
		cost += newDay;
		q.push(newDay);
	}
	cout << cost << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
