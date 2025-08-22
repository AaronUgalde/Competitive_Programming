#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int n;

vector<int> ans(int take_2, vector<int> v){
    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(v[i] == 2){
            ans.push_back(i);
            ans.push_back(i);
            take_2--;
        }
        if(take_2 == 0){
            break;
        }
    }

    return ans;
}

void solve(int testcase){
    int k; cin >> n >> k;
    vector<int> a(n+1, 0), b(n+1, 0);
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        a[x]++;
    }
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        b[x]++;
    }

    int n_1 = 0;
    int n_2 = 0;
    for(int i = 1; i<=n; i++){
        if(a[i] == 1){
            n_1++;
        }else if(a[i] == 2){
            n_2++;
        }
    }

    int exedente = max(0, k - n_2);
    int take_2 = k - exedente;
    int take_1 = exedente*2;

    for(int)

    vector<int> asn_a = ans(take_2, a);
    vector<int> asn_b = ans(take_2, b);

    for(int i = 0; i<2*k; i++){
        cout << asn_a[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i<2*k; i++){
        cout << asn_b[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        cout << "test: " << i << endl;
        solve(i);
    }
}