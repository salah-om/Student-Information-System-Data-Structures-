/*-- Student.h --------------------------------------------------------------

  This header file defines the data type Student for processing student records.
  Basic operations are:
     Default Constructor
     Parameterized Constructor
     setID: Set the student's ID
     setFirstName: Set the student's first name
     setLastName: Set the student's last name
     setGPA: Set the student's GPA
     getID: Retrieve the student's ID
     getFirstName: Retrieve the student's first name
     getLastName: Retrieve the student's last name
     getGPA: Retrieve the student's GPA
     getAcademicStatus: Retrieve the student's academic status
     addCourseCode: Add a course to the student's record
     getCourseCodes: Retrieve the list of course codes
     isRegisteredInCourse: Check if the student is registered in a specific course
     removeCourseCode: Remove a course from the student's record
     Operator==: Comparison operator for Student objects
     Input Operator (>>): Input stream operator for Student objects
     Output Operator (<<): Output stream operator for Student objects
-------------------------------------------------------------------------*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student {
public:
    /******** Function Members ********/
    /***** Constructors *****/
    Student();

    /*----------------------------------------------------------------------
      Construct a default Student object.

      Precondition: None.
      Postcondition: A default Student object is created with uninitialized data.
    -----------------------------------------------------------------------*/

    Student(const string &ID, const string &firstName, const string &lastName, double GPA);
    /*----------------------------------------------------------------------
      Construct a Student object with given ID, first name, last name, and GPA.

      Precondition: ID, firstName, lastName are strings; GPA is a double.
      Postcondition: A Student object is created with the specified ID, first name,
                     last name, and GPA.
    -----------------------------------------------------------------------*/

    /***** Setters *****/
    bool setID(const string &);

    /*----------------------------------------------------------------------
      Set the student's ID.

      Precondition: ID is a string.
      Postcondition: The student's ID is set to the given value.
    -----------------------------------------------------------------------*/

    bool setFirstName(const string &);

    /*----------------------------------------------------------------------
      Set the student's first name.

      Precondition: firstName is a string.
      Postcondition: The student's first name is set to the given value.
    -----------------------------------------------------------------------*/

    bool setLastName(const string &);

    /*----------------------------------------------------------------------
      Set the student's last name.

      Precondition: lastName is a string.
      Postcondition: The student's last name is set to the given value.
    -----------------------------------------------------------------------*/

    bool setGPA(double);
    /*----------------------------------------------------------------------
      Set the student's GPA.

      Precondition: GPA is a double.
      Postcondition: The student's GPA is set to the given value.
    -----------------------------------------------------------------------*/

    /***** Getters *****/
    string getID() const;

    /*----------------------------------------------------------------------
      Retrieve the student's ID.

      Precondition: None.
      Postcondition: The student's ID is returned.
    -----------------------------------------------------------------------*/

    string getFirstName() const;

    /*----------------------------------------------------------------------
      Retrieve the student's first name.

      Precondition: None.
      Postcondition: The student's first name is returned.
    -----------------------------------------------------------------------*/

    string getLastName() const;

    /*----------------------------------------------------------------------
      Retrieve the student's last name.

      Precondition: None.
      Postcondition: The student's last name is returned.
    -----------------------------------------------------------------------*/

    double getGPA() const;

    /*----------------------------------------------------------------------
      Retrieve the student's GPA.

      Precondition: None.
      Postcondition: The student's GPA is returned.
    -----------------------------------------------------------------------*/

    string getAcademicStatus() const;
    /*----------------------------------------------------------------------
      Retrieve the student's academic status.

      Precondition: None.
      Postcondition: The student's academic status based on GPA is returned.
    -----------------------------------------------------------------------*/

    /***** Course Code Operations *****/
    void addCourseCode(const string &code);

    /*----------------------------------------------------------------------
      Add a course code to the student's record.

      Precondition: code is a string representing a course code.
      Postcondition: The course code is added to the student's list of courses.
    -----------------------------------------------------------------------*/

    const vector<string> &getCourseCodes() const;

    /*----------------------------------------------------------------------
      Retrieve the list of course codes.

      Precondition: None.
      Postcondition: Returns a const reference to the vector containing the student's course codes.
    -----------------------------------------------------------------------*/

    bool isRegisteredInCourse(const string &courseCode) const;

    /*----------------------------------------------------------------------
      Check if the student is registered in a specific course.

      Precondition: courseCode is a string representing a course code.
      Postcondition: Returns true if the student is registered in the course, false otherwise.
    -----------------------------------------------------------------------*/
    void removeCourseCode(const string &courseCode);
    /*----------------------------------------------------------------------
      Remove a course code from the student's record.

      Precondition: courseCode is a string representing a course code.
      Postcondition: The course code is removed from the student's list of courses,
                     if it exists.
    -----------------------------------------------------------------------*/

    /***** Overloaded Operators *****/
    bool operator==(const Student &otherStudent);
    /*----------------------------------------------------------------------
      Compare this student object with another for equality.

      Precondition: otherStudent is a Student object.
      Postcondition: Returns true if this student and otherStudent have the same ID,
                     false otherwise.
    -----------------------------------------------------------------------*/

private:
    /******** Data Members ********/
    string ID;                 // Student's identification number
    string lastName;           // Student's last name
    string firstName;          // Student's first name
    double GPA;                // Student's Grade Point Average
    string academicStatus;     // Student's academic standing based on GPA
    vector<string> courseCodes; // List of course codes the student is registered in

    /******** Private Member Functions ********/
    void updateAcademicStatus();
    /*----------------------------------------------------------------------
      Update the student's academic status based on GPA.

      Precondition: None.
      Postcondition: The academicStatus member is updated based on the current GPA.
    -----------------------------------------------------------------------*/
};

/***** Non-member Functions *****/
istream &operator>>(istream &in, Student &student);

/*----------------------------------------------------------------------
  Input stream operator for Student objects.

  Precondition: in is an input stream, student is a Student object.
  Postcondition: The student object is populated with data from the input stream.
-----------------------------------------------------------------------*/

ostream &operator<<(ostream &out, const Student &student);
/*----------------------------------------------------------------------
  Output stream operator for Student objects.

  Precondition: out is an output stream, student is a Student object.
  Postcondition: The student's data is outputted to the stream in a formatted manner.
-----------------------------------------------------------------------*/

#endif // STUDENT_H
