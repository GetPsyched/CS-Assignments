#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

class Process {
  public:
  int name ;
  vector<int> allocated;
  vector<int> needed;
  vector<int> maximum ;
  int totalNeeded ;
  Process() {/*No Arg Constructor*/}
  Process(vector<int> &_allocated, vector<int> &_needed, vector<int> &_maximum, int _name) {
    // arged Constructor
    this->name = _name ;
    totalNeeded = 0 ;
    for(int i = 0; i < _allocated.size(); i++) {
      this->allocated.push_back(_allocated[i]) ;
    }

    for(int i = 0; i < _needed.size(); i++) {
      this->needed.push_back(_needed[i]) ;
      totalNeeded += _needed[i] ;
    }

    for(int i=0;i < _maximum.size(); i++) {
      this->maximum.push_back(_maximum[i]) ;
    }
  }
};

void checkSafeSeq(vector<Process*> processes, vector<int> &available, int numResouces, int &count) {
  // Base Case
  if(count == processes.size()) {
    return ;
  }

  for(int i = 0; i < processes.size(); i++) {
    bool canBeTaken = true ;
    for(int j = 0; j < numResouces; j++) {
      if((processes[i]->needed[j] > available[j]) || (processes[i]->needed[j] < 0)) {
        canBeTaken = false ;
        break ;
      }
    }

    if(canBeTaken) {
      for(int j = 0; j < numResouces; j++) {
        processes[i]->needed[j] = -1 ;
        available[j] += processes[i]->maximum[j] ;
      }
      count++ ;
      cout << "Process Name: " << processes[i]->name << endl ;
      checkSafeSeq(processes, available, numResouces, count) ;
    }
  }
}

int main() {
  cout << "Enter the number of processes: " ;
  int numProcesses ; cin >> numProcesses ;
  cout << "Enter the number of resources: " ;
  int numResouces ; cin >> numResouces ;

  vector<int> available(numResouces) ;
  vector<Process*> processes(numProcesses) ;

  vector<int> maxInstances(numResouces) ;
  vector<int> maxNeeded(numResouces) ;

  // getting the available resources as input
  for(int i = 0; i < numResouces; i++) {
    cout << "Enter the number of instances available of resource " << i+1 << ": " ;
    cin >> available[i] ;
    maxInstances[i] += available[i] ;
  }


  // getting the processes as input
  for(int i = 0; i < numProcesses ; i++) {
    cout << "Enter the details of Process " << i+1 << ": " ;
    cout << "Allocated: " << endl ;
    vector<int> _allocated(numResouces) ;

    for(int j = 0; j < numResouces ; j++) {
      cout << "Resource " << j+1 << ": " ;
      cin >> _allocated[j] ;
      maxInstances[j] += _allocated[j] ;
    }

    vector<int> _maximum(numResouces) ;
    cout << "Maximum Needed: " << endl ;
    for(int j = 0; j  < numResouces ; j++) {
      cout << "Resource: " << j+1 << ": " ;
      cin >> _maximum[j] ;
      maxNeeded[j] = max(maxNeeded[j], _maximum[j]) ;
    }

    vector<int> _needed(numResouces) ;
    for(int j = 0; j < numResouces; j++) {
      _needed[j] = _maximum[j] - _allocated[j] ;
    }

    processes[i] = new Process(_allocated, _needed, _maximum, i+1) ;
  }


  //Peforming Initial check
  for(int i = 0; i < numResouces; i++) {
    if(maxNeeded[i] > maxInstances[i]) {
      cout << "with the provided information about needs of the processses and maximum available instances of all the resources it is not possible to generate a safe sequence of processes, because the maximum need of resouce " << i+1 << " is: " << maxNeeded[i] << " and the maximum instances of this resource are: " << maxInstances[i] << endl ;
      return 0;
    }
  }

  int count = 0 ;
  cout << endl << "Safe Sequence is" << endl ;
  checkSafeSeq(processes, available, numResouces, count) ;
  return 0;
}

