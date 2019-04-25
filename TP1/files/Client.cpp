/**************************************************
* Titre: Travail pratique #1 - Client.cpp
* Date: 1 février 2018
* Auteur: Dalyna Pak et William Balea
**************************************************/

#include "Client.h"
#include <iostream>
#include <string>

Client::Client(string  nom, string prenom, int identifiant, string codePostal, long date)
{
	monPanier_ = nullptr;
	nom_ = nom;
	prenom_ = prenom;
	identifiant_ = identifiant;
	codePostal_ = codePostal;
	dateNaissance_ = date;
}

Client::~Client() {
	delete monPanier_;
	monPanier_ = nullptr;
}

string Client::obtenirNom() const
{
	return nom_;
}

string Client::obtenirPrenom() const
{
	return prenom_;
}

int Client::obtenirIdentifiant() const
{
	return identifiant_;
}
string Client::obtenirCodePostal() const
{
	return codePostal_;
}
long Client::obtenirDateNaissance() const
{
	return dateNaissance_;
}

void Client::modifierNom(string nom)
{
	nom_ = nom;
}

void Client::modifierPrenom(string prenom)
{
	prenom_ = prenom;
}
void Client::modifierIdentifiant(int identifiant)
{
	identifiant_ = identifiant;
}
void Client::modifierCodePostal(string codePostal)
{
	codePostal_ = codePostal;
}
void Client::modifierDateNaissance(long date)
{
	dateNaissance_ = date;
}

void Client::acheter(Produit * prod)
{

	if (monPanier_ == nullptr)
		monPanier_ = new Panier(4); // Si le panier n'existe pas, on crée un objet Panier de 4 produits

	monPanier_->ajouter(prod);


}


void Client::afficherPanier() {
	if (monPanier_ != nullptr) { //Si le panier n'est pas nul, on affiche celui-ci
		monPanier_->afficher();
	}
}

void Client::livrerPanier() {
	cout << "-----------------------------------------------" << endl;
	cout << "Mode de livraison: Livraison gratuite (7 jours)" << endl;
	cout << "===============================================" << endl;
	delete[] monPanier_; //supprimer le Panier actuel du client
	monPanier_ = nullptr;
}


