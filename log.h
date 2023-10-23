#ifndef LOG
#define LOG
#define LINE_SHOWN 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char mois[5];
    int jour;
    char heure[30];
    char session[20];
    char user[30];
} Session;

typedef struct{
	char name[100];
	char pswd[200];
	char connex[200];
}User;

////////// Utilisateur création
void signInput(char* url);
void addLog(char* nom, char* passwd);

////////// Utilisateur log
void loginInput(char* url);
int countUser();
User* getUsers();
bool inUsers(char* nom);
bool verifyUser(char* nom, char* passwd);

/////////// Connection
bool connected(char* nom);
void connection(char* nom);
void deconnection(char* nom);

////////// Bar de navigation
char* caseChange(char* ch);
void displayBar(char* nom);

////////// Page auth.log
void authLogPage(char* nom,char* u,Session* s,int c,int page);

////////// Session
char* getUser();
bool searchUser(Session* s,int c,char* u);
int countSession(char* u);
Session* getSession(char* u);

////////// Date
bool isB(int y);
int intMois(char* m);
int jourDuMois(int m,int y);
char* volana(char* m);
char* andro(int y,char* m,int jour);

////////// Tableau
void sessionTable(char* nom,Session*s,int c,int page);

////////// Pagination
int getNum();
void lienPagination(int c,char* nom,char* u);

#endif
