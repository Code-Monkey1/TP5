/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

template< typename T, typename C, typename D >
class GestionnaireGenerique
{
public:	
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

private:
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

}

template<typename T, typename C, typename D>
inline int GestionnaireGenerique<T, C, D>::getNombreElements() const
{
	return 0;
}

template<typename T, typename C, typename D>
inline D GestionnaireGenerique<T, C, D>::getElementParIndex(int i) const
{
	return D();
}
