/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

// TODO : Créer la classe GestionnaireProduits
class GestionnaireProduits : public GestionnaireGenerique<Produit, multimap<int, Produit*>, AjouterProduit , SupprimerProduit >
{
// TODO : Méthodes :
public:
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher();
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher();
	vector<pair<int, Produit*>> obtenirProduitsEntre(double borneInf, double borneSup);
	Produit* obtenirProduitSuivant(Produit* prod);
	
private: 
};