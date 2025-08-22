#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

vector<pair<int, int>> pairs = {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 2}, {2, 3}, {3, 3}, {3, 4}, {4, 4}, {4, 5}};

void solve(int testcase){
    int n; cin >> n;
    int a = 0, b = 0;
    bool g_a = true;
    int base = 1;
    while(n > 0){
        if((n%10)%2 == 0){
            a += pairs[n%10].first * base;
            b += pairs[n%10].second * base;
        }else{
            if(g_a){
                a += pairs[n%10].second * base;
                b += pairs[n%10].first * base;
            }else{  
                a += pairs[n%10].first * base;
                b += pairs[n%10].second * base;
            }
            g_a = !g_a;
        }
        n /= 10;
        base *= 10;
    }

    cout << a << ' ' << b << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}