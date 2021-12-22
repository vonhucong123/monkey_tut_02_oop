#pragma once
#include "Coronavirus.h"
#include <list>
#include <iostream>
using namespace std;

enum class Protein
{
	NS3,
	NS5,
	E
};

class BetaCoronavirus:private Coronavirus
{
public:
	BetaCoronavirus();				// oke
	~BetaCoronavirus();

	void doBorn() override;					// oke

	list<Coronavirus*> doClone() override;	// oke

	void doDie() override;					// oke

	void initResistance() override;			// oke

	int virusType() override;				//oke
protected:
	Protein m_protein;

private:

};

