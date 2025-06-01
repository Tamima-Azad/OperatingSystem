#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const char  nl = '\n';
class cpu{
    public:
    int P, AT, BT, CT, TAT, WT;
};
int main()
{
    int n;
    cin >> n;
    vector<cpu>algo(n);
    for(int i = 0; i < n; ++i){
        algo[i].P = i + 1;
        cin >> algo[i].AT;
        cin >> algo[i].BT;
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.AT < b.AT;
    });
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (algo[i].AT > cnt) {
            cnt = algo[i].AT;
        }
        cnt += algo[i].BT;
        algo[i].CT = cnt;
    }
    int avg_wt = 0, avg_tat = 0;
    for(int i = 0; i < n; ++i){
        algo[i].TAT = algo[i].CT - algo[i].AT;
        algo[i].WT = algo[i].TAT - algo[i].BT;
        avg_tat += algo[i].TAT;
        avg_wt += algo[i].WT;
    }
    // sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
    //     return a.P < b.P;
    // });
    for(int i = 0; i < n; ++i){
        cout << "p" << algo[i].P  << ' ' << algo[i].AT << ' ' << algo[i].BT << ' ' << algo[i].CT   << ' ' << algo[i].TAT << ' ' << algo[i].WT << nl;
    }
    cout << nl;
    cout << "Average Turn Around Time = " << (float) avg_tat / n  << nl;
    cout << "Average Waiting Time = " << (float) avg_wt / n  << nl;
    return 0;
}