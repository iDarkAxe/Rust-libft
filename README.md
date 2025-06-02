# Rust-libft #

## Introduction ##

Tentative de reproduction de la libft en Rust.
On écrit toujours du C, mais la bibliothèque n'est pas en C.

L'outil fabrique à partir des fichiers .rs le header en .h, compatible avec du code C

## Comment utiliser Rust-lifbt ? ##

```sh
make
```

Tout devrait compiler, vous pouvez vous inspirer du Makefile pour comprendre comment ça marche.

## Comment ajouter des fonctions ? ##

Le plus simple est de se calquer sur la façon dont on a codé notre lifbt en C, et de 'le convertir' en rust.

## Comment est généré le header ? ##

L'outil suivant est notre allié pour cette tâche :
*<https://github.com/mozilla/cbindgen>*
