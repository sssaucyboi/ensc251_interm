/*
* ioUtil.hpp
*/
// MADE BY ERIC TRAN
#pragma once
#include <string>

namespace ioUtil {
	/* et
	* given a string, loops through each character
	* and determines if the value is numerical
	*/
	bool isNumerical(std::string in) {
		int decimals = 0;
		for (char& x : in) {
			// checks for the first occurence of a decimal place
			if (x == '.') {
				if (decimals < 1) {
					decimals = 1;
					continue;
				}
				else return false;
			}
			// if character is not a decimal regular logic
			if (!isdigit(x)) return false;
		}
		return true;
	}
}