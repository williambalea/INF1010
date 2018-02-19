/********************************************
* Titre: Travail pratique #3 - Client.h
* Date:
* Auteur:
*******************************************/

#include "Usager.h"
using namespace std;


Usager::Usager(const string&  nom, const string& prenom, int identifiant, const string& codePostal):
	nom_{ nom },
	prenom_{ prenom },
	identifiant_{ identifiant },
	codePostal_{ codePostal }	
{
}


string Usager::obtenirNom() const
{
	return nom_;
}


string Usager::obtenirPrenom() const
{
	return prenom_;
}


int Usager::obtenirIdentifiant() const
{
	return identifiant_;
}


string Usager::obtenirCodePostal() const
{
	return codePostal_;
}


void  Usager::modifierNom(const string& nom)
{
	nom_ = nom;
}

void Usager::modifierPrenom(const string& prenom)
{
	prenom_ = prenom;
}

void Usager::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}

void Usager::modifierCodePostal(const string& codePostal)
{
	codePostal_ = codePostal;
}


Usager &Usager::operator=(const Usager & usager)
{
	if (this != &usager) {
		nom_ = usager.nom_;
		prenom_ = usager.prenom_;
		identifiant_ = usager.identifiant_;
		codePostal_ = usager.codePostal_;		
	}
	return *this;
}

bool Usager::operator==(int indentifiant) const {
	return identifiant_ == identifiant_;
};
bool Usager::operator == (const Usager & usager)
{
	return  *this == usager.obtenirIdentifiant();
}
bool operator==(int indentifiant, const Usager& usager) {
	return usager == indentifiant;
}

ostream & operator<<(ostream & os, const Usager & usager)
{
	os << " Usager :";
	os << "\t nom : " << usager.obtenirNom() << endl
	   << "\t prenom : " << usager.obtenirPrenom() << endl
	   << "\t codePostal: " << usager.obtenirCodePostal() << endl;
	return os;
}

