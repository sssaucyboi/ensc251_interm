/*
* Calendar.cpp
*/

#include <iostream>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <string>
#include "Calendar.hpp"
using namespace std;

/* rw
* book an appointment on the date date, using TimeRange time
* provides details:
* date is invalid
* timerange is invalid
* hints if date is on holidays, weekends
* if time is already booked
*/
bool Calendar::book(const Date &date, const TimeRange &time)
{
    if (date.isValid() == false)
    {
        std::cout << "The entered date is not in a readable format or in the SFU Fall 2021 term, try again";
        return false;
    }
    // checks for if date is on a weekend
    if (date.isWeekend() == true)
    {
        std::cout << "The entered date is on a weekend, SFU is not open for appointments on the weekends, try again";
        return false;
    }
    // checks for if date is on a holiday
    if (date.isHoliday() == true)
    {
        std::cout << "The entered date is on a holiday, SFU is not open for appointments on holidays, try again";
        return false;
    }

    std::cout << "Your entered date (MM/DD/YYYY) is: " << date.getMonth() << "/" << date.getDate() << "/" 
			<< date.getYear() << endl;

    // checks for if the timerange is valid
    if (time.isValid() == false)
    {
        std::cout << "The entered time range is not in multiples of 30 minutes, 24 hour format, or in the same day, try again";
        return false;
    }

    // booking
    appointment appointmentObject;
    // rand id, if rng decides to fail the program, user should buy local lottery 
    appointmentObject.setId(rand());
    // passes integer appointmentObject into string 
    int timeStart = time.getStart();
    int timeEnd = time.getEnd();
    // convert to integer positions in 48 formatt
    int starttimeIndex = timeStart / 100 * 2 + (timeStart - (timeStart / 100) * 100) / 30;
    int endtimeIndex = timeEnd / 100 * 2 + (timeEnd - (timeEnd / 100)*100) / 30;

    appointmentObject.setStartTime(starttimeIndex);
    appointmentObject.setEndTime(endtimeIndex);

    Date *testDate = getDate(date);
    if (testDate == nullptr)
    {
        testDate = new Date(date.getYear(), date.getMonth(), date.getDate());
        addDate(*testDate);
        // get newly added date object or error
        testDate = getDate(date);
        if (testDate == nullptr) {
            std::cout << "ERROR (Calendar::book) : cannot get newly added date" << endl;
            return false;
        }
    };
    // do booking stuff to testDate

    for(int i = starttimeIndex; i < endtimeIndex; i++) 
    {
        if (testDate->getAppointed(i) == true)
        {
            cout << "Time has already been booked, try another time." << endl;
            return false;
        }
    }
    for(int i = starttimeIndex; i < endtimeIndex; i++) 
    {
         testDate->setAppointed(i, true);
    }
    testDate->addAppointment(appointmentObject);

    // closing statements
    std::cout << "Your appointment is booked from [" << time.getStart() << "] to [" << time.getEnd() << "]" << std::endl;
    std::cout << "on " << date.getMonth() << "/" << date.getDate() << "/" << date.getYear() << std::endl;

    return true;
}


/* et
* searches calendar date and gives information if the timeslot
* is completely booked, or partially booked
*/
bool Calendar::query(const Date& date, const TimeRange& time) {
    // try to find the date in the calendar, check if is valid
    Date* calendarDate = getDate(date);
    if (calendarDate == nullptr) {
        std::cout << "There are no appointments on this day." << std::endl;
        return false;
    };
    // if date is valid we can then check appointments
    int timeStart = time.getStart();
    int timeEnd = time.getEnd();
    // convert to integer positions in 48 formatt
    int startPos = timeStart / 100 * 2 + (timeStart - (timeStart / 100) * 100) / 30;
    int endPos = timeEnd / 100 * 2 + (timeEnd - (timeEnd / 100) * 100) / 30;
    // check if time slots between slots and end times have been booked, count number of time slots booked
    int bookedSlots = 0;
    int totalSlots = endPos - startPos + 1;
    // track which times are booked in the time range given
    bool bookedTimes[48] = { 0 };
    for (int i = 0; i < 48; i++) {
        if (i >= startPos && i <= endPos) {
            if (calendarDate->getAppointed(i) == true) {
                bookedSlots = bookedSlots + 1;
                bookedTimes[i] = true;
            }
        }
    }
    // logic for not booked, partially booked, and fully booked
    if (bookedSlots == 0) {
        // fully free
        std::cout << "There are no appointments on this day within this time range." << std::endl;
        return true;
    }
    else if (bookedSlots < totalSlots) {
        // partially free
        std::cout << "There are some appointments on this day within this time range: ";
        for (int i = 0; i < 48; i++) {
            if (bookedTimes[i] == true) {
                std::cout << " " << static_cast<int>(i / 2) << ":" << setw(2) << setfill('0') << i % 2 * 30 << "-" << static_cast<int>((i+1) / 2) << ":" << setw(2) << setfill('0') << (i+1) % 2 * 30;
            }
        };
        std::cout << endl;
        return true;
    }
    else {
        // fully booked
        std::cout << "There are no appointments on this day within this time range." << std::endl;
        return false;
    }
    return false;
};

/* et
* searches appointments for the date and checks if time range matches one of the appointments
* if so, removes that appointment otherwise returns an error
*/
bool Calendar::cancel(const Date& date, const TimeRange& time) {
    // try to find the date in the calendar, check if is valid
    Date* calendarDate = getDate(date);
    if (calendarDate == nullptr) {
        std::cout << "There are no appointments on this day." << std::endl;
        return true;
    };
    // check and cancel appointment
    int timeStart = time.getStart();
    int timeEnd = time.getEnd();
    // convert to integer positions in 48 formatt
    int startPos = timeStart / 100 * 2 + (timeStart - (timeStart / 100) * 100) / 30;
    int endPos = timeEnd / 100 * 2 + (timeEnd - (timeEnd / 100) * 100) / 30;
    // find appointments that match this time range
    for (int i = 0; i < 47; i++) {
        appointment* apt = calendarDate->getAppointment(i);
        // getAppointment returns nullptr if no appointmentObject is found
        if (apt == nullptr) continue;
        if (apt->getStartTime() == startPos && apt->getEndTime() == endPos) {
            // found appointment, cancel appointment
            for (int z = startPos; z < endPos; z++) {
                calendarDate->setAppointed(z, false);
            };
            std::cout << "Appointment found and canceled!" << std::endl;
            calendarDate->delAppointment(i);
            return true;
       }
    }
    // no appointment found during this time range / abort cancel
    std::cout << "No appointment was found during this time range!" << std::endl;
    return false;
};

/* et
* seaches the calendarDays vector and check if there is a date appointmentObject with the same date,
* it then returns a pointer to that date, else it returns a nullptr
*/
Date* Calendar::getDate(const Date& date) {
    auto it = std::find(calendarDays.begin(), calendarDays.end(), date);
    if (it != std::end(calendarDays)) {
        int index = std::distance(calendarDays.begin(), it);
        Date *ptr = &calendarDays.at(index);
        return ptr;
    }
    return nullptr;
};

/* et
* adds a new date into the calendarDays vector if it doesn't already exist
*/
bool Calendar::addDate(const Date& date) {
    // check if the date already exists
    Date* findDate = getDate(date);
    if (findDate == nullptr) {
        Date newDate(date.getYear(), date.getMonth(), date.getDate());
        calendarDays.push_back(newDate);
        return true;
    };
    return false;
};

/* et
* removes a date from the calendarDays vector if it exists
*/
bool Calendar::removeDate(const Date& date) {
    // check if the date exists
    auto it = std::find(calendarDays.begin(), calendarDays.end(), date);
    if (it != std::end(calendarDays)) {
        int index = std::distance(calendarDays.begin(), it);
        // save the date appointmentObject to a pointer, since erase doesn't actually delete the date appointmentObject
        Date* ptr = &calendarDays[index];
        // remove the date from the vector
        calendarDays.erase(calendarDays.begin() + index);
        // free the memory location
        delete ptr;
        return true;
    };
    return false;
};

/*
* prints all days that are not fully booked yet
* **check for all days that are fully booked, subtract from total days**
*/
std::string Calendar::printFreeDays(std::ostream& os) {
   // create loop that goes through all dates in date range 
   // set date object to each dates in loop 
   // outside loop create date object
   // inside loop set object to new date 
   // test date using get date, tests if date exists in calendar, if not its a free day (print)
   // if date is taken, if statement if bool getAppointed(int index) all equal true, not a free day 
   // else free day 
   Date dateObject;
   std::string output;
   std::ostringstream ss;
   ss << "START OF DAYS WITH A FREE APPOINTMENT SLOT:\n\n";
   for (int month = 1; month < 13; month++) {
       for (int day = 1; day < 32; day++) {
           if (dateObject.isValid() == true) {
               if (getDate(dateObject) == nullptr) {
                   ss << "[" << month << "/" << day << "/2021]\n";
               }
               else
               {
                   for (int i = 0; i < 49; i++) {
                       if (dateObject.getAppointed(i) == false) {
                           ss << "[" << month << "/" << day << "/2021]\n";
                           break;
                       };
                   };
               };
           };
       };
   };
   ss << "\nEND OF DAYS WITH A FREE APPOINTMENT SLOT\n\n";
   output = ss.str();
   os << output;
   return output;
}

std::string Calendar::printFreeTimeSlots(std::ostream& os, const Date &date)
{
    //passes date object
    //use getdate function to get date from calendar
    //from getdate get date object and call print free time slots
    date.getDate();
    date.printFreeTimeSlots(std::cout);
}

/*et
* finds the calendar day with the given input and
* uses the printAppointments method of Date class to print all appointments
*/
std::string Calendar::printAppointments(std::ostream& os, const Date& date) {
    Date* calendarDate = getDate(date);
    if (calendarDate == nullptr) {
        std::cout << "There are no appointments on this day." << std::endl;
        return  "There are no appointments on this day.";
    };
    std::string output = calendarDate->printAppointments(os);
    return output;
}
std::vector<Date> calendarDays;
std::string Calendar::printallAppointments(std::ostream& os)
{
    for (int i = 0; i < calendarDays.size(); i++)
    {
        
    }
}