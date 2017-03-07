// Addeline Mitchell
// Mar 7, 2017
// ings.cpp
//
// This is an interactive simulated demonstration of
// semi-strict OoOE for CS441 presentation purposes.


#include "ings.h"


// CTOR & DCTOR
Ing::Ing(int id, double amt, string unit, string name, bool isDry)
{
	_id = id;
	_amt = amt;
	_unit = unit;
	_name = name;
	_isDry = isDry;
}

Ing::~Ing()
{}


// SETS
void Ing::setID(int in)
{ _id = in; }

void Ing::setAmt(double in)
{ _amt = in; }

void Ing::setUnit(string in)
{ _unit = in; }

void Ing::setName(string in)
{ _name = in; }

void Ing::setIsDry(bool in)
{ _isDry = in; }


// GETS
int Ing::getID() const
{ return _id; }

double Ing::getAmt() const
{ return _amt; }

string Ing::getUnit() const
{ return _unit; }

string Ing::getName() const
{ return _name; }

bool Ing::getIsDry() const
{ return _isDry; }