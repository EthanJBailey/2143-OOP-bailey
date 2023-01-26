/*****************************************************************************
 *
 *  Author:           Ethan Bailey
 *  Email:            businessjoebailey@gmail.com
 *  Label:            A03
 *  Title:            Commenting Code Class
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *      This program implements a circular array queue using an overloaded operator.
 *      It declares methods within the CircularArrayQue class to add and remove items
 *      onto the queue within its predefined size.
 *
 *  Files:
 *        main.cpp    : driver program
 *****************************************************************************/
#include <iostream>
using namespace std;

/**
 * CircularArrayQueue
 * 
 * Description:
 *      This class creates an  of the queue that is array based.
 *      It utilizes an an ostream &operator to overload the operator.
 *      
 * Public Methods:
 *      void         Push() 
 *      int          Pop()
 * 
 * Private Methods:
 *      void          intit()
 *      bool          Full() 
 *      
 */
class CircularArrayQue {
private:
  int *Container;         // container of the queue
  int Front;              // front of the queue
  int Rear;               // rear of the queue
  int QueSize;            // items in the queue
  int CurrentSize;        // holds the current size of the queue

  /**
  * Initialize the queue.
  * @return 0 for Front, Rear and CurrentSize variables.
  */ 
  void init(int size = 0) {
    Front = Rear = CurrentSize = 0;
    QueSize = size;
  }
  /**
  * Checks if the queue is full.
  * @return true if full, false otherwise.
  */  
  bool Full() { 
    return CurrentSize == QueSize; 
  }

public:

  // Method call to create queue
  CircularArrayQue() {
    Container = new int[10];
    init(10);
  }
  // Method to initialize the size of the queue
  CircularArrayQue(int size) {
    Container = new int[size];
    init(size);
  }
  // Method to add an item onto the queue, until full
  void Push(int item) {
    if (!Full()) {
      Container[Rear] = item;
      Rear = (Rear + 1) % QueSize;
      CurrentSize++;
    } else {
      cout << "FULL!!!!" << endl;
    }
  }
  // Method to remove the first item off the queue, until empty
  int Pop() {
    int temp = Container[Front];
    Front = (Front + 1) % QueSize;
    CurrentSize--;
    return temp;
  }
  // Creates the connection or friendship between class and function
  friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

//Function to overload the operator
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

  for (int i = other.Front; i < other.CurrentSize;
       i = (i + 1) % other.QueSize) {
    os << other.Container[i] << " ";
  }
  os << endl;
  return os;
}

/**
 * Main Driver
 *
 * For this program, the main driver was used to test the CircularArrayQue class
 *
 */
int main() {
  CircularArrayQue C1(5);

  // C1.Push(34);
  // C1.Push(38);
  // C1.Push(44);
  // C1.Push(22);
  // C1.Push(99);
  // C1.Push(100);

  // Function Call to Push each item onto the queue
  C1.Push(1);
  C1.Push(2);
  C1.Push(3);
  // C1.Push(6);
  // C1.Push(7);
  cout << C1 << endl;

  // C1.Push(1);
  // C1.Push(2);
  // C1.Push(3);

  cout << C1 << endl;
}
