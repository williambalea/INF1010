#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	cout << "PROFILS" << endl;
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		usagers_[i]->afficherProfil();
	}
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double affaires = 0.0;
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		affaires += usagers_[i]->obtenirTotalAPayer();
	}
	return affaires;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
	bool pasDeDoublons = true;
	for (unsigned int i = 0; i < usagers_.size(); i++)
		if (usagers_[i] == usager)
			pasDeDoublons = false;
	if (pasDeDoublons == true)
		usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()
{
	for (unsigned int i = 0; i < usagers_.size(); i++)
	{
		usagers_[i]->reinitialiser();
	}

}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (montant > produit->obtenirPrix())
		produit->mettreAJourEnchere(client, montant);
}
