#pragma once

#include "depense.h"
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

#include <algorithm>
#include <vector>

template< typename T, typename C, typename D >
class GestionnaireDepenses : public GestionnaireGenerique<Depense, Depense*, vector<Depense*>>
{
public:
	double getTotalDepenses() const;
};

template<typename T, typename C, typename D>
inline double GestionnaireDepenses<T, C, D>::getTotalDepenses() const
{
	double somme = accumulate(conteneur_.begin(), conteneur_.end());
	return somme;
}