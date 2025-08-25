#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int n; cin >> n;
    int k; cin >> k;
    map<int, string> problem_division;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<n; j++){
            int p; cin >> p;
            problem_division[p] += char(i + '0');
        }
    }

    map<string, int> division_problem;
    for(auto &[problem, division] : problem_division){
        division_problem[division]++;
    }

    for(auto &[division, problem] : division_problem){
        cout << division << ' ' << problem << endl;
    }


    int problems_sponsored = 3*k - 2*division_problem["012"];
    int b = problems_sponsored / 3;
    problems_sponsored -= min(b, division_problem["01"]);
    b -= division_problem["01"];
    cout << " b:" << b << endl;
    cout << problems_sponsored << endl;

    problems_sponsored -= min(max(0, b), division_problem["12"]);

    cout << problems_sponsored << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}