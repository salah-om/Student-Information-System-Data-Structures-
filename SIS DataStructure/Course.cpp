#include "Course.h"
#include <sstream>

using namespace std;

// Default Constructor
Course::Course() : code(""), title(""), credits(0), enrolled(0), capacity(0) {
    // Initializes a course object with default values.
}

// Parameterized Constructor
Course::Course(const string &code, const string &title, int credits, int capacity)
        : code(code), title(title), credits(credits), enrolled(0), capacity(capacity) {
    // Initializes a course object with specified code, title, credits, and capacity.
    // The number of enrolled students is initially set to 0.
}

// Getters

// Returns the course code.
string Course::getCode() const {
    return code;
}

// Returns the course title.
string Course::getTitle() const {
    return title;
}

// Returns the number of credits for the course.
int Course::getCredits() const {
    return credits;
}

// Returns the current number of enrolled students.
int Course::getEnrolled() const {
    return enrolled;
}

// Returns the capacity of the course.
int Course::getCapacity() const {
    return capacity;
}

// Setters

// Sets the course code. Assumes validation is done elsewhere.
void Course::setCode(const string &newCode) {
    code = newCode;
}

// Sets the course title. Assumes validation is done elsewhere.
void Course::setTitle(const string &newTitle) {
    title = newTitle;
}

// Sets the number of credits for the course. Assumes validation is done elsewhere.
void Course::setCredits(int newCredits) {
    credits = newCredits;
}

// Sets the capacity of the course. Assumes validation is done elsewhere.
void Course::setCapacity(int newCapacity) {
    capacity = newCapacity;
}

// Sets the number of enrolled students. Assumes validation is done elsewhere.
void Course::setEnrolled(int newEnrolled) {
    enrolled = newEnrolled;
}

// Display Function

// Displays course information.
void Course::display(ostream &os) const {
    os << "Course Code: " << code << "\n"
       << "Title: " << title << "\n"
       << "#Credits: " << credits << "\n"
       << "Enrolled: " << enrolled << "\n"
       << "Capacity: " << capacity << endl;
}

// Checks if the course is full (enrolled students equal or exceed capacity).
bool Course::isFull() const {
    return enrolled >= capacity;
}

// Overloaded Operators

// Inequality operator. Compares courses based on their code.
bool Course::operator!=(const Course &other) const {
    return code != other.code;
}

// Student Management

// Adds a student ID to the list and increments the enrolled count.
void Course::addStudentID(const string &id) {
    studentIDs.push_back(id);
    enrolled++;
}

// Returns the list of student IDs enrolled in the course.
const vector<string> &Course::getStudentIDs() const {
    return studentIDs;
}

// Removes a student ID from the list and decrements the enrolled count.
void Course::removeStudentID(const string &id) {
    for (size_t i = 0; i < studentIDs.size(); ++i) {
        if (studentIDs[i] == id) {
            studentIDs.erase(studentIDs.begin() + i); // Remove the student ID
            --enrolled; // Decrement the enrolled count
            break; // Exit the loop after removing the ID
        }
    }
}

// Stream Insertion Operator

// Stream insertion operator for outputting course data.
ostream &operator<<(ostream &out, const Course &course) {
    course.display(out);
    return out;
}

// Stream Extraction Operator

// Stream extraction operator for reading course data.
istream &operator>>(istream &in, Course &course) {
    string code;
    string title;
    int credits;
    int capacity;

    // Read the course code, handling leading whitespace.
    in >> ws;
    if (!getline(in, code, ' ')) {
        return in; // If failed to read code, return.
    }

    // Read the course title, stopping when credits are encountered.
    string part;
    title.clear();
    while (in >> part) {
        if (isdigit(part[0])) {
            stringstream ss(part);
            ss >> credits;
            break; // Found credits, exit loop.
        } else {
            if (!title.empty()) {
                title += " "; // Add space before next title part.
            }
            title += part;
        }
    }

    // Read the course capacity.
    in >> capacity;

    // Create the course object with the data read.
    course = Course(code, title, credits, capacity);

    return in;
}