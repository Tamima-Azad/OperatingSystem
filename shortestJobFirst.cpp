#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';

class cpu {
public:
    int process_num;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main() {
    int n;
    cin >> n;
    vector<cpu> algo(n);
    
    // Input processes
    for (int i = 0; i < n; ++i) {
        algo[i].process_num = i + 1;
        cin >> algo[i].arrival_time >> algo[i].burst_time;
    }

    // Sort processes by arrival time first
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.arrival_time < b.arrival_time;
    });

    // Implement SJF scheduling (Non-Preemptive)
    int current_time = 0, completed = 0;
    vector<bool> is_completed(n, false);
    int avg_wt = 0, avg_tat = 0;

    while (completed < n) {
        int idx = -1;
        int min_burst = INT_MAX;

        // Find the process with the shortest burst time in the ready queue
        for (int i = 0; i < n; ++i) {
            if (!is_completed[i] && algo[i].arrival_time <= current_time) {
                if (algo[i].burst_time < min_burst) {
                    min_burst = algo[i].burst_time;
                    idx = i;
                }
            }
        }

        // If no process is ready, move time forward
        if (idx == -1) {
            current_time++;
        } else {
            // Process execution
            current_time += algo[idx].burst_time;
            algo[idx].completion_time = current_time;
            algo[idx].turn_around_time = algo[idx].completion_time - algo[idx].arrival_time;
            algo[idx].waiting_time = algo[idx].turn_around_time - algo[idx].burst_time;
            avg_tat += algo[idx].turn_around_time;
            avg_wt += algo[idx].waiting_time;

            // Mark process as completed
            is_completed[idx] = true;
            completed++;
        }
    }

    // Restore original process order
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.process_num < b.process_num;
    });

    // Output process details
    for (int i = 0; i < n; ++i) {
        cout << "p" << algo[i].process_num << ' ' << algo[i].arrival_time << ' ' 
             << algo[i].burst_time << ' ' << algo[i].completion_time << ' ' 
             << algo[i].turn_around_time << ' ' << algo[i].waiting_time << nl;
    }

    // Output average TAT and WT
    cout << nl;
    cout << "Average Turn Around Time = " << (float) avg_tat / n << nl;
    cout << "Average Waiting Time = " << (float) avg_wt / n << nl;

    return 0;
}
