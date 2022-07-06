#include <stdio.h>
#include <stdlib.h>
#include <s
#include "tdtp3.h"


//
// Created by Tanguy on 30/06/2022.
//

/*
 *Traitement de toutes les questions du TD/TP3
*/
int main(int argc, char** argv){

//-------------Q7-------------
    int size;
    int res;
    printf("Entrez le nombre de valeurs: ");
    res = scanf("%d", &size);
    
    //Si res == 0 le scanf n'as pas bien fonctionné
    if (res == 0) {
       printf("Erreur");
       return 5;
    }
    int tab[size];

    //Q8: passage du scan des valeurs dans une fonction
    if(size > 0){
        scan_tab_int(size, tab);
        //calcul de la moyenne et affichage
        float moyenne = average_int_array(tab, size);
        printf("La moyenne des %d elements entres est: %f\n", size, moyenne);
    }
    else{
        printf("Mauvaise taille entrée, passage à la suite...\n");
    }
//--------------------------

//-------------Q9-------------
    char chaine[] = "il faut un espace à la fin sinon le dernier mot n'est pas compté ";

    const int nb_mots = getNbMots(chaine);
    //Initialisation d'un tableau avec suffisament de "cases" pour stocker tous les mots séparément
    char *liste_mots[nb_mots];
    split(chaine, liste_mots, nb_mots);

    //Affichage du résultat du traitement pour vérification
    printf("Nombre de mots: %d\n", nb_mots);
    for(int i = 0; i < nb_mots; ++i){
        printf("Mot n %d: %s\n", i, liste_mots[i]);
    }

}


/*
 * Q4
 */
float  average_int(int a, int b){
    return ((float)(a+b))/2;
}


/*
 * Q4 (suite)
 */
float average_double(double a, double b){
    return ((float)(a+b))/2;
}


/*
 * Q5
 */
float average_int_array(const int *tab, int size){
    int somme = 0;
    for (int i = 0; i < size; ++i){
        somme += tab[i];
    }
    return (float)somme/(float)size;
}


/*
 * Q6
 */
float  average_int2(int a, int b){
    int tab[] = {a, b};
    return average_int_array(tab, 2);
}


/*
 * Q8
 */
int scan_tab_int(int size,int* tab){
    int res;
    for(int i = 0; i < size; ++i){
        printf("Entrez une valeur: ");
        res = scanf("%d", &tab[i]);
        if (res == 0) {
            printf("Erreur");
            return 5;
        }

    }
    return 0;
}


/*
 * Q9
 */
int split(const char* chaine, char *liste_mots[], int nbMots){
    //indice_chaine permet de repérer l'emplacement dans la chaine
    int indice_chaine = 0;

    for(int i = 0; i<nbMots; ++i){
        int size_mot = 0;
        int j = 0;

        //Pour chaque mot, on récupère sa taille en comptant le nombre de caractère avant de trouver un espace
        while(chaine[indice_chaine+j] != ' '){
            size_mot ++;
            j++;
        }

        //On alloue un espace mémoire de la bonne taille pour stocker le mot
        char *mot = (char*)malloc((size_mot+2) * sizeof(char));

        //copie des caractère du mot "courant" dans le tableau dédié à ce mot
        for(int k = 0; k < size_mot; ++k){
            mot[k] = chaine[indice_chaine];
            indice_chaine += 1;
        }

        indice_chaine += 1;
        //Ajout du caractère "fin de chaine"="\0"
        mot[size_mot] = '\0';

        //Ajout du mot dans la liste de mot
        liste_mots[i] = mot;
    }
    return 1;
}

/*
 *Retourne le nombre de mots dans une chaine de caractère (basé sur les espaces)
 */
int getNbMots(const char *chaine) {
    char caractere = chaine[0];
    int cmp = 0;
    int i = 0;
    while(caractere != '\0'){
        if(caractere == ' '){
            cmp ++;
        }
        ++i;
        caractere = chaine[i];
    }
    return cmp;
}





