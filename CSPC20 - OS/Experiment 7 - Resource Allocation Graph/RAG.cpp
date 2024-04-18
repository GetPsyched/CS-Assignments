#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph {
public:
    int numResources, numProcesses;
    map<string, list<string>> adjList;
    vector<string> resources;
    vector<string> processes;

    Graph(int _numResources, int _numProcesses) {
        numResources = _numResources;
        numProcesses = _numProcesses;

        cout << "Resources: " << numResources << endl;
        cout << "Process: " << numProcesses << endl;
    }

    void getInputs() {
        cout << "Enter the name of all the resources" << endl;

        for(int i = 0; i < numResources; i++ ) {
            cout << "Resource " << i <<": ";
            string str; cin >> str;
            resources.push_back(str);
        }

        cout << "Enter the name of all the processe" << endl;
        for(int i = 0; i < numProcesses; i++) {
            cout << "Process " << i <<": ";
            string str; cin >> str;
            processes.push_back(str);
        }
    }

    void getAssignmentEdge(int numEdges) {
        for(int j = 0; j < numEdges; j++) {
            cout << "Enter the number corresponding the resource" << endl;
            for(int i = 0; i < numResources; i++)
                cout << i << " " << resources[i] << endl;
            int src; cin >> src;

            cout << "Enter the number corresponding the process" << endl;
            for(int i = 0; i < numProcesses; i++)
                cout << i << " " << processes[i] << endl;
            int dest; cin >> dest;

            adjList[resources[src]].push_back(processes[dest]);
                cout << "Added assignment edge from resource " << resources[src] << " to process " << processes[dest] << endl;
        }
    }

    void getRequestEdge(int numEdges) {
        for(int j = 0; j < numEdges; j++){
            cout << "Enter the number corresponding the resource" << endl;
            for(int i = 0; i < numResources; i++)
                cout << i << " " << resources[i] << endl;
            int src; cin >> src;

            cout << "Enter the number corresponding the process" << endl;
            for(int i = 0; i < numProcesses; i++)
                cout << i << " " << processes[i] << endl;
            int dest; cin >> dest;

            adjList[processes[dest]].push_back(resources[src]);
            cout << "added request edge from process " << processes[dest] << " to resource " << resources[src] << endl;
        }
    }

    bool cycleDetection(int src) {
        map<string, bool> visited;
        for(int i = 0; i < numProcesses; i++)
            visited[resources[i]] = false;
        for(int i = 0; i < numProcesses; i++)
            visited[processes[i]] = false;

        queue<string> q;
        q.push(resources[src]);

        while(!q.empty()) {
            string first = q.front();
            visited[first] = true;
            q.pop();
            cout << first << endl;
            for(auto edge: adjList[first]) {
                if(visited[edge] == true)
                    return true;
                q.push(edge);
            }
        }
        return false;
    }
};

int
main() {
    cout << "Enter the number of resource: "; int numResources; cin >> numResources;
    cout << "Enter the number of processes: "; int numProcesses; cin >> numProcesses;
    Graph *allocationGraph = new Graph(numResources, numProcesses);
    allocationGraph->getInputs();
    cout << "Enter the number of request edges: "; int requests; cin >> requests;
    cout << "Enter the number of assignment edges: "; int assigs; cin >> assigs;

    cout << "Enter the request edges!" << endl;
    allocationGraph->getRequestEdge(requests);

    cout << "Enter the assignment edges!" << endl;
    allocationGraph->getAssignmentEdge(assigs);


    bool isDeadLocked = allocationGraph->cycleDetection(0);
    if(isDeadLocked) {
      cout << "A deadlock is present, as there is a cycle in the graph!" << endl;
    } else {
      cout << "The system is in safe state!" << endl;
    }
    return 0;
}
