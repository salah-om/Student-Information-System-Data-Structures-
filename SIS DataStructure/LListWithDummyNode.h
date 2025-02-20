/*-- LListWithDummyNode.h -----------------------------------------------------

  This header file defines the data type LListWithDummyNode for processing linked lists.
  Basic operations are:
     Default Constructor
     Copy Constructor
     Assignment Operator
     Destructor
     insert: Insert a new element at the end of the list
     remove: Deletes a specific element
     size: Retrieve the size of the list
     isEmpty: Check if the list is empty
     find: Find a specific course in the list
     display: Display the list elements
     at: Access a specific node in the list by its index
     Operator<<: Output stream operator for LListWithDummyNode objects
     Operator>>: Input stream operator for LListWithDummyNode objects
  Private member variables:
     Node: A private class within LListWithDummyNode representing a list node
     myFirst: Pointer to the first node (dummy node)
     mySize: Number of elements in the list
-------------------------------------------------------------------------*/

#ifndef LLISTWITHDUMMYNODE_H
#define LLISTWITHDUMMYNODE_H

#include <string>
#include "Course.h"

using namespace std;

typedef Course CourseType; // Alias CourseType to Course

class LListWithDummyNode {
private:
    // Node class definition
    class Node {
    public:
        CourseType data;  // The data stored in the node
        Node *next;       // Pointer to the next node in the list

        // Node constructor
        Node(const CourseType &n) : data(n), next(nullptr) {}
    };

    typedef Node *NodePtr;
    NodePtr myFirst;  // Pointer to the first node (dummy node)
    int mySize;       // Number of elements in the list

public:
    /******** Function Members ********/
    /***** Constructor *****/
    LListWithDummyNode();

    /*----------------------------------------------------------------------
      Construct a default LListWithDummyNode object.

      Precondition: None.
      Postcondition: A default LListWithDummyNode object is created with a dummy node.
    -----------------------------------------------------------------------*/

    /***** Copy Constructor *****/
    LListWithDummyNode(const LListWithDummyNode &);

    /*----------------------------------------------------------------------
      Construct a copy of a LListWithDummyNode object.

      Precondition: A copy of an existing LListWithDummyNode object is needed.
      Postcondition: A copy of the LListWithDummyNode object is created.
    -----------------------------------------------------------------------*/

    /***** Destructor *****/
    ~LListWithDummyNode();

    /*----------------------------------------------------------------------
      Destruct a LListWithDummyNode object.

      Precondition: The life of a LListWithDummyNode object is over.
      Postcondition: The memory dynamically allocated for the linked list nodes
                     has been returned to the heap.
    -----------------------------------------------------------------------*/

    /***** Assignment Operator *****/
    LListWithDummyNode &operator=(const LListWithDummyNode &);

    /*----------------------------------------------------------------------
      Assigns the content of another LListWithDummyNode object to this object.

      Precondition: The right-hand side object, other, is an existing
      LListWithDummyNode object.

      Postcondition: The current list is cleared and then filled with a deep copy of the
      contents of the other list. If the current object and the other object are the same,
      no actions are performed. The current object is returned.
    -----------------------------------------------------------------------*/

    /***** Functionality *****/
    /***** Insert Course *****/
    bool insert(const CourseType &data);

    /*----------------------------------------------------------------------
      Insert a new element at the end of the list.

      Precondition: data is an object of CourseType.
      Postcondition: The new element is inserted at the end of the list.
    -----------------------------------------------------------------------*/

    /***** Remove course *****/
    bool remove(const string &code);

    /*----------------------------------------------------------------------
      Deletes a specific element based on course code.

      Precondition: code is a string representing the course code.
      Postcondition: If an element with the specified code exists, it is removed from the list,
                     and true is returned; otherwise, false is returned.
    -----------------------------------------------------------------------*/

    /***** Utility functions *****/
    /***** Get Size of List *****/
    int size() const;

    /*----------------------------------------------------------------------
      Retrieve the size of the list.

      Precondition: None.
      Postcondition: Returns the number of elements in the list.
    -----------------------------------------------------------------------*/

    /***** Check if Empty *****/
    bool isEmpty() const;

    /*----------------------------------------------------------------------
      Check if the list is empty.

      Precondition: None.
      Postcondition: Returns true if the list is empty, false otherwise.
    -----------------------------------------------------------------------*/

    /***** Find Course *****/
    CourseType *find(const string &code) const;

    /*----------------------------------------------------------------------
      Find a specific course in the list by its code.

      Precondition: code is a string representing the course code.
      Postcondition: Returns a pointer to the CourseType object if found; otherwise, returns nullptr.
    -----------------------------------------------------------------------*/

    /***** Display List Contents *****/
    void display(ostream &out) const;

    /*----------------------------------------------------------------------
      Display the list elements.

      Precondition: out is an output stream.
      Postcondition: The elements of the list are outputted to the stream.
    -----------------------------------------------------------------------*/

    /***** Access to a specific node *****/
    NodePtr at(int index) const;

    /*----------------------------------------------------------------------
      Access a specific node in the list by its index.

      Precondition: index is an integer.
      Postcondition: Returns a pointer to the node at the specified index; if the index is out of bounds, returns nullptr.
    -----------------------------------------------------------------------*/
};

/***** Non-member Functions *****/
/***** Stream Insertion Operator *****/
ostream &operator<<(ostream &, const LListWithDummyNode &);

/*----------------------------------------------------------------------
  Output stream operator for LListWithDummyNode objects.

  Precondition: out is an output stream, list is a LListWithDummyNode object.
  Postcondition: The list's data is outputted to the stream in a formatted manner.
-----------------------------------------------------------------------*/

/***** Stream Extraction Operator *****/
istream &operator>>(istream &, LListWithDummyNode &);

/*----------------------------------------------------------------------
  Input stream operator for LListWithDummyNode objects.

  Precondition: in is an input stream, list is a LListWithDummyNode object.
  Postcondition: The list object is populated with data from the input stream.
-----------------------------------------------------------------------*/

#endif // LLISTWITHDUMMYNODE_H