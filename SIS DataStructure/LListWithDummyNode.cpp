#include "LListWithDummyNode.h"
#include <iostream>
#include <iomanip>
#include <new>

// Constructor: Initializes a new linked list with a dummy node.
LListWithDummyNode::LListWithDummyNode() : myFirst(new Node(CourseType())), mySize(0) {}

// Copy Constructor: Creates a deep copy of another list.
LListWithDummyNode::LListWithDummyNode(const LListWithDummyNode &other) : myFirst(new Node(CourseType())), mySize(0) {
    NodePtr current = other.myFirst->next; // Start after the dummy node of the other list
    while (current != nullptr) {
        insert(current->data);  // Insert data from the other list
        current = current->next;
    }
}

// Destructor: Frees all the nodes in the list, including the dummy node.
LListWithDummyNode::~LListWithDummyNode() {
    NodePtr current = myFirst->next; // Start after the dummy node
    while (current != nullptr) {
        NodePtr next = current->next; // Save the next node
        delete current;             // Delete the current node
        current = next;             // Move to the next node
    }
    delete myFirst; // Delete the dummy node
}

// Insert function: Adds a new node with the given data at the end of the list.
bool LListWithDummyNode::insert(const CourseType &data) {
    NodePtr newNode = new (std::nothrow) Node(data);
    if (newNode == nullptr) {
        // Memory allocation failed
        return false;
    }

    NodePtr current = myFirst;
    while (current->next != nullptr) { // Traverse to the end of the list
        current = current->next;
    }
    current->next = newNode; // Insert the new node at the end
    mySize++;                // Increment size

    return true; // Insertion successful
}

// Remove function: Deletes the first node with the matching course code.
bool LListWithDummyNode::remove(const string &courseCode) {
    NodePtr current = myFirst;
    while (current->next != nullptr && current->next->data.getCode() != courseCode) {
        current = current->next; // Traverse until the course is found
    }

    if (current->next == nullptr) {
        return false; // Course code not found
    } else {
        NodePtr toDelete = current->next; // Node to delete
        current->next = toDelete->next; // Bypass the node to delete
        delete toDelete;               // Delete the node
        mySize--;                      // Decrement size
        return true;
    }
}

// Size function: Returns the number of elements in the list, excluding the dummy node.
int LListWithDummyNode::size() const {
    return mySize;
}

// IsEmpty function: Checks if the list is empty (excluding the dummy node).
bool LListWithDummyNode::isEmpty() const {
    return mySize == 0;
}

// Find function: Searches for a course by its code and returns a pointer to it.
CourseType *LListWithDummyNode::find(const string &courseCode) const {
    NodePtr current = myFirst->next;  // Skip the dummy node
    while (current != nullptr) {
        if (current->data.getCode() == courseCode) {
            return &(current->data); // Return the course if found
        }
        current = current->next;
    }
    return nullptr; // Course not found
}

// Display function: Outputs the details of each course in the list.
void LListWithDummyNode::display(ostream &out) const {
    const int codeWidth = 10;
    const int titleWidth = 40;
    const int creditWidth = 10;
    const int enrolledWidth = 10;
    const int capacityWidth = 10;

    out << left << setw(codeWidth) << "Code"
        << setw(titleWidth) << "Title"
        << setw(creditWidth) << "#Credits"
        << setw(enrolledWidth) << "Enrolled"
        << setw(capacityWidth) << "Capacity" << endl;

    Node *current = myFirst->next; // Skip the dummy node
    while (current != nullptr) {
        out << left << setw(codeWidth) << current->data.getCode()
            << setw(titleWidth) << current->data.getTitle()
            << setw(creditWidth) << current->data.getCredits()
            << setw(enrolledWidth) << current->data.getEnrolled()
            << setw(capacityWidth) << current->data.getCapacity() << endl;
        current = current->next;
    }
}

// Access a specific node by its index in the list.
LListWithDummyNode::NodePtr LListWithDummyNode::at(int index) const {
    NodePtr currentNode = myFirst->next; // Start after the dummy node
    int currentIndex = 0;
    while (currentNode != nullptr && currentIndex < index) {
        currentNode = currentNode->next; // Move to the next node
        ++currentIndex;
    }
    if (currentIndex == index) {
        return currentNode; // Return the node if found at the specified index
    } else {
        return nullptr; // Return nullptr if index is out of bounds
    }
}

// Assignment operator: Assigns another list to this list.
LListWithDummyNode& LListWithDummyNode::operator=(const LListWithDummyNode &other) {
    if (this != &other) { // Check for self-assignment
        // Clear the current list
        while (!isEmpty()) {
            remove(at(0)->data.getCode());
        }

        // Now copy from the other list
        NodePtr current = other.myFirst->next; // Start after the dummy node of the other list
        while (current != nullptr) {
            insert(current->data);  // Insert data from the other list
            current = current->next;
        }
    }
    return *this; // Return a reference to the current object
}


// Overloaded << operator: Outputs the list using the display function.
ostream &operator<<(ostream &out, const LListWithDummyNode &list) {
    list.display(out); // Display the list contents
    return out;
}

// Overloaded >> operator: Reads data into the list from an input stream.
istream &operator>>(istream &in, LListWithDummyNode &list) {
    int coursesSize;
    in >> coursesSize; // Read the number of courses to be read

    for (int i = 0; i < coursesSize; ++i) {
        Course course;
        in >> course; // Read course data using the overloaded >> operator for Course
        if (!in) {
            // Error handling if input fails
            break;
        }
        list.insert(course); // Insert the course into the list
    }
    return in;
}