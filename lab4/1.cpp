/* Consider the following Job sequencing with deadline problem: No. of
jobs = 9, deadlines of job are (J1, J2, J3, J4, J5, J6, J7, J8, J9) = (7, 2,
5, 3, 4, 5, 2, 7, 3) profit per job is (P1, P2, P3, P4, P5, P6, P7, P8,
P9) = (15, 20, 30, 18, 18, 10, 23, 16, 25).*/

#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compareJobs(const Job& job1, const Job& job2) {
    return job1.profit > job2.profit;
}

int findMaxDeadline(vector<Job>& jobs) {
    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    return maxDeadline;
}

void printJobSequence(vector<int>& jobIds) {
    cout << "Job Sequence: ";
    for (auto jobId : jobIds) {
        cout << "J" << jobId << " ";
    }
    cout << endl;
}

void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);
    int maxDeadline = findMaxDeadline(jobs);
    vector<bool> slot(maxDeadline, false);
    vector<int> jobSequence(maxDeadline, -1);
    for (auto job : jobs) {
        for (int i = job.deadline - 1; i >= 0; i--) {
            if (!slot[i]) {
                slot[i] = true;
                jobSequence[i] = job.id;
                break;
            }
        }
    }
    printJobSequence(jobSequence);
}

int main() {
    vector<Job> jobs = {
        {1, 7, 15},
        {2, 2, 20},
        {3, 5, 30},
        {4, 3, 18},
        {5, 4, 18},
        {6, 5, 10},
        {7, 2, 23},
        {8, 7, 16},
        {9, 3, 25}
    };

    jobSequencing(jobs);

    return 0;
}