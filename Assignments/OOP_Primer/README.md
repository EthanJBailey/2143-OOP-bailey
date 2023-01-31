## A04 - OOP Primer

- Name: Ethan Bailey
- Date: 31 January 2023
- Class: 2143 OOP

## Definitions

#### Abstraction
> Abstraction means displaying only essential information and hiding the details. For example: 
>><img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/Abstraction.jpg" width=500>
> Types of Abstraction:
> 1. Data abstraction – This type only shows the required information about the data and hides the unnecessary data.Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
> 2. Control Abstraction – This type only shows the required information about the implementation and hides unnecessary information.
>
>  Example of Code below:
>  
> Source: https://www.geeksforgeeks.org/abstraction-in-cpp/
 ````// C++ Program to Demonstrate the
// working of Abstraction
#include <iostream>
using namespace std;
 
class implementAbstraction {
private:
    int a, b;
 
public:
    // method to set values of
    // private members
    void set(int x, int y)
    {
        a = x;
        b = y;
    }
 
    void display()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
 
int main()
{
    implementAbstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}
````

#### Attributes / Properties
>

#### Class
>

#### Class Variable
>

#### Composition
>

#### Constructor
>

#### Encapsulation
>

#### Friends
>

#### Inheritance
>

#### Instance Variable
>

#### Member Variable
>

#### Method
>

#### Multiple Inheritance
>

#### Object
>

#### Overloading
>

#### Polymorphism
>

#### Public / Private / Protected
>

#### Static
>

#### Virtual
