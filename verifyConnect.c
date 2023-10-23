#include "log.h"

int main(){
	
    char nom[100];
    char passwd[500];
    char* auth = getenv("QUERY_STRING");
    
    sscanf(auth,"%*[^=]=%[^&]&%*[^=]=%[^&]",nom,passwd);
    if(connected(nom)){
		printf("Location: http://www.cgi-scr.com/log/login.cgi?error=connexion\n\n");
	}
    else if(!verifyUser(nom,passwd)){
    	printf("Location: http://www.cgi-scr.com/log/login.cgi?error=incorrect\n\n");
		//printf("Location: http://www.cgi-script.com/l/login.cgi?error=incorrect\n\n");		// Tsy mitovy
	}
	else{
		connection(nom);
	}
}
