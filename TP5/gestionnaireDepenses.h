#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <vector>

class GestionnaireDepenses : public GestionnaireGenerique<Depense, Depense*, vector<Depense*>>
{
public:
	double getTotalDepenses() const;
};