#pragma once
#include "Coronavirus.h"
#include "AlphaCoronavirus.h"
#include "BetaCoronavirus.h"
#include <iostream>
#include <list>
using namespace std;

enum class State
{
	DIE,
	ALIVE
}; 

class Patient
{
public:
	Patient();
	~Patient();
	void setResistance(int& resi);
	int getResistance();
	State getState();
	void setState(State &state);

	// hởi tạo ngẫu nhiên sức đề kháng của bẹnh nhân
	void initResistance();

	// khởi tạo virus trong bệnh nhân
	void doStart();

	// bệnh nhân uống thuốc (thuốc đc random)
	void takeMedicine();
	
	// người bệnh qua đời
	void doDie();

protected:
	// sức đề kháng của bệnh nhân
	int m_resistance;
	// danh sách các virus của bệnh nhân
	list<Coronavirus*> m_virusList;
	// trạng thái sống chết của virus
	State m_state;

private:

};

