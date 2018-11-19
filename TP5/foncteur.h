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
//
//class AjouterDepense
//{
//public:
//	AjouterDepense() {};
//	~AjouterDepense() {};
//	vector<Depense*>& operator()() {
//	
//	};
//private:
//	vector<Depense*> conteneur_;
//};
//

/*
Foncteur AjouterUtilisateur

Méthode :
Constructeur
map<Utilisateur*, double>& operator()();

Attribut :
map<Utilisateur*, double> conteneur_;
*/


class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup): borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*,double> unePaire) {
		return (unePaire.second >= borneInf_ && unePaire.second <= borneSup_);
	};
private:
	double borneInf_, borneSup_;
};
