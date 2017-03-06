// Homework02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //Figured it out, probably

#include <iostream> //
#include <string>	//are these even necessary, then

using namespace std;

// Declare functions prior to use
string get_class_type(float contribution);
bool validate_phone_number(char phone_number[]);

int main()
{
	//	OBJ 1- Get NUMBER_OF_CONTRIBUTORS
	int number_of_contributors;
	cout << "Enter total number of contributors: ";
	cin >> number_of_contributors;

	/*	OBJ 2- Create array MEMBER_ARRAY of structures Member and length NUMBER_OF_CONTRIBUTORS
		OBJ 3- Structure Member details 
	*/

	struct Member {
		string name;
		float contribution;
		char phone_number[10];
		string class_name;
	};

	Member* member_array = new Member[number_of_contributors];
	
	/*	OBJ 4- foreach CONTRIBUTOR in CONTRIBUTOR_LIST,
		cin >> name, amount, phone
		class is derived from amount :
		if > 10000 = platinum
		else if 5001 to 10000 = diamond
		else if 1001 to 5000 = gold
		else 500 to 1000 = silver
	*/

	for (int i = 0; i<number_of_contributors; i++) {
		
		Member m;

		cout << "Enter first name only (no spaces): ";
		cin >> m.name;

		/* OBJ 5- check for valid Amount input.
		Condition : Amount >= 500 AND Amount <= 20000.
		If true, move on
		If false, cout error, loop until User inputs valid one
		*/
		do {
			cout << "Enter contribution in dollars: $";
			cin >> m.contribution;

			m.class_name = get_class_type(m.contribution);

		} while (m.class_name == "-1");

		/* OBJ 6- check for valid Telephone input.
		Condition : Telephone must be of length 10, only contain digits
		If true, move on
		If false, cout error, loop until User inputs valid one
		*/
		bool is_valid_phone;

		do
		{
			cout << "Enter phone number: ";
			cin >> m.phone_number;

			is_valid_phone = validate_phone_number(m.phone_number);
		} while (!is_valid_phone);

		member_array[i] = m;
	}


	// OBJ 7- By decreasing class, output details of each CONTRIBUTOR in CONTRIBUTOR LIST
	// OBJ 8- Stream output to text file Charity.txt

	// output this to 'Charity.txt' as well as console
	// if you can, print by 'member class' Platinum, Diamond, Gold, Silver
	/*cout << sizeof(member_array) << endl;
	for (int i = 0; i<sizeof(member_array); i++) {
		cout << "Name:\t" << member_array[i].name;
		cout << "Phone Number:\t" << member_array[i].phone_number;
		cout << "Contribution:\t" << member_array[i].contribution;
		cout << "Class Type:\t" << member_array[i].class_type;
	}
	*/

	return 0;
}

string get_class_type(float contribution) {

	if (contribution >= 500 && contribution <= 1000)
	{
		return "Silver";
	}
	else if (contribution > 1000 && contribution <= 5000)
	{
		return "Gold";
	}
	else if (contribution > 5000 && contribution <= 10000)
	{
		return "Diamond";
	}
	else if (contribution > 10000 && contribution <= 20000)
	{
		return "Platinum";
	}
	else if (contribution > 20000)
	{
		cout << "Error, value must be below $20000" << endl;
	}
	else if (contribution < 500)
	{
		cout << "Error, value must be above $500" << endl;
	}

	return "-1";
}

bool validate_phone_number(char phone_number[]) {

	if (strlen(phone_number) == 10)
	{
		return true;
	}
	else
	{
		return false;
	}

}
