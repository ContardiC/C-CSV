#include<stdio.h>
#include<string.h>
typedef struct{
    char firstname[61];
    char lastname[61];
}Contact;
Contact contacts[100], tmp;

int main(){
    int opt;
    int gonext=0;
    int i,j;
    FILE *fp;
    //main menu
    do{
        puts("1 - Salva un contatto ");
        puts("2 - Leggi tutti i contatti");
        puts("0 - Esci dal programma");
        //TODO: aggiungere opzioni
        scanf("%d",&opt);
        fflush(stdin);
        // operazioni
        switch(opt) {
            case 1:
                i=0;
                do{
                    puts("Nome del contatto");
                    scanf("%s",contacts[i].firstname);
                    puts("Cognome del contatto");
                    scanf("%s",contacts[i].lastname);
                    puts("1 - Altro contatto ");
                    puts("0 - Esci");
                    scanf("%d",&gonext);
                    fflush(stdin);
                    i++;
                    //TODO: sistemare condizioni
                }while(gonext==1 && i<100);
                // salvo i dati letti
                fp= fopen("contacts.csv","a");
                if(fp!=NULL){
                    for(j=0;j<i;j++) {
                        fprintf(fp, "%s;%s\n", contacts[j].firstname, contacts[j].lastname);
                    }
                }else{
                    puts("Mi spiace non posso salvare i tuoi dati");
                }
                fclose(fp);
                break;
            case 2:
                fp=fopen("contacts.csv","r");
                if(fp==NULL){
                    puts("Non posso leggere i contatti");
                }else{
                    while(!feof(fp)){
                        fscanf(fp,"%[^;];%[^\n]\n",tmp.firstname,tmp.lastname);
                        printf("NOME: %s COGNOME: %s\n",tmp.firstname,tmp.lastname);
                    }
                }
                fclose(fp);
                break;
            default:
                puts("Ops, qualcosa e' andato storto");
        }
        //TODO: sistemare condizioni
    }while(opt!=0);

    return 0;
}
