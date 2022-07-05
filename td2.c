#include <stdio.h>

int cmpR(char r, const char* tab, int size);
int contientR(char r, const char* tab, int size);
int copieTab(char* tab1, const char* tab2, int size);
int printTab(char* tab, int size);


int main(int argc, char** argv){
  printf("nom du fichier: %s \nNombre d'argumetn(s) envoyé(s): %d\n",*argv, argc );
  int a[10];
  a[0] = 5;
  int n = 4;
  int s = 0;
  for (int i = 0; i <= n; ++i)
      {
        s += i;
      }  
  printf("%d\n", s);

  int size = 5;
  char t1[] = "voici";
  char t2[] = "voico";
  
  copieTab(t1, t2, size);

  printTab(t1, size);

  char car = 'o';
  int chiffre = cmpR(car, t1, size);

  printf("le mot %s contient %d fois le caractère %c\n",t1, chiffre, car );


}


int contientR(char r, const char* tab, int size){
    for (int i = 0; i < size; ++i)
    {
      if(tab[i] == r){
        return 1;
      }
    }
    return 0;
}


int cmpR(char r, const char* tab, int size){
    int somme = 0;
    for (int i = 0; i < size; ++i)
    {
      if(tab[i] == r){
        somme ++;
      }
    }
    return somme;
}


int copieTab(char* tab1, const char* tab2, int size){
  for (int i = 0; i < size; ++i)
  {
    tab1[i]=tab2[i];
  }
  return 1;
}


int printTab(char* tab, int size){
  for (int i = 0; i < size; ++i)
  {
    printf("%c",tab[i]);
  }
  printf("\n");
  return 1;
}
