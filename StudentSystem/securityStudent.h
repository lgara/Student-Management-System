#pragma once
#include <string>
#include "student.h"
class securityStudent : public student
{
public:
	securityStudent();
	securityStudent(
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

	~securityStudent();
};

