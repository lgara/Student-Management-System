#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
class student
{
public:
	const static int arraySize = 3;

	student(); // Empty constructor
	// Full constructor
	student(string id, string firstName, string lastName, string emailAddress, int age, int numberOfDaysToComplete[]);
protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numberOfDaysToComplete[arraySize];
	Degree degree;
	
public:
	string GetStudentId();
	void SetStudentId(string x);
	string GetFirstName();
	void SetFirstName(string x);
	string GetLastName();
	void SetLastName(string x);
	string GetEmailAddress();
	void SetEmailAddress(string x);
	int GetAge();
	void SetAge(int x);
	int* GetNumberOfDaysToComplete();
	void SetNumberOfDaysToComplete(int numberOfDays[]);
	virtual Degree GetDegree() = 0;

	virtual void print() = 0;

	// The destructor
	~student();
};



