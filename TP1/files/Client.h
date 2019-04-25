//  client.h
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "panier.h"
using namespace std;
class Client
{
public:
	Client(string  nom, string prenom, int identifiant, string codePostal, long date);
	~Client();
	// methodes d'acces

	string obtenirNom() const;
	string obtenirPrenom() const;
	int obtenirIdentifiant() const;
	string obtenirCodePostal() const;
	long obtenirDateNaissance() const;

	// methodes de modification
	void modifierNom(string nom);
	void modifierPrenom(string prenom);
	void modifierIdentifiant(int identifiant);
	void modifierCodePostal(string codePostal);
	void modifierDateNaissance(long date);

	// autres méthodes
	void acheter(Produit * prod);
	void afficherPanier();
	void livrerPanier();


private:

	string nom_;
	string prenom_;
	int identifiant_;
	string codePostal_;
	long dateNaissance_;
	Panier *  monPanier_;
};
#endif /* client_h */




