#include "log.h"
int main(){
	char* url = malloc(100*sizeof(char));
	char nom[100];
	char passwd[200];
	
	url = getenv("QUERY_STRING");
	
	if(*url != 0){
		if(strstr(url,"disconnect=")!=NULL){
			sscanf(url,"disconnect=%s",nom);
			deconnection(nom);
		}
		else if(strstr(url,"error=")==NULL){
			sscanf(url,"nom=%[^&]&passwd=%s",nom,passwd);
			if(inUsers(nom)){
				printf("Location: http://www.cgi-scr.com/log/sign.cgi?error=name\n\n");
				//printf("Location: http://www.cgi-script.com/l/sign.cgi?error=name\n\n");		// Tsy mitovy
			}
			else{
				addLog(nom,passwd);
			}
		}
	}
	printf("Content-Type: text/html\n\n");
	
	loginInput(url);
	
	return 0;
}
