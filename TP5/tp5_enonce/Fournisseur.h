#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include "Usager.h"
#include "Produit.h"
#include "GestionnaireProduits.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);

	// TODO : Modifier l'impl�mentation de ses m�thodes : ----
	GestionnaireProduits* obtenirCatalogue() const;
    void afficherCatalogue() const;
    virtual void afficher() const;
    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);   
	// -------------------------------------------------------

	// TODO : impl�menter les m�thodes suivantes :
	Produit* trouverProduitPlusCher() const;
	void DiminuerPrix(int pourcent) const;

  private:
   GestionnaireProduits* catalogue_;
};

#endif
