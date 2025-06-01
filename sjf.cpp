#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';
#ifdef ONLINE_JUDGE
#define debug(...) 27
#define debug_array(x, y) 27
#else
#endif
class cpu
{
public:
    int process_num;
    int arrival_time;
    int brust_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    bool check;
};
int32_t main()
{
    cout<<"Enter no of process: "<<endl;
    int n;
    cin >> n;
    vector<cpu> algo(n);
    cout<<" AT:  BT: "<<endl;
    for (int i = 0; i < n; ++i)
    {
        algo[i].process_num = i + 1;
        cin >> algo[i].arrival_time;
        cin >> algo[i].brust_time;
        algo[i].check = false;
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b)
         { return a.arrival_time < b.arrival_time; });
    int cnt = algo[0].arrival_time, waiting_time = 0, cnt1 = 0;
    int avg_wt = 0, avg_tat = 0;
    for(int i = 0; i < n; ++i){
        int mini = algo[i].brust_time;
        int ind = i;
        for(int j = 0; j < n; ++j){
            if(algo[j].arrival_time <= cnt and algo[j].brust_time < mini and algo[j].check == false){
                mini = algo[j].brust_time;
                ind = j;
            }
        }
        swap(algo[i].process_num, algo[ind].process_num);
        swap(algo[i].arrival_time, algo[ind].arrival_time);
        swap(algo[i].brust_time, algo[ind].brust_time);
        if(algo[i].arrival_time > cnt){
            waiting_time++;
        }
            cnt += algo[i].brust_time;
            algo[i].completion_time = cnt;
            algo[i].check = true;
            algo[i].turn_around_time = algo[i].completion_time - algo[i].arrival_time;
            algo[i].waiting_time = algo[i].turn_around_time - algo[i].brust_time;
            avg_tat += algo[i].turn_around_time;
            avg_wt += algo[i].waiting_time;
    }
     sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b)
         { return a.process_num < b.process_num; });
    for (int i = 0; i < n; ++i)
    {
        cout << "p" << algo[i].process_num << ' ' << algo[i].arrival_time << ' ' << algo[i].brust_time << ' ' << algo[i].completion_time << ' ' << algo[i].turn_around_time << ' ' << algo[i].waiting_time << nl;
    }
    if (waiting_time > 0)
    {
        cout << "CPU was free for " << waiting_time << " period time\n";
    }
    cout << nl;
    cout << "Average Turn Around Time = " << (float)avg_tat / n << nl;
    cout << "Average Waiting Time = " << (float)avg_wt / n << nl;
    system(" color F0");
    return 0;

}
