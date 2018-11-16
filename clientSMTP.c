#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NOMBRE_ARGUMENT 2

void erreur(char * message_erreur);

int main(int argc , char** argv)
{
  if(argc != NOMBRE_ARGUMENT + 1) // vérifie le nombre d'arguments
  {
    fprintf(stderr, "Erreur: nombre insuffisant d'argument. Nombre d'argument %d \n",NOMBRE_ARGUMENT);
    exit(EXIT_FAILURE);
  }
  char* address_internet = argv[1];// les arguments
  char* fichier_email = argv[2];

  struct hostent* adresse_ip_info = gethostbyname(address_internet);

  if(adresse_ip_info == NULL)
  {
    fprintf(stderr,"Erreur lors de la demande de l'adresse ip : %s \n",hstrerror(h_errno));
  }
  
return 0;
}

void erreur(char* message_erreur)
{
  int nombre_erreur = errno;
  fprintf(stderr,message_erreur);
  fprintf(stderr," %s \n",hstrerror(nombre_erreur));
  exit(EXIT_FAILURE);
}
