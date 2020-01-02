#pragma once
#include <string>
#include "student.h"
class networkStudent : public student
{
public:
	networkStudent();
	networkStudent(
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

	~networkStudent();
};

