/*
* main.cpp
*/
#include <stdio.h>
#include <stdlib.h>
#include "Date.hpp"
#include "TimeRange.hpp"
#include "ioUtil.hpp"
#include "Calendar.hpp"
#include <string>
using namespace std;

// testing function
// int main() {
// 	Calendar testCalendar;
// 	Date testDate(2021, 10, 7);
// 	appointment apt1(1, 2);

// 	std::cout << "\n\nappointment\n\n";

// 	testDate.addAppointment(apt1);
// 	testDate.printAppointedTimeSlots(std::cout);
// 	appointment *aptPtr1 = testDate.getAppointment(0);
// 	aptPtr1->printBookedTime(std::cout);
// 	testDate.delAppointment(0);

// 	std::cout << "\n\ncalendar\n\n";
// 	testCalendar.addDate(testDate);
// 	Date* datePtr1 = testCalendar.getDate(testDate);
// 	datePtr1->printFreeTimeSlots(std::cout);
// 	testCalendar.removeDate(testDate);

// 	std::cout << "\n\nbooking\n\n";

// 	std::cout << "\n\nend of test\n\n";
// }

// Calendar object
Calendar calendarObject;

// rw
// main function
int main();

// user input function for date
void userinputD(int &enteredYear, int &enteredMonth, int &enteredDay,
				string userenteredYear, string userenteredMonth, string userenteredDay);

// user input function for timerange
void userinputTR(int &enteredbeginMinute, int &enteredbeginHour, int &enteredendMinute, int &enteredendHour,
				 string userenteredbeginMinute, string userenteredbeginHour, string userenteredendMinute, string userenteredendHour);
				 
int main()
{
	// variables to pass into the classes (book appointment)
	int enteredYear;
	int enteredMonth;
	int enteredDay;
	int enteredbeginMinute;
	int enteredbeginHour;
	int enteredendMinute;
	int enteredendHour;

	// variables to test user input (book appointment)
	string userenteredYear;
	string userenteredMonth;
	string userenteredDay;
	string userenteredbeginMinute;
	string userenteredbeginHour;
	string userenteredendMinute;
	string userenteredendHour;

	//menu variables
	string optionMenu;
	int optionnumberMenu;
	string yesorno;

	//// Opening Program
	// opening statements
	std::cout << "Welcome to the SFU Fall 2021 Calendar\n";

// menu_start start point after menu error
menu_start:
	std::cout << "Choose an option below by typing in the corresponding number\n\n";
	std::cout << "1) Print currently booked appointments\n";
	std::cout << "2) Print out all days with free time slots\n";
	std::cout << "3) Print out all free time slots for a given day\n";
	std::cout << "4) Book an appointment\n";
	std::cout << "5) Query an appointment\n";
	std::cout << "6) Cancel an appointment\n";
	std::cout << "7) Show all appointments on a date\n";
	std::cout << "\nTo exit the program, enter 0\n";
	std::cin >> optionMenu;

	/// error checking
	if (ioUtil::isNumerical(optionMenu) == false)
	{
		std::cout << "The entered option is not a number, which is not readable, try again";
		goto menu_start;
	}
	// changes type string to int
	optionnumberMenu = stoi(optionMenu);
	// checks for non option user input
	if ((optionnumberMenu < 0) || (optionnumberMenu > 7))
	{
		std::cout << "The entered option is not an option, try again";
		goto menu_start;
	}

	// executes option chosen from menu
	switch (optionnumberMenu)
	{
	// 1) Print currently booked appointments
	case 1:
	{
		
	}
	// 2) Print out all days with free time slots
	case 2:
	{
		// print function to print all days with free time slots
		calendarObject.printFreeDays(std::cout);
		goto menu_start;
	}
	// 3) Print out all free time slots for a given day
	case 3:
	{
		// user input function for date
		userinputD(enteredYear, enteredMonth, enteredDay,
				   userenteredYear, userenteredMonth, userenteredDay);

		// user entered date gets passed into the constructor function and setup date object
		Date dateObject(enteredYear, enteredMonth, enteredDay);

		// print function to print all days with free time slots
		calendarObject.printFreeTimeSlots(std::cout, dateObject);
		goto menu_start;
	}

	// 4) Book an appointment
	case 4:
	{
	// user input function
	option4_start:
		// user input function for date
		userinputD(enteredYear, enteredMonth, enteredDay,
				   userenteredYear, userenteredMonth, userenteredDay);

		// user input function for timerange
		userinputTR(enteredbeginMinute, enteredbeginHour, enteredendMinute, enteredendHour,
					userenteredbeginMinute, userenteredbeginHour, userenteredendMinute, userenteredendHour);

		// user entered date gets passed into the constructor function and setup date object
		Date dateObject(enteredYear, enteredMonth, enteredDay);

		// user entered time range gets passed into the constructor function
		TimeRange timerangeObject(enteredbeginMinute, enteredbeginHour, enteredendMinute, enteredendHour);

		// options after the book function completes
		if (calendarObject.book(dateObject, timerangeObject) == false)
		{
		option4_exit1_start:
			cout << "\nWould you like to try another date and time? (y/n)\n";
			cin >> yesorno;
			if (yesorno == "y")
			{
				goto option4_start;
			}
			else if (yesorno == "n")
			{
				goto menu_start;
			}
			else
			{
				cout << "Entered option was unreadable, try again and type y for yes and n for no\n";
				goto option4_exit1_start;
			}
		}
		goto menu_start;
	}
	// 5) Query an appointment
	case 5:
	{
		// user input function for date
		userinputD(enteredYear, enteredMonth, enteredDay,
				   userenteredYear, userenteredMonth, userenteredDay);

		// user input function for timerange
		userinputTR(enteredbeginMinute, enteredbeginHour, enteredendMinute, enteredendHour,
					userenteredbeginMinute, userenteredbeginHour, userenteredendMinute, userenteredendHour);

		// user entered date gets passed into the constructor function and setup date object
		Date dateObject(enteredYear, enteredMonth, enteredDay);

		// user entered time range gets passed into the constructor function
		TimeRange timerangeObject(enteredbeginMinute, enteredbeginHour, enteredendMinute, enteredendHour);

		// query function using calendar object
		calendarObject.query(dateObject, timerangeObject);
		goto menu_start;
	}
	// 6) Cancel an appointment
	case 6:
	{
		// user input function for date
		userinputD(enteredYear, enteredMonth, enteredDay,
				   userenteredYear, userenteredMonth, userenteredDay);

		// user input function for timerange
		userinputTR(enteredbeginMinute, enteredbeginHour, enteredendMinute, enteredendHour,
					userenteredbeginMinute, userenteredbeginHour, userenteredendMinute, userenteredendHour);

		// user entered date gets passed into the constructor function and setup date object
		Date dateObject(enteredYear, enteredMonth, enteredDay);

		// user entered time range gets passed into the constructor function
		TimeRange timerangeObject(enteredbeginMinute, enteredbeginHour, enteredendMinute, enteredendHour);

		calendarObject.cancel(dateObject, timerangeObject);
		goto menu_start;
	}
	// 7) inquire about appointment on date
	case 7:
	{
		// user input function for date
		userinputD(enteredYear, enteredMonth, enteredDay,
				   userenteredYear, userenteredMonth, userenteredDay);

		// user entered date gets passed into the constructor function and setup date object
		Date dateObject(enteredYear, enteredMonth, enteredDay);
		calendarObject.printAppointments(std::cout, dateObject);
		goto menu_start;
	}
	// exits program
	case 0:
	{
		cout << "Exiting the program\n";
		goto menu_exit;
	}
	// delete this later
	default:
	{
		cout << "placeholder, something went wrong";
		break;
	}
	};

menu_exit:
	exit(0);
}

// user input function for date
void userinputD(int &enteredYear, int &enteredMonth, int &enteredDay,
				string userenteredYear, string userenteredMonth, string userenteredDay)
{
//// Opening Date
// date opening statements
userinputD_start:
	std::cout << "Enter the date in integer format:\n"
			  << "Example: 9/7/2021\n";
	// user enters date in integer format
	std::cout << "Enter Month:";
	std::cin >> userenteredMonth;
	std::cout << "\nEnter Day:";
	std::cin >> userenteredDay;
	std::cout << "\nEnter Year:";
	std::cin >> userenteredYear;

	//// User Valid Input Checks [Date]
	// checks for non numerical input
	if (ioUtil::isNumerical(userenteredMonth) == false || ioUtil::isNumerical(userenteredDay) == false || ioUtil::isNumerical(userenteredYear) == false)
	{
		std::cout << "The entered date is not a number, which is not readable, try again";
		goto userinputD_start;
	}
	// changes type string to int
	enteredYear = stoi(userenteredYear);
	enteredMonth = stoi(userenteredMonth);
	enteredDay = stoi(userenteredDay);
	// checks for negative user input
	if ((enteredYear < 0) || (enteredMonth < 0) || (enteredDay < 0))
	{
		std::cout << "The entered date is negative, which is not readable, try again";
		goto userinputD_start;
	};
}
// user input function for timerange
void userinputTR(int &enteredbeginMinute, int &enteredbeginHour, int &enteredendMinute, int &enteredendHour,
				 string userenteredbeginMinute, string userenteredbeginHour, string userenteredendMinute, string userenteredendHour)
{
	//// Opening Time Range
	// time range opening statements
userinputTR_start:
	std::cout << "Enter the time range in multiples of 30 minutes and in 24 hour format:\n";
	std::cout << "Example: 9:30\n";
	// user enters time range in multiples of 30 minutes and in 24 hour format
	std::cout << "Enter Start Hour:";
	std::cin >> userenteredbeginHour;
	std::cout << "\nEnter Start Minute:";
	std::cin >> userenteredbeginMinute;
	std::cout << "\nEnter End Hour:";
	std::cin >> userenteredendHour;
	std::cout << "\nEnter End Minute:";
	std::cin >> userenteredendMinute;

	//// User Valid Input Checks [TimeRange]
	// checks for non numerical input
	if (ioUtil::isNumerical(userenteredbeginHour) == false || ioUtil::isNumerical(userenteredbeginMinute) == false || ioUtil::isNumerical(userenteredendHour) == false || ioUtil::isNumerical(userenteredendMinute) == false)
	{
		std::cout << "The entered time is not a number, which is not readable, try again";
		goto userinputTR_start;
	}
	// changes type string to int
	enteredbeginHour = stoi(userenteredbeginHour);
	enteredbeginMinute = stoi(userenteredbeginMinute);
	enteredendHour = stoi(userenteredendHour);
	enteredendMinute = stoi(userenteredendMinute);
	// checks for negative user input
	if ((enteredbeginHour < 0) || (enteredbeginMinute < 0) || (enteredendHour < 0) || (enteredendMinute < 0))
	{
		std::cout << "The entered time is negative, which is not readable, try again";
		goto userinputTR_start;
	}
}
