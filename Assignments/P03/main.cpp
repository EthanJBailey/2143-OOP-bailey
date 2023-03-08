/*****************************************************************************
 *
 *  Email:            businessjoebailey@gmail.com
 *  Label:            P03
 *  Title:            GraphViz Code Generator
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *        Generates graphviz "dot" syntax that can visualize the output of data
 *        structures.
 *
 *  Usage:
 *        - This program can be used like a graphiz code generator
 *        - Run the main.cpp file
 *
 *  Files:
 *        main.cpp  :  driverprogram
 *
 *****************************************************************************/
#include <fstream>   // To use file stream
#include <iostream>  // To use input and output stream
#include <map>       // To use map libraries
#include <vector>    // To use vector libraries
using namespace std; // To use namespace standard

/**
 * Class: Attribute
 *
 * Description:
 *      This class creates a map of attributes used as a template to store
 *      our graph components
 * 
 * Public Methods:
 *      - void addAttribute(string key, string val);    // add attributes to map
 *      - void addAttributes(map<string, string> atts); // passes in and stores a map

 * Usage:
 *      - To create a map off attributes
 *      - Store, retreive and manipulate attributes.
 *
 **/
class Attribute {
protected:
  map<string, string> att; // attributes

public:
  // Default Constructor
  Attribute() {}

  // Update an edge attribute. Assumes key is valid.
  void addAttribute(string key, string val) { att[key] = val; }

  // Takes a map of attributes. Loops over them and saves them locally.
  void addAttributes(map<string, string> atts) {
    for (auto const &x : atts) {
      cout << x.first << "=" << x.second << endl;
      att[x.first] = x.second;
    }
  }

  // Use our basic print to dump this class out.Linked
  friend ostream &operator<<(ostream &os, Attribute &e) {
    //os << "[";
    int i = 0;
    for (auto const &x : e.att) {
      os << x.first << "="
         << "\"" << x.second << "\"";
      if (i < e.att.size() - 1) {
        os << ", ";
      }
      i++;
    }
    //os << "];";
    return os;
  }
};

/**
 * Class: Edge
 *
 * Description:
 *      This class creates is used to create edges in the graph
 *      by inherting from the class Attributes
 *
 * Usage:
 *      - It declares all the components of the edges
 *      - Sets defaults attributes of an edge
 *      - Allows user to manipulate and add new edges
 *
 **/
class Edge : public Attribute {

public:
  string eStart;    // decares value for the start edge
  string eEnd;      // decares value for the end edge
  string eLocation; // decares value for the location edge
  string efromLoc;  // decares value for the location edge
  string etoLoc;    // decares value for the location edge

  // Default Constructor
  Edge() {
    att["color"] = "black";   // default color
  }
  // Overloaded constructor
  Edge(string start, string end) {
    att["color"] = "black";   // default color
  
    eStart = start;           // Stores the name of the start edge
    eEnd = end;               // Stores the name of the end edge
  }
  // Overloaded constructor for record types
  Edge(string start, string end, string location) {
    att["color"] = "black";   // default color
  
    eStart = start;           // Stores the name of the start edge
    eEnd = end;               // Stores the name of the end edge
    eLocation = location;     // Stores the location of the end edge
  }

  // Overloaded constructor for record types (with prev and next)
    Edge(string start, string end, string eFromLocation, string eToLocation) {
      att["color"] = "black"; // default color
    
      eStart = start;         // Stores the name of the start edge
      eEnd = end;             // Stores the name of the end edge
      efromLoc =eFromLocation;// Stores the start location of the edge
      etoLoc = eToLocation;   // Stores the end location of the edge
    }
};

/**
 * Class: Node
 *
 * Description:
 *      This class creates is used to create nodes in the graph
 *      by inherting from the class Attributes
 *
 * Usage:
 *      - It declares all the components of the nodes
 *      - Sets defaults attributes of an edge
 *      - Allows user to manipulate and add new edges
 *
 **/
class Node : public Attribute {
//protected:
//int data; 
public:
  int data;
  string nName;
  string nData;
  string nRef;
  string nPrev;     
  string nNext;

  // Default Constructor
  Node(){
    att["color"] = "black"; // default color
    att["shape"] = "box";   // default arrow shape
  }
  // Overloaded Constructor
  Node(string nodeName, string nodeData){
    att["color"] = "black"; // default color
    //att["shape"] = "box"; // default arrow shape
    
    nName = nodeName;       // Stores in name of the node
    nData = nodeData;       // Stores the data of the node
  }
  // Overloaded Constructor (linked list-records)
  Node(string nodeName, string nodeData, string nodeRef){
    att["color"] = "blue";  // default color
    
    nName = nodeName;       // Stores in name of the node
    nData = nodeData;       // Stores the data of the node
    nRef = nodeRef;         // Stores the data of the node
  }
  // Overloaded Constructor (doubly-linked list)
  Node(string nodeName, string nodeData, string nodePrev, string nodeNext){
    att["color"] = "blue";  // default color
    
    nName = nodeName;       // Stores in name of the node
    nData = nodeData;       // Stores the data of the node
    nPrev = nodePrev;       // Stores the prev ref of the node
    nNext = nodeNext;       // Stores the prev ref of the node
  }
};

/**
 * Class: GraphViz
 *
 * Description:
 *      This class creates a graph using vectors of edges and nodes that
 *      that can be used to print out the dot syntax used in GraphViz.
 *
 * Private Methods:
 *      - string makeEid(string start, string end);  // creates an id using start and end of edge
 *      - string makeNid(string nodeName, int data); // creates an id using namean end of node
 *
 * Public Methods:
 *      - int addNode(string nodeName, string nodeData);                
 *      - int addNode(string nodeName, string nodeData, string nodeRef);
 *      - int addNode(string nodeName, string nodeData, string nodePrev, string nodeNext);
 *      - void updateNode(int nodeId, string key, string val);
 *      - void addEdge(string start, string end);
 *      - void addEdge(string start, string end, string location);
 *      - void addEdge(string start, string end, string eFromlocation, string eToLocation);
 *      - void updateEdge(int edgeId, string key, string val);
 *      - void printGraph(ostream &fout,string graphName);
 *      - void printLL(ostream &fout,string graphName);
 *      - void printDLL(ostream &fout,string graphName);
 *      - void printBST(ostream &fout,string graphName);
 *
 * Usage:
 *      - You can use this class to create graphs on GraphViz
 *      - Create an instance and add, update and style nodes and edges
 *
 **/
class GraphViz {
protected:
  
  // Create an Edge Id using start and end points of the edge
  string makeEid(string start, string end) { return start + "-" + end;}

  // Create a node id using the name of the node  
  string makeNid(string nodeName, int data) {return nodeName;} 

public:
  vector<Edge> Edges;  // creates a vector of Edges 
  vector<Node> Nodes;  // creates a vector of Nodes 

  // Default Constructor
  GraphViz() {}

  // Function to add node to vector of Nodes
  int addNode(string nodeName, string nodeData) {
    Nodes.push_back(Node(nodeName,nodeData));
    return Nodes.size() - 1;
  }

  // Overloaded Function to add node to vector of Nodes (between records with ref)
  int addNode(string nodeName, string nodeData, string nodeRef) {
    Nodes.push_back(Node(nodeName,nodeData, nodeRef));
    return Nodes.size() - 1;
  }
  // Overloaded Function to add node to vector of Nodes (with prev and next)
  int addNode(string nodeName, string nodeData, string nodePrev, string nodeNext) {
    Nodes.push_back(Node(nodeName,nodeData, nodePrev, nodeNext));
    return Nodes.size() - 1;
  }

  // Updates the nodes using the add Attribute method
  void updateNode(int nodeId, string key, string val){
    Nodes[nodeId].addAttribute(key, val);
  }

  // Function to add edge to vector of Edges
  void addEdge(string start, string end) { 
    Edges.push_back(Edge(start, end)); 
  }

  // Overloaded function to add edge to vector of Edges (between records)
  void addEdge(string start, string end, string location) { 
    Edges.push_back(Edge(start, end,location)); 
  }

  // Overloaded function to add edge to vector of Edges (with prev and next)
  void addEdge(string start, string end, string eFromlocation, string eToLocation) { 
    Edges.push_back(Edge(start, end,eFromlocation, eToLocation)); 
  }

  // Updates the edges using the add Attribute method
  void updateEdge(int edgeId, string key, string val){
    Edges[edgeId].addAttribute(key, val);
  }

  // Prints out the entire generic graph
  void printGraph(ostream &fout,string graphName) {     
    // Prints name of graph and type of graph
    cout << "digraph " << graphName << "{\n";
    fout << "digraph " << graphName << "{\n";
    
    //Prints out label and background color of the graph
    cout << "\t""label=\"LinkedList\";" << endl; 
    fout << "\t""label=\"LinkedList\";" << endl; 
    cout << "\t""bgcolor=\"gold:skyblue\";" << endl;
    fout << "\t""bgcolor=\"gold:skyblue\";" << endl;
    
    // Prints out global rank direction
    cout << "\t""rankdir=LR;" <<endl;
    fout << "\t""rankdir= LR;"<<endl;

    // Loops through vector of Nodes and outputs to console
    for(int i = 0 ; i < Nodes.size(); i++){
      cout<<"\t"<<Nodes[i].nName<<" "<<"["<<Nodes[i]<<"];"<<endl;
      fout<<"\t"<<Nodes[i].nName<<" "<<"["<<Nodes[i]<<"];"<<endl;
    }
    
    // Loops through vector of Edges and outputs to console
    for(int i = 0; i < Edges.size(); i++){
      cout<<"\t"<<Edges[i].eStart<< "->" <<Edges[i].eEnd<<" "
      <<"["<<Edges[i]<< "];"<<endl;
      fout<<"\t"<<Edges[i].eStart<< "->" <<Edges[i].eEnd<<" "
      <<"["<<Edges[i]<< "];"<<endl;
    }
    
    // Prints out }
    cout << "}\n";
    fout << "}\n";
  }

  // Prints a linked list version of the graph in record format
  void printLL(ostream &fout,string graphName){
    
    // Prints name of graph and type of graph
    cout << "digraph " << graphName << "{\n";
    fout << "digraph " << graphName << "{\n";
    
    //Prints out label and background color of the graph
    cout << "\t""label=\"Linked List\";" << endl; 
    fout << "\t""label=\"Linked List\";" << endl; 
    cout << "\t""bgcolor=\"gold:skyblue\";" << endl;
    fout << "\t""bgcolor=\"gold:skyblue\";" << endl;
    
    // Prints out global rank direction
    cout << "\t""rankdir=LR;" <<endl;
    fout << "\t""rankdir= LR;"<<endl;

    // Prints out global node data 
    cout<<"\t"<<Nodes[0].nName<<" ["<<Nodes[0]<<"];"<<endl;
    fout<<"\t"<<Nodes[0].nName<<" ["<<Nodes[0]<<"];"<<endl;
    
    // Loops through vector of Nodes and outputs to console
    for(int i = 1; i < Nodes.size(); i++){
    
      cout<<"\t"<<Nodes[i].nName<<" [label = \"{ <data> "<<Nodes[i].nData
      <<" | <ref> "<< Nodes[i].nRef<<"}\", " << Nodes[i] <<"];"<<endl;
      
      fout<<"\t"<<Nodes[i].nName<<" [label = \"{ <data> "<<Nodes[i].nData
      <<" | <ref> "<< Nodes[i].nRef<<"}\", " << Nodes[i] <<"];"<<endl;
    }
    
    // Loops through vector of Edges and outputs to console
    for(int i = 0 ; i < Edges.size(); i++){
      cout<<"\t"<<Edges[i].eStart<< ":ref:"<< Edges[i].eLocation << " -> "
      <<Edges[i].eEnd<<":data "<< "[" <<Edges[i] << "];"<<endl;
      
      fout<<"\t"<<Edges[i].eStart<< ":ref:"<< Edges[i].eLocation << " -> "
      <<Edges[i].eEnd<<":data "<< "[" <<Edges[i] << "];"<<endl;
    }
  
    cout << "}" << endl;
    fout << "}" << endl;
  }

  // Prints a doubly-linked list version of the graph in record format
  void printDLL(ostream &fout,string graphName){
    
    // Prints name of graph and type of graph
    cout << "digraph " << graphName << "{\n";
    fout << "digraph " << graphName << "{\n";
    
    //Prints out label and background color of the graph
    cout << "\t""label=\"Doubly-Linked List\";" << endl; 
    fout << "\t""label=\"Doubly-Linked List\";" << endl; 
    cout << "\t""bgcolor=\"gold:red\";" << endl;
    fout << "\t""bgcolor=\"gold:red\";" << endl;
    
    // Prints out global rank direction
    cout << "\t""rankdir=LR;" <<endl;
    fout << "\t""rankdir= LR;" <<endl;

    // Prints out global node data 
    cout<<"\t"<<Nodes[0].nName<<" ["<<Nodes[0]<<"];"<<endl;
    fout<<"\t"<<Nodes[0].nName<<" ["<<Nodes[0]<<"];"<<endl;

    // Prints out global edge data 
    cout<<"\t"<<Edges[0].eStart<<" ["<<Edges[0]<<"];"<<endl;
    fout<<"\t"<<Edges[0].eStart<<" ["<<Edges[0]<<"];"<<endl;

    // Prints out Nptr data 
    cout<<"\t"<<Nodes[1].nName<<" ["<<Nodes[1]<<"];"<<endl;
    fout<<"\t"<<Nodes[1].nName<<" ["<<Nodes[1]<<"];"<<endl;
    
    // Loops through vector of Nodes and outputs to console
    for(int i = 2; i < Nodes.size(); i++){
    
      cout<<"\t"<<Nodes[i].nName<<" [label = \"{ "<<"<prev> " <<Nodes[i].nPrev
      << " | <data> "<<Nodes[i].nData <<" | <ref> "<< Nodes[i].nNext<<"}\", "<< Nodes[i]
      <<  "];"<<endl;
      
      fout<<"\t"<<Nodes[i].nName<<" [label = \"{ "<<"<prev> " <<Nodes[i].nPrev
      << " | <data> "<<Nodes[i].nData <<" | <ref> "<< Nodes[i].nNext<<"}\", "<< Nodes[i]
      <<  "];"<<endl;
    }
    
    // Loops through vector of Edges and outputs to console
    for(int i = 1; i < Edges.size(); i++){
      cout<<"\t"<<Edges[i].eStart<< ":"<< Edges[i].efromLoc << " -> "
      <<Edges[i].eEnd<<":" << Edges[i].etoLoc<< " ["<<Edges[i]<<"];"<<endl;
      
      fout<<"\t"<<Edges[i].eStart<< ":"<< Edges[i].efromLoc << " -> "
      <<Edges[i].eEnd<<":" << Edges[i].etoLoc<< " ["<<Edges[i]<<"];"<<endl;
    }
  
    cout << "}" << endl;
    fout << "}" << endl;
  }

  // Prints a doubly-linked list version of the graph in record format
  void printBST(ostream &fout,string graphName){
    
    // Prints name of graph and type of graph
    cout << "digraph " << graphName << "{\n";
    fout << "digraph " << graphName << "{\n";
    
    //Prints out label and background color of the graph
    cout << "\t""label=\"Binary Search Tree\";" << endl; 
    fout << "\t""label=\"Binary Search Tree\";" << endl; 
    cout << "\t""bgcolor=\"skyblue:pink\";" << endl;
    fout << "\t""bgcolor=\"skyblue:pink\";" << endl;
    
    // Prints out global rank direction
    cout << "\t""rankdir=TB;" <<endl;
    fout << "\t""rankdir= TB;" <<endl;

    // Prints out global node data 
    cout<<"\t"<<Nodes[0].nName<<" ["<<Nodes[0]<<"];"<<endl;
    fout<<"\t"<<Nodes[0].nName<<" ["<<Nodes[0]<<"];"<<endl;

    // Prints out global edge data 
    cout<<"\t"<<Edges[0].eStart<<" ["<<Edges[0]<<"];"<<endl;
    fout<<"\t"<<Edges[0].eStart<<" ["<<Edges[0]<<"];"<<endl;
    
    // Loops through vector of Nodes and outputs to console
    for(int i = 1; i < Nodes.size(); i++){
    
      cout<<"\t"<<Nodes[i].nName<<" [label = \"{ "<<"<prev> " <<Nodes[i].nPrev
      << " | <data> "<<Nodes[i].nData <<" | <ref> "<< Nodes[i].nNext<<"}\", "<< Nodes[i]
      <<  "];"<<endl;
      
      fout<<"\t"<<Nodes[i].nName<<" [label = \"{ "<<"<prev> " <<Nodes[i].nPrev
      << " | <data> "<<Nodes[i].nData <<" | <ref> "<< Nodes[i].nNext<<"}\", "<< Nodes[i]
      <<  "];"<<endl;
    }
    // Loops through vector of Edges and outputs to console
    for(int i = 1; i < Edges.size(); i++){
      cout<<"\t"<<Edges[i].eStart << " -> " <<"{ "<<Edges[i].eEnd<< " } ["<<Edges[i]<<"];"<<endl;
      
      fout<<"\t"<<Edges[i].eStart<< " -> " <<"{ "<<Edges[i].eEnd<< " } ["<<Edges[i]<<"];"<<endl;
    }
  
    cout << "}" << endl;
    fout << "}" << endl;
  }
};


/**
* Public : printHeading
* 
* Description:
*      Fucntion to print and post the heading of the program 
* 
* Params:
*      ofstream: &fout
* 
* Returns:
*      Nothing : prints heading to console and output file
*/
void printHeading(ofstream &fout) {
  cout << "Ethan Bailey" << endl;
  cout << "03/04/2023" << endl;
  cout << "Spring 2143" << endl;
  cout << endl;
 
  fout << "Ethan Bailey" << endl;
  fout << "03/04/2023" << endl;
  fout << "Spring 2143" << endl;
  fout << endl;
}

int main() {
  int start = 0;            // initializes variable used to track the program 
  string graphName;         // declares varibale used to hold the graph name 

  // Create an instance of the output file stream
  ofstream fout;            // calls ofstream to create an instance
  fout.open("output.txt");  // opens the output file
  
  // Loop to excute program
  for (int i = 0; i < 3; i++){
      // Prints heading only at the start of the program
      if (start==0){
        // Prints heading of program
        printHeading(fout);
      }
    
      // Prompts user for name of graph
      cout << "State the the type of your graph (BST/DLL/LL): ";
      cin >> graphName;
    
      // Prints graph based on graph type 
      if (graphName == "BST"){
        // Create instance of GraphViz class (Object)
        GraphViz graph1;
        
        // Sets global node attributes of the graph
        graph1.addNode("node", "0");
        graph1.updateNode(0, "shape", "record");
        graph1.updateNode(0, "arrowhead", "dot");
      
        // Sets the global edge attributes of the graph
        graph1.addEdge("edge", "0");
        graph1.updateEdge(0, "arrowhead", "vee");
        graph1.updateEdge(0, "arrowtail", "dot");
        graph1.updateEdge(0, "dir", "both");
        graph1.updateEdge(0, "tailclip", "false");

        // Creates other nodes in the graph
        graph1.addNode("11", "0", "81", "90");
        graph1.addNode("23", "0", "74", "10");
        graph1.addNode("7", "23", "45", "12");
        
        // Sets the node attributes
        graph1.updateNode(1, "color", "purple");
        graph1.updateNode(2, "color", "red");

        // Creates edges between nodes
        graph1.addEdge("11:s", "7,23");
        graph1.addEdge("7:next", "3,9");
        graph1.addEdge("23:prev", "13,51");

        // Sets the edge attributes
        graph1.updateEdge(1, "color", "maroon");
        graph1.updateEdge(2, "color", "purple");
        graph1.updateEdge(3, "color", "gold");
        graph1.updateEdge(2, "arrowhead", "icurve");
        graph1.updateEdge(3, "arrowhead", "diamond");

        // Prints out the graph
        graph1.printBST(fout, graphName);
        
      }else if (graphName == "DLL"){
        // Create instance of GraphViz class (Object)
        GraphViz graph2;    

        // Sets global atributes of the graph
        graph2.addNode("node", "0");
        graph2.updateNode(0, "shape", "record");
        graph2.updateNode(0, "arrowhead", "invdot");
        graph2.updateNode(0, "arrowtail", "dot");
        
        graph2.addEdge("edge", "0");
        graph2.updateEdge(0, "arrowhead", "vee");
        graph2.updateEdge(0, "arrowtail", "dot");
        graph2.updateEdge(0, "dir", "both");
        graph2.updateEdge(0, "tailclip", "false");

        // Sets Nptr atributes of the graph
        graph2.addNode("Nptr", "0");
        graph2.updateNode(1, "label", "null");
        graph2.updateNode(1, "shape", "star");
        graph2.updateNode(1, "color", "silver");

        // Creates other nodes in the graph
        graph2.addNode("N0", "1", "23", "09");
        graph2.addNode("N1", "5", "12", "Me");
        graph2.addNode("N2", "7", "49", "You");

        // Adds other node attrbutes 
        graph2.updateNode(2, "color", "grey");
        graph2.updateNode(3, "color", "green");
        graph2.updateNode(4, "color", "purple");

        // Example of adding edge between records (includes next and prev):
        graph2.addEdge("Nptr", "N0:prev", "e" , "N2");
        graph2.addEdge("N0:next", "N1:data", "N2" , "n");
        graph2.addEdge("N1:next", "N2:data", "N2" , "n");
        graph2.addEdge("N2:next", "N3", "N2" , "N3");
        graph2.addEdge("N2:prev", "N1:data", "N2" , "s");
        graph2.addEdge("N1:prev", "N0:data", "N2" , "s");

        // Update edge attributes
        graph2.updateEdge(1, "arrowhead", "dot");
        graph2.updateEdge(2, "color", "purple");
        graph2.updateEdge(3, "width", "1.0");
        graph2.updateEdge(4, "headclip", "true");
        graph2.updateEdge(5, "label", "She Calls Me");
        graph2.updateEdge(6, "label", "Crazy");

        graph2.updateEdge(3, "dir", "both");
        graph2.updateEdge(4, "color", "pink");
        graph2.updateEdge(5, "color", "blue");
        graph2.updateEdge(6, "color", "skyblue");

        // Prints out the graph in DLL format
        graph2.printDLL(fout, graphName);
        
      }else{
        // Create instance of GraphViz class (Object)
        GraphViz graph3;
  
        // Sets global atributes of the graph
        graph3.addNode("node", "0");
        graph3.updateNode(0, "shape", "circle");
        
        // Creates nodes in our graph (records  with ref)
        graph3.addNode("N1", "23", "50");
        graph3.addNode("N2", "34", "70");
        graph3.addNode("N3", "42", "45");
        graph3.addNode("null", "null", "null");
        
        // Creates attributes for the nodes in our graph
        graph3.updateNode(1, "color", "blue");
        graph3.updateNode(2, "color", "purple");
        graph3.updateNode(3, "color", "red");
        graph3.updateNode(4, "width", "1.2");

        graph3.updateNode(1, "shape", "diamond");
        graph3.updateNode(2, "shape", "box3d");
        graph3.updateNode(3, "shape", "box");
        graph3.updateNode(4, "shape", "plain"); 
       
        // Creates edges in our graph
        graph3.addEdge("N1", "N2", "n");
        graph3.addEdge("N2", "N3", "w");
        graph3.addEdge("N3", "N4", "e");
        graph3.addEdge("N4", "null", "s");
                    
        // Creates attributes for the nodes in our graph
        graph3.updateEdge(0, "color", "navy");
        graph3.updateEdge(1, "color", "purple");
        graph3.updateEdge(2, "color", "red");
      
        graph3.updateEdge(0, "dir", "one");
        graph3.updateEdge(1, "dir", "one");
        graph3.updateEdge(2, "dir", "none");

        graph3.updateEdge(0, "arrowhead", "vee");
        graph3.updateEdge(1, "arrowhead", "icurve");
        graph3.updateEdge(2, "arrowhead", "diamond");

        // Prints out graph
        graph3.printGraph(fout, graphName);

        // Prints out record version of graph 
        // graph3.updateNode(0, "shape", "record");
        // graph3.updateNode(1, "shape", "record");
        // graph3.updateNode(2, "shape", "record");
        // graph3.updateNode(3, "shape", "record");
        // graph3.updateNode(4, "shape", "record");
        // graph3.printLL(fout, graphName);
      }
      
      // Increment program
      start ++;
    }
  
  // Close output file
  fout.close();
  
  return 0;
}