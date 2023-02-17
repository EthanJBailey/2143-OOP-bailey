/*****************************************************************************
*                    
*  Email:            businessjoebailey@gmail.com
*  Label:            P02
*  Title:            Linked-list vector implementation with overloaded operators
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        Uses a singly linked list as the backend for an STL like "vector" 
*        class definition with overloaded operators.
* 
*  Usage:
*        - This program can be used like a linked list.
*        - Run the main.cpp file
* 
*  Files:
*        main.cpp  :  driverprogram
*
*****************************************************************************/
#include <fstream>     // To use file stream
#include <iostream>    // To use input and output stream
#include <string>      // To use string libraries
#include <vector>      // To use vector libraries

#define INF 1000000000 // infinity

using namespace std;   // To use the namespace standard

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

    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/**
 * Vector
 *
 * Description:
 *      This class creates a dynamic vector class that can add or remove values
 *      at the front, end, and the chosen location of a list. 
 *
 * Private Methods:
 *      - void _inOrderPush(int x);                // add ordered item to vector
 *
 * Public Methods:
 *      - void inOrderPush(int x);                 // add ordered item to vector
 *      - void sortList();                         // sort the list of vectors
 *      - void pushFront(int x);                   // push item to the front of the list
 *      - void pushFront(const MyVector& other);   // push vector to the front of the list
 *      - void pushRear(const MyVector& other);    // push vector to the rear of the list
 *      - void pushAt(int i, int x);               // push value to the rear of the list
 *      - void pushRear(int x);                    // push value to the rear of the list
 *      - void clear();                            // clears the list of values
 *
 * Usage:
 *      - You can  use this class by adding new values onto a gradesheet
 *      - and depending on if the student graduates you can pop or remove it.
 *
 **/
class MyVector {
private:
    Node*           head;      // base pointer of list
    Node*           tail;      // tail pointer of list
    int             size;      // declare integer variable
    static ofstream fout;      // declare variable for the static output stream
    string          fileName;  // declare string variable for fileName
    bool            sorted;    // declare boolean variable
    /**
     * @brief Private version of inOrder push. 
     * 
     * @param x 
     */
    void _inorderPush(int x) {
        Node* tempPtr = new Node(x);  // allocate new node
        Node* prev = head;            // get previous and next pointers
        Node* curr = head;           

        while (curr->data > x) {      // loop to find proper location
            prev = curr;
            curr = curr->next;
        }

        tempPtr->next = prev->next;   // add new node in its proper position
        prev->next = tempPtr;

        size++;                       // add to size :)
    }

public:

    /**
     * @brief Default constructor 
     * 
     */
    MyVector() {
        init();
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * @param int   *A - pointer to array 
     * @param int   aSize - size of array
     */
    MyVector(int A[], int aSize) {
        init();

        for (int i = 0; i < aSize; i++) {
            pushRear(A[i]);
        }
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * @param string FileName - file to open and read
     * 
     * Assumes infile will contain numbers only delimited by spaces or 
     * new lines.
     */
    MyVector(string FileName) {
        init();

        ifstream fin;
        int      x = 0;

        fin.open(FileName);
        while (!fin.eof()) {
            fin >> x;
            pushRear(x);
        }
    }

    /**
     * @brief Copy Constructor 
     * 
     * @param MyVector &other 
     */
    MyVector(const MyVector& other) {
        init();

        Node* temp = other.head;

        while (temp) {
            pushRear(temp->data);
            temp = temp->next;
        }
    }

    /**
     * @brief - Initialize the data members so we don't
     *      have duplicate lines in each constructor.
     * 
     */
    void init() {
        head = tail = NULL;
        fileName = "";
        size = 0;
        sorted = 0;
    }


    /**
     * @brief Public version of inOrder push.
     * 
     * @param x 
     */
    void inorderPush(int x) {
        if (!sorted) {
            sortList();
        }
        if (!head) {
            pushFront(x);            // call push front for empty list (or pushRear works)
        } else if (x < head->data) {
            pushFront(x);            // call push front if x is less than head
        } else if (x > tail->data) {
            pushRear(x);             // call push rear if x > tail
        } else {
            _inorderPush(x);         // call private version of push in order
        }
    }

    /**
     * @brief Sort the current values in the linked list.
     * 
     * @returns None
     */
    void sortList() {
        Node* newFront = head;
        while (newFront->next) {
            Node* smallest = newFront;
            Node* current = newFront;
            int   minimum = INF;
            while (current) {
                if (current->data < minimum) {
                    smallest = current;
                    minimum = current->data;
                }
                current = current->next;
            }
            smallest->data = newFront->data;
            newFront->data = minimum;
            newFront = newFront->next;
        }
        sorted = true;
    }

    /**
     * @brief Add value to front of list.
     * 
     * @param x 
     */
    void pushFront(int x) {
        Node* tempPtr = new Node(x);

        // empty list make head and tail
        // point to new value
        if (!head) {
            head = tail = tempPtr;
            // otherwise adjust head pointer
        } else {
            tempPtr->next = head;
            head = tempPtr;
        }
        size++;
    }

    /**
     * @brief This method loads values from 'other' list in 'this' list.
     *          It loads an array first so we can process the values in
     *          reverse so they end up on 'this' list in the proper order.
     *          If we didn't use the array, we would reverse the values
     *          from the 'other' list.
     * 
     * @depends - Uses `pushFront(int)`
     * @param MyVector& other 
     * @return None
     */
    void pushFront(const MyVector& other) {
        Node* otherPtr = other.head;           // get copy of other lists head
        int*  tempData = new int[other.size];  // allocate memory to hold values

        // load other list into array
        int i = 0;
        while (otherPtr) {
            tempData[i] = otherPtr->data;
            otherPtr = otherPtr->next;
            ++i;
        }

        // process list in reverse in order to keep them
        // in their original order.
        for (int i = other.size - 1; i >= 0; i--) {
            pushFront(tempData[i]);
        }
    }

    /**
     * @brief -  Add 'other' list's values to end of 'this' list.
     * @note - Uses `pushRear(int)`
     * @param MyVector& other 
     * @return None
     */
    void pushRear(const MyVector& other) {
        Node* otherPtr = other.head;  // get copy of other lists head

        while (otherPtr) {            // traverse and add
            pushRear(otherPtr->data);
            otherPtr = otherPtr->next;
        }
    }

    /**
     * @brief Push value onto list at soecified position, if it exists.
     * 
     * @param int i - location index 
     * @param inr x - value to add 
     * @return bool - true add successful / false add failed 
     */
    bool pushAt(int i, int x) {
        if(i >= size){
            return false;
        }

        Node* tempPtr = new Node(x);  // allocate new node
        Node* prev = head;            // get previous and next pointers
        Node* curr = head;

        while (i > 0) {               // loop to find proper location
            prev = curr;
            curr = curr->next;
            i--;
        }
      
        tempPtr->next = prev->next;   // add new node in its proper position
        prev->next = tempPtr;

        size++;                       // add to size :)
        return true;
    }

    /**
     * @brief - Add value to rear of list
     * 
     * @param int x - value to be added 
     * @return None
     */
    void pushRear(int x) {
        Node* tempPtr = new Node(x);

        if (!head) {
            head = tail = tempPtr;

        } else {
            tail->next = tempPtr;
            tail = tempPtr;
        }
        size++;  // add to size of list
    }

    // Function to lookup the location of a value in a vector
    Node *_Find(int location) {
      Node *travel = head;
      
      while (travel && location--) {
  
        travel = travel->next;
      }
      return travel;
    }

    // Function to clear the vector 
    void clear(){
      Node *temp = head;
      while (temp) {
        Node *deleting = temp;
        temp = temp->next;
        delete deleting;
      }
      head = tail = nullptr;
      size = 0;
    }

    // MY OVERLOADED OPERATORS

    // Overloaded the << operator to output vectors to the console is easy.
    friend ostream& operator<<(ostream& os, const MyVector& rhs) {
        Node* temp = rhs.head;  // temp pointer copies head
        os << "[";
        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            os << temp->data;  // print data from Node
            if (temp->next) {
                os << ",";
            }
            temp = temp->next;  // move to next Node
        }
        os << "]" << endl;
        return os;
    }
    // Overloaded the << (ofstream) so that printing to the output file is easy.
    friend ofstream& operator<<(ofstream& ofs, const MyVector& rhs) {
        Node* temp = rhs.head;  
        ofs << "[";
        while (temp) {           
            ofs << temp->data;   
            if (temp->next) {
                ofs << ",";
            }
            temp = temp->next;  
        }
        ofs << "]" << endl;
        return ofs;
    }

    // Overloaded the [] so that MyVector can be treated as an array
    int &operator[](int location) {
      Node *temp = _Find(location);
  
      return temp->data;
    }    
    
    // Overloaded the + operator so that vectors can be added together 
    MyVector operator+(const MyVector &rhs) {
      MyVector V;
      Node *shorter;
      Node *longer;
  
      if (this->size > rhs.size) {
        shorter = rhs.head;
        longer = this->head;
  
      } else {
        longer = rhs.head;
        shorter = this->head;
      }
      while (longer) {
        if (shorter) {
          V.pushRear(shorter->data + longer->data);
          shorter = shorter->next;
        } else {
          V.pushRear(longer->data);
        }
        longer = longer->next;
      }

      return V;
    }

    // Overloaded the - operator so that vectors can be subtracted from one another
    MyVector operator-(const MyVector &rhs) {
      MyVector V;
      Node *v1 = this->head;
      Node *v2 = rhs.head;
      
      while (v1 && v2) {
        V.pushRear(v1->data - v2->data);
        v1 = v1->next;
        v2 = v2->next;
      }
      while (v1) {
        V.pushRear(v1->data);
        v1 = v1->next;
      }
      while (v2) {
        V.pushRear(v2->data);
        v2 = v2->next;
      }
      
      return V;
    }

    // Overloaded the * operator so that vectors can be multiplied
    MyVector operator*(const MyVector &rhs) {
      MyVector V;
      Node *shorter;
      Node *longer;
  
      if (this->size == rhs.size) {
        shorter = rhs.head;
        longer = this->head;
    
      } else if (this->size > rhs.size) {
        shorter = rhs.head;
        longer = this->head;    
      } else {
        longer = rhs.head;
        shorter = this->head;
      }
      while (longer) {
        if (shorter) {
          V.pushRear(longer->data * shorter->data);
          shorter = shorter->next;
        } else {
          V.pushRear(longer->data);
        }
        longer = longer->next;
      }

      return V;
    }

    // Overloaded the / operator so that vectors can be divided from one another
    MyVector operator/(const MyVector &rhs) {
      MyVector V;
      Node *v1 = this->head;
      Node *v2 = rhs.head;
      
      while (v1 && v2) {
        if (v2->data != 0) {
          V.pushRear(v1->data / v2->data);
        } else {
          V.pushRear(0);
        }
        v1 = v1->next;
        v2 = v2->next;
      }
      
      while (v1) {
        V.pushRear(v1->data);
        v1 = v1->next;
      }
      while (v2) {
        V.pushRear(v2->data);
        v2 = v2->next;
      }
      
      return V;
    }

    // Overloaded the = operator to allow vectors to be assigned
    MyVector& operator=(const MyVector &rhs){
      if(this == &rhs){
        return *this;
      }
      this->clear();
    
      Node *temp = rhs.head;
      while (temp) {
        this->pushRear(temp->data);
        temp = temp->next;
      }
    
      return *this;
    }

    // Overloaded the equality operator to return true or false if two vectors are equal
    bool operator==(const MyVector &rhs) const {
      if (this == &rhs){
        return true;
      }
      else{
        if (this->size != rhs.size) {
          return false;
        }
    
        Node *currentThis = this->head;
        Node *currentRhs = rhs.head;
        while (currentThis && currentRhs) {
          if (currentThis->data != currentRhs->data) {
            return false;
          }
          currentThis = currentThis->next;
          currentRhs = currentRhs->next;
        }
    
        return true;
      }
    }

    /**
     * @brief Destroy the My Vector object
     * 
     */
    ~MyVector() {
        Node* curr = head;
        Node* prev = head;

        while(curr){
            prev = curr;
            curr = curr->next;
            // cout << "deleting: " << prev->data << endl;
            delete prev;
        }
    }
};

// ofstream MyVector::fout;

int main() {

  /**
      Testing your code: GIVEN
  **/
  int a1[] = { 1, 2, 3, 4, 5 };
  int a2[] = { 10, 20, 30 };
  
  MyVector v1(a1,5);
  MyVector v2(a2,3);
  
  ofstream fout;
  fout.open("output.txt");

  // Banners for the Program 2
  cout << "Ethan Bailey" << endl << "Program #2" << endl
       << "02/16/2023" << endl
       << "Spring 2143" << endl << endl;

  fout << "Ethan Bailey" << endl << "Program #2" << endl
       << "02/16/2023" << endl
       << "Spring 2143" << endl << endl;  
  
  cout << v1[2] << endl;
  fout << v1[2] << endl;
  // writes out 3 to console and your output file.
    
  v1[4] = 9;
  // v1 now = [1,2,3,4,9]
  
  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.
  
  fout << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [11,22,33,4,9] to console and file.
  
  v3 = v1 - v2;
  cout << v3 << endl;
  fout << v3 << endl;
  //writes out [-9,-18,-27,4,9] to console and file.
  
  v3 = v2 - v1;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [9,18,27,4,9] to console and file.
  
  v3 = v2 * v1;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [10,40,90,4,9] to console and file.
  
  v3 = v1 * v2;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [10,40,90,4,9] to console and file.
  
  v3 = v1 / v2;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [0,0,0,4,9] to console and file.
  
  v3 = v2 / v1;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [10,10,10,4,9] to console and file.
  
  cout << (v2 == v1) << endl;
  fout << (v2 == v1) << endl;
  // writes 0 to console and file (false).
  
  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  fout << (v4 == v1) << endl;
  // writes 1 to console and file (true).
  
}