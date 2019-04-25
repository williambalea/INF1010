/**************************************************
* Titre: Travail pratique #1 - rayon.cpp
* Date: 1 février 2018
* Auteur: Dalyna Pak et William Balea
**************************************************/

#include "Rayon.h"
#include <iostream>
#include <string>
using namespace std;



Rayon::Rayon()
{
	categorie_ = "inconnue";
	tousProduits_ = new Produit*[capaciteProduits_];	
	for (int i = 0; i <= capaciteProduits_; i++)
		tousProduits_[i] = nullptr;

	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}

Rayon::Rayon(string cat)
{
	categorie_ = cat;
	tousProduits_ = new Produit*[capaciteProduits_];
	capaciteProduits_ = 0;
	nombreProduits_ = 0;
}

string Rayon::obtenirCategorie() const
{
	return categorie_;
}

Produit** Rayon::obtenirTousProduits() const
{
	return tousProduits_;
}

int Rayon::obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

int Rayon::obtenirNombreProduits() const
{
	return nombreProduits_;
}

void Rayon::modifierCategorie(string cat)
{
	categorie_ = cat;
}

void Rayon::ajouterProduit(Produit * produit)
{

	if (capaciteProduits_ < 1) //Si la capacité est nulle, on crée 5 places
	{
		capaciteProduits_ += 5;
		tousProduits_ = new Produit*[capaciteProduits_];		
	}
	else if (nombreProduits_ == capaciteProduits_) {
		capaciteProduits_ += 5;
		Produit** tousProduitsAncien = nullptr;	//Initialiser le pointeur
		tousProduitsAncien = tousProduits_;
		tousProduits_ = new Produit*[capaciteProduits_]; //Création de tousProduit avec la nouvelle capacité
		for (int i = 0; i < nombreProduits_; i++)
			tousProduits_[i] = tousProduitsAncien[i]; //On copie ce qu'il avait dans tousProduitsAncien dans tousProduit qui a une nouvelle capacité plus grande
		delete[] tousProduitsAncien;
		tousProduitsAncien = nullptr;
	}
	tousProduits_[nombreProduits_++] = produit;
}

void Rayon::afficher() const
{
	cout << "===============================================" << endl;
	cout << "Magasiner par rayon :" << " " << categorie_ << endl;
	cout << "===============================================" << endl;
	for (int i = 0; i < nombreProduits_; i++)
		tousProduits_[i]->afficher();
	//cout << " Ce rayon contient" << " " << nombreProduits_<< "produits ayant une capacité de" << " " << capaciteProduits_ << endl; 
	// La ligne ci-dessus permet de vérifier si la fonction ajouterProduit marche, donc de comparer le nombreProduits avec la capaciteProduits 
	cout << "===============================================" << endl;
}


