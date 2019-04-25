/**************************************************
* Titre: Travail pratique #1 - Produit.cpp
* Date: 1 février 2018
* Auteur: Dalyna Pak et William Balea
**************************************************/

#include "Produit.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;



Produit::Produit()
{
	nom_ = "outil";
	reference_ = 0;
	prix_ = 0.0;
}

Produit::Produit(string nom, int reference, double prix)
{
	nom_ = nom;
	reference_ = reference;
	prix_ = prix;
}

string Produit::obtenirNom()const
{
	return nom_;
}

int Produit::obtenirReference()const
{
	return reference_;
}

double Produit::obtenirPrix()const
{
	return prix_;
}

void Produit::modifierNom(string nom)
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

void Produit::afficher()const
{
	cout << setw(25) << left << nom_ << '\t' << reference_ << '\t' << setprecision(2) << fixed << prix_ << " " << '$' << endl;
}



