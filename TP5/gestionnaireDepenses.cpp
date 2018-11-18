#include "gestionnaireDepenses.h"

#include <algorithm>
#include <functional>
#include <numeric>


double GestionnaireDepenses::getTotalDepenses() const
{
	double somme = accumulate(conteneur_.begin(), conteneur_.end());
	return somme;
}
