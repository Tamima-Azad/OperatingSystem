#include <bits/stdc++.h>
using namespace std;

class CPU
{
public:
    int process_num;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void round_robin_scheduling(vector<CPU> &processes, int time_quantum)
{
    int n = processes.size();
    queue<int> q;
    vector<bool> in_queue(n, false);
    int current_time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    // Sorting processes by arrival time
    sort(processes.begin(), processes.end(), [](const CPU &a, const CPU &b)
         { return a.arrival_time < b.arrival_time; });

    // Push first arrived process into the queue
    q.push(0);
    in_queue[0] = true;

    while (completed < n)
    {
        int index = q.front();
        q.pop();

        // Process execution
        if (processes[index].remaining_time > time_quantum)
        {
            current_time += time_quantum;
            processes[index].remaining_time -= time_quantum;
        }
        else
        {
            current_time += processes[index].remaining_time;
            processes[index].remaining_time = 0;
            processes[index].completion_time = current_time;
            processes[index].turn_around_time = processes[index].completion_time - processes[index].arrival_time;
            processes[index].waiting_time = processes[index].turn_around_time - processes[index].burst_time;

            avg_wt += processes[index].waiting_time;
            avg_tat += processes[index].turn_around_time;
            completed++;
        }

        // Enqueue new processes that have arrived
        for (int i = 0; i < n; i++)
        {
            if (!in_queue[i] && processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
            {
                q.push(i);
                in_queue[i] = true;
            }
        }

        // Re-add the current process if it has remaining execution time
        if (processes[index].remaining_time > 0)
        {
            q.push(index);
        }
    }

    // Output results
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processes[i].process_num << "\t"
             << processes[i].arrival_time << "\t"
             << processes[i].burst_time << "\t"
             << processes[i].completion_time << "\t"
             << processes[i].turn_around_time << "\t"
             << processes[i].waiting_time << endl;
    }

    cout << "\nAverage Turnaround Time = " << fixed << setprecision(2) << avg_tat / n << endl;
    cout << "Average Waiting Time = " << fixed << setprecision(2) << avg_wt / n << endl;
}

int main()
{
    int n, time_quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<CPU> processes(n);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].process_num = i + 1;
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    round_robin_scheduling(processes, time_quantum);

    return 0;
}
