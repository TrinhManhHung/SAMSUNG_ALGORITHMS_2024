// DÃY SỐ BI-TONIC

#include<bits/stdc++.h>
using namespace std;

void increaseLeft(int a[], int n, int left[]){
    left[0] = 0;
    for(int i =1; i <=n; i++){
        left[i] = a[i];
        for(int j =1; j<i; j++){
            if(a[i] > a[j]){
                left[i] = max(left[i], left[j] + a[i]);
            }
        }

    }
}

void increaseRight(int a[], int n, int right[]){
    right[0] = 0;
    for(int i =n; i >=1; i--){
        right[i] = a[i];
        for(int j =n; j > i; j--){
            if(a[i] > a[j]){
                right[i] = max(right[i], right[j] + a[i]);
            }
        }

    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        for(int i =1; i <=n; i++) cin >> a[i];
        int left[n+1], right[n+1];
        increaseLeft(a, n, left);
        increaseRight(a, n, right);
        int res = 0;
        for(int i =1; i <=n; i++){
            res = max(res, left[i] + right[i] - a[i]);
        }
        cout << res << endl;
    }
    return 0;
}