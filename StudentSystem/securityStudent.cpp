#include "securityStudent.h"
#include <iostream>
using std::cout;

securityStudent::securityStudent() :student()
{
	degree = NETWORKING;
}

securityStudent::securityStudent(string studentId, string firstName, string lastName, string email, int age, int numberOfDays[], Degree degree)
	: student(studentId, firstName, lastName, email, age, numberOfDays)
{
	degree = SECURITY;
}

Degree securityStudent::GetDegree()
{
	return SECURITY;
}

void securityStudent::print()
{
	this->student::print();
	cout << "SECURITY" << "\n";
}

securityStudent::~securityStudent()
{
	student::~student();
}