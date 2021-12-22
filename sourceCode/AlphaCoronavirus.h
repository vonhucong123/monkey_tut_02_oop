#pragma once
#include "Coronavirus.h"
#include <list>
#include <iostream>
using namespace std;
enum class Color
{
	BLUE,
	RED
};

class AlphaCoronavirus:private Coronavirus
{
public:
	AlphaCoronavirus();				
	~AlphaCoronavirus();			

	void doBorn() override;			

	list<Coronavirus*> doClone() override;

	void doDie() override;							

	// khởi tạo sức đề kháng của virus
	void initResistance() override;			

	// trả về kiểu virus
	int virusType() override;				

	void randomColor();	

	bool _isDie() override;
protected:
	Color m_color;
private:
};

