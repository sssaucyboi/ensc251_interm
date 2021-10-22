//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <string>

// passes the on file student info into the student class (RW)
Student::Student(string onfilefirstName, string onfilelastName, float onfileCGPA, int onfileresearchScore, int onfilestudentID){
    firstName = onfilefirstName;
    lastName = onfilelastName;
    CGPA = onfileCGPA;
    researchScore = onfileresearchScore;
    studentID = onfilestudentID;
};

//// COMPARE FUNCTIONS (RW)
string compareCGPA(const Student& stu1, const Student& stu2){
    if (stu1.CGPA < stu2.CGPA){
        return("<");
    }
    else if (stu1.CGPA == stu2.CGPA){
        return("==");
    }
    else if (stu1.CGPA > stu2.CGPA){
        return(">");
    }
    else{
        cout << "ERROR IN FUNCTION compareCGPA";
        exit(1);
    }
};

string compareResearchScore(const Student& stu1, const Student& stu2){
    if (stu1.researchScore < stu2.researchScore){
        return("<");
    }
    else if (stu1.researchScore == stu2.researchScore){
        return("==");
    }
    else if (stu1.researchScore > stu2.researchScore){
        return(">");
    }
    else{
        cout << "ERROR IN FUNCTION compareResearchScore";
        exit(1);
    }
};

//// WARNING: THIS FUNCTION ASSUMES THAT THE FIRST LETTER OF FIRST AND LAST NAMES ARE CAPITAL AS IN THE FILES GIVEN 
// also its kinda cool that operators will automatically sort strings based on first index and amount of indexes (RW)
string compareFirstName(const Student& stu1, const Student& stu2){
    if (stu1.firstName < stu2.firstName){
        return("<");
    }
    else if (stu1.firstName == stu2.firstName){
        return("==");
    }
    else if (stu1.firstName > stu2.firstName){
        return(">");
    }
    else{
        cout << "ERROR IN FUNCTION compareFirstName";
        exit(1);
    }
};

// same warning as in function compareFirstName
string compareLastName(const Student& stu1, const Student& stu2){
    if (stu1.lastName < stu2.lastName){
        return("<");
    }
    else if (stu1.lastName == stu2.lastName){
        return("==");
    }
    else if (stu1.lastName > stu2.lastName){
        return(">");
    }
    else{
        cout << "ERROR IN FUNCTION compareLastName";
        exit(1);
    }
};

// operator overloading for domestic student object (RW)
std::ostream& operator<<(std::ostream& os, const DomesticStudent& domObject){

    // text stuff
    os << "Domestic student " << domObject.getstudentID() << " " << domObject.getfirstName() << " " 
	 << domObject.getlastName() << " from " << domObject.getProvince() << " province has cgpa of "
	 << domObject.getCGPA() << ", and research score of " << domObject.getresearchScore() << endl;

    return os;
}

//// get and set functions (RW)
// firstName
void Student::setfirstName(string input){
    firstName = input;
};
string Student::getfirstName() const{
    return firstName;
};

// lastName
void Student::setlastName(string input){
    lastName = input;
};
string Student::getlastName() const{
    return lastName;
};

// CGPA
void Student::setCGPA(int input){
    CGPA = input;
};
int Student::getCGPA() const{
    return CGPA;
};

// researchScore
void Student::setresearchScore(int input){
    researchScore = input;
};
int Student::getresearchScore() const{
    return researchScore;
};

// studentID
void Student::setstudentID(int input){
    studentID = input;
};
int Student::getstudentID() const{
    return studentID;
};
//// end of get and set functions

// get and set functions for Domestic Student
void DomesticStudent::setProvince(string input){
    province = input;
};
string DomesticStudent::getProvince() const{
    return province;
};
