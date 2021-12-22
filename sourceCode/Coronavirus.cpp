#include "Coronavirus.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Coronavirus::Coronavirus()
{
	initResistance();
	doBorn();
}

Coronavirus::Coronavirus(const Coronavirus& obj)
{
	m_dna = obj.m_dna;
	m_resistance = obj.m_resistance;
}

Coronavirus::~Coronavirus()
{
	doDie();
}

void Coronavirus::setDna(std::string& dna)
{
	m_dna = dna;
}

std::string Coronavirus::getDna()
{
	return m_dna;
}

void Coronavirus::setResistance(int& resistance)
{
	m_resistance = resistance;
}

int Coronavirus::getResistance()
{
	return m_resistance;
}

void Coronavirus::loadADNInformation()
{
	ifstream ADN;
	ADN.open("ATGX.bin", ios::app);
	if (ADN.is_open())
	{
		string adn;
		ADN >> adn;
		m_dna = adn;
	}
	else
	{
		m_dna = "ADN not avariable";
	}
}

void Coronavirus::reduceResistance(int i_medicineResistance)
{
	m_resistance = m_resistance - i_medicineResistance;
	if (m_resistance <= 0)
	{
		// tiêu diệt virus
		doDie();
	}
}

void Coronavirus::doBorn()
{
	loadADNInformation();
}

list<Coronavirus*> Coronavirus::doClone()
{
	// sinh ngẫu nhiên 1-5 virus
	int numberCovid = rand() % (5 - 1 + 1) + 1;
	list<Coronavirus*> corList;
	for (int i = 0; i < numberCovid; i++)
	{
		Coronavirus *corvi = new Coronavirus(*this);
		corList.push_back(corvi);
	}
	return corList;
}

void Coronavirus::doDie()
{
	m_resistance = 0;
}

bool Coronavirus::_isDie()
{
	if (m_resistance <= 0)
	{
		return true;
	}
	else 
		return false;
}

// khởi tạo sức đề kháng của virus
void Coronavirus::initResistance()
{
	m_resistance = rand() % (30 - 10 + 1) + 10;
}

int Coronavirus::virusType()
{
	return 0;
}
