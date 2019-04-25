/********************************************
* Titre: Travail pratique #1 -Panier.h
* Date: 20 janvier 2018
* Auteur:
*******************************************/

#include <string>
#include "Produit.h"

#ifndef PANIER_H
#define PANIER_H
class Panier
{
public:
	Panier(int capacite);
	// methodes d'accès
	Produit **  obtenirContenuPanier() const;
	int obtenirNombreContenu()const;
	double obtenirTotalApayer()const;

	// méthodes de modification

	// autres méthodes
	void ajouter(Produit * prod);
	void livrer();
	void afficher();

private:

	Produit ** contenuPanier_;
	int  nombreContenu_;
	int capaciteContenu_;
	double totalAPayer_;
};

#endif

