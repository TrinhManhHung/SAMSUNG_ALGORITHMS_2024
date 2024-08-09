#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
#define pb push_back
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<float, float>> v;
		
		for(int i =0; i <n; i++){
			float x, y; cin >> x >> y;
			v.pb({x, y});
		}
		
		int F[n]; //F[i] day con dai nhat tinh den vi tri i
		for(int i =0; i <n; i++){
			F[i] = 1;
			for(int j =i-1; j >=0; j--){
				if(v[i].first > v[j].first && v[i].second < v[j].second){
					F[i] = max(F[i], F[j] + 1);
				}
			}
		}
		cout << *max_element(F, F+n) << endl;
	}
}
