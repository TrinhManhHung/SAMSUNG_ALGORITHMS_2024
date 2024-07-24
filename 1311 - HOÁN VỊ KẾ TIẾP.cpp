//Hoan vi ke tiep
#include<bits/stdc++.h>
using namespace std;

void Solve(){
	int n; cin >> n;
	int a[n+1]; a[0] = 0;
	for(int i=1; i<=n; i++) cin >> a[i];
	int idx = n-1;
	while(idx >= 1 && a[idx] > a[idx+1]){
		idx--;
	}
	if(idx == 0){
		for(int i=1; i<=n; i++){
			a[i] = i;
		}
	}
	else{
		for(int j=n; j>=idx+1; j--){
			if(a[j] > a[idx]){
				swap(a[idx], a[j]);
				break;
			}
		}
		sort(a+idx+1, a+n+1);
	}
	for(int i=1; i<=n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
