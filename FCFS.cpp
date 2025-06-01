#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const char  nl = '\n';
class cpu{
    public:
    int process_num;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
int main()
{
    int n;
    cin >> n;
    vector<cpu>algo(n);
    for(int i = 0; i < n; ++i){
        algo[i].process_num = i + 1;
        cin >> algo[i].arrival_time;
        cin >> algo[i].burst_time;
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.arrival_time < b.arrival_time;
    });
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (algo[i].arrival_time > cnt) {
            cnt = algo[i].arrival_time;
        }
        cnt += algo[i].burst_time;
        algo[i].completion_time = cnt;
    }
    int avg_wt = 0, avg_tat = 0;
    for(int i = 0; i < n; ++i){
        algo[i].turn_around_time = algo[i].completion_time - algo[i].arrival_time;
        algo[i].waiting_time = algo[i].turn_around_time - algo[i].burst_time;
        avg_tat += algo[i].turn_around_time;
        avg_wt += algo[i].waiting_time;
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.process_num < b.process_num;
    });
    for(int i = 0; i < n; ++i){
        cout << "p" << algo[i].process_num  << ' ' << algo[i].arrival_time << ' ' << algo[i].burst_time << ' ' << algo[i].completion_time   << ' ' << algo[i].turn_around_time << ' ' << algo[i].waiting_time << nl;
    }
    cout << nl;
    cout << "Average Turn Around Time = " << (float) avg_tat / n  << nl;
    cout << "Average Waiting Time = " << (float) avg_wt / n  << nl;
    return 0;
}