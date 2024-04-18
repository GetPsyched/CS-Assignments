#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>

#include "utils.cpp"
#include "first_come_first_served.cpp"

#include "sjf_priority_common.cpp"
// #include "shortest_job_first.cpp"
// #include "priority.cpp"

#include "round_robin.cpp"
#include "multi_level_queue.cpp"

using namespace std;

void
clrscr() { cout << "\033[2J\033[1;1H"; }

void
wait() {
    cout << endl << "Press enter to continue...";
    cin.get(); cin.get();
}

void
unimplemented() {
    cout << "This algorithm has not been implemented yet!\n";
}

int
main() {
    int i, n;

    map<string, void (*)()> algos;
    algos["First-Come, First Served"] = &FCFS;
    algos["Shortest-Job-First (non-pre-emptive)"] = &SJF;
    algos["Shortest-Job-First (pre-emptive)"] = &SRTF;
    algos["Priority (non-pre-emptive)"] = &Priority;
    algos["Priority (pre-emptive)"] = &PriorityPreEmptive;
    algos["Round-Robin"] = &RR;
    algos["Multilevel Queue"] = &unimplemented;
    algos["Multilevel Feedback Queue"] = &unimplemented;
    algos["Rate-Monotonic"] = &unimplemented;
    algos["Earliest-Deadline-First"] = &unimplemented;
    algos["Proportional Share"] = &unimplemented;

    map<string, void (*)()>::const_iterator begin;
    map<string, void (*)()>::const_iterator end;

    while (true) {
        clrscr();
        begin = algos.begin();
        end = algos.end();

        i = 0;
        while ( begin != end ) {
            cout << ++i << ". " << begin->first << endl;
            ++begin;
        }
        cout << ++i << ". Exit" << endl;

        cout << endl << "Enter your choice --> ";
        cin >> n;

        if (n == i)
            return EXIT_SUCCESS;

        // Execute the scheduling algorithm
        clrscr();
        begin = algos.begin();
        advance(begin, n - 1);
        (begin->second)();
        wait();
    }

    return EXIT_SUCCESS;
}