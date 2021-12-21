#pragma once
#include "Coronavirus.h"
#include <iostream>
class AlphaCoronavirus:private Coronavirus
{
public:
	void doBorn();

	void doClone();

	void doDie();

	void initResistance();
protected:

private:
};

