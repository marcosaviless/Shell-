#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/utsname.h>
#include <limits.h>

#include "list.h"

#define MAXLINEA 1024

tList list;

void imprimirPrompt();
void leerEntrada();
int trocearCadena(char *cadena, char *trozos[]);
void procesarEntrada(char *tr[]);

void cmd_chdir(char **);
void cmd_getcwd(char **);
void cmd_exit(char **);
void cmd_open(char **);
void cmd_close(char **);
void cmd_authors(char **);
void cmd_getpid(char **);
void cmd_date(char **);
void cmd_historic(char **);
void cmd_listopen(char **);
void cmd_infosys(char **);
void cmd_help(char **);
void cmd_quit(char **);
void cmd_bye(char **);


struct CMD{
    char *cmdname;
    void (*func)(char **);
};

struct CMD C[]={
        {"chdir", cmd_chdir},
        {"getcwd", cmd_getcwd},
        {"exit", cmd_exit},
        {"open", cmd_open},
        {"close", cmd_close},
        {"authors", cmd_authors},
        {"getpid", cmd_getpid},
        {"date", cmd_date},
        {"historic", cmd_historic},
        {"listopen", cmd_listopen},
        {"infosys", cmd_infosys},
        {"help", cmd_help},
        {"quit", cmd_quit},
        {"bye", cmd_bye},
        {NULL ,NULL}
};

void cmd_chdir(char *tr[]){
    //EN PRINCIPIO FUNCIONA
    char cwd[MAXLINEA];

    if (tr[0] == NULL){
        
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("Current working directory: %s\n", cwd);
        else printf("Error trying to find the directory\n");
    }
    else{
        if (chdir(tr[0]) == 0){
            if (getcwd(cwd, sizeof(cwd)) != NULL)
                printf("Directory successfully changed to: %s\n", cwd);
            else printf("Error trying to find the directory\n");
        }
        else printf("Error trying to change the directory\n");
    }
}

void cmd_getcwd(char *tr[]){
    char dir[MAXLINEA];

    if (getcwd(dir, MAXLINEA) != NULL)
        printf("Current working directory: %s\n", dir);
    else printf("Error trying to find the directory\n");
}

void cmd_exit(char *tr[]){
    exit(0);
}

void cmd_open(char *tr[]){
    printf("not yet implemented\n");
}

void cmd_close(char *tr[]){
    printf("not yet implemented\n");
}

void cmd_authors(char *tr[]){
    if (tr[0] == NULL)
        printf("Los autores son:\nFernando Otero: fernando.otero.lado\nMarcos Aviles: marcos.aviles\n");
    else if (!strcmp(tr[0], "-l"))
        printf("Los autores son:\nfernando.otero.lado\nmarcos.aviles\n");
    else if (!strcmp(tr[0], "-n"))
        printf("Los autores son:\nFernando Otero\nMarcos Aviles\n");
    else
        printf("command not found\n");
}

void cmd_getpid(char *tr[]){
    if (tr[0] == NULL)
        printf("Shell process ID: %d\n", getpid());
    else if (!strcmp(tr[0], "-p"))
        printf("Shell parent process ID: %d\n", getppid());
    else
        printf("command not found\n");
}

void cmd_date(char *tr[]){
    time_t t;
    t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);

    if(tr[0] == NULL)
        printf("Fecha y hora actual:%02d/%02d/%d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    else if (!strcmp(tr[0], "-d"))
        printf("Fecha actual:%02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    else if (!strcmp(tr[0], "-h"))
        printf("Hora actual:%02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    else
        printf("command not found\n");
}

void cmd_historic(char *tr[]){
    printf("not yet implemented\n");
}

void cmd_listopen(char *tr[]){
    printf("not yet implemented\n");
}

void cmd_infosys(char *tr[]){
    printf("not yet implemented\n");
}

void cmd_help(char *tr[]){
    printf("not yet implemented\n");
}

void cmd_quit(char *tr[]){
    exit(0); 
}

void cmd_bye(char *tr[]){
    exit(0); 
}

void imprimirPrompt(){
    printf("-->");
}

void leerEntrada(){
    char comando[MAXLINEA];
    fgets(comando, sizeof(comando), stdin);
    printf("entrada leida: %s\n", comando);
}

int trocearCadena(char *cadena, char *trozos[]){
    int i = 1;
    if ((trozos[0] = strtok(cadena, " \n\t")) == NULL)
        return 0;
    while ((trozos[i] = strtok(NULL, " \n\t")) != NULL)
        i++;
    return i;
}

void procesarEntrada(char *tr[]){
    bool encontrado = false;

    int i;
    if (tr[0] == NULL) return;
    for (i = 0; C[i].cmdname != NULL; i++){
        if (!strcmp(tr[0], C[i].cmdname)){
            (*C[i].func)(tr + 1);
            encontrado = true;
        }
    }
    if (!encontrado) printf("command not found\n");
}

int main(){
    int terminado = 0;

    char linea[MAXLINEA];
    char aux[MAXLINEA];
    char *tr[MAXLINEA / 2];

    //createList(&list);

    while (!terminado){
        imprimirPrompt();
        //leerEntrada();

        fgets(linea, MAXLINEA, stdin);

        strcpy(aux, linea);
        aux[strlen(aux)-1] = '\0'; //elimina el salto de línea

        if (trocearCadena(linea, tr) > 0){
            tItemL item;
            strcpy(item.cmdline, aux);
            //insertItem(item, &list);
            procesarEntrada(tr);
        }
    }

    return 0;
}