#include <stdio.h>

int isTriangle(int a, int b, int c);

int main(int argc, char** argv){

    float a=3;
    float b=2;
    float c=a/b;
    printf("%.1f divisé par %.1f vaut %f\n",a, b, c );

    printf("%d\n",4-3*2-1 );
    printf("%d\n",8/4+2*10%5+3+2/1);
    printf("%d\n",2+3*6+7*2*-2/4);
    float z = 10 -2; int y = 4 * 2; int x = z < y++;
    printf("%d\n",x);

    x = 3 > 2 > 1; y = x ++ + 1; int z2 = x||!y;
    printf("%d\n", z2);

//      printf("%f\n", x);
//      x = 3 > 2 > 1 ; y = x ++ + 1 ; z = x | | ! y ;
//      printf("%f\n", z);
    int a2 = 6;
    int b2 = 1;
    int c2 = 1;
    if(isTriangle(a2, b2, c2)){
        printf("TRIANGLE\n");
    }else{
        printf("PAS TRIANGLE\n");
    }

    float* p_a = &a;
    *p_a = 55;
    printf("%f\n", a);

    char tab_char[] = {'u', 'n', '_', 'p', 'o','i','n','t','e','u','r', '\0'};
    printf("adresse: %p valeur: %s\n", &tab_char, tab_char);
    char val ='0';
    int taille=0;
    while (val != '\0'){
        val = tab_char[taille];
        taille ++;
    }
    printf("taille: %d\n", taille);

    tab_char[8] = '\0';
    printf("%s\n", tab_char);
    char* p_9_e = tab_char+8;
    *p_9_e = 'e';
    printf("%s\n", tab_char);
}


int isTriangle(int a, int b, int c){
	if (a > b+c){
		return 0;
	}
	if (b > a+c){
		return 0;
	}
	if (c > b+a){
		return 0;
	}
	return 1;
}