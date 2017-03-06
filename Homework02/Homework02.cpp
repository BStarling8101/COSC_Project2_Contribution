// Homework02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" //Figured it out, probably

#include <iostream> //
#include <string>	//are these even necessary, then


using namespace std;


/*
\	Method for getting the contribution class type for certain contribution amount
\		contribution must be between 500 and 20,000 else it asks the user to input
\		the number again.
\
*/
string get_class_type(float contribution, string class_names[]) {

	if (contribution >= 500 && contribution <= 1000)
	{
		return class_names[3];
	}
	else if (contribution > 1000 && contribution <= 5000)
	{
		return class_names[2];
	}
	else if (contribution > 5000 && contribution <= 10000)
	{
		return class_names[1];
	}
	else if (contribution > 10000 && contribution <= 20000)
	{
		return class_names[0];
	}
	else if (contribution > 20000)
	{
		cout << "Error, value must be below $20000" << endl;
	}
	else
	{
		cout << "Error, value must be above $500" << endl;
	}

	return "invalid";
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

int main()
{
	/*
	\	Here is what we will be using for the rest of the program,
	\		these will not change.
	\	'Member' struct and contributor class names
	*/
	string class_names[4] = { "Platinum", "Diamond", "Gold", "Silver" };
	struct Member {
		string name;
		char phone_number[10];
		float contribution;
		string class_type;
	};

	/*
	\	Getting the number of contributors from user
	*/
	int number_of_contributors;
	cout << "Enter total number of contributors: ";
	cin >> number_of_contributors;

	/*
	\	Creating a dynamic array of 'Member' structs.
	\	Declaring temp variables for the use of looping for each contributor
	\
	*/
	Member* member_array = new Member[];

	string store_name;
	char store_phone_number[10];
	float store_contribution;
	string store_class_type;
	bool is_valid;

	for (int i = 0; i<number_of_contributors; i++) {

		cout << "Enter first name only (no spaces): ";
		cin >> store_name;

		do
		{
			cout << "Enter phone number: ";
			cin >> store_phone_number;

			is_valid = validate_phone_number(store_phone_number);
		} while (!is_valid);


		do {
			cout << "Enter contribution in dollars: $";
			cin >> store_contribution;

			store_class_type = get_class_type(store_contribution, class_names);
		} while (store_class_type == "invalid");

		Member m;
		m.name = store_name;
		strcpy(m.phone_number, store_phone_number);
		m.contribution = store_contribution;
		m.class_type = store_class_type;

		//append to 'member_array'
	}

	// output this to 'Charity.txt' as well as console
	// if you can, print by 'member class' Platinum, Diamond, Gold, Silver
	cout << sizeof(member_array) << endl;
	for (int i = 0; i<sizeof(member_array); i++) {
		cout << "Name:\t" << member_array[i].name;
		cout << "Phone Number:\t" << member_array[i].phone_number;
		cout << "Contribution:\t" << member_array[i].contribution;
		cout << "Class Type:\t" << member_array[i].class_type;
	}

	return 0;
}