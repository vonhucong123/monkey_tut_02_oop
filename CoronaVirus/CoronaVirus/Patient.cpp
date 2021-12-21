#include "Patient.h"

Patient::Patient()
{
	doStart();
}

Patient::~Patient()
{

}

void Patient::setResistance(int& resi)
{
	m_resistance = resi;
}

int Patient::getResistance()
{
	return m_resistance;
}

void Patient::setState(int state)
{
	
}

void Patient::initResistance()
{
	m_resistance = rand()%(9000 - 1000 + 1) + 1000;
}

void Patient::doStart()
{
	char count = rand() % (20 - 10 + 1) + 10;
	while (count != 0)
	{
		char rnd = rand() % (3 - 0 + 1) + 0;
		switch (rnd)
		{
		case 1:
		{
			Coronavirus CoronaVi;
			m_virusList.push_back(&CoronaVi);
			break;
		}
		case 2:
		{
			AlphaCoronavirus AlphaVi;
			m_virusList.push_back((Coronavirus*)&AlphaVi);
			break;
		}
		default:
		{
			BetaCoronavirus BetaVi;
			m_virusList.push_back((Coronavirus*)&BetaVi);
		}
		}
	}	
}

void Patient::takeMedicine()
{
}
