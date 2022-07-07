#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student
{
    // le contenu de la structure
    char *name;         
    int age;                        

    // où trouver la suite
    struct _student* next;
} student_t;


int main(int argc, char* argv[]){                       
    student_t student_list;
    student_t* current_student_ptr;
    char *names[] = {"Foo", "Bar", "Baz"};
    int ages[] = {42, 45, 49};

    // on peut initialiser, ou pas, le point d'entrée comme un élément valide
    // ici "ou pas", c'est plus simple à gérer car la liste contient toujours
    // au moins un élément fantôme qu'on prendra garde à "sauter" lors du parcours.
    student_list.name = NULL;
    student_list.age = -1; 
    student_list.next = NULL; 

    // on pointe vers l'étudiant courant (permet de généraliser le code ci-dessous)
    // ici la liste est vide donc on pointe vers l'étudiant "fantôme"
    current_student_ptr = &student_list;

    // une fois que current_student_ptr pointe bien vers le dernier élève créé on
    // peut dérouler le code ci-dessous quel que soit l'état de la liste
    for (int i = 0; i < 3; i++){
        // allocation mémoire d'un nouvel étudiant 
        current_student_ptr->next = (student_t*)malloc(sizeof(student_t));
        // déplacament du pointeur de l'étudiant courant vers l'étudiant créé
        current_student_ptr = current_student_ptr->next;
        // initialisation du contenu de l'étudiant
        current_student_ptr->name = names[i];
        current_student_ptr->age = ages[i];
        // pour l'instant c'est le dernier étudiant
        current_student_ptr->next = NULL; 
    }

    // exemple de parcours de la liste
    current_student_ptr = student_list.next;
    while(current_student_ptr){
        printf("%s %d\n", current_student_ptr->name, current_student_ptr->age);
        current_student_ptr = current_student_ptr->next;
    }
    
    //return 0;

// exercices:
    // q0: supprimer l'étudiant nommé "Bar" en gardant une liste cohérente, le vérifier en affichant la liste
    current_student_ptr = student_list.next;
    student_t* prev_to_delete_student_ptr = NULL
    while(current_student_ptr ){
        if (strcmp(current_student_ptr->next->name, "Bar")){
            prev_to_delete_student_ptr = current_student_ptr;
        }
        current_student_ptr = current_student_ptr->next;
    }
    printf("%s\n",current_student_ptr->next->name );

    // Pour la suite partir éventuellement sur un nouveau fichier dans lequel on fera des copier/coller judicieux
    // q1: écrire une fonction qui renvoie une liste contenant uniquement un étudiant fantôme

    // q2: écrire une fonction qui rajoute un nom/age en fin d'une liste d'élèves passée en argument, la fonction renvoie 1 si l'ajout se 
    // passe bien, 0 si l'age ou le nom sont invalides (nom de 0 lettre, age négatif, etc).

    // q2bis: écrire une fonction qui rajoute plusieurs noms/ages en fin de liste en appelant q2, la fonction renvoie le nombre
    // d'élèves qui ont été ajoutés

    // q2ter: bien évidemment tester si ça marche avec les étudiants Foo, Bar et Baz

    // q3: faire une fonction qui affiche le contenu de la liste

    // q4: écrire une fonction qui prend une liste en paramètre, renvoie son nombre d'éléments et modifie une variable
    // passée en paramètre pour qu'elle pointe vers le dernier élément
    // q5: écrire une fonction qui prend en paramètre le nom d'un étudiant, son age, une position dans la liste et une liste d'étudiants
    //  et ajoute cet étudiant dans la liste à la position demandée

    return 0;
    
 
}
