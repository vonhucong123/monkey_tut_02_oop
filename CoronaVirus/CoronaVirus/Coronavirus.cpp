#include "Coronavirus.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Coronavirus::Coronavirus()
{

}

Coronavirus::Coronavirus(const Coronavirus& obj)
{
	m_dna = obj.m_dna;
	m_resistance = obj.m_resistance;
}

Coronavirus::~Coronavirus()
{

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
}

void Coronavirus::doBorn()
{
}

void Coronavirus::doClone()
{
}

void Coronavirus::doDie()
{
}

void Coronavirus::initResistance()
{
}
