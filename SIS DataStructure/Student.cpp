#include "Student.h"
#include <iostream>

// Default Constructor
Student::Student()
        : ID(""), firstName(""), lastName(""), GPA(0.0), academicStatus("None") {
    // Initializes a student object with default values.
}

// Parameterized Constructor
Student::Student(const string &ID, const string &firstName, const string &lastName, double GPA) {
    // Initializes a student object with provided values and performs validation.
    if (!setID(ID)) {
        cerr << "Invalid ID: " << ID << endl;
    } else if (!setLastName(lastName)) {
        cerr << "Invalid last name: " << lastName << endl;
    } else if (!setFirstName(firstName)) {
        cerr << "Invalid first name: " << firstName << endl;
    } else if (!setGPA(GPA)) {
        cerr << "Invalid GPA: " << GPA << endl;
    } else {
        updateAcademicStatus();
    }
}

// Setters

// Sets student ID after validation.
bool Student::setID(const string &id) {
    if (id.length() != 8 || id[0] != 'A') {
        cerr << "ID must be 8 characters long and start with 'A'." << endl;
        return false;
    }
    for (int i = 1; i < id.length(); ++i) {
        if (id[i] < '0' || id[i] > '9') {
            cerr << "ID must contain digits after the first character." << endl;
            return false;
        }
    }
    this->ID = id;
    return true;
}

// Sets student first name after validation.
bool Student::setFirstName(const string &fn) {
    for (char ch: fn) {
        if ((ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z')) {
            cerr << "First name must contain only alphabetic characters." << endl;
            return false;
        }
    }
    this->firstName = fn;
    return true;
}

// Sets student last name after validation.
bool Student::setLastName(const string &ln) {
    for (char ch: ln) {
        if ((ch < 'A' || ch > 'Z') && (ch < 'a' || ch > 'z')) {
            cerr << "Last name must contain only alphabetic characters." << endl;
            return false;
        }
    }
    this->lastName = ln;
    return true;
}

// Sets student GPA and updates academic status.
bool Student::setGPA(double gpa) {
    if (gpa > 4.0 || gpa < 0.0) {
        cerr << "GPA must be between 0.0 and 4.0." << endl;
        return false;
    }
    this->GPA = gpa;
    updateAcademicStatus();
    return true;
}

// Getters

// Returns student ID.
string Student::getID() const {
    return ID;
}

// Returns student first name.
string Student::getFirstName() const {
    return firstName;
}

// Returns student last name.
string Student::getLastName() const {
    return lastName;
}

// Returns student GPA.
double Student::getGPA() const {
    return GPA;
}

// Returns student academic status.
string Student::getAcademicStatus() const {
    return academicStatus;
}

// Updates the academic status based on GPA.
void Student::updateAcademicStatus() {
    if (GPA < 2.0) {
        academicStatus = "Probation";
    } else {
        academicStatus = "Regular";
    }
}

// Course Management

// Adds a course code to the list of registered courses.
void Student::addCourseCode(const string &code) {
    courseCodes.push_back(code);
}

// Returns a reference to the list of registered course codes.
const vector<string> &Student::getCourseCodes() const {
    return courseCodes;
}

// Checks if student is registered in a specific course.
bool Student::isRegisteredInCourse(const string &courseCode) const {
    for (const string &code: courseCodes) {
        if (code == courseCode) {
            return true; // Course code found
        }
    }
    return false; // Course code not found
}

// Removes a course code from the list of registered courses.
void Student::removeCourseCode(const string &courseCode) {
    for (int i = 0; i < courseCodes.size(); ++i) {
        if (courseCodes[i] == courseCode) {
            courseCodes.erase(courseCodes.begin() + i); // Remove the course code
            break; // Exit the loop after removing the course code
        }
    }
}

// Overloaded Operators

// Equality operator to compare two students based on their IDs.
bool Student::operator==(const Student &orig) {
    return this->ID == orig.getID();
}

// Stream extraction operator for reading student data.
istream &operator>>(istream &in, Student &student) {
    string ID;
    string firstName;
    string lastName;
    double GPA;

    // Read the data in the expected order.
    in >> ID >> firstName >> lastName >> GPA;

    // If the read was successful, use the values to create a Student object.
    if (!(in.fail())) {
        student = Student(ID, firstName, lastName, GPA);
    }

    return in;
}

// Stream insertion operator for outputting student data.
ostream &operator<<(ostream &out, const Student &student) {
    out << "ID: " << student.getID() << endl
        << "Name: " << student.getFirstName() << " " << student.getLastName() << endl
        << "Major: Computer Science" << endl
        //supposing that all students are computer scientists
        << "GPA: " << student.getGPA() << endl;
    return out;
}