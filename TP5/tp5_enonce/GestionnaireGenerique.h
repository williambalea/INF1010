/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include "Foncteur.h"

template<typename T, typename C, typename A, typename S>
// TODO : Créer la classe GestionnaireGenerique
class GestionnaireGenerique
{
public:
// TODO : Méthodes :

	virtual void ajouter(T* t)
	{
		A a(conteneur_);
		a(t);
	}
	virtual void supprime(T* t) 
	{
		S s(conteneur_);
		s(t); //on inverse
	}
	virtual C obtenirConteneur()
	{
		return conteneur_;
	}
	template<typename Predicate>
	void pourChaqueElement(Predicate pred)
	{
		for_each(conteneur_.begin(), conteneur_.end(), pred);
	}

protected:
	C conteneur_;

};