/*--------------------------------------
    Tester class for the program
--------------------------------------*/
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    
    char option;
    string studentID;
    string courseCode;
    DoublyLinkedList registeredStudents;
    DoublyLinkedList nonRegisteredStudents;
    LListWithDummyNode offeredCourses;

    // Open and read student data from a file.
    ifstream inFile1(
            R"(C:\Users\Salah\Desktop\students.txt)");

    if (!inFile1) {
        cerr << "Unable to open file students.txt";
        return 1;
    }
    inFile1 >> nonRegisteredStudents; // Read non-registered students from the file.
    inFile1.close(); // Close the file after reading.

    // Open and read course data from a file.
    ifstream inFile2(
            R"(C:\Users\Salah\Desktop\courses.txt)");
    if (!inFile2) {
        cerr << "Unable to open file courses.txt";
        return 1; 
    }
    inFile2 >> offeredCourses; // Read offered courses from the file.
    inFile2.close(); // Close the file after reading.

 
    int choice;
    do {
        cout << "1. Display the list of non-registered students." << endl
             << "2. Display the list of offered courses." << endl
             << "3. Display the list of registered students with the registered courses." << endl
             << "4. Display the list of offered courses with the registered students." << endl
             << "5. Display the registered courses for a student." << endl
             << "6. Display the list of students registered in a course." << endl
             << "7. Display the information related to a specific student." << endl
             << "8. Register a student." << endl
             << "9. Choose a student to add/drop a course for him/her." << endl
             << "10. Quit the application." << endl;
        cout << "Enter your choice: ";

        // Input validation for user's choice.
        while (!(cin >> choice)) { // Check if the previous extraction failed
            cin.clear(); // Clear the error state of cin
            cin.ignore(10000, '\n'); // Discard up to 10000 characters or until a newline is found
            cerr << "Error: Invalid, insert an integer. Please try again: " << endl;
        }
        // Process user's choice.
        switch (choice) {
            case 1:
                cout << endl << "Students that didn't register yet: " << endl;
                cout << nonRegisteredStudents << endl;
                break;
            case 2:
                cout << endl << offeredCourses << endl;
                break;
            case 3: {
                
                cout << endl;
                // Iterate over all registered students.
                for (int i = 0; i < registeredStudents.getSize(); ++i) {
                    

                    // Student obj accessed at ith position in registeredStudents list.
                    // at(i) returns a pointer to the node
                    Student *student = &(registeredStudents.at(i)->data);

                    // Displaying the student's details.
                    cout << "Student: " << student->getID() << " - "
                         << student->getLastName() << ", " << student->getFirstName() << endl;

                    // Retrieve the list of course codes that the student is registered for.
                    const vector<string> codes = student->getCourseCodes();

                    // Check if the student is registered for any courses.
                    if (codes.empty()) {
                        cout << "No registered courses." << endl;
                    } else {
                        
                        for (const string &code: codes) {
                            cout << "- " << code << endl;
                        }
                    }
                    cout << endl; 
                }
                break;
            }
            case 4: {

                cout << endl;
                // Iterating over all offered courses.
                for (int i = 0; i < offeredCourses.size(); ++i) {
                    
                    // at(i) returns a pointer to the node if it exists 
                    Course *course = &(offeredCourses.at(i)->data);

                    // Displaying the course details.
                    cout << "Course: " << course->getCode() << " - " << course->getTitle() << endl;

                    // Retrieve the list of student IDs registered in the course.
                    const vector<string> &studentIDs = course->getStudentIDs();

                    // Check if any students are registered in the course.
                    if (studentIDs.empty()) {
                        cout << "No students registered for this course." << endl;
                    } else {
                        Student *student;
                        // If students are registered, display each student ID.
                        for (const string &id: studentIDs) {
                            student = registeredStudents.find(studentID);
                            cout << id << " " << student->getLastName() << ", " <<
                                 student->getFirstName() << endl;
                        }
                    }
                    cout << endl; 
                }
                break;
            }
            case 5: {
                
                cout << "Enter the student ID: ";
                cin >> studentID;
                cout << endl;
                for (char& c : studentID) {
                    c = toupper(c);
                }
                // Attempt to find the student by their ID in the registered students list.
                Student *student = registeredStudents.find(studentID);

                // Check if the student was found.
                if (student != nullptr) {
                    // Display the student's details.
                    cout << "Student: " << student->getID() << " - " << student->getFirstName() << " "
                         << student->getLastName() << endl;

                    // Retrieve and display the list of course codes the student is registered in.
                    const vector<string> &courseCodes = student->getCourseCodes();
                    if (courseCodes.empty()) {
                        cout << "No Registered Courses." << endl;
                    } else {
                        cout << "Courses: " << endl;
                        for (const string &code: courseCodes) {
                            cout << "- " << code << endl;
                        }
                    }
                } else {
                    cout << "No student found with ID " << studentID << endl;
                }
                cout << endl; // Newline for formatting.
                break;
            }
            case 6: {
                // Prompt for and receive a course code from the user.
                cout << "Enter the course code: ";
                cin >> courseCode;

                for (char& c : courseCode) {
                    c = toupper(c);
                }
                cout << endl;
                // Find the course in the offered courses list using the provided code.
                Course *course = offeredCourses.find(courseCode);

                // Check if the course was found.
                if (course != nullptr) {
                    // Display the course details.
                    cout << "Course: " << course->getCode() << " - " << course->getTitle() << endl;

                    // Retrieve and display the IDs of students registered in the course.
                    const vector<string> &studentIDs = course->getStudentIDs();
                    if (studentIDs.empty()) {
                        cout << "This course is not registered by any student." << endl;
                    } else {
                        // For each student ID, find and display the student's details.
                        for (const string &id: studentIDs) {
                            Student *student = registeredStudents.find(id);
                            cout << id << " " << student->getLastName() << ", " << student->getFirstName()
                                 << endl;
                        }
                    }
                } else {
                    cout << "No course found with code " << courseCode << endl;
                }
                cout << endl;
                break;
            }
            case 7: {
                // Prompt for and receive a student ID from the user.
                cout << "Enter the student ID: ";
                cin >> studentID;

                for (char& c : studentID) {
                    c = toupper(c);
                }
                cout << endl;
                // Attempt to find the student in the registered students list.
                Student *student = registeredStudents.find(studentID);

                // If the student isn't found in the registered list, try the non-registered list.
                if (student == nullptr) {
                    student = nonRegisteredStudents.find(studentID);
                }

                // Check if the student was found in either list.
                if (student == nullptr) {
                    cout << "Student not found." << endl << endl;
                } else {
                    // Display the student's details.
                    cout << "Student: " << endl
                         << *student; // Knowing that the operator<< is overloaded for Student objects
                    cout << endl;
                }

                break;
            }
            case 8: {
                string input;
                cout << "Enter the student ID: ";
                cin >> studentID;

                for (char& c : studentID) {
                    c = toupper(c);
                }
                // Find the student in either the non-registered or registered list
                Student *student = nonRegisteredStudents.find(studentID);
                bool isStudentNew = (student != nullptr);

                if (!isStudentNew) {
                    student = registeredStudents.find(studentID);
                }

                if (student == nullptr) {
                    cout << "Student with ID " << studentID << " not found." << endl;
                } else {
                    bool tryAgain;
                    do {
                        cout << "Enter the course code: ";
                        cin >> courseCode;

                        
                        for (char& c : courseCode) {
                            c = toupper(c);
                        }

                        Course *course = offeredCourses.find(courseCode);

                        if (course == nullptr) {
                            cout << "The course is not offered." << endl;
                        } else if (student->isRegisteredInCourse(courseCode)) {
                            cout << "Student ID " << studentID << " is already registered in the course " << courseCode
                                 << "." << endl;
                        } else if (course->isFull()) {
                            cout << "Cannot register for course " << courseCode << " because it is full." << endl;
                        } else {
                            student->addCourseCode(course->getCode());
                            course->addStudentID(student->getID());

                            cout << "Student registered" << endl;
                        }

                        cout << "Do you need to add more courses [Y] yes or [N] no: ";
                        cin >> ws;
                        cout << endl;
                        getline(cin, input);
                        tryAgain = !input.empty() && toupper(input[0]) == 'Y';
                    } while (tryAgain);
                }
                if (student != nullptr && isStudentNew) {
                    // Move the student from non-registered to registered list
                    registeredStudents.insert(*student);// Add student to the new list
                    nonRegisteredStudents.remove(studentID);// Remove student from the old list
                }
                break;
            }

            case 9: {
                string input;
                cout << "Enter the student ID: ";
                cin >> studentID;

                for (char& c : studentID) {
                    c = toupper(c);
                }
                // Find the student in the registered students list
                Student *student = registeredStudents.find(studentID);
                bool isStudentNew = false;  // Flag to check if student is newly registered

                // Check if the student is in the non-registered list
                if (student == nullptr) {
                    student = nonRegisteredStudents.find(studentID);
                    isStudentNew = (student != nullptr);
                }

                if (student == nullptr) {
                    cout << "Student not found." << endl;
                } else {
                    cout << "Student: " << student->getID() << " - " << student->getFirstName() << " "
                         << student->getLastName() << endl;

                    const vector<string> &courseCodes = student->getCourseCodes();
                    if (courseCodes.empty()) {
                        cout << "Not registered in any courses yet." << endl;
                    } else {
                        cout << "Courses: " << endl;
                        for (const string &code: courseCodes) {
                            cout << "- " << code << endl;
                        }
                    }

                    bool modified = false;
                    do {
                        cout << "Add course [A] or Drop course [D]: ";
                        cin >> input;
                        char action = toupper(input[0]);

                        if (action == 'A') {
                            cout << "Choose course code: ";
                            cin >> courseCode;

                            for (char& c : courseCode) {
                                c = toupper(c);
                            }
                            Course *course = offeredCourses.find(courseCode);

                            if (course == nullptr) {
                                cout << "Course not found." << endl;
                            } else if (course->isFull()) {
                                cout << "Cannot add course " << courseCode << " because it is full." << endl;
                            } else if (student->isRegisteredInCourse(courseCode)) {
                                cout << "Student already registered in course " << courseCode << "." << endl;
                            } else {
                                student->addCourseCode(courseCode);
                                course->addStudentID(student->getID());
                                cout << "Course added successfully" << endl;
                                modified = true;
                            }
                        } else if (action == 'D') {
                            cout << "Choose course code: ";
                            cin >> courseCode;

                            for (char& c : courseCode) {
                                c = toupper(c);
                            }
                            if (!student->isRegisteredInCourse(courseCode)) {
                                cout << "Course not found." << endl;
                            } else {
                                student->removeCourseCode(courseCode);
                                Course *course = offeredCourses.find(courseCode);

                                if (course != nullptr) {
                                    course->removeStudentID(studentID);
                                }
                                cout << "Course dropped successfully" << endl;
                                modified = true;
                            }
                        } else {
                            cout << "Invalid action. Please enter 'A' to add or 'D' to drop a course." << endl;
                        }

                        cout << "Do you need to add/drop more courses for this student [Y/N]: ";
                        cin >> ws;
                        cout << endl;
                        getline(cin, input);
                        option = toupper(input[0]);

                    } while (option == 'Y');

                    // Move the student between lists if modifications were made
                    if (modified) {
                        if (isStudentNew && !student->getCourseCodes().empty()) {
                            registeredStudents.insert(*student); // Move to registered list
                            nonRegisteredStudents.remove(studentID);
                        } else if (!isStudentNew && student->getCourseCodes().empty()) {
                            nonRegisteredStudents.insert(*student); // Move to non-registered list
                            registeredStudents.remove(studentID);
                        }
                    }
                }
                break;
            }


            case 10:
                exit(0); // Exits the program.
            default:
                cout << endl;
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 10);

    return 0;
}