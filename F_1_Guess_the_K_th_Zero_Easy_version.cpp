#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, t; cin >> n >> t;
    int k; cin >> k;

    int low = - 1, high = n;

    auto number_zeros = [&](int mid){
        cout << "? " << 1 << ' ' << mid + 1 << endl;
        int sum; cin >> sum;
        return mid - sum + 1;
    };

    while(high - low > 1){
        int mid = midpoint(low, high);
        if(number_zeros(mid) > k - 1){
            high = mid;
        }else{
            low = mid;
        }
    }

    cout << "! " << high + 1 << endl; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}