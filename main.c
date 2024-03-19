#include<stdio.h>
#include<string.h>
typedef struct {
    char nome[61];
    char cognome[61];
} Contatto;


int main() {
    Contatto contatti[100];
    // menu principale
    int opt;
    int gonext=0;
    int i=0;
    FILE *fp;
    do {
        printf("1- Salva un contatto\n");
        printf("2- Leggi il file \n");
        printf("0- Esci dal programma\n");
        scanf("%d", &opt);
        fflush(stdin);
        switch(opt){
            case 1:
                //controllo se posso usare il file
                fp=fopen("rubrica.txt","a");
                if(fp==NULL){
                    puts("Mi spiace non posso salvare contatti");
                }else{
                    // data entry
                    do{
                        puts("Inserisci il nome");
                        gets(contatti[i].nome);
                        puts("Inserisci il cognome");
                        gets(contatti[i].cognome);
                        puts("Vuoi inserire un altro contatto? 1-si 0-no");
                        scanf("%d",&gonext);
                        fflush(stdin);
                        // scrivo il contatto nel file
                        fprintf(fp,"%s;%s\n",contatti[i].nome, contatti[i].cognome);
                        i++;
                    }while(gonext==1);
                    fclose(fp);
                }
                break;
            case 2:
                //controllo se posso aprire il file
                fp=fopen("rubrica.txt","r");
                if(fp==NULL){
                    puts("Mi spiace, non posso leggere i contatti nel file");
                    //TODO: leggere quelli in memoria?
                }else{

                }

                break;
            default:
                puts("Ops, qualcosa non funziona");
        }
    } while (opt != 0);

    return 0;
}
