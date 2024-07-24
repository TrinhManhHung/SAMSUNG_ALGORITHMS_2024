//TẬP CON LIỀN KỀ PHÍA TRƯỚC
#include<bits/stdc++.h>
using namespace std;

void Solve(){
	int n, k; cin >> n >> k;
	int a[k+1]; a[0] = 0;
	for(int i=1; i<=k; i++) cin >> a[i];
	int idx = k;
	while(idx >= 1 && a[idx] == a[idx-1] + 1){
		idx--;
	}
	if(idx == 0){
		for(int i=1; i<=k; i++){
			a[i] = n - k + i;
		}
	}
	else{
		a[idx]--;
		for(int i=idx+1; i<=k; i++){
			a[i] = n - k + i;
		}
	}
	for(int i=1; i<=k; i++) cout << a[i] << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
