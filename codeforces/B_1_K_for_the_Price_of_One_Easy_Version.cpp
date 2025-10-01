#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n, p, k; cin >> n >> p >> k;
    vector<int> A(n);
    for(auto &a : A) cin >> a;

    sort(all(A));

    int choice1 = 0;
    int p1 = p;
    int i = 1;
    for(; i < n && p1 >= A[i]; i += 2){
        choice1 += 2;
        p1 -= A[i];
    }
    if(p1 >= A[i - 1] && i < n) choice1++;

    int choice2 = (p >= A[0] ? 1 : 0);
    int p2 = p - A[0];
    i = 2;
    for(; i < n && p2 >= A[i]; i += 2){
        choice2 += 2;
        p2 -= A[i];
    }
    if(p2 >= A[i - 1] && i < n) choice2++;

    cout << max(choice1, choice2) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}