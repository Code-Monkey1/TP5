/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (int i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

/// TODO : À modifier :
vector<Depense*> Groupe::getDepenses() const
{
	return gestionnaireDepenses_->getConteneur();
}

/// TODO : À modifier :
map<Utilisateur*, double> Groupe::getUtilisateurs() const
{
	return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const
{
	return transferts_;
}

/// TODO : À modifier :
vector<double> Groupe::getComptes() const {
	
	return gestionnaireUtilisateurs_->getComptes();
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs()
{
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses()
{
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
// TODO : À modifier :
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu)
{

	auto iterateur = find(gestionnaireUtilisateurs_->getConteneur().begin(), gestionnaireUtilisateurs_->getConteneur().end(), payePar);
	if (iterateur == gestionnaireUtilisateurs_->getConteneur().end())
	{
		return *this;
	}
	Depense* depense = new Depense(nom, montant, lieu);

	// Modifié :
	// depenses_.push_back(depense);

	// Ajouté :
	gestionnaireDepenses_->ajouter(*depense);

	*payePar += depense;

	// Mise a jour des comptes
	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur)
{
	/// Ajouté :
	gestionnaireUtilisateurs_->ajouter(utilisateur);

	gestionnaireUtilisateurs_->getComptes().push_back(0);
	return *this;
}

/// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		map<Utilisateur*, double>::iterator iterateurDuMax;
		map<Utilisateur*, double>::iterator iterateurDuMin;

		// On cherche le compte le plus eleve et le moins eleve
		for (auto it = gestionnaireUtilisateurs_->getConteneur().begin(); it != gestionnaireUtilisateurs_->getConteneur().end(); ++it) {
			if (it->first->getBalance() > max) {
				max = it->first->getBalance();
				iterateurDuMax = it;
			}
			if (it->first->getBalance() < min) {
				min = it->first->getBalance();
				iterateurDuMin = it;
			}

			// On cherche lequel des deux a la dette la plus grande
			if (-min <= max && min != 0 && max != 0) {
				if (iterateurDuMin->first->getMethodePaiement() == Interac) {
					TransfertInterac* transfert = new TransfertInterac(-min, iterateurDuMin->first, iterateurDuMax->first);
					transferts_.push_back(transfert);
					transfert->effectuerTransfert();
				}
				else {
					TransfertPaypal* transfert = new TransfertPaypal(-min, iterateurDuMin->first, iterateurDuMax->first);
					transferts_.push_back(transfert);
					transfert->effectuerTransfert();
				}
				iterateurDuMax->second += min;
				iterateurDuMin->second = 0;
			}
			else if (-min > max  && min != 0 && max != 0) {
				if (iterateurDuMin->first->getMethodePaiement() == Interac) {
					TransfertInterac* transfert = new TransfertInterac(max, iterateurDuMin->first, iterateurDuMax->first);
					transferts_.push_back(transfert);
					transfert->effectuerTransfert();
				}
				else {
					TransfertPaypal* transfert = new TransfertPaypal(max, iterateurDuMin->first, iterateurDuMax->first);
					transferts_.push_back(transfert);
					transfert->effectuerTransfert();
				}
				iterateurDuMax->second = 0;
				iterateurDuMin->second += max;
			}

			// On incremente le nombre de comptes mis a 0
			count++;
			if (-min == max) {
				count++;
			}
			if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
				calcul = false;
			}
		}

	}
}

// Methode d'affichage
/// TODO : À modifier :
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	for (map<Utilisateur*, double>::iterator it = groupe.gestionnaireUtilisateurs_->getConteneur().begin();
		 it != groupe.gestionnaireUtilisateurs_->getConteneur().end(); ++it) {
		os << "\t- " << it->first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (map<Utilisateur*, double>::iterator it = groupe.gestionnaireUtilisateurs_->getConteneur().begin();
			 it != groupe.gestionnaireUtilisateurs_->getConteneur().end(); ++it) {
			os << it->first->getNom() << " : " << it->second << endl;
		}
	}

	os << endl;
	return os;
}
