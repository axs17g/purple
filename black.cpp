#include <iostream>
#include "p2queue.h"
#include "p2priorityqueue.h"
#include "p2stack.h"
using namespace std;

int main()
{
  //declaring and initializing PriorityQueue, Queue and Stack to check the black box
  PriorityQueue<int, int> pq;
  Queue<int> q;
  Stack<int> s;
  initialize(pq);
  initialize(q);
  initialize(s);

  //declaring bools that will be used to check the satisfaction of commands with pq, q and s
  bool isPQ = true, isQ = true, isS = true, finalPQ = true, finalQ = true, finalS = true;
  //variables to store commands in
  string type;
  int val;

  cout << "Command: ";
  cin >> type >> val;
  while (type != "END")
  {
    //pushes the value to the pq, q, s if it is PUSH
    if (type == "PUSH"){
      push(pq, val, val);
      push(q, val);
      push(s, val);
    }
    //similarly, pops form pq, q, s if it is POP
    if (type == "POP"){
      isPQ = (pop(pq) == val);
      isQ = (pop(q) == val);
      isS = (pop(s) == val);
    }
    //sets the final bools to false if any of the expected case if failed
    if (!isPQ)
      finalPQ = false;
    if (!isQ)
      finalQ = false;
    if (!isS)
      finalS = false;
    cout << "Command: ";
    cin >> type >> val;
  }

  //prints out the type of holding accordingly
  if (!finalPQ && !finalQ && !finalS)
    cout << "The black box holds something else.";
  else if ((finalPQ && finalS) || (finalPQ && finalQ) || (finalQ && finalS) )
    cout << "The black box remains mysterious.";
  else if (finalPQ)
    cout << "The black box holds a priority queue.";
  else if (finalS)
    cout << "The black box holds a stack.";
  else if (finalQ)
    cout << "The black box holds a queue.";

  //our contract is to destroy any PriorityQueue, Queue and Stack we create
  destroy(pq);
  destroy(q);
  destroy(s);
}
