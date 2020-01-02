#include "student.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::left;
using std::setw;

	student::student()
	{
		this->studentId = "";
		this->firstName = "";
		this->lastName = "";
		this->emailAddress = "";
		this->age = 0;
		for (int i = 0; i < arraySize; i++) this->numberOfDaysToComplete[i] = 0;
	}

	student::student(string id, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToComplete[])
	{
		this->studentId = id;
		this->firstName = firstName;
		this->lastName = lastName;
		this->emailAddress = emailAddress;
		this->age = age;
		for (int i = 0; i < arraySize; i++) this->numberOfDaysToComplete[i] = numberOfDaysToComplete[i];
	}

	string student::GetStudentId()
	{
		return studentId;
	}

	void student::SetStudentId(string id)
	{
		studentId = id;
	}


	string student::GetFirstName()
	{
		return firstName;
	}

	void student::SetFirstName(string firstName)
	{
		this->firstName = firstName;
	}

	string student::GetLastName()
	{
		return lastName;
	}

	void student::SetLastName(string lastName)
	{
		this->lastName = lastName;
	}

	string student::GetEmailAddress()
	{
		return emailAddress;
	}

	void student::SetEmailAddress(string emailAddress)
	{
		this->emailAddress = emailAddress;
	}

	int student::GetAge()
	{
		return age;
	}

	void student::SetAge(int age)
	{
		this->age = age;
	}

	int* student::GetNumberOfDaysToComplete()
	{
		return numberOfDaysToComplete;
	}

	void student::SetNumberOfDaysToComplete(int numberOfDays[])
	{
		for (int i = 0; i < arraySize; i++) numberOfDaysToComplete[i] = numberOfDays[i];
	}

	void student::print()
	{
		int* numDays = student::GetNumberOfDaysToComplete();

		cout << left << setw(5) << student::GetStudentId();
		cout << left << setw(10) << student::GetFirstName();
		cout << left << setw(10) << student::GetLastName();
		cout << left << setw(30) << student::GetEmailAddress();
		cout << left << setw(5) << student::GetAge();
		cout << left << setw(5) << numDays[0];
		cout << left << setw(5) << numDays[1];
		cout << left << setw(5) << numDays[2];
	}

	student::~student()
	{

	}