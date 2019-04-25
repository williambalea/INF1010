/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include "Usager.h"
#include "Produit.h"

// TODO : Créer le FoncteurEgal
template<typename T>
class FoncteurEgal {
public:
	FoncteurEgal(T* t) : t_(t)
	{
	}
	bool operator()(pair<int, T*> egal)
	{
		return (egal.second == t_);
	}
private:
	T* t_;
};

// TODO : Créer le FoncteurGenerateurId
class FoncteurGenerateurId {
public:
	FoncteurGenerateurId()
	{
		id_ = 0;
	}
	int operator()()
	{
		return id_++;
	}
private:
	int id_;
};


// TODO : Créer le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) : pourcentage_(pourcentage)
	{
	}
	void operator()(pair<int, Produit*> rabais)
	{
		double nouveauPrix = ((100 - pourcentage_) / 100) * rabais.second->obtenirPrix();			//énoncé veut prix brut ???
		rabais.second->modifierPrix(nouveauPrix);
	}
private:
	int pourcentage_;
};

// TODO : Créer le FoncteurIntervalle
class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double inferieur, double superieur) : borneInf_(inferieur), borneSup_(superieur)
	{
	}
	bool operator()(pair<int, Produit*> intervalle)
	{
		return (intervalle.second->obtenirPrix() <= borneSup_ && intervalle.second->obtenirPrix() >= borneInf_) ? 1:0;
	}
private:
	double borneInf_;
	double borneSup_;
};

// TODO : Créer le Foncteur AjouterProduit
class AjouterProduit
{
public:
	AjouterProduit(multimap<int, Produit*> &map) : multimap_(map)
	{
	}
	multimap<int, Produit*>& operator()(Produit* prod)
	{
		multimap_.insert(make_pair(prod->obtenirReference(), prod));
		return multimap_;
	}
private:
	multimap<int, Produit*> &multimap_;
};

// TODO : Créer le Foncteur SupprimerProduit
//template<class FoncteurEgal>
class SupprimerProduit
{
public:
	SupprimerProduit(multimap<int, Produit*> &map) : multimap_(map)
	{
	}
	multimap<int, Produit*> & operator()(Produit* prod)
	{
		multimap<int, Produit*>::iterator it;

		it = find_if(multimap_.begin(), multimap_.end(), FoncteurEgal<Produit>(prod));
		if ((*it).second == prod)
			multimap_.erase(it);
		return multimap_;
	}
private:
	multimap<int, Produit*> &multimap_;
};



/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/
class AjouterUsager {
public:
	AjouterUsager(set<Usager*> &usager) : set_(usager) {}
	set<Usager*>& operator()(Usager* usager)
	{
		set_.insert(usager);
		return set_;
	}
private:
	set<Usager*> &set_;
};


//template<class FoncteurEgal>
class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*> &usager) : set_(usager) {}
	set<Usager*> operator()(Usager* usager)
	{
		set<Usager*>::iterator it = find_if(set_.begin(), set_.end(), FoncteurEgal<Usager>(usager));
		if (*it == usager) {
			set_.erase(it);
			return set_;
		}
		else
			return set_;
	}
private:
	set<Usager*> &set_;
};


//TODO : Créer le Foncteur AjouterUsager
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
