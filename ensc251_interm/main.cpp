//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"
#include "stu_sort.hpp"
#include "ioUtil.hpp" // made exclusively by Eric Tran

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */

// functions
int main();
int domesticStudent();
void exitProgram(int option1Menu, int option2Menu);

// main function, prints the menu (RW)
int main(){

  // menu variables
  string stroptionMenu;
	int option1Menu;
  int option2Menu;

  //// main menu start
  cout << "SFU Graduate Student Admission Program\n";
  menu_start1:
  std::cout << "\nSelect Domestic or International Student by typing in the corresponding number\n\n";
	std::cout << "1) Domestic Student\n";
	std::cout << "2) International Student\n";
	std::cout << "\nTo exit the program, enter 0\n";
  std::cin >> stroptionMenu;

  /// error checking
	if (ioUtil::isNumerical(stroptionMenu) == false){
		std::cout << "The entered option is not a number, which is not readable, try again";
		goto menu_start1;
	}
	// changes type string to int
	option1Menu = stoi(stroptionMenu);
	// checks for non option user input
	if ((option1Menu < 0) || (option1Menu > 2)){
		std::cout << "The entered option is not an option, try again";
		goto menu_start1;
	}
  
  // exits 
  exitProgram(option1Menu, option2Menu);

  // user selects sorting 
  menu_start2:
  std::cout << "\n\nSelect sort preference by typing in the corresponding number\n\n";
	std::cout << "1) CGPA\n";
	std::cout << "2) Research Score\n";
  std::cout << "3) Name\n";
	std::cout << "4) Overall Sorting (Sorts by Research Score first and then CGPA)\n";
	std::cout << "\nTo exit the program, enter 0\n";
  std::cin >> stroptionMenu;

  /// error checking
	if (ioUtil::isNumerical(stroptionMenu) == false){
		std::cout << "The entered option is not a number, which is not readable, try again";
		goto menu_start2;
	}
	// changes type string to int
	option2Menu = stoi(stroptionMenu);
	// checks for non option user input
	if ((option2Menu < 0) || (option2Menu > 4)){
		std::cout << "The entered option is not an option, try again";
		goto menu_start2;
	}

  // exits 
  exitProgram(option1Menu, option2Menu);

  //// functions to print and to sort added below
  
};

void exitProgram(int option1Menu, int option2Menu){
  if (option1Menu == 0 || option2Menu == 0){
    exit(0);
  }
};

int domesticStudent(){
  //Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */
  int stu_count = 1;
  while( getline(domesticFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases. We will leave the
     *error and exception handling of file format to Lab Assignment 4
     */
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    //print the student info to the screen
    cout << "Domestic student " << stu_count << " " << firstName << " " 
	 << lastName << " from " << province << " province has cgpa of "
	 << cgpa << ", and research score of " << researchScore << endl;

    stu_count++;
  }

  //close your file
  domesticFile.close();

  return 0;
}
