// BẦU CỬ

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int dem[11]; memset(dem, 0, sizeof(dem));
	int n, m; cin >> n >> m;
	for(int i =1; i <=n; i++){
		int x; cin >> x;
		dem[x]++;
	}
	int max1 = 0, max2 = 0;
	for(int i =1; i <=10; i++){
		if(dem[i] > max1){
			max2 = max1;
			max1 = dem[i];
		}
		else if(dem[i] < max1 && dem[i] > max2){
			max2 = dem[i];
		}
	}
	if(max2 == 0) cout << "NONE";
	else{
		for(int i =1; i <=10; i++){
			if(dem[i] == max2){
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}