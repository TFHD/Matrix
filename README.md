# Matrix 🚀

## Présentation 📝

Ce projet est une collection d’exercices et de modules C++ autour de la manipulation des vecteurs et des matrices, regroupés par dossiers (`ex00`, `ex01`, ..., `ex13`). Il vise à implémenter et tester différentes opérations mathématiques fondamentales en algèbre linéaire telles que la combinaison linéaire, le produit scalaire (dot product), l’interpolation linéaire, le calcul de norme, le rang, la trace, la réduction en forme échelonnée, etc.

Chaque dossier contient un ou plusieurs fichiers sources (`.cpp`) avec des tests unitaires illustrant l’utilisation des fonctions et classes développées, ainsi que des `Makefile` pour la compilation.

---

## Fonctionnalités principales ✨

Voici un aperçu des fonctionnalités implémentées par exercice :

- **ex01** : Calcul de combinaison linéaire de vecteurs avec des coefficients donnés.
- **ex02** : Interpolation linéaire (`lerp`) entre deux vecteurs.
- **ex03** : Produit scalaire (dot product) de deux vecteurs.
- **ex04** : Calcul des différentes normes d’un vecteur, dont la norme infinie (`norm_inf`).
- **ex08** : Calcul de la trace d’une matrice (somme des éléments diagonaux).
- **ex10** : Réduction de matrice en forme échelonnée (`row_echelon`).
- **ex13** : Calcul du rang de matrices (identité, matrices nulles, lignes proportionnelles, matrices rectangulaires).

Chaque fonctionnalité est testée avec divers cas : matrices carrées, rectangulaires, vecteurs de tailles différentes, gestion des erreurs, etc. ✅

---

## Exemple d’utilisation 💡

Voici quelques exemples de ce que permet le projet :

- Calculer le rang d’une matrice :
  ```cpp
  Matrix<float> m({{1, 2}, {2, 4}});
  std::cout << "Rang(M) = " << m.rank() << std::endl;
  ```
- Combiner plusieurs vecteurs linéairement :
  ```cpp
  std::vector<Vector<float>> vectors = {v1, v2, v3};
  std::vector<float> coefs = {2.0, -1.0, 0.5};
  Vector<float> res = linear_combination(vectors, coefs);
  ```
- Calculer le produit scalaire :
  ```cpp
  Vector<int> v1({1, 2, 3});
  Vector<int> v2({4, 5, 6});
  std::cout << v1.dot(v2) << std::endl;
  ```
- Réduire une matrice en forme échelonnée :
  ```cpp
  Matrix<float> m({{2, 4, 2}, {4, 8, 6}, {6, 12, 10}});
  Matrix<float> echelon = m.row_echelon();
  ```

---

## Compilation 🛠️

Chaque dossier possède son propre `Makefile` :
```sh
cd ex01
make
./ex01
```
Les options permettent de compiler les sources et de lancer les tests associés.

---

## Organisation du code 📁

Le projet est organisé par exercices :
- `exNN/sources/exNN.cpp` : Fichier source principal
- `exNN/Makefile` : Makefile, script de compilation

Les classes principales sont probablement :
- `Vector<T>` : Représentation de vecteurs génériques
- `Matrix<T>` : Représentation de matrices génériques

---

## Auteur 👤

Projet réalisé par [sabartho](https://github.com/TFHD).
