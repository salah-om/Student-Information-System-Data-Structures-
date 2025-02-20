/*-- DoublyLinkedList.h -------------------------------------------------------

  This header file defines the data type DoublyLinkedList for managing a list of Student objects.
  Basic operations are:
     Default Constructor
     Copy Constructor
     Assignment Operator
     Destructor
     insert: Insert a new element into the list
     remove: Remove an element from the list based on a given ID
     find: Find and return an element with a specific ID
     isEmpty: Check if the list is empty
     getSize: Retrieve the number of elements in the list
     display: Display the list elements
     at: Access a specific node in the list by its index
     Operator<<: Output stream operator for DoublyLinkedList objects
     Operator>>: Input stream operator for DoublyLinkedList objects
  Private member variables:
     DNode: A private class within DoublyLinkedList representing a list node
     myFirst: Pointer to the first node in the list
     mySize: Number of elements in the list
-------------------------------------------------------------------------*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Student.h"
#include <string>

using namespace std;

typedef Student StudentType;

class DoublyLinkedList {
private:
    // Node class definition
    class DNode {
    public:
        StudentType data;  // The data stored in the node
        DNode *prev;       // Pointer to the previous node
        DNode *next;       // Pointer to the next node

        // Node constructor
        DNode(const StudentType &dataValue) : data(dataValue), prev(nullptr), next(nullptr) {}
    };

    typedef DNode *DNodePtr;
    DNodePtr myFirst;  // Pointer to the first node in the list
    int mySize;        // Number of elements in the list

public:
    /******** Function Members ********/
    /***** Constructor *****/
    DoublyLinkedList();
    /*----------------------------------------------------------------------
      Construct a default DoublyLinkedList object.

      Precondition: None.
      Postcondition: A default DoublyLinkedList object is created.
    -----------------------------------------------------------------------*/

    /***** Copy Constructor *****/
    DoublyLinkedList(const DoublyLinkedList &source);
    /*----------------------------------------------------------------------
      Construct a copy of a DoublyLinkedList object.

      Precondition: A copy of an existing DoublyLinkedList object is needed.
      Postcondition: A copy of the DoublyLinkedList object is created.
    -----------------------------------------------------------------------*/

    /***** Destructor *****/
    ~DoublyLinkedList();
    /*----------------------------------------------------------------------
      Destruct a DoublyLinkedList object.

      Precondition: The life of a DoublyLinkedList object is over.
      Postcondition: The memory dynamically allocated for the linked list nodes
                     has been returned to the heap.
    -----------------------------------------------------------------------*/

    /***** Assignment Operator *****/
    DoublyLinkedList &operator=(const DoublyLinkedList &);
    /*----------------------------------------------------------------------
      Assigns the content of another LListWithDummyNode object to this object.

      Precondition: The right-hand side object, other, is an existing
      LListWithDummyNode object.

      Postcondition: The current list is cleared and then filled with a deep copy of the
      contents of the other list. If the current object and the other object are the same,
      no actions are performed. The current object is returned.
    -----------------------------------------------------------------------*/

    /***** Functionality *****/
    /***** Add Student *****/
    bool insert(const StudentType &element);

    /*----------------------------------------------------------------------
      Insert a new element into the list.

      Precondition: element is an object of ElementType (Student).
      Postcondition: The new element is inserted into the list, and true is returned.
                     If the insertion fails, false is returned.
    -----------------------------------------------------------------------*/

    /***** Remove Student *****/
    bool remove(const string &id);

    /*----------------------------------------------------------------------
      Remove an element from the list based on a given ID.

      Precondition: id is a string representing the ID of the element to remove.
      Postcondition: If an element with the specified ID exists, it is removed from the list,
                     and true is returned; otherwise, false is returned.
    -----------------------------------------------------------------------*/

    /***** Find Student *****/
    StudentType *find(const string &id) const;

    /*----------------------------------------------------------------------
      Find and return an element with a specific ID.

      Precondition: id is a string representing the ID of the element to find.
      Postcondition: Returns a pointer to the ElementType object if found; otherwise, returns nullptr.
    -----------------------------------------------------------------------*/

    /***** Check if Empty *****/
    bool isEmpty() const;

    /*----------------------------------------------------------------------
      Check if the list is empty.

      Precondition: None.
      Postcondition: Returns true if the list is empty, false otherwise.
    -----------------------------------------------------------------------*/

    /***** Get Size of List *****/
    int getSize() const;

    /*----------------------------------------------------------------------
      Retrieve the number of elements in the list.

      Precondition: None.
      Postcondition: Returns the number of elements in the list.
    -----------------------------------------------------------------------*/

    /***** Display List Contents *****/
    void display(ostream &out) const;

    /*----------------------------------------------------------------------
      Display the list elements.

      Precondition: out is an output stream.
      Postcondition: The elements of the list are outputted to the stream in a formatted manner.
    -----------------------------------------------------------------------*/

    /***** Access Specific Node *****/
    DNodePtr at(int index) const;

    /*----------------------------------------------------------------------
      Access a specific node in the list by its index.

      Precondition: index is an integer.
      Postcondition: Returns a pointer to the node at the specified index; if the index is out of bounds, returns nullptr.
    -----------------------------------------------------------------------*/
};

/***** Non-member Functions *****/
/***** Stream Insertion Operator *****/
ostream &operator<<(ostream &out, const DoublyLinkedList &);

/*----------------------------------------------------------------------
  Output stream operator for DoublyLinkedList objects.

  Precondition: out is an output stream, list is a DoublyLinkedList object.
  Postcondition: The list's data is outputted to the stream in a formatted manner.
-----------------------------------------------------------------------*/

/***** Stream Extraction Operator *****/
istream &operator>>(istream &in, DoublyLinkedList &);

/*----------------------------------------------------------------------
  Input stream operator for DoublyLinkedList objects.

  Precondition: in is an input stream, list is a DoublyLinkedList object.
  Postcondition: The list object is populated with data from the input stream.
-----------------------------------------------------------------------*/

#endif // DOUBLYLINKEDLIST_H
