## A04 - OOP Primer

- Name: Ethan Bailey
- Date: 31 January 2023
- Class: 2143 OOP

## Definitions

#### Abstraction
> Abstraction means displaying only essential information and hiding the details.
> 
> Abstraction is selecting data from a larger pool to show only relevant details of the object to the user. It helps in reducing programming complexity and efforts. It is one of the most important concepts of OOPs. For example: 
> 
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/Abstraction.jpg" width=400>
>
> **Types of Abstraction:**
> 1. Data abstraction – This type only shows the required information about the data and hides the unnecessary data.Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
> 2. Control Abstraction – This type only shows the required information about the implementation and hides unnecessary information.
>
>  **Example of Code below:**
>  
> Source: https://www.geeksforgeeks.org/abstraction-in-cpp/
````c++
// C++ Program to Demonstrate the
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
>**Output**
````
a = 10
b = 20
````
#### Attributes / Properties
> **Attributes** are additional information about an object.Attributes and methods are basically variables and fucntions that belongs to the class. These are often referred to as "class members"
> **Properties** describe the characteristics of an object.
> 
> **For example:**
> When each property of an object gets value, it is actually the concept of attributes. Let's look at an example using a Car:
> 
> - Car properties: Colour, Type of Car, Production Year, Fuel type, etc.
> 
> - Car Attributes: Colour is blue, The type of Car is a Ford, Production Year is 2023, Fuel type is Gasoline, etc.
> 
> This picture further shows the difference between the two:
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/Attributes_Properties.png" width=350>

#### Class
> In object-oriented programming, a class is a blueprint for creating objects (a particular data structure), providing initial values for state (member variables or attributes), and implementations of behavior (member functions or methods).
> 
> **For example:**
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/Class.png" width=350>
>
> The user-defined objects are created using the class keyword. The class is a blueprint that defines a nature of a future object. An instance is a specific object created from a particular class. Classes are used to create and manage new objects and support inheritance—a key ingredient in object-oriented programming and a mechanism of reusing code
> 
> A class is a way of organizing information about a type of data so a programmer can reuse elements when making multiple instances of that data type—for example, if a programmer wanted to make three instances of Car, maybe a BMW, a Ferrari, and a Ford instance. The Car class would allow the programmer to store similar information that is unique to each car (they are different models, and maybe different colors, etc.) and associate the appropriate information with each car.
> 
> To create a class the _class_ keyword is used:
````c++
class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};
````


#### Class Variable
> A class variable is an important part of object-oriented programming (OOP) that defines a specific attribute or property for a class and may be referred to as a member variable or static member variable.
> 
> Class variables − Class variables also known as static variables are declared with the static keyword in a class, but outside a method, constructor or a block. There would only be one copy of each class variable per class, regardless of how many objects are created from it.


#### Composition
> Composition in OOPS is a fundamental concept and describes a class that refers to one or more objects of the other class instance variables. It drives the design of the application and lets us know how the application should evolve as there are new features getting added or any requirements change. It is also one of the specialized but restricted forms of aggregation where two entities are dependent on each other. In Java, Object-Oriented Programming, it implements has-a relationship, which is achieved by using an instance variable referring to other objects.
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/Composition.jpg" width=400>
> 
> An example of has-a relationship, i.e., Composition in OOPS.
>
> - The class has a teacher
> - Zoo has a lion
> - The bike has an engine
>
> It is one of the special types of aggregation; restricted aggregation is called composition. This scenario is known as Composition, when an object contains other objects, and the contained object can’t exist without other objects.

#### Constructor
> A constructor is a special method of a class or structure in object-oriented programming that initializes a newly created object of that type. Whenever an object is created, the constructor is called automatically.
>
> A constructor is like an instance method that usually has the same name as the class, and can be used to set the values of the members of an object, either to default or to user-defined values. However, although it resembles it, a constructor is not a proper method since it doesn’t have a return type. Instead of performing a task by executing code, the constructor initializes the object, and it cannot be static, final, abstract, and synchronized.
> 
> Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure. Constructor is invoked at the time of object creation. It constructs the values i.e. provides data for the object which is why it is known as constructors. Constructors can be defined inside or outside the class declaration.
> 
> Constructor does not have a return value, hence they do not have a return type.
>
> The prototype of Constructors is as follows:
````c++
<class-name> (list-of-parameters);
````

#### Encapsulation
>
> The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users. To achieve this, you must declare class variables/attributes as private (cannot be accessed from outside the class). If you want others to read or modify the value of a private member, you can provide public get and set methods.
> 
>**Why Encapsulation?**
>
> - It is considered good practice to declare your class attributes as private (as often as you can). Encapsulation ensures better control of your data, because you (or others) can change one part of the code without affecting other parts
> - Increased security of data
> 
> **Example**
````c++
#include <iostream>
using namespace std;

class Employee {
  private:
    // Private attribute
    int salary;

  public:
    // Setter
    void setSalary(int s) {
      salary = s;
    }
    // Getter
    int getSalary() {
      return salary;
    }
};

int main() {
  Employee myObj;
  myObj.setSalary(50000);
  cout << myObj.getSalary();
  return 0;
}
````

#### Friends
> **Friend Class** 
> 
> A friend class can access private and protected members of other classes in which it is declared as a friend. It is sometimes useful to allow a particular class to access private and protected members of other classes. For example, a LinkedList class may be allowed to access private members of Node.
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/friend_class.png" width=400>
>
> **Syntax:**
````c++
friend class class_name;    // declared in the base class
````
> **Friend Function**
> 
> Like a friend class, a friend function can be granted special access to private and protected members of a class in C++. They are the non-member functions that can access and manipulate the private and protected members of the class for they are declared as friends.
>
> A friend function can be:
>
> - A global function
> - A member function of another class
> 
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/friend_functioninC.png" width=400>
> 
> **Syntax:**
````c++
friend return_type function_name (arguments);    // for a global function
            or
friend return_type class_name::function_name (arguments);    // for a member function of another class
````

#### Inheritance
> The capability of a class to derive properties and characteristics from another class is called Inheritance. Inheritance is one of the most important features of Object-Oriented Programming.
>
> - Sub Class: The class that inherits properties from another class is called Sub class or Derived Class.
> - Super Class:The class whose properties are inherited by sub class is called Base Class or Super class.
> - Reusability: Inheritance supports the concept of “reusability”, i.e. when we want to create a new class and there is already a class that includes some of the code that we want, we can derive our new class from the existing class. By doing this, we are reusing the fields and methods of the existing class.
> 
> **Types Of Inheritance:**
> 1. Single inheritance
> 2. Multilevel inheritance
> 3. Multiple inheritance
> 4. Hierarchical inheritance
> 5. Hybrid inheritance
> 
> **Example**: Dog, Cat, Cow can be Derived Class of Animal Base Class.
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/inheritance.png" width=350>
> 
> Check out this coded example of inheritance below:
 ````c++
// C++ program to demonstrate implementation
// of Inheritance

#include <bits/stdc++.h>
using namespace std;

// Base class
class Parent {
public:
	int id_p;
};

// Sub class inheriting from Base Class(Parent)
class Child : public Parent {
public:
	int id_c;
};

// main function
int main()
{
	Child obj1;

	// An object of class child has all data members
	// and member functions of class parent
	obj1.id_c = 7;
	obj1.id_p = 91;
	cout << "Child id is: " << obj1.id_c << '\n';
	cout << "Parent id is: " << obj1.id_p << '\n';

	return 0;
}
````
>**Output**
````
Child id is: 7
Parent id is: 91
````

#### Instance Variable
> Instance variables − Instance variables are declared in a class, but outside a method. When space is allocated for an object in the heap, a slot for each instance variable value is created. 
> Instance variables hold values that must be referenced by more than one method, constructor or block, or essential parts of an object's state that must be present throughout the class.
> 
> **Example**
````c++
public class VariableExample{
   int myVariable;
   static int data = 30;
   
   public static void main(String args[]){
      int a = 100;
      VariableExample obj = new VariableExample();
      
      System.out.println("Value of instance variable myVariable: "+obj.myVariable);
      System.out.println("Value of static variable data: "+VariableExample.data);
      System.out.println("Value of local variable a: "+a);
   }
}
````
>**Output**
````
Value of instance variable myVariable: 0
Value of static variable data: 30
Value of local variable a: 100
````

#### Member Variable
> A member variable is a variable (an object) that is part of a class.
> Member variables implement the values and member functions implement the operations. 
> In object-oriented programming, a member variable (sometimes called a member field) is a variable that is associated with a specific object, and accessible for all its methods (member functions).
>
> In class-based programming languages, these are distinguished into two types: class variables (also called static member variables), where only one copy of the variable is shared with all instances of the class; and instance variables, where each instance of the class has its own independent copy of the variable.
>
>**Example:**
```c++
class Foo {
    int bar; // Member variable
  public:
    void setBar(const int newBar) { 
      bar = newBar;
    }
};

int main () {
  Foo rect; // Local variable

  return 0;
}
```

#### Method
> A method is the equivalent of a function in object-oriented programming. A noun is to a verb what a variable is to a method — the methods are the actions that perform operations on a variable. A method accepts parameters as arguments, manipulates these, and then produces an output when the method is called on an object. Methods are similar to functions, but methods are also classified according to their purpose in the class design. In classes, variables are called attributes, so methods often operate on attributes.
> 
> To put simply; a method is an action which an object is able to perform.
> 
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/method.png" width=400>


#### Multiple Inheritance
> Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one subclass is inherited from more than one base class.
> 
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/multiple-inheritance.png" width=400>
> 
> **Example:**
````c++
// C++ program to explain
// multiple inheritance
#include <iostream>
using namespace std;

// first base class
class Vehicle {
public:
	Vehicle() { cout << "This is a Vehicle\n"; }
};

// second base class
class FourWheeler {
public:
	FourWheeler()
	{
		cout << "This is a 4 wheeler Vehicle\n";
	}
};

// sub class derived from two base classes
class Car : public Vehicle, public FourWheeler {
};

// main function
int main()
{
	// Creating object of sub class will
	// invoke the constructor of base classes.
	Car obj;
	return 0;
}
````
>**Output:**
````
This is a Vehicle
This is a 4 wheeler Vehicle
````

#### Object
> Objects are instances of a class created with specific data. Class templates are used as a blueprint to create individual objects. These represent specific examples of the abstract class. Each object can have unique values to the properties defined in the class.
> 
> **Example:**
> 
> In C++, an object is created from a class. We have already created the class named MyClass, so now we can use this to create objects.
> 
>To access the class attributes (myNum and myString), use the dot syntax (.) on the object:
````c++
class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15; 
  myObj.myString = "Some text";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;
  return 0;
}
````

#### Overloading
> An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).
>
>When you call an overloaded function or operator, the compiler determines the most appropriate definition to use, by comparing the argument types you have used to call the function or operator with the parameter types specified in the definitions. The process of selecting the most appropriate overloaded function or operator is called **overload resolution**.
>
> **Types of Overloading:**
> 
> - Operator Overloading: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
> - Function Overloading: Function overloading is using a single function name to perform different types of tasks.
>
> The following example shows the same function print() is being used to print different data types −
````c++
#include <iostream>
using namespace std;
 
class printData {
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }
      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }
      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

int main(void) {
   printData pd;
 
   // Call print to print integer
   pd.print(5);
   
   // Call print to print float
   pd.print(500.263);
   
   // Call print to print character
   pd.print("Hello C++");
 
   return 0;
}
````
>**Output**
````
Printing int: 5
Printing float: 500.263
Printing character: Hello C++
````
#### Polymorphism
> In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
> A person at the same time can have different characteristic. Like a man at the same time is a father, a husband, an employee. So the same person posses different behaviour in different situations. This is called **polymorphism**.
> 
> An operation may exhibit different behaviours in different instances. The behaviour depends upon the types of data used in the operation.
> 
> Polymorphism is extensively used in implementing inheritance.
> 
> Example: Suppose we have to write a function to add some integers, some times there are 2 integers, some times there are 3 integers. We can write the Addition Method with the same name having different parameters, the concerned method will be called according to parameters.
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/polymorphism.png" width=400>

#### Public / Private / Protected
> These are access modifiers and help us implement Encapsulation (or information hiding). They tell the compiler which other classes should have access to the field or method being defined.
> 
> In object-oriented languages, access modifiers (or access specifiers) are keywords that control the accessibility of classes, methods, and other members. Access modifiers are a type of programming language syntax that makes it easier to encapsulate components.
>
> There are just three access modifiers in C++. The number of them is increased to six in C#, whereas Java has four access modifiers but only three keywords for this purpose. The package-private modifier is used by default in Java when there is no keyword preceding it.
>
> - private - Only the current class will have access to the field or method.
> - protected - Only the current class and subclasses (and sometimes also same-package classes) of this class will have access to the field or method.
> - public - Any class can refer to the field or call the method.
> - default (for java) - A default modifier's access level is limited to the package. It's not possible to get to it from outside the package. If you don't indicate an access level, the default will be used. 
>
> This assumes these keywords are used as part of a field or method declaration within a class definition.
>
> <img src="https://github.com/EthanJBailey/2143-OOP-bailey/blob/main/Assignments/OOP_Primer/images/Access_Modifier.png" width=400>

#### Static
> When you declare a variable or a method as static, it belongs to the class, rather than a specific instance. This means that only one instance of a static member exists, even if you create multiple objects of the class, or if you don’t create any. It will be shared by all objects.
>
> The static keyword can be used with variables, methods, code blocks and nested classes.
> 
> **1) Static Variables**
> 
> **Example:**
``` java
public class Counter {
  public static int COUNT = 0;
  Counter() {
    COUNT++;
  }
}
// The COUNT variable will be shared by all objects of that class. 
// When we create objects of our Counter class in main, and access the static variable.

public class MyClass {
  public static void main(String[] args) {
    Counter c1 = new Counter();
    Counter c2 = new Counter();
    System.out.println(Counter.COUNT);
  }
}
// Outputs "2"
````
> The output is 2, because the COUNT variable is static and gets incremented by one each time a new object of the Counter class is created. You can also access the static variable using any object of that class, such as c1.COUNT.
>
> **2) Static Methods**
>
> A static method belongs to the class rather than instances. Thus, it can be called without creating instance of class. It is used for altering static contents of the class. There are some restrictions of static methods :
>
> - Static method can not use non-static members (variables or functions) of the class.
> - Static method can not use this or super keywords.
>
> **Example:**
````java
public class Counter {
  public static int COUNT = 0;
  Counter() {
    COUNT++;
  }

  public static void increment(){
    COUNT++;
  }
}
// Static methods can also be called from instance of the class.

public class MyClass {
  public static void main(String[] args) {
    Counter.increment();
    Counter.increment();
    System.out.println(Counter.COUNT);
  }
}
// Outputs "2"
// The output is 2 because it gets incremented by static method increament(). 
// Similar to static variables, static methods can also be accessed using instance variables.
````
> **1) Static Blocks**
> Static code blocks are used to initialise static variables. 
> 
> These blocks are executed immediately after declaration of static variables.
>
> **Example:**
```` java
public class Saturn {
  public static final int MOON_COUNT;

  static {
    MOON_COUNT = 62;
  }
}
public class Main {
  public static void main(String[] args) {
    System.out.println(Saturn.MOON_COUNT);
  }
}
// Outputs "62"
````
> The output is 62, because variable MOON_COUNT is assigned that value in the static block.
>
> **Static Nested Classes**
> 
> A class can have static nested class which can be accessed by using outer class name.
>
> **Example:**
```` java
public class Outer {

  public Outer() {
  }

  public static class Inner {
    public Inner() {
    }
  }
}
// In above example, class Inner can be directly accessed as a static member of class Outer.

public class Main {
  public static void main(String[] args) {
    Outer.Inner inner = new Outer.Inner();
  }
}
````
#### Virtual
> A virtual function or virtual method in an OOP language is a function or method used to override the behavior of the function in an inherited class with the same signature to achieve the polymorphism.
> 
> When the programmers switch the technology from C++ to Java, they think about where is the virtual function in Java. In C++, the virtual function is defined using the virtual keyword, but in Java, it is achieved using different techniques. See Virtual function in C++.
> 
> Java is an object-oriented programming language; it supports OOPs features such as polymorphism, abstraction, inheritance, etc. These concepts are based on objects, classes, and member functions.
> 
> By default, all the instance methods in Java are considered as the Virtual function except final, static, and private methods as these methods can be used to achieve polymorphism.
> 
> A virtual function in C++ is a base class member function that you can redefine in a derived class to achieve polymorphism. You can declare the function in the base class using the virtual keyword. Once you declare the function in the base class, you can use a pointer or reference to call the virtual class and execute its virtual version in the derived class. Thus, it asks the compiler to determine the object’s type during run-time and create a function bind (late binding or dynamic linkage).
> 
> A virtual function in C++ helps ensure you call the correct function via a reference or pointer. The C++ programming language allows you only to use a single pointer to refer to all the derived class objects. Since the pointer refers to all the derived objects, calling it will consistently execute the function in the base class. You can overcome this challenge with a virtual function in C++ as it helps execute the virtual version of the derived class, which is done at the run-time.
>
> **There are a few rules you need to follow to create a virtual function in C++. These rules are:**
>
> - The functions cannot be static
> - You derive them using the “virtual” keyword
> - Virtual functions in C++ needs to be a member of some other class (base class)
> - They can be a friend function of another class
> - The prototype of these functions should be the same for both the base and derived class
> - Virtual functions are accessible using object pointers
> - Redefining the virtual function in the derived class is optional, but it needs to be defined in the base class
> - The function call resolving is done at run-time
> - You can create a virtual destructor but not a constructor
````c++
#include <iostream>
using namespace std;

class Base{
  public:
  virtual void Output(){
  cout << "Output Base class" << endl;
  }
  
  void Display(){
  cout << "Display Base class" << endl;
  }
};

class Derived : public Base{
  public:
  void Output(){
  cout << "Output Derived class" << endl;
  }

 void Display(){ 
 cout << "Display Derived class" << endl;
 }
};

int main(){
Base* bpointr;
Derived dpointr;
bpointr = &dpointr;

// virtual function binding
bpointr->Output();

// Non-virtual function binding
bpointr->Display();

}
````
> **Output:**
````
Output Derived class
Display Base class
````
