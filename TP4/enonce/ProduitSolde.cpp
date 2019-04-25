#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{
	return ((1.0 - pourcentageRabais_ / 100.0) * prix_);
}

void ProduitSolde::afficher() const
{
	Produit::afficher();
	cout << '\t' << '\t' << "rabais: " << '\t' << pourcentageRabais_ << '%' << endl;
}
