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
    erreur("Erreur lors de la demande de l'adresse ip");
  }

  if(adresse_ip_info->h_addrtype & AF_INET)
  {
    printf("type adresse IPv4 \n");
  }
  else if(adresse_ip_info->h_addrtype & AF_INET6 )
  {
    printf("type adresse IPv6 \n");
  }
  else
  {
    printf("type adresse inconnu \n");
  }
printf(" test length %d \n",adresse_ip_info->h_length);

  int i=0;
    printf(adresse_ip_info->h_aliases[i]);
    printf(" : ");
    if(adresse_ip_info->h_addr_list[i] != NULL)
    {
    printf(adresse_ip_info->h_addr_list[i] );

    printf("\n");
  }
printf("test de fin \n");

}

void erreur(char* message_erreur)
{
  int nombre_erreur = h_errno;
  fprintf(stderr,message_erreur);
  fprintf(stderr," %s \n",hstrerror(nombre_erreur));
  exit(EXIT_FAILURE);
}
