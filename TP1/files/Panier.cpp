/**************************************************
* Titre: Travail pratique #1 - Panier.cpp
* Date: 1 février 2018
* Auteur: Dalyna Pak et William Balea
**************************************************/

#include "Panier.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


Panier::Panier(int capacite)
{
	contenuPanier_ = new Produit*[capaciteContenu_];
	for (int i = 0; i < capaciteContenu_; i++)
		contenuPanier_[i] = nullptr;
	nombreContenu_ = 0;
	capaciteContenu_ = capacite;
	totalAPayer_ = 0.0;

}

Produit** Panier::obtenirContenuPanier() const
{
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() const
{
	return nombreContenu_;
}

double Panier::obtenirTotalApayer() const
{
	return totalAPayer_;
}

void Panier::ajouter(Produit * prod)
{
	if (nombreContenu_ == capaciteContenu_) {

		Produit ** contenuPanierAncien = new Produit*[capaciteContenu_];
		contenuPanierAncien = contenuPanier_;
		capaciteContenu_ *= 2;
		contenuPanier_ = new Produit*[capaciteContenu_]; //Création du contenuPanier avec la nouvelle capacité
		for (int i = 0; i < nombreContenu_; i++)
			contenuPanier_[i] = contenuPanierAncien[i]; //On copie l'ancien contenu du panier dans le nouveau panier qui a une nouvelle capacité
	} 
	
	contenuPanier_[nombreContenu_++] = prod;
	totalAPayer_ += prod->obtenirPrix();

}



void Panier::livrer()
{
	for (int i = 0; i < nombreContenu_; i++)
		delete contenuPanier_[i];	//Supprimer le nombre de contenu du contenu panier
	delete[] contenuPanier_;	// Supprimer le contenu du panier
	contenuPanier_ = nullptr;
	nombreContenu_ = 0;
	totalAPayer_ = 0.0;
	capaciteContenu_ = 0;
}

void Panier::afficher()
{
	for (int i = 0; i < nombreContenu_; i++)
		contenuPanier_[i]->afficher();
	cout << "===============================================" << endl;
	cout << setw(38) <<"Total :" << " " << totalAPayer_ << " " << "$" << endl; 

}
