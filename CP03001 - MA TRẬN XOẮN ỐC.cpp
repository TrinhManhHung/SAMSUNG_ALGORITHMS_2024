//MA TRẬN XOẮN ỐC
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+1][n+1];
    int h1 = 1, h2 = n;
    int c1 = 1, c2 = n;
    int tmp = 1;
    while(h1 <= h2 && c1 <= c2){
        for(int j =c1; j <=c2; j++){
            a[h1][j] = tmp++;
        }
        h1++;
        for(int i =h1; i <=h2; i++){
            a[i][c2] = tmp++;
        }
        c2--;
        if(c1 < c2){
            for(int j =c2; j >=c1; j--){
                a[h2][j] = tmp++;
            }
            h2--;
        }
        if(h1 < h2){
            for(int i =h2; i >=h1; i--){
                a[i][c1] = tmp++;
            }
            c1++;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}