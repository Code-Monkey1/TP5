/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include <algorithm>
#include <map>
#include <functional>
#include <iterator>
#include "foncteur.h"
#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
using namespace std::placeholders;

vector<double> GestionnaireUtilisateurs::getComptes() const
{
	vector<pair<Utilisateur*, double>> vecteurTemp;
	vector<double> vecteurComptes;
	copy(mapUtilisateur.begin(), mapUtilisateur.end(), back_inserter(vecteurTemp));
	for (unsigned i = 0; i < vecteurTemp.size(); i++)
	{
		vecteurComptes.push_back(vecteurTemp[i].second);
	}
	return vecteurComptes;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur * utilisateur) const
{
	bool estExistant = false;
	if (mapUtilisateur.find(utilisateur) != mapUtilisateur.end()) {
		estExistant = true;
	}
	return estExistant;
}

void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur * payePar, double montant)
{
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const
{	
	auto max = mapUtilisateur.begin();
	for (auto it = mapUtilisateur.begin(); it != mapUtilisateur.end(); ++it)
	{
		if (it->second > max->second)
		{
			max = it;
		}
	}
	pair<Utilisateur*, double> maPaire = make_pair(max->first, max->second);
	return maPaire;

}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const
{
	auto min = mapUtilisateur.begin();
	for (auto it = mapUtilisateur.begin(); it != mapUtilisateur.end(); ++it)
	{
		if (it->second < min->second)
		{
			min = it;
		}
	}
	pair<Utilisateur*, double> maPaire = make_pair(min->first, min->second);
	return maPaire;
}

Utilisateur * GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur * utilisateur, double montant) const
{

	auto it = find_if( mapUtilisateur.begin(), mapUtilisateur.end(), bind(equal_to<Utilisateur*>(), utilisateur, _1) );
	it++;
	return it->first;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const
{
	vector<pair<Utilisateur*, double>> utilisateurDansIntervalle;
	copy_if(mapUtilisateur.begin(), mapUtilisateur.end(), back_inserter(utilisateurDansIntervalle), FoncteurIntervalle(borneInf, borneSup));
	return utilisateurDansIntervalle;
}

GestionnaireUtilisateurs & GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p)
{
	auto it = find(mapUtilisateur.begin(), mapUtilisateur.end(), p.first);
	it->second = p.second;
}
