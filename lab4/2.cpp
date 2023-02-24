/*Consider the following Job sequencing with deadline and penalties
problem: No. of jobs = 4, deadlines of job are (J1, J2, J3, J4) = (1, 3,
2, 1), penalty per job is (P1, P2, P3, P4) = (5, 10, 6, 3) and burst time
for each job is (T1, T2, T3, T4) = (1, 2, 1, 1).*/
#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int penalty;
    int time;
};

bool compareJobs(Job a, Job b) {
    return a.penalty > b.penalty;
}

void jobSequence(vector<Job>& jobs, int n) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    vector<int> slot(maxDeadline, -1);

    int totalPenalty = 0;
    int totalJobs = 0;

    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        int j = deadline - 1;
        while (j >= 0 && slot[j] != -1) {
            j--;
        }
        if (j >= 0) {
            slot[j] = jobs[i].id;
            totalPenalty += jobs[i].penalty;
            totalJobs++;
        }
    }

    cout << "Job sequence: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            cout << "J" << slot[i] << " ";
        }
    }
    cout << endl;
    cout << "Total penalty: " << totalPenalty << endl;
    cout << "Total jobs: " << totalJobs << endl;
}

int main() {
    vector<Job> jobs = {{1, 1, 5, 1}, {2, 3, 10, 2}, {3, 2, 6, 1}, {4, 1, 3, 1}};
    int n = jobs.size();
    jobSequence(jobs, n);
    return 0;
}