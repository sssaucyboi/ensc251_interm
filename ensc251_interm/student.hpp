//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>

// Student:

// 		string firstname, lastname

// 		float CGPA 4.3

// 		float researchScore + int type

// 		int id(8 digit id format 2021xxxx)
	
// 			<<<children objects:

// 				DomesticStudent:

// 					string province (bc specific scholarships)
			
// 				InternationalStudent:

// 					string country

// 					int TOEFL

// 	ToeflScore:

// 		int reading, listening, speaking, writing

// 		int total

// Student:

// 	friend function overloads

// 	compareCGPA ==

// 	compareResearchScore ==

// 	compareFirstName ==
	
// 	compareLastName ==
	
// 			<<<children objects:

// 				DomesticStudent:

// 					<< overload (object information : full name)
			
// 				InternationalStudent:

// 					<< overload (object information : full name)

// Student Class (RW)
class Student
{
    public:

        // default constructor
        Student() {};

        // student constructor
        Student(string firstName, string lastName, float CGPA, int researchScore, int studentID);

        //// get and set functions (RW)
        // firstName
        void setfirstName(string input);
        string getfirstName() const;

        // lastName
        void setlastName(string input);
        string getlastName() const;

        // CGPA
        void setCGPA(int input);
        int getCGPA() const;

        // researchScore
        void setresearchScore(int input);
        int getresearchScore() const;

        // studentID
        void setstudentID(int input);
        int getstudentID() const;
        //// end of get and set functions

        // compare functions (RW)
        friend string compareCGPA(const Student& stu1, const Student& stu2);
        friend string compareResearchScore(const Student& stu1, const Student& stu2);
        friend string compareFirstName(const Student& stu1, const Student& stu2);
        friend string compareLastName(const Student& stu1, const Student& stu2);
        
    private:

        // student variables 
        string firstName;
        string lastName;
        float CGPA;
        int researchScore;
        int studentID;
};

// Child DomesticStudent Class (RW)
class DomesticStudent : public Student
{
    public:
        // operator overloading
        friend std::ostream& operator<<(std::ostream& os, const Student& studObject);

        // get and set functions
        void setProvince(string input);
        string getProvince() const;

    private:

        // province variable uses two letter abbreviations ex. BC
        string province;
};

// Child InternationalStudent Class (RW)
class InternationalStudent : public Student
{
    public:
        // operator overloading
        friend std::ostream& operator<<(std::ostream& os, const DomesticStudent& interObject);
    private:

        // International Student variables
        string country;
        int TOEFL;
};

// ToeflScore Class (RW)
class ToeflScore
{
    public:

    private:

        // TOEFL score variables 
        int reading;
        int listening;
        int speaking;
        int writing;
        int total;
};