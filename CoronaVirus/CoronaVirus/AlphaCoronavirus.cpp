#include "AlphaCoronavirus.h"
#include <list>
#include <iostream>
#include <random>
using namespace std;

void AlphaCoronavirus::doBorn()
{
    // xong
    loadADNInformation();
    randomColor();
}

AlphaCoronavirus::AlphaCoronavirus()
{
    loadADNInformation();
    doBorn();
}

AlphaCoronavirus::~AlphaCoronavirus()
{
   
}

list<Coronavirus*> AlphaCoronavirus::doClone()
{
    list<Coronavirus*> corList;
    Coronavirus corvi = AlphaCoronavirus(*this);
    corList.push_back(&corvi);
    return corList;
}

void AlphaCoronavirus::doDie()
{
    m_resistance = 0;
}

void AlphaCoronavirus::initResistance()
{
    if (m_color == Color::RED)
    {
        m_resistance = rand() % (20 - 10 + 1) + 10;
    }
    else
    {
        m_resistance = rand() % (15 - 10 + 1) + 10;
    }
}

int AlphaCoronavirus::virusType()
{
    return 1;
}

void AlphaCoronavirus::randomColor()
{
    m_color = Color(rand() % 2);
}
