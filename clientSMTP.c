#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define NOMBRE_ARGUMENT 2

void erreur(char * message_erreur, int nombre_erreur);

int main(int argc , char** argv)
{
  if(argc != NOMBRE_ARGUMENT + 1) // vérifie le nombre d'arguments
  {
    fprintf(stderr, "Erreur: nombre insuffisant d'argument. Nombre d'argument %d \n",NOMBRE_ARGUMENT);
    exit(EXIT_FAILURE);
  }
  char* address_internet = argv[1];// les arguments
  char* fichier_email = argv[2];

  struct hostent* adresse_ip_info = gethostbyname(adress_internet);

  if(adresse_ip_info == NULL)
  {
    int err = h_errno;
    erreur("Erreur lors de la demande de l'adresse ip",err);
  }

  if(adresse_ip_info->h_addrtype & AF_INET)
  {
    printf("type adresse IPv4 /n");
  }
  else if(adresse_ip_info->h_addrtype & AF_INET6 )
  {
    printf("type adresse IPv6 /n");
  }
  else
  {
    printf("type adresse inconnu /n");
  }

  for(int i=0; i < adresse_ip_info->h_length,++i)
  {
    printf(adresse_ip_info->h_aliases[i]);
    printf(" : ");
    printf(adresse_ip_info->h_addrtype[i] );
    printf("/n");
  }


}

void erreur(char* message_erreur, int nombre_erreur)
{
  fprintf(stderr,message_erreur);
  fprintf(stderr," %s /n",strerror(nombre_erreur));
  exit(EXIT_FAILURE);
}
