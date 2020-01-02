#include "networkStudent.h"
#include <iostream>
using std::cout;

networkStudent::networkStudent():student()
{
	degree = NETWORKING;
}

networkStudent::networkStudent(string studentId, string firstName, string lastName, string email, int age, int numberOfDays[], Degree degree) 
	: student(studentId, firstName, lastName, email, age, numberOfDays)
{
	degree = NETWORKING;
}

Degree networkStudent::GetDegree()
{
	return NETWORKING;
}

void networkStudent::print()
{
	this->student::print();
	cout << "NETWORKING" << "\n";
}

networkStudent::~networkStudent()
{
	student::~student();
}