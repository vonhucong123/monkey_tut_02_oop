#include "BetaCoronavirus.h"
#include <list>
using namespace std;

BetaCoronavirus::BetaCoronavirus()
{
    doBorn();
}

BetaCoronavirus::~BetaCoronavirus()
{
}

void BetaCoronavirus::doBorn()
{
    loadADNInformation();
    m_protein = Protein(rand()%3);
}

list<Coronavirus*> BetaCoronavirus::doClone()
{
    list<Coronavirus*> corList;
    for (int i = 0; i < 1; i++)
    {
        BetaCoronavirus *betaCorvi = new BetaCoronavirus(*this);
        corList.push_back(betaCorvi);
    }
    return corList;
}

void BetaCoronavirus::doDie()
{
    m_resistance = 0;
}

void BetaCoronavirus::initResistance()
{
    // xong
    if (m_protein == Protein::NS3)
    {
        m_resistance = rand() % (10 - 1 + 1) + 1;
    }
    else if(m_protein == Protein::E)
    {
        m_resistance = rand() % (30 - 21 + 1) + 21;
    }
    else
    {
        m_resistance = rand() % (20 - 11 + 1) + 11;
    }
}

int BetaCoronavirus::virusType()
{
    return 2;
}
