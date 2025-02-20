/*--Course.h-----------------------------------------------------------------------------------

  This header file defines the data type Course for proccessing the Course class.
  Basic operations are:
     Constructors
     enrollStudent:   Enrolls a Student into the Course
     dropStudent:     Drops a Student from the Course
     isFull:          Check if the course is full
     overloaded !=:   Inequality operator for Course objects
     addStudentID:    Add a student's ID to the course
     getStudentIDs:   Get the list of student IDs enrolled in the course
     removeStudentID: Remove a student's ID from the course
     setters:		  setCourse, setCode, setTitle, setCredits, setEnrolled, setCapacity:
     accessors:       getCode, getTitle, getCredits, getEnrolled, getCapacity
     displays:		  displayCourseStd, displayCrsCode, displayCrsCodeandTitle, displayCrsInfo
     <<:              Output operator
     >>:              Input operator
----------------------------------------------------------------------------------------------*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Course {
public:
    /********Function Members********/
    /*****Class Constructors*****/
    Course();
    /*----------------------------------------------------------------------
      Purpose: Construct a default Course object.
      Precondition: None.
      Postcondition: A default Course object is created with uninitialized data.
    -----------------------------------------------------------------------*/

    Course(const string &code, const string &title, int credits, int capacity);
    /*----------------------------------------------------------------------
      Purpose: Construct a Course object with given code, title, credits, and capacity.
      Precondition: code and title are strings; credits and capacity are integers.
      Postcondition: A Course object is created with the specified code, title,
                     credits, and capacity.
    -----------------------------------------------------------------------*/

    /***** Getters *****/
    string getCode() const;
    /*----------------------------------------------------------------------
      Purpose: Retrieve the course's code.
      Precondition: None.
      Postcondition: The course's code is returned.
    -----------------------------------------------------------------------*/

    string getTitle() const;
    /*----------------------------------------------------------------------
      Purpose: Retrieve the course's title.
      Precondition: None.
      Postcondition: The course's title is returned.
    -----------------------------------------------------------------------*/

    int getCredits() const;
    /*----------------------------------------------------------------------
      Purpose: Retrieve the number of credits for the course.
      Precondition: None.
      Postcondition: The number of credits for the course is returned.
    -----------------------------------------------------------------------*/

    int getEnrolled() const;
    /*----------------------------------------------------------------------
      Purpose: Retrieve the number of enrolled students.
      Precondition: None.
      Postcondition: The number of enrolled students is returned.
    -----------------------------------------------------------------------*/

    int getCapacity() const;
    /*----------------------------------------------------------------------
      Purpose: Retrieve the course's capacity.
      Precondition: None.
      Postcondition: The course's capacity is returned.
    -----------------------------------------------------------------------*/

    /***** Setters *****/
    void setCode(const string &newCode);
    /*----------------------------------------------------------------------
      Purpose: Set a new course code.
      Precondition: newCode is a string.
      Postcondition: The course's code is updated to newCode.
    -----------------------------------------------------------------------*/

    void setTitle(const string &newTitle);
    /*----------------------------------------------------------------------
      Purpose: Set a new course title.
      Precondition: newTitle is a string.
      Postcondition: The course's title is updated to newTitle.
    -----------------------------------------------------------------------*/

    void setCredits(int newCredits);
    /*----------------------------------------------------------------------
      Purpose: Set the number of credits for the course.
      Precondition: newCredits is an integer.
      Postcondition: The course's credits are updated to newCredits.
    -----------------------------------------------------------------------*/

    void setCapacity(int newCapacity);
    /*----------------------------------------------------------------------
      Purpose: Set the course's capacity.
      Precondition: newCapacity is an integer.
      Postcondition: The course's capacity is updated to newCapacity.
    -----------------------------------------------------------------------*/

    void setEnrolled(int newEnrolled);
    /*----------------------------------------------------------------------
      Purpose: Set the number of enrolled students.
      Precondition: newEnrolled is an integer.
      Postcondition: The number of enrolled students is updated to newEnrolled.
    -----------------------------------------------------------------------*/

    /***** Other Member Functions *****/
    void display(ostream &os) const;
    /*----------------------------------------------------------------------
      Purpose: Display course details.
      Precondition: os is an output stream.
      Postcondition: The course details are outputted to the stream.
    -----------------------------------------------------------------------*/

    bool isFull() const;
    /*----------------------------------------------------------------------
      Purpose: Check if the course is full.
      Precondition: None.
      Postcondition: Returns true if the course is full, false otherwise.
    -----------------------------------------------------------------------*/

    bool operator!=(const Course &other) const;
    /*----------------------------------------------------------------------
       Purpose: Inequality comparison for Course objects.
       Precondition: other is a Course object.
      Postcondition: Returns true if this course and other course are not equal.
    -----------------------------------------------------------------------*/

    void addStudentID(const string &id);
    /*----------------------------------------------------------------------
      Purpose: Add a student's ID to the course.
      Precondition: id is a string representing a student's ID.
      Postcondition: The student's ID is added to the course's list of student IDs.
    -----------------------------------------------------------------------*/

    const vector<string> &getStudentIDs() const;
    /*----------------------------------------------------------------------
      Purpose: Get the list of student IDs enrolled in the course.
      Precondition: None.
      Postcondition: Returns a const reference to the vector containing the student IDs.
    -----------------------------------------------------------------------*/

    void removeStudentID(const string &id);
    /*----------------------------------------------------------------------
      Purpose: Remove a student's ID from the course.
      Precondition: id is a string representing a student's ID.
      Postcondition: The student's ID is removed from the course's list of student IDs, if it exists.
    -----------------------------------------------------------------------*/

private:
    /******** Data Members ********/
    string code;                // Course code
    string title;               // Course title
    int credits;                // Number of credits
    int enrolled;               // Number of enrolled students
    int capacity;               // Maximum capacity of the course
    vector<string> studentIDs;  // List of student IDs enrolled in the course
};

/***** Non-member Functions *****/
istream &operator>>(istream &, Course &);
/*----------------------------------------------------------------------
  Purpose: Input stream operator for Course objects.
  Precondition: in is an input stream, course is a Course object.
  Postcondition: The course object is populated with data from the input stream.
-----------------------------------------------------------------------*/

ostream &operator<<(ostream &, const Course &);
/*----------------------------------------------------------------------
  Purpose: Output stream operator for Course objects.
  Precondition: out is an output stream, course is a Course object.
  Postcondition: The course's data is outputted to the stream in a formatted manner.
-----------------------------------------------------------------------*/

#endif // COURSE_H
