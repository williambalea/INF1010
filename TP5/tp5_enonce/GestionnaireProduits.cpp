/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"
#include "ProduitAuxEncheres.h"
#include <algorithm>
#include <functional>

using namespace std::placeholders;

void GestionnaireProduits::reinitialiserClient()
{
	//on revient dessus
	multimap<int, Produit*>::iterator end = conteneur_.end();
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != end; it++)
	{
		ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>((*it).second);
		if (produit) {
			produit->modifierEncherisseur(nullptr);
			produit->modifierPrix(produit->obtenirPrixInitial());
		}
	}
	conteneur_.clear();
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	// on revient dessus

	multimap<int, Produit*>::iterator end = conteneur_.end();
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != end; it++)
		(*it).second->modifierFournisseur(nullptr);
	conteneur_.clear();
}

void GestionnaireProduits::afficher()
{
	// on revient dessus
	multimap<int, Produit*> multi;
	for (multimap<int, Produit*>::iterator it = multi.begin(); it != multi.end(); it++)
		(*it).second->afficher();
}

double GestionnaireProduits::obtenirTotalAPayer()
{
	// on revient dessus
	double montant = 0.0;
	multimap<int, Produit*>::iterator end = conteneur_.end();
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != end; it++)
		montant += (*it).second->obtenirPrix();
	return montant;
}
double GestionnaireProduits::obtenirTotalApayerPremium()
{
	// on revient dessus
	double montant = 0.0;

	multimap<int, Produit*>::iterator end = conteneur_.end();
	for (multimap<int, Produit*>::iterator it = conteneur_.begin(); it != end; it++) {
		double prix = (*it).second->obtenirPrix();
		montant += prix < 5 ? 0 : prix - 5;
	}
	return montant;
}
Produit* GestionnaireProduits::trouverProduitPlusCher()
{
	if (conteneur_.size() == 0)
		return nullptr;
	return (*max_element(conteneur_.begin(),
		conteneur_.end(),
		[](pair<int, Produit*> i, pair<int, Produit*> j) {return (i.second->obtenirPrix() < j.second->obtenirPrix()); })).second;
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInf, double borneSup)
{
	multimap<int, Produit*>::iterator it = conteneur_.begin();
	multimap<int, Produit*>::iterator end = conteneur_.end();
	FoncteurIntervalle intervalle(borneInf, borneSup);
	vector<pair<int, Produit*>> intervalleProd;
	copy_if(it, end, back_inserter(intervalleProd), intervalle);
	return intervalleProd;
	
}

Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* prod)
{
	multimap<int, Produit*>::iterator it;
	it = find_if(conteneur_.begin(), conteneur_.end(), bind(greater<pair<int,Produit*>>(), _1, pair<int,Produit*>(prod->obtenirReference(), prod)));
	return (*it).second;
	// à revenir
}