#include "Fournisseur.h"
#include <iostream>
#include <algorithm>
#include "GestionnaireProduits.h"

Fournisseur::Fournisseur()
    : Usager()
{
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal) : Usager(nom, prenom, identifiant, codePostal)
{
	// TODO : À modifier
	catalogue_ = new GestionnaireProduits;
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
	// TODO : À modifier
	return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : À modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
	cout << endl;
    //for (unsigned int i = 0; i < catalogue_.size(); i++)
       // catalogue_[i]->afficher();
   // cout << endl;
	
}

void Fournisseur::afficher() const
{
	// TODO : À modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << catalogue_->obtenirConteneur().size() << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
	catalogue_->ajouter(produit);
 
}

void Fournisseur::enleverProduit(Produit *produit)
{
	// TODO : À modifier
	produit->modifierFournisseur(nullptr);
	catalogue_->supprime(produit);
		
	
}

Produit* Fournisseur::trouverProduitPlusCher() const
{
	return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::DiminuerPrix(int pourcent) const
{
	FoncteurDiminuerPourcent rabais(pourcent);
	catalogue_->pourChaqueElement(rabais);
}
