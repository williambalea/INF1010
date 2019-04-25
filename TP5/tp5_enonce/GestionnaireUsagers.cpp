/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"
#include"Fournisseur.h"
#include"Gestionnaire.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double chiffreAffaires = 0.0;
	set<Usager*>::iterator end = conteneur_.end();
	for (set<Usager*>::iterator it = conteneur_.begin(); it != end; it++)
		chiffreAffaires += (*it)->obtenirTotalAPayer();
	return chiffreAffaires;
}
void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}
void GestionnaireUsagers::reinitialiser()
{
	set<Usager*>::iterator end = conteneur_.end();
	for (set<Usager*>::iterator it = conteneur_.begin(); it != end; it++)
		(*it)->reinitialiser();
}
void GestionnaireUsagers::afficherProfils() const
{
	cout << "PROFILS" << endl;
	set<Usager*>::iterator end = conteneur_.end();
	for (set<Usager*>::iterator it = conteneur_.begin(); it != end; it++)
		(*it)->afficher();
	cout << endl;
}