/********************************************
* Titre: Travail pratique #3 - Produit.cpp
* Date: 
* Auteur: 
*******************************************/

#include "Produit.h"
using namespace std;

Produit::Produit(Fournisseur& fournisseur,const string& nom, int reference, double prix,TypeProduit type) : fournisseur_(fournisseur), nom_(nom), reference_(reference), prix_(prix), type_(type)
{
	fournisseur.obtenirCatalogue().push_back(this);
}

void eraseProduit(vector<Produit*>& catalogue, int pos)
{
	unsigned int max = catalogue.size() - 1;
	for (unsigned int i = pos; i < max; i++)
		catalogue[i] = catalogue[i + 1];
	catalogue.pop_back();
}

Produit::~Produit() {
	for (unsigned int i = 0; i < fournisseur_.obtenirCatalogue().size(); i++) {
		if (*(fournisseur_.obtenirCatalogue()[i]) == *this)
			eraseProduit(fournisseur_.obtenirCatalogue(), i);
	}
}

// Methodes d'acces
string Produit::obtenirNom() const
{
	return nom_;
}

int Produit::obtenirReference() const
{
	return reference_;
}

double Produit::obtenirPrix() const
{
	return prix_;
}

Fournisseur& Produit::obtenirFournisseur() const
{
	return fournisseur_;
}
TypeProduit Produit::retournerType() {
	return type_;
}

// Methodes de modification
void Produit::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Produit::modifierReference(int reference)
{
	reference_ = reference;
}

void Produit::modifierPrix(double prix)
{
	prix_ = prix;
}


bool Produit::operator>(const Produit & produit) const
{
	return prix_ > produit.prix_;
}

bool Produit::operator<(const Produit & produit) const
{
	return prix_ < produit.prix_;
}

bool Produit::operator==(const Produit & produit) const
{
	return (nom_ == produit.nom_ &&
			prix_ == produit.prix_ &&
			reference_ == produit.reference_);
}
// pour lire un type enumer�
inline istream & operator >> (istream & is, TypeProduit & typeProduit) {
	unsigned int type = 0;
	if (is >> type)
		typeProduit = static_cast<TypeProduit>(type);
	return is;
}

istream & operator>>(istream & is, Produit & produit)
{
	return is >> produit.nom_ >> produit.reference_ >> produit.prix_ >> produit.type_;
}

 ostream & operator<<(ostream & os, const Produit & produit)
{
	 os << "Produit :"
		 << " nom: " << produit.obtenirNom() << endl
		 << " \t \t ref : " << produit.obtenirReference() << endl
		 << " \t \t prix actuel : " << produit.obtenirPrix() << endl
		 << "\t Fournisseur " << produit.obtenirFournisseur().obtenirNom() << endl;
	 return os;
}


