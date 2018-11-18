#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include <numeric>
#include <algorithm>
#include <vector>



class GestionnaireDepenses : public GestionnaireGenerique<Depense, vector<Depense*>, Depense*>
{
public:
	double getTotalDepenses() const;
};
