/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/


class AjouterDepense
{
public:
	AjouterDepense(Depense*) {};
	vector<Depense*>& operator()(Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	};
private:
	vector<Depense*> conteneur_;
};



/*
Foncteur AjouterUtilisateur

M�thode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/


/*
Foncteur FoncteurIntervalle

M�thode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/

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
