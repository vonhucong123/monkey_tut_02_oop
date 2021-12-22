#include "AlphaCoronavirus.h"
#include "BetaCoronavirus.h"
#include "Coronavirus.h"
#include "Patient.h"
#include <iostream>
using namespace std;

int main()
{
	Coronavirus cor;
	cor.loadADNInformation();
	string a = cor.getDna();
	cout << a;
	//Patient par;
	//par.doStart();
}