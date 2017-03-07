// Addeline Mitchell
// Mar 7, 2017
// ings.h
//
// This is an interactive simulated demonstration of
// semi-strict OoOE for CS441 presentation purposes.


#ifndef INGS_H_INCLUDED
#define INGS_H_INCLUDED

#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <queue>
using std::deque;


class Ing
{
	public:
		Ing(int id, double amt, string unit, string name, bool isDry);
		~Ing();

		void setID(int in);
		void setAmt(double in);
		void setUnit(string in);
		void setName(string in);
		void setIsDry(bool in);

		int getID() const;
		double getAmt() const;
		string getUnit() const;
		string getName() const;
		bool getIsDry() const;

	private:
		int _id;
		double _amt;
		string _unit, _name;
		bool _isDry;
};

#endif // INGS_H_INCLUDED