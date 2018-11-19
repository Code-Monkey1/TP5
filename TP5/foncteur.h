/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 18 novembre 2018
* Auteur: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include <map>

class AjouterDepense
{
public:
	AjouterDepense(vector<Depense*>& depenses):conteneur_(depenses){};
	vector<Depense*>& operator()(Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	};
private:
	vector<Depense*> conteneur_;
};

class AjouterUtilisateur {
public:
	AjouterUtilisateur(map<Utilisateur*, double>& map):conteneur_(map) {};
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
		conteneur_.insert(make_pair(utilisateur, 0));
		return conteneur_;
	};

private:
	map<Utilisateur*, double> conteneur_;
};

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup): borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*, double> unePaire) {
		return (unePaire.second >= borneInf_ && unePaire.second <= borneSup_);
	};
private:
	double borneInf_, borneSup_;
};
