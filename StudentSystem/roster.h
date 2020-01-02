#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
class roster
{
private:

	int lastIndex;
	int capacity;
public:
	roster();
	roster(int capacity);
	student** classRosterArray;
	student* getStudentAt(int index);
	void parseThenAdd(string datarow);
	void add(Degree deg, string sId, string sFirstname, string sLastName,string email, int age, int nd1, int nd2, int nd3);
	void printAll();
	bool remove(string id);
	void printAverageDaysToComplete(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(Degree deg);
	~roster();
	
};

