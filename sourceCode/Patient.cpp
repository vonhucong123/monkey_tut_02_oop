#include "Patient.h"
#include <list>
Patient::Patient()
{
	doStart();
	initResistance();
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
		count--;
		char rnd = rand() % (3 - 0 + 1) + 0;
		switch (rnd)
		{
		case 1:
		{
			Coronavirus *CoronaVi = new Coronavirus();
			m_virusList.push_back(CoronaVi);
			break;
		}
		case 2:
		{
			AlphaCoronavirus *AlphaVi = new AlphaCoronavirus;
			m_virusList.push_back((Coronavirus*)AlphaVi);
			break;
		}
		default:
		{
			BetaCoronavirus *BetaVi = new BetaCoronavirus;
			m_virusList.push_back((Coronavirus*)BetaVi);
		}
		}
	}	
	m_state = State::ALIVE;
}

void Patient::takeMedicine()
{
	// bệnh nhân uống thuốc
	for (auto const& i : m_virusList)
	{
		int i_medicineResistance = rand() % (60 - 1 + 1) + 1;
		i->reduceResistance(i_medicineResistance);
	}

	// nhân bản virus
	list<Coronavirus*> corList;
	for (auto const i : m_virusList)
	{
		if (!i->_isDie())
		{
			list<Coronavirus*> corlist;
			corList = i->doClone();
			for (auto const j : corlist)
			{
				corList.push_back(j);
			}
		}
	}

	// thêm các virus mới vào list
	for (auto const i : corList)
	{
		m_virusList.push_back(i);
	}

	// xét sức đề kháng của bệnh nhân
	int sumRes = 0;
	for (auto const& i : m_virusList)
	{
		sumRes += i->getResistance();
	}
	if (sumRes > m_resistance)
	{
		doDie();
	}
}

void Patient::doDie()
{
	m_virusList.clear();
	m_state = State::DIE;
}
