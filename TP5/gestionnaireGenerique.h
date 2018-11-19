/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#ifndef GESTIONNAIREGENERIQUE_H
#define GESTIONNAIREGENERIQUE_H

template< typename T, typename C, typename D>
class GestionnaireGenerique
{

public:

	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

protected:
		C conteneur_;
};

template<typename T, typename C, typename D>
inline C GestionnaireGenerique<T, C, D>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C, typename D>
inline void GestionnaireGenerique<T, C, D>::ajouter(T t)
{
	copy(t, back_inserter(conteneur_));
}

template<typename T, typename C, typename D>
inline int GestionnaireGenerique<T, C, D>::getNombreElements() const
{
	return conteneur_.size();
}

template<typename T, typename C, typename D>
inline D GestionnaireGenerique<T, C, D>::getElementParIndex(int i) const
{
	/*if (D == (Utilisateur*) ) {

		int compteur = 0;
		for (map<Utilisateur*, double>::iterator it = conteneur_.begin(); it != conteneur_.end(); ++it) {

			if (counter == index) {
				return it->first;
			}
			compteur++;
		}
	}
	else
	{*/
	return conteneur_[i];
	//}
}
#endif // !GESTIONNAIREGENERIQUE_H