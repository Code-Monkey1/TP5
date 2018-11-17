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
	virtual void ajouter(T t) = 0;	//Fonction virtuelle pure pour que la classe soit abstraite
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
inline int GestionnaireGenerique<T, C, D>::getNombreElements() const
{
	return conteneur_.size();	//Pas sur si c'est bon
}

template<typename T, typename C, typename D>
inline D GestionnaireGenerique<T, C, D>::getElementParIndex(int i) const
{
	return conteneur_[i];	//Pas sur si c'est bon
}
#endif // !GESTIONNAIREGENERIQUE_H