#pragma once
#include "Coronavirus.h"
#include <iostream>

enum class m_protein
{
	NS3,
	NS5,
	E
};

class BetaCoronavirus:private Coronavirus
{
public:
	void doBorn();

	void doClone();

	void doDie();

	void initResistance();

	int virusType();
protected:

private:

};

