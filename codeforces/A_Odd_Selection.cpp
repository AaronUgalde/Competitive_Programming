#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int n, x; cin >> n >> x;
    int evens = 0, odds = 0;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        if(x % 2 == 0) evens++;
        else odds++;
    }

    if(odds == 0){
        cout << "NO\n";
        return;
    }

    odds--; x--;

    if(x <= evens){
        cout << "YES\n";
        return;
    }

    if(evens){
        if((x - evens) % 2 != 0){
            x -= evens - 1;
        }else{
            x -= evens;
        }
    }

    if(odds >= x && x % 2 == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}