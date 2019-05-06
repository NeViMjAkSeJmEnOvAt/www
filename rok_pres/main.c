/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 4. února 2019, 8:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MIN 1582
#define MAX 3600

/*
 * 
 */
int vstup (){
    int rok;
    int pocetZnaku;
    do{
        printf("Zadejte rok v intervalu %d do %d:", MIN, MAX);
        scanf("%d", &rok);
        pocetZnaku=0;
        while (getchar() != '\n')
            pocetZnaku++;
        if(pocetZnaku>0)
            printf("Nebylo zadano cela cislo.\n");
        else if (rok<MIN || rok>MAX)
            printf("Nezadal jste rok v intervalu!\n");
    }while( pocetZnaku != 0 || rok < MIN || rok > MAX );
    return rok;
}
int prestupnyRok(int r){
    if(r % 4 != 0)
        return 0;
    else if(r % 100 != 0)
        return 1;
    else if (r % 400 != 0)
        return 0;
    else 
        return 1;
}
int konec(){
    char znak;
    int pocetZnaku=0;
    printf("Pro ukonceni programu zmackenete klavesu \'k\':\n");
    scanf("%c", &znak);
    while(getchar() != '\n')
        pocetZnaku++;
    if(pocetZnaku > 0)
        return 0;
    else if(tolower(znak) == 'k')
        return 1;
    else
        return 0;
}
int main(int argc, char** argv) {
    int rok;    
    do{
    rok=vstup();
    printf("Zadany rok je prestupny.\n ", rok,
            (prestupnyRok(rok)) ? "je" : "není");
    }while(!konec());
    return (EXIT_SUCCESS);
}

