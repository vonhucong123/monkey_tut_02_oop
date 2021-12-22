#include "Patient.h"
#include <list>
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

State Patient::getState()
{
	return m_state;
}

void Patient::setState(State& state)
{
	m_state = state;
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
	m_state = State::ALIVE;
}

void Patient::takeMedicine()
{
	// lưu các số lượng virus không chết
	// 0 - corona; 1 - alpha; 2 - beta
	char numberVirusWillBeAdd[3] = {0,0,0};
	for (auto const& i : m_virusList)
	{
		int i_medicineResistance = rand() % (60 - 1 + 1) + 1;
		i->reduceResistance(i_medicineResistance);
		if (!i->_isDie())
		{
			int k = i->virusType();
			numberVirusWillBeAdd[k]++;	
		}
	}

	// virus nhân bản
	for (int j = 0; j < 3; j++)
	{
		while (numberVirusWillBeAdd[j] > 0)
		{
			switch (j)
			{
			case 0:
			{
				Coronavirus CoronaVi;
				m_virusList.push_back(&CoronaVi);
				break;
			}
			case 1:
			{
				AlphaCoronavirus AlphaVi;
				m_virusList.push_back((Coronavirus*)&AlphaVi);
				break;
			}
			default:
			{
				BetaCoronavirus BetaVi;
				m_virusList.push_back((Coronavirus*)&BetaVi);
				break;
			}
			}
		}
	}
}

void Patient::doDie()
{
	m_virusList.clear();
	m_state = State::DIE;
}
