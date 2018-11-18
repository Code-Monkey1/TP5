/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

/*
	Foncteur AjouterDepense

	Méthode :
	Constructeur
	vector<Depense*>& operator()();

	Attribut :
	vector<Depense*> conteneur_;
*/



/*
Foncteur AjouterUtilisateur

Méthode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/



/*
Foncteur FoncteurIntervalle

Méthode :
Constructeur
bool operator()();

Attribut :
double borneInf_, borneSup_;
*/

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup): borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(double montant) {
		return (montant >= borneInf_ && montant <= borneSup_);
	};
private:
	double borneInf_, borneSup_;
};
