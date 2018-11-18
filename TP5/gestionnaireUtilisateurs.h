/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <vector>
#include "utilisateur.h"
#include "gestionnaireGenerique.h"

class GestionnaireUtilisateurs : public GestionnaireGenerique<Utilisateur*, map<Utilisateur*, double>, Utilisateur>
{
public:
	
	vector<double> getComptes() const;
	bool estExistant(Utilisateur* utilisateur) const;
	void mettreAJourComptes(Utilisateur* payePar, double montant);
	pair<Utilisateur*, double>& getMax() const;
	pair<Utilisateur*, double>& getMin() const;
	Utilisateur* getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const;
	vector<pair<Utilisateur*, double>> getUtilisateursEntre(double borneInf, double borneSup) const;
	GestionnaireUtilisateurs& setCompte(pair<Utilisateur*, double> p);

private:
	map<Utilisateur*, double> mapUtilisateur;
};