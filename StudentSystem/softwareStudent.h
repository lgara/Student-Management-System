#pragma once
#include <string>
#include "student.h"
class softwareStudent : public student
{
public:
	softwareStudent();
	softwareStudent(
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int numberOfDaysToComplete[],
		Degree degree
	);
	Degree GetDegree();
	void print();

	~softwareStudent();
};