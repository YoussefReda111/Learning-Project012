#pragma once

#include "cls_string.h"
#include "cls_date.h"

class clsInputValidate
{
public:
	static bool is_number_between(int number, int from, int to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool is_number_between(double number, double from, double to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool is_date_between(cls_date date, cls_date from, cls_date to)
	{
		if ((cls_date::is_date1_after_date2(date, from) || cls_date::is_date1_equal_date2(date, from))
			&&
			(cls_date::is_date1_before_date2(date, to) || cls_date::is_date1_equal_date2(date, to))
			)
		{
			return true;
		}
		if ((cls_date::is_date1_after_date2(date, to) || cls_date::is_date1_equal_date2(date, to))
			&&
			(cls_date::is_date1_before_date2(date, from) || cls_date::is_date1_equal_date2(date, from))
			)
		{
			return true;
		}
		return false;
	}

	static int read_int_number(string error_message = "Invalid Number, Enter again\n")
	{
		int number;
		while (!(cin >> number)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_message;
		}
		return number;
	}

	static int read_int_number_between(int from, int to, string error_message = "Number is not within range, Enter again:\n")
	{
		int number = read_int_number();
		while (!is_number_between(number, from, to))
		{
			cout << error_message;
			number = read_int_number();
		}
		return number;
	}

	static double read_double_number(string error_message = "Invalid Number, Enter again\n")
	{
		double number;
		while (!(cin >> number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << error_message;
		}
		return number;
	}

	static double read_double_number_between(double from, double to, string error_message = "Number is not within range, Enter again:\n")
	{
		double number = read_double_number();
		while (!is_number_between(number, from, to)) 
		{
			cout << error_message;
			number = read_double_number();
		}
		return number;
	}

	static bool is_valid_date(cls_date date)
	{
		return	cls_date::is_valid_date(date);
	}
};