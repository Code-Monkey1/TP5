#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"
#include <vector>
#include <numeric>



class GestionnaireDepenses : public GestionnaireGenerique<Depense, vector<Depense*>, Depense*>
{
public:
	double getTotalDepenses() const;
};
