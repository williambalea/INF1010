#include "ProduitAuxEncheres.h"

ProduitAuxEncheres::ProduitAuxEncheres(double prix)
    : Produit(),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

ProduitAuxEncheres::ProduitAuxEncheres(Fournisseur *fournisseur, const string &nom,
                                       int reference, double prix)
    : Produit(fournisseur, nom, reference, prix),
      prixInitial_(prix),
      encherisseur_(nullptr)
{
}

double ProduitAuxEncheres::obtenirPrixInitial() const
{
    return prixInitial_;
}

Client *ProduitAuxEncheres::obtenirEncherisseur() const
{
    return encherisseur_;
}

void ProduitAuxEncheres::afficher() const
{
	Produit::afficher();
	cout << '\t' << '\t' << "prix initial: " << '\t' << prixInitial_ << endl
		<< '\t' << '\t' << "encherisseur: " << '\t' << encherisseur_->obtenirNom() << endl;
}

void ProduitAuxEncheres::modifierPrixInitial(double prixInitial)
{
    prixInitial_ = prixInitial;
}

void ProduitAuxEncheres::mettreAJourEnchere(Client *encherisseur, double nouveauPrix)
{
	if (encherisseur == nullptr) {				//deux cas : un c'est la réinit ( nullptr ) et l'autre c'est quand 
		prix_ = nouveauPrix;					// quelqu'un D'AUTRE encherit un montant plus ÉLEVÉ
		encherisseur_ = nullptr;
	}

	else if (encherisseur != nullptr) {
		if (encherisseur != encherisseur_) {
				if (encherisseur_ != nullptr)	//car le premier qui encherit le fait sur un encherisseur null au départ
					encherisseur_->enleverProduit(this);
				prix_ = nouveauPrix;
				encherisseur_ = encherisseur;
				encherisseur_->ajouterProduit(this);

			}
		}
	}



	/*if (encherisseur != encherisseur_) {
		if (nouveauPrix > prix_) {
			if (encherisseur_ != nullptr)
				encherisseur_->enleverProduit(this);
			prix_ = nouveauPrix;
			encherisseur_ = encherisseur;
			encherisseur_->ajouterProduit(this);

		}
			
	}*/

