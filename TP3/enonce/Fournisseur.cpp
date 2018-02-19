/********************************************
* Titre: Travail pratique #3 - Fournisseur.cpp
* Date: 
* Auteur:
*******************************************/
#include "Fournisseur.h"
Fournisseur::Fournisseur(const string&  nom, const string& prenom, int identifiant, const string& codePostal) : Usager(nom, prenom, identifiant, codePostal)
{
	for (int i = 0; i < NIVEAUX_SATISFACTION; i++)
		satisfaction_.niveaux_[i] = 0;
}

vector<Produit*> Fournisseur::obtenirCatalogue() const
{
	return contenuCatalogue_;
}
Satisfaction Fournisseur::obtenirSatisfaction() const
{
	return satisfaction_;
}

void Fournisseur::modifierSatisfaction(Satisfaction satisfaction)
{
	satisfaction_ = satisfaction;
}
void Fournisseur::noter(int appreciation)
{
	satisfaction_.niveaux_[appreciation]++;
}

void Fournisseur::ajouterProduit(Produit* produit)
{
	contenuCatalogue_.push_back(produit);
}
void Fournisseur::enleverProduit(Produit* produit)
{
	contenuCatalogue_.pop_back(); //enelver produit actuel et non le dernier seulement
}
Fournisseur& Fournisseur::operator=(const Fournisseur& fournisseur)
{
	Usager* ptrusager = new Fournisseur;
	Fournisseur* ptrFournisseur = static_cast<Fournisseur*> (ptrusager);
	return *ptrFournisseur;
}

ostream& operator<<(ostream & os, Fournisseur& fournisseur)
{
	os << &fournisseur.satisfaction_ << endl;
	return os;
}