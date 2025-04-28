#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_X = 1000005;

ll divisors[MAX_X];

void solve(int testcase){
    int x; cin >> x;
    cout << divisors[x] << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for(int i = 1; i < MAX_X; i++){
        for(int j = i; j < MAX_X; j += i){
            divisors[j]++;
        }
    }

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}