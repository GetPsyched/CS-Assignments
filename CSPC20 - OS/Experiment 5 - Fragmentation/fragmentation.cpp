#include <bits/stdc++.h>
using namespace std;

int
main() {
    int total_pages;
    cout << "Enter the number of pages --> "; cin >> total_pages;
    int page_size;
    cout << "Enter the page size --> "; cin >> page_size;
    int total_processes;
    cout << "Enter the number of processes --> "; cin >> total_processes;

    vector<int> process(total_processes);
    vector<int> fragments;
    bool external_frag = false;
    int total_internal_fragmentation = 0;

    for (auto &process_size : process) {
        cout << "Enter the size of the new process --> "; cin >> process_size;
        int required_pages = (process_size + page_size - 1) / page_size;

        if (total_pages < required_pages) {
            if (total_internal_fragmentation >= process_size)
                cout << "Cannot Allocate External Fragmentation occur\n";
            else
                cout << "not enough free space available\n";
        } else {
            total_pages -= required_pages ;
            int full = process_size / page_size;
            int fragment_left = page_size - process_size % page_size;
            cout << "Internal fragmentation --> " << fragment_left << endl;
            total_internal_fragmentation += fragment_left;
        }
    }

    cout << "Total internal fragmentation --> " << total_internal_fragmentation << endl;
    return 0;
}
