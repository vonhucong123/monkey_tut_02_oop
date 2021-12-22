#include "AlphaCoronavirus.h"
#include "BetaCoronavirus.h"
#include "Coronavirus.h"
#include "Patient.h"
#include <iostream>
using namespace std;
enum class an
{
	ga,
	lon
};
int main()
{
	cout << "start\n";
	Patient par;
	par.takeMedicine();
	cout << "oke";
	return 0;
}