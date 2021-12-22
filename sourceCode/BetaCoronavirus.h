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
	BetaCoronavirus();				
	~BetaCoronavirus();

	void doBorn() override;					

	list<Coronavirus*> doClone() override;	

	void doDie() override;					

	void initResistance() override;			

	int virusType() override;				

	bool _isDie() override;
protected:
	Protein m_protein;

private:

};

