/*****************************************************************************
 *
 *  Author:           Ethan Bailey
 *  Email:            businessjoebailey@gmail.com
 *  Label:            P01
 *  Title:            Vector Classes
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        This program creates a dynamic vector class that contains a linked list.
 * 
 *  Usage:
 *        - Ensure that all input files are correct
 *        - Run the main.cpp
 *
 *  Files:
 *        main.cpp  :  driverprogram
 *        input.dat :  input file
 *****************************************************************************/

#include <bits/stdc++.h> // To use the header file that includes every standard library
#include <fstream>       // To use ifstream
#include <iomanip>       // To use input and output manipulation
#include <iostream>      // To use input output stream
#include <list>          // To use the list libraries
#include <vector>        // To use the vector library
using namespace std;     // To use the namespace started
/**
 * Node
 *
 * Description:
 *      This public struct creates a blank linked list
 *      and all its needed variables.
 *
 * Usage:
 *      - To create a linked list data structure to adequately
 *      - store, retreive and manipulate data.
 *
 **/
struct Node {
  int data; 

  Node *next;
  Node *previous;

  Node(int x, Node *next = nullptr, Node *prev = nullptr) {
    data = x;
    next = next;
    previous = prev;
  }
};

/**
 * Vector
 *
 * Description:
 *      This class creates a dynamic vector class that can add or remove values
 *      at the front, end, and the chosen location of a list. 
 *
 * Public Methods:
 *      - void Push(int);           // add item to vector
 *      - int Pop();                // remove item from vector
 *      - void Print();             // print the vector
 *      - void PushAt(int, int);    // push value at specific location
 *
 * Usage:
 *      - You can  use this class by adding new values onto a gradesheet
 *      - and depending on if the student graduates you can pop or remove it.
 *      - Additionally, this program f
 *
 **/
class Vector {
  Node *front;
  Node *rear;

private:
  int *array;
  int index;
  int size;
  int currentSize = 0;

public:
  // Initializing class instance
  Vector();               // default constructor
  Vector(int V);          // specify vector size
  Vector(const Vector &); // copy constructor
  Vector(int *, int);     // create vector given array of items

  Vector(string FileName) {                          
    front = rear = nullptr;          
    int V;
    
    ifstream inputName;                 
    inputName.open(FileName);           

    while(!inputName.eof()) {          
      inputName >> V;               
      pushFront(V);            
    }
  }
  // Prototypes or declarations
  void print();                     // print the vector
  void postData(ofstream &outfile); // post data to output file
  void PushAt(int, int);            // push value at specific location

  /**
  * Public : pushFront(int val)
  * 
  * Description:
  *      Function to push values at the front of the list
  * 
  * Params:
  *      - integer variable val
  *   
  * Returns:
  *      - Pushes values onto list, does not return anything
  */
  void pushFront(int val) {
    Node *temp = new Node(val);   

    if(!front) {                       
      front = rear = temp;                 
    } 
    else {           
      temp->next = front;         
      front->previous = temp;      
      front = temp;                
      currentSize++;
    }
  }

   /**
  * Public : pushFront(Vector V2)
  * 
  * Description:
  *      Function to push values from a vector at the front of the list
  * 
  * Params:
  *      - Vector V2
  *   
  * Returns:
  *      - Pushes values from vector onto array, does not return anything
  */
  void pushFront(Vector V2) {
    Node *temp = V2.rear;

    while (temp){
      pushRear(temp->data);
      temp = temp->previous;
    }
  }

 /**
  * Public : pushRear(int val)
  * 
  * Description:
  *      Function to push values at the rear of the list
  * 
  * Params:
  *      - integer variable val
  *   
  * Returns:
  *      - Pushes values onto list, does not return anything
  */
  void pushRear(int val) {
   Node *temp = new Node(val);

    if(!front){                     
      front = rear = temp;     
    } else{
      rear->next = temp;       
      temp->previous = rear;   
      rear = temp;            
                
    }
  }
  /**
    * Public : pushRer(Vector V2)
    * 
    * Description:
    *      Function to push values from a vector at the rear of the list
    * 
    * Params:
    *      - Vector V2
    *   
    * Returns:
    *      - Pushes values from vector onto array, does not return anything
    */
  void pushRear(Vector V2) {
    Node *temp = V2.front;

    while (temp){
      pushFront(temp->data);
      temp = temp->previous;
    }
  }

  /**
    * Public : pushAt(int loc, int val)
    * 
    * Description:
    *       Pushes values at a specified location (if it exists)
    *
    * Params:
    *      - integer variable loc, integer variable val
    *   
    * Returns:
    *      - Pushes values onto list, does not return anything
    */
  void pushAt(int loc, int val) {
     int pos = 0;                                                      
     Node *temp = front;                                                   
  
    if(loc == 0){                                                    
      pushFront(val);                                                     
    }
    else {
      while(temp->next != nullptr){                                      
      temp = temp->next;             
      pos++;
      Node *temp2 = temp->previous;
      if(loc == pos){              
        temp = temp->previous;                                
        temp->next = new Node(val, temp->next, temp);        
        break;
      }
      }
    }
  }

  /**
    * Public : pushAt(int loc, int val)
    * 
    * Description:
    *       Pushes value to proper location in order to maintain order 
    *       (ascending or descending)
    *
    * Params:
    *      - integer variable val
    *   
    * Returns:
    *      - Pushes values onto list, does not return anything
  */
  void inOrderPush(int val) {
    // Node* temp = front;            

    // while(temp){
    //   if(val > temp->data){
    //       temp = temp->next;
    //   } else if(val < temp->data){
    //     temp = temp->previous;
    //     temp->next = new Node(val, temp->next, temp);  
    //   } else if(temp->next == nullptr){
    //     temp->next = new Node(val, nullptr, temp);
    //           }
    //   else{
    //     cout << "Error";
    //   }
    // }
  }
  /**
  * Public : popFront()
  * 
  * Description:
  *      Function to remove the first value at the front of the list
  * 
  * Params:
  *      - None
  *   
  * Returns:
  *      - Removes the first value, does not return anything
  */
  int popFront() {
    int temp = front->data;
    Node *deleteme = front;
    front = front->next;
    delete deleteme;

    return temp;
  }

  /**
  * Public : popRear()
  * 
  * Description:
  *      Function to remove the first value at the rear of the list
  * 
  * Params:
  *      - None
  *   
  * Returns:
  *      - Removes the first value, does not return anything
  */
  int popRear() {
    
    int temp = rear->data;
    Node *deleteme = rear;
    rear = rear->next;
    delete deleteme;

    return temp;
  }

  /**
  * Public : find(int val)
  * 
  * Description:
  *      Function to find location of item (index) if it exists
  * 
  * Params:
  *      - integer variable val
  *   
  * Returns:
  *      - Removes the index of the value found
  */
  int find(int val) { 
    int i = 0;
    Node *temp = front;

    while (temp){
      if (val == temp->data){
        return i;
      }
     temp = temp->next;
      i++;
    }
    return -1;
  }

  /**
  * Public : popAt(int loc)
  * 
  * Description:
  *      Function to remove single value from an indexed location, 
  *      if index between 0 and size of list -1
  * 
  * Params:
  *      - integer variable loc
  *   
  * Returns:
  *      - returns the list with the value chosen, removed
  */
  int popAt(int loc) { 
    int pos = 0;          
    
    Node* temp = front;
      if(loc ==  0){                                                     
        popFront();
      }
      else {
        while(temp->next != nullptr){
          temp = temp->next;      
          pos++;
          
          if(loc == pos){                                          
            delete temp;
          }
        }
      }
    return loc;
  }

  friend ostream &operator<<(ostream &, const Vector &);
  Vector operator+(const Vector &);
  int &operator[](int i);
};

// Fucnction to initialize all pointers to null 
Vector::Vector() { front = rear = nullptr; }

// Fucnction to initialize vector with another vector values 
Vector::Vector(const Vector &V1) {
  front = rear = nullptr;
  Node *temp = V1.front;

  while (temp) {
    this->pushRear(temp->data);
    temp = temp->next;
  }
}

// Function to initialize vector given array values
Vector::Vector(int array[], int size){      
  front = rear = nullptr;             
  //Push values onto array
  for(int i = 0; i < size; i++){
    pushRear(array[i]);       
  }
}

// Function to print out linked list contained in vector
void Vector::print() {
  Node *temp = front;
  cout << "[";
  while (temp) {

    cout << temp->data;
    if (temp->next) {
      cout << ", ";
    }
    temp = temp->next;
  }
  cout << "]" << endl;

}

// Function to post linked list contained in vector to the output file
void Vector::postData(ofstream &outfile) {

  Node *temp = front;
  outfile << "[";
  while (temp) {

    outfile << temp->data;
    if (temp->next) {
      outfile << ", ";
    }
    temp = temp->next;
  }
  outfile << "]" << endl;
}


int main() {
  int x = 0;

  // Print banner for program
  cout << "Ethan Bailey" << endl
       << "02/07/2023" << endl
       << "Spring 2143" << endl << endl;
  
  // Post banner to file
  std::ofstream outfile("test.out");
  outfile << "Ethan Bailey" << endl
          << "02/07/2023" << endl
          << "Spring 2143" << endl << endl;

  // Generated or Given code
  Vector v1;
  v1.pushFront(18);
  v1.pushFront(20);
  v1.pushFront(25);
  v1.pushRear(18);
  v1.pushRear(20);
  v1.pushRear(25);
  v1.print();

  v1.postData(outfile);
  //[25, 20, 18, 18, 20, 25]

  int A[] = {11, 25, 33, 47, 51};
  Vector v2(A, 5);
  v2.print();
  v2.postData(outfile);
  //[11, 25, 33, 47, 51]

  v2.pushFront(9);
  v2.inOrderPush(27);
  v2.pushRear(63);
  v2.print();
  v2.postData(outfile);
  // [9, 11, 25, 33, 47, 51, 63]

  v1.pushRear(v2);
  v1.print();
  v1.postData(outfile);
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print();
  v1.postData(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  cout << x << endl;
  outfile << x << endl;
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print();
  v1.postData(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]
  cout << x << endl;
  outfile << x << endl;
  // 47

  x = v2.popAt(3);
  v2.print();
  // [9, 11, 25, 33, 47, 51, 63]
  cout << x << endl;
  outfile << x << endl;
  // 27

  x = v2.find(51);
  cout << x << endl;
  // 5

  x = v2.find(99);
  cout << x << endl;
  outfile << x << endl;
  // -1

  Vector v3(v1);
  v3.print();
  v3.postData(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]

  v3.pushFront(v2);
  v3.print();
  v3.postData(outfile);
  // //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  Vector v4("input.dat");
  v4.pushRear(v3);
  v4.print();
  v4.postData(outfile);
  // // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23,
  // 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33,
  // 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  outfile.close();
}
