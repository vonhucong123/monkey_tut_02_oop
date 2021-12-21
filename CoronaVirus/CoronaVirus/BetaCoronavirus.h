#pragma once
#include "Coronavirus.h"
#include <iostream>

class BetaCoronavirus:private Coronavirus
{
public:
	void doBorn();

	void doClone();

	void doDie();

	void initResistance();

protected:
	enum class m_protein
	{
		NS3,
		NS5,
		E
	};
private:

};

