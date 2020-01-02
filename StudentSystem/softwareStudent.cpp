#include "softwareStudent.h"
#include <iostream>
using std::cout;

softwareStudent::softwareStudent() :student()
{
	degree = SOFTWARE;
}

softwareStudent::softwareStudent(string studentId, string firstName, string lastName, string email, int age, int numberOfDays[], Degree degree)
	: student(studentId, firstName, lastName, email, age, numberOfDays)
{
	degree = SOFTWARE;
}

Degree softwareStudent::GetDegree()
{
	return SOFTWARE;
}

void softwareStudent::print()
{
	this->student::print();
	cout << "SOFTWARE" << "\n";
}

softwareStudent::~softwareStudent()
{
	student::~student();
}