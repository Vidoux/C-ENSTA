#include <stdio.h>
#include <stdlib.h>

#define STR_LEN   9 // 8+1
#define ARRAY_LEN   4

// 1/ lire le main, compiler le programme, ignorer le warning à la compilation
// 2/ expliquer ce qu'affichent les trois printf de print_array en utilisant sa
// troisième définition ne pas hésiter à lancer le programme plusieurs fois
// pour voir ce qui change
// 3/ pourquoi le programme plante-t-il ?

//void print_array(int array_len, int str_len, char to_print[][str_len]){
//void print_array(int array_len, int str_len, char (*to_print)[str_len]){
void print_array(int array_len, int str_len, char **to_print){
	printf("%p\n", to_print);
	printf("%p\n", to_print[0]);
	printf("%p\n", &to_print[0]);
	for(int i = 0; i < array_len; i++){
		printf("%s\n", to_print[i]);
	}
}

int main(int agrc, char *argv[]){

	// Est-ce qu'un tableau est vraiment parfaitement équivalent à un
	// pointeur ? On a vu que dans le cas d'un tableau à une dimension
	// cette approximation fonctionne, cependant on peut observer un
	// comportement surprenant avec sizeof() et &.
	
	char two_words[] = "Guten Tag";
	printf("two_words: %p, &two_words %p\n", two_words, &two_words);
	printf("two_words + 1: %p, &two_words + 1 %p\n", two_words + 1, &two_words + 1);
	printf("sizeof(two_words) %lu, sizeof(&two_words) %lu\n", sizeof(two_words), sizeof(&two_words));

	// Dans le cas de sizeof et &, two_words est vu pour ce qu'il est
	// vraiment: un tableau de 10 caractères dont on va respectivement
	// chercher la taille (10) et l'adresse. On a donc bien l'adresse
	// du tableau de 10 caractères qui est la même que le pointeur
	// vers ces 10 mêmes caractères (heureusement !), d'où le comportement
	// de &. Quand on fait "two_words + 1" on incrémente de 1 un pointeur
	// de caractères, donc on avance d'un octet. Par contre quand on fait
	// &two_words + 1 on incrémente de 1 l'adresse d'un tableau de 10 
	// caractères, donc on avance de 10 octets.
	// Dans toutes les autres utilisations il est vu comme un pointeur
	// vers des char, soit un char*. Ce comportement s'appelle
	// "array decay" ou en plus long "array to pointer decay" qu'on
	// pourrait tenter de traduire en "désintégration de tableaux vers
	// pointeur".
	// Si dans le cas des tableaux mono-dimensionnels on peut se contenter
	// de dire "c'est pareil", ce n'est pas du tout le cas pour les tableaux
	// de dimensions supérieures comme on va l'illustrer avec print_array
	// ci-dessous.
	
	char words_array[][STR_LEN] = {"Bonjour1", "Bonjour2", "Bonjour3", "Bonjour4"};
	print_array(ARRAY_LEN, STR_LEN, words_array);
	return 0;
}


