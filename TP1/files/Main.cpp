/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 1 f�vrier 2018
* Auteur: Dalyna Pak et William Balea
**************************************************/

/**

Questions:


1.	Client-Panier : Composition
Le panier fait partie de client. Si le client est d�truit, un panier qui n�appartient � personne serait illogique.
Donc, si on d�truit le client, on d�truit le panier. En d�autres mots, un panier doit obligatoirement avoir un client pour exister.

2.	Rayon-produit : agr�gation
Les produits font partie d'un rayon. Si le rayon est d�truit, les produits qui y �taient ne sont plus dans un rayon,
mais ceux-ci ont une vie en elle-m�me. Donc, dans le contexte, les produits existent quand m�me sans un rayon.
En d�autres mots, si le rayon est d�truit, cela ne d�truit pas n�cessairement les produits.


**/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

void PrintCenteredText(char* phrase) // Une fonction pour seulement centrer un texte (ici "Votre facture")
{
	for (int i = 0; i < ((48 - strlen(phrase)) / 2) ; i++) cout << " ";
	cout << phrase << endl;
}

int main()
{
	//C'est � vous de voir si vous devez allouer dynamiquement ou non les �l�ments

	//1-  Creez 15 objets du classe produit

	Produit produit1,
		produit2("Tournevis", 51, 10.99),
		produit3("Perceuses sans fil", 84, 149.00),
		produit4("Marteau", 33, 12.98),
		produit5("Pinceau", 24, 10.00),
		produit6("Echelle", 15, 11.00),
		produit7("Ampoules", 76, 10.99),
		produit8("Lampes de poche", 87, 11.99),
		produit9("Ponceuses", 10, 39.99),
		produit10("Ancrages", 41, 19.99),
		produit11("Scie", 26, 16.99),
		produit12("Vis", 92, 13.99),
		produit13("Grattoir", 55, 18.99),
		produit14("Ruban impermeabilisant", 16, 16.99),
		produit15("Pelle", 54, 19.99);
	

	//2-  Modifiez le nom, la r�f�rence, le prix de  troisieme objet Produit cr��
	//   afficher les attributs de cet objet Produit
	cout << "===============================================" << endl;
	PrintCenteredText(" Votre facture "); 
	cout << "===============================================" << endl;
	cout << " Aubaines de la semaine (seulement en ligne)  " << endl;
	cout << "-----------------------------------------------" << endl;
	produit3.modifierNom("Perceuses avec fil");
	produit3.modifierReference(99);
	produit3.modifierPrix(64.95);
	produit3.afficher();

	//3-  Creez un objet du classe rayon � l'aide du constructeur par d�faut
	Rayon rayon;

	//4-  Modifiez la cat�gorie  du rayon
	rayon.modifierCategorie("Construction");

	// 5- Ajouter 6 produits de  voret chaoix dans le rayon cr��

	rayon.ajouterProduit(&produit2);
	rayon.ajouterProduit(&produit3);
	rayon.ajouterProduit(&produit4);
	rayon.ajouterProduit(&produit5);
	rayon.ajouterProduit(&produit6);
	rayon.ajouterProduit(&produit7);



	// 6- afficher le contenu du rayon
	rayon.afficher();

	//7-  Creez un objet de classe client � l'aide du constructeur
	Client client("Pak", "Dalyna", 1865507, "J7G3E9", 199708);


	//8-  afficher l'etat des attributs du client
	cout << "Destinataire : ";
	
		cout << client.obtenirNom() << " "
			 << client.obtenirPrenom() << " "
			 << client.obtenirIdentifiant() << " "
			 << client.obtenirCodePostal() << " "
			 << client.obtenirDateNaissance() << endl;
		
		cout << "===============================================" << endl;

	//9-   Le client achete 9 produits
		 
	client.acheter(&produit2);
	client.acheter(&produit3);
	client.acheter(&produit4);
	client.acheter(&produit5);
	client.acheter(&produit6);
	client.acheter(&produit7);
	client.acheter(&produit8);
	client.acheter(&produit9);
	client.acheter(&produit10);

	//10- Afficher le contenu du panier du client
	client.afficherPanier();
	//11- livrer le panier du client
	client.livrerPanier();

	//12- afficher le contenu du panier du client
	client.afficherPanier();
	//13-  terminer le programme correctement
	return 0;
}