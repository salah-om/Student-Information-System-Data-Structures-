#include "DoublyLinkedList.h"
#include <iostream>
#include <iomanip>

// Default Constructor: Initializes an empty list.
DoublyLinkedList::DoublyLinkedList() : myFirst(nullptr), mySize(0) {}

// Copy Constructor: Creates a deep copy of the source list.
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &source) : myFirst(nullptr), mySize(0) {
    DNodePtr sourceNode = source.myFirst;
    DNodePtr newNode;
    DNodePtr lastNewNode = nullptr;

    while (sourceNode != nullptr) {
        newNode = new(nothrow) DNode(sourceNode->data);

        if (!newNode) {
            cerr << "*** Inadequate memory to allocate storage for list ***\n";
            // Memory allocation failure
            break;
        }

        if (lastNewNode == nullptr) {
            myFirst = newNode;
        } else {
            lastNewNode->next = newNode;
            newNode->prev = lastNewNode;
        }

        lastNewNode = newNode;
        sourceNode = sourceNode->next;
        mySize++;
    }
}


// Destructor: Frees all nodes in the list.
DoublyLinkedList::~DoublyLinkedList() {
    DNodePtr temp;
    while (myFirst != nullptr) {
        temp = myFirst;
        myFirst = temp->next;
        delete temp; // Delete each node.
    }
}

// Assignment operator: Assigns another list to this list.
DoublyLinkedList &DoublyLinkedList::operator=(const DoublyLinkedList &other) {
    if (this != &other) { // Check for self-assignment
        // Clear the current list
        while (!isEmpty()) {
            remove(at(0)->data.getID());
        }

        // Deep copy from the other list
        DNodePtr current = other.myFirst;
        while (current != nullptr) {
            insert(current->data);  // Insert data from the other list
            current = current->next;
        }
    }
    return *this; // Return a reference to the current object
}

bool DoublyLinkedList::isEmpty() const {
    return mySize == 0;
}

// Insert function: Adds a new node with the given data at the end of the list.
bool DoublyLinkedList::insert(const StudentType &data) {
    DNodePtr newPtr = new(nothrow) DNode(data); // Use nothrow here
    if (!newPtr) {
        cerr << "*** Inadequate memory to allocate storage for new node ***\n";
        // Memory allocation failure
        return false;
    }

    if (isEmpty()) {
        myFirst = newPtr; // If the list is empty, set the new node as the first node.
    } else {
        DNodePtr temp = myFirst;
        while (temp->next != nullptr) {
            temp = temp->next; // Find the last node.
        }
        newPtr->prev = temp;
        temp->next = newPtr; // Append the new node.
    }
    mySize++;
    return true;
}


// Remove function: Deletes the first node with the matching ID.
bool DoublyLinkedList::remove(const string &id) {
    DNodePtr temp = myFirst;
    while (temp != nullptr) {
        if (temp->data.getID() == id) {
            if (temp->prev == nullptr) {
                myFirst = temp->next; // If it's the first node, update the head.
            } else {
                temp->prev->next = temp->next; // Bypass the node to delete.
            }
            delete temp;
            mySize--;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Size function: Returns the number of elements in the list.
int DoublyLinkedList::getSize() const {
    return mySize;
}

// Find function: Searches for a student by ID and returns a pointer to it.
StudentType *DoublyLinkedList::find(const string &id) const {
    DNodePtr temp = myFirst;
    while (temp != nullptr) {
        if (temp->data.getID() == id) {
            return &(temp->data);
        }
        temp = temp->next;
    }
    return nullptr;
}

// Display function: Outputs the details of each student in the list.

void DoublyLinkedList::display(ostream &out) const {
    const int idWidth = 10;     // Width for the ID column
    const int nameWidth = 20;   // Width for the Name column
    const int gpaWidth = 6;     // Width for the GPA column
    const int statusWidth = 16; // Width for the Academic Status column

    out << left << setw(idWidth) << "ID" << setw(nameWidth) << "Name"
        << setw(gpaWidth) << "GPA" << setw(statusWidth) << "Academic Status" << endl;

    DNodePtr current = myFirst;
    while (current != nullptr) {
        out << left << setw(idWidth) << current->data.getID()
            << setw(nameWidth) << current->data.getLastName() + ", " + current->data.getFirstName()
            << setw(gpaWidth) << current->data.getGPA()
            << setw(statusWidth) << current->data.getAcademicStatus() << endl;
        current = current->next;
    }
}


DoublyLinkedList::DNodePtr DoublyLinkedList::at(int index) const {
    DNodePtr currentNode = myFirst; // Assuming head points to the first node in the list
    int currentIndex = 0;
    while (currentNode != nullptr && currentIndex < index) {
        currentNode = currentNode->next; // Move to the next node
        ++currentIndex;
    }
    if (currentIndex == index) {
        return currentNode; // Found the node at the specified index
    } else {
        return nullptr; // Index out of bounds
    }
}

// Overloaded << operator: Outputs the list using the display function.
ostream &operator<<(ostream &out, const DoublyLinkedList &list) {
    list.display(out);
    return out;
}

// Overloaded >> operator: Reads data into the list from an input stream.
istream &operator>>(istream &in, DoublyLinkedList &list) {
    int studentsSize;
    in >> studentsSize; // Read the number of students to be read

    for (int i = 0; i < studentsSize; ++i) {
        StudentType student;
        in >> student; // Read student data using the overloaded >> operator for Student
        if (!in) {
            // Error handling if input fails
            break;
        }
        list.insert(student); // Insert the course into the list
    }
    return in;
}