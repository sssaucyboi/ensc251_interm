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
// idk how to return less than, equal to, or greater than so im going to do less than = 0, equal to = 1, greater than = 2
int compareCGPA(const Student& stu1, const Student& stu2){
    if (stu1.CGPA < stu2.CGPA){
        return(0);
    }
    else if (stu1.CGPA == stu2.CGPA){
        return(1);
    }
    else if (stu1.CGPA > stu2.CGPA){
        return(2);
    }
    else{
        cout << "ERROR IN FUNCTION compareCGPA";
        exit(1);
    }
};

int compareResearchScore(const Student& stu1, const Student& stu2){
    if (stu1.researchScore < stu2.researchScore){
        return(0);
    }
    else if (stu1.researchScore == stu2.researchScore){
        return(1);
    }
    else if (stu1.researchScore > stu2.researchScore){
        return(2);
    }
    else{
        cout << "ERROR IN FUNCTION compareResearchScore";
        exit(1);
    }
};

//// WARNING: THIS FUNCTION ASSUMES THAT THE FIRST LETTER OF FIRST AND LAST NAMES ARE CAPITAL AS IN THE FILES GIVEN 
// also its kinda cool that operators will automatically sort strings based on first index and amount of indexes (RW)
int compareFirstName(const Student& stu1, const Student& stu2){
    if (stu1.firstName < stu2.firstName){
        return(0);
    }
    else if (stu1.firstName == stu2.firstName){
        return(1);
    }
    else if (stu1.firstName > stu2.firstName){
        return(2);
    }
    else{
        cout << "ERROR IN FUNCTION compareFirstName";
        exit(1);
    }
};

// same warning as in function compareFirstName
int compareLastName(const Student& stu1, const Student& stu2){
    if (stu1.lastName < stu2.lastName){
        return(0);
    }
    else if (stu1.lastName == stu2.lastName){
        return(1);
    }
    else if (stu1.lastName > stu2.lastName){
        return(2);
    }
    else{
        cout << "ERROR IN FUNCTION compareLastName";
        exit(1);
    }
};

