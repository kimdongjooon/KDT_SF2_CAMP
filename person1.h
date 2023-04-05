#pragma once 

#ifndef __PERSON1_H__
#define __PERSON1_H__
#include <iostream>
using std::string;

class Person {
	static int cnt;
	string name;
public:
	Person(string name);
	static int getCnt();
	void plusCnt();
};

#endif