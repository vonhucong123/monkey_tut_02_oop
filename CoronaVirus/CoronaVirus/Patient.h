#pragma once
#include "Coronavirus.h"
#include "AlphaCoronavirus.h"
#include "BetaCoronavirus.h"
#include <iostream>
#include <list>
using namespace std;

class Patient
{
public:
	Patient();
	~Patient();
	void setResistance(int& resi);
	int getResistance();
	void setState(int state);

	// hởi tạo ngẫu nhiên sức đề kháng của 
	// Bệnh nhân (1000-9000). Gọi nó trong Constructor.
	void initResistance();

	// Khởi tạo ngẫu nhiên tất cả virus(around 10 – 20 virus) và 
	// thêm chúng vào m_virusList. all nó trong Constructor.Set m_state = ALIVE
	void doStart();

	void takeMedicine();


protected:
	// sức đề kháng của bệnh nhân
	int m_resistance;
	// danh sách các virus của bệnh nhân
	list<Coronavirus*> m_virusList;
	// trạng thái sống chết
	enum class m_state
	{
		DIE,
		ALIVE
	};
private:

};

