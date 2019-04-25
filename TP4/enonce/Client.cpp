#include "Client.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{
	double total = 0.0;
	for (unsigned int i = 0; i < panier_.size(); i++)
		total += panier_[i]->obtenirPrix();
	return total;
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
	Usager::afficherProfil();
	cout << '\t' << '\t' << "code client:" << '\t' << codeClient_ << endl
		 << '\t' << '\t' << "panier: " << '\t' << panier_.size() << " elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
	while( !panier_.empty() )
	{
		if (dynamic_cast<ProduitAuxEncheres*>(panier_.back()) != nullptr) {
			dynamic_cast<ProduitAuxEncheres*>(panier_.back())->mettreAJourEnchere(nullptr, dynamic_cast<ProduitAuxEncheres*>(panier_.back())->obtenirPrixInitial());
		}
		//panier_.pop_back();
		this->enleverProduit(panier_.back());
	}

}
