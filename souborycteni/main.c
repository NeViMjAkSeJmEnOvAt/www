/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 8. dubna 2019, 7:49
 */

#include <stdio.h>
#include <stdlib.h>
#define VSTUP "Nahodnytextovysoubor.txt"
#define VYSTUP "Nahodnakopie.txt"

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *fr;
    FILE *fw;
    int znak;
    //otevreni souboru cteni
    if((fr = fopen(VSTUP, "r")) == NULL){
        printf("Soubor %s nebyl otevren.\n", VSTUP);
        return -1;
        
    }
    //otevreni souboru pro zapis
    if((fw = fopen(VYSTUP, "w")) == NULL){
        printf("Soubor %s nebyl otevren.\n", VYSTUP);
        return -1;
        
    }
    //Cteni souboru po znacich a zobrazeni v konzoli
    while((znak=getc(fr)) != EOF)
        printf("%c", znak);
        fprintf(fw, "%c", znak);
    
    //Uzavrenbi souboru
    if (fclose(fr) == EOF){
        printf("Soubor %s nebyl uzavren.\n", VSTUP);
    }
    if (fclose(fw) == EOF){
        printf("Soubor %s nebyl uzavren.\n", VYSTUP);
    }
    return (EXIT_SUCCESS);
}

