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
	AlphaCoronavirus();				// oke
	~AlphaCoronavirus();			// oke

	void doBorn() override;			// oke

	list<Coronavirus*> doClone() override;	// oke

	void doDie() override;					// oke			

	// khởi tạo sức đề kháng của virus
	void initResistance() override;			// oke

	// trả về kiểu virus
	int virusType() override;				// oke

	void randomColor();				// oke
protected:
	Color m_color;
private:
};

