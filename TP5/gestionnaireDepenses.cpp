#include "gestionnaireDepenses.h"

double GestionnaireDepenses::getTotalDepenses() const
{
	double totalDepenses = accumulate(conteneur_.begin(), conteneur_.end(), 0);
	return totalDepenses;
	/*
	double totalDepenses = 0;
	for (int i = 0; i < conteneur_.size(); i++) {
		totalDepenses += conteneur_[i]->getMontant();
	}
	return totalDepenses;
	*/
}