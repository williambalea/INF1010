/********************************************
* Titre: Travail pratique #3 - ProduitOrdinaire.h
* Date: 
* Auteur:
*******************************************/


#include <string>
#include <iostream>
#include "ProduitOrdinaire.h"
#include "Fournisseur.h"
using namespace std;

ProduitOrdinaire::ProduitOrdinaire (Fournisseur& fournisseur,
	const string& nom, int reference,
	double prix, TypeProduit type, bool estTaxable) : Produit(fournisseur, nom, reference, prix, type), estTaxable_(estTaxable)
{
}

bool ProduitOrdinaire::obtenirEstTaxable() const
{
	return estTaxable_;
}

void ProduitOrdinaire::modifierEstTaxable(bool estTaxable)
{
	estTaxable_ = estTaxable;
}

//void ProduitOrdinaire::print(ostream& os) const
//{
//	cout << "PRALADADKFFGS!!!!";
//	Produit::print(os);
//}

istream& operator>>(istream& is, ProduitOrdinaire& produit)
{
	is >> static_cast<Produit &> (produit);
	//cout << "Taxable? <true/false> : ";
	is >> produit.estTaxable_;
	return is;
}

ostream& operator<<(ostream& os, const ProduitOrdinaire& produit)
{
	os << "ProduitOrdinaire ";
	os << static_cast<Produit> (produit);
	os << "est Taxable : " << boolalpha << produit.estTaxable_ << endl;
	return os;
}
