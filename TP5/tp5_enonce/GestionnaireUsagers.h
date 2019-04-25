/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "ProduitAuxEncheres.h"
#include "Client.h"

// TODO : Créer la classe GestionnaireUsager
class GestionnaireUsagers : public GestionnaireGenerique<Usager, set<Usager*>, AjouterUsager, SupprimerUsager>
{
public:
	double obtenirChiffreAffaires() const;
	void encherir(Client *client, ProduitAuxEncheres *produit, double montant) const;
	void reinitialiser();
	void afficherProfils() const;
};
