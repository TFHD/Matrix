#!/bin/bash

check_one() {
    num=$(printf "%02d" "$1")
    dir="ex${num}"
    if [ -d "$dir" ]; then
        cd "$dir"
        make
        valgrind --show-leak-kinds=all --leak-check=full ./$dir
        make fclean
        cd ..
    else
        echo "Le dossier $dir n'existe pas."
    fi
}

if [ "$#" -eq 0 ]; then
    echo "Usage : $0 <numéro d'exercice ou 'all'>"
    echo "Exemple :"
    echo "  $0 1     # Compile et vérifie ex01"
    echo "  $0 all   # Compile et vérifie tous les exercices"
    exit 1
elif [ "$1" == "all" ]; then
    for i in $(seq 0 14); do
        check_one "$i"
    done
elif [[ "$1" =~ ^[0-9]+$ ]] && [ "$1" -ge 0 ] && [ "$1" -le 14 ]; then
    check_one "$1"
else
    echo "Argument invalide. Utilisez un nombre entre 0 et 14 ou 'all'."
    exit 1
fi