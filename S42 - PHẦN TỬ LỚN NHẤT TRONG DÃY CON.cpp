// PHẦN TỬ LỚN NHẤT TRONG DÃY CON

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        deque<int> Q;
        for(int i = 0; i < n; i++){
            while(!Q.empty() && a[i] >= a[Q.back()]){
                Q.pop_back();
            }
            Q.push_back(i);
            if(Q.front() <= i - k){
                Q.pop_front();
            }
            if(i >= k - 1) {
                cout << a[Q.front()] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

