// ce programme travail sur l'alphabet {a,b,c} et va créer un automate qui va 
//reconnaitre ensemble des mots qui commencent par a , se terminent par b et qui contient un nombre pair de c
//date de création : 11/10/18
//resulats obtenue : Le programme répond a l'exercice demandé


JM1BFB2PN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ACCEPTATION 0
#define ECHEC       1

//tableau avec les états 
int noetats [5];

//tableau de transsition avec le nombre d'états et l'alphabet
int transition [5][3];

void construire_noetats()
{
  int i;

  /* Par defaut, ils sont en status ECHEC */
  for(i=0;i<5;i++) noetats[i]=ECHEC;

  /* On ajoute à la main l'etats ACCEPTATION */
  noetats[4]= ACCEPTATION;
}

void construire_transition()
{
  int i,j;		//i= noEtat et j=lettreTransition

  /* Par defaut, toutes les transitions sont a -1 donc impossible  */ 
  for(i=0;i<5;i++)
    for(j=0;j<3;j++)
      transition[i][j]=-1;

  /* On ajoute à la main les transitions */
  /* Note : a=0 , b=1 ,c=2 et c5=0 , c4=1 , c3=2 , c1=3 , c2=4 */


  /* transition C5 lettre a on arrive en C4 */
  transition[0][0]=1;
  
  /*transition C5 lettre b on arrive en C1 */
  transition[0][1]=3;
  
  /*transition C5 lettre c on arrive en C1 */
  transition[0][2]=3;
  
  /* transition C4 lettre a on arrive en C4 */
  transition[1][0]=1;
  
  /* transition C4 lettre b on arrive en C2 */
  transition[1][1]=4;
  
  /* transition C4 lettre c on arrive en C3 */
  transition[1][2]=2;
  
  /* transition C3 lettre a on arrive en C3 */
  transition[2][0]=2;
  
  /* transition C3 lettre b on arrive en C3 */
  transition[2][1]=2;
  
  /* transition C3 lettre c on arrive en C3 */
  transition[2][2]=1;
  
  /* transition C1 lettre a on arrive en C3 */
  transition[3][0]=3;
  
  /* transition C1 lettre b on arrive en C3 */
  transition[3][1]=3;

  /* transition C1 lettre c on arrive en C3 */
  transition[3][2]=3;
  
  /* transition C2 lettre a on arrive en C4 */
  transition[4][0]=1;
  
  /* transition C2 lettre b on arrive en C2 */
  transition[4][1]=4;
  
  /* transition C2 lettre c on arrive en C3 */
  transition[4][2]=2;
  
}

char lire(){
	char chaine;
	scanf("%s",&chaine);
	return chaine;
}


int translettre(char l)
{
  return((int)(l-'a'));
}

int automate()
{
  char lu; /* caractere lu */
  int e=0; /* etat courant */

  // vérification de l'états actuel , la lettre lu et états suivants 
  printf("Entrer un mot avec les lettres (a,b,c lettre par lettre) suivit d'un / pour finir votre mot :\n");
  
  lu=lire();
 
 while(lu !='/'){
  
  //verification des états de passage
  printf("état %d, lettre lue %c, prochaine état %d\n",e,lu,transition[e][translettre(lu)]);

   e=transition[e][translettre(lu)];
   if(e==-1) return(ECHEC);
   
   lu=lire();
  }

 return noetats[e];
}

int main()
{
  char lu;

  construire_noetats();
  construire_transition();

  if(automate()==ECHEC) printf(" désolé votre mot n'est pas reconnu !\n"); else printf(" Felicitaiton mot Reconnu !\n");


}



