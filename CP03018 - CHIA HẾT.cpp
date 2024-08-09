#include<bits/stdc++.h>
using namespace std;
#define ll long long

void process(ll x, map<ll, int> &pta){
	for (ll i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            pta[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        pta[x]++;
    }
}
int main(){
	int n, m; cin >> n >> m;
	ll a[n], b[n];
	for(int i =0; i <n; i++)
		cin >> a[i];
		
	map<ll, int> pta;
	pta[1] = 1;
	
	for(int i =0; i <n; i++){
		ll tmp = a[i];
		process(tmp, pta);
	}
	
	vector<int> res;
	int idx = 1;
	while(idx <= m){
		for(int i =0; i <n; i++) cin >> b[i];
		map<ll, int> ptb;
		for(int i =0; i <n; i++){
			ll tmp = b[i];
			process(tmp, ptb);
		}
		
		bool check = true;
		for(auto x : ptb){
			if(pta.find(x.first) == pta.end() || pta[x.first] < x.second){
				check = false;
				break;
			}
		}
		if(check) res.push_back(idx);
		idx++;
	}
	
	cout << res.size() << endl;
	for(auto x : res) cout << x << " ";
	return 0;
}

