/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 5. listopadu 2018, 7:55
 */

#include <stdio.h>
#include <stdlib.h>
#define PIN 1111
#define POKUSY 4
#define PUK 123456789
#define PUKPOKUSY 5
/*
 * 
 */
int main(int argc, char** argv){
int pokusy=POKUSY;
int zadanyPIN;
int pocetZnaku;
int pokusyPuk=PUKPOKUSY;
int zadanyPUK;
int pocetZnakuPUK;   
/*musíme snížit počet pokusu o 1*/
    do{
        printf("Zadejte PIN:");
        scanf("%d", &zadanyPIN);
        pokusy--;
        pocetZnaku=0;
        while(getchar() != '\n')
            pocetZnaku++;
        if(pocetZnaku>0){
            printf("Zadal/a jste chybny PIN. \n"
                    "Zbyva vam %d pokusu.\n ",pokusy);
        }
        else if(zadanyPIN != PIN)
            printf("Chybny PIN. \n"
                    "Zbyva vam %d pokusu.\n",pokusy);
        else
            printf("Zadal jste spravny PIN! \n");
    }while(pokusy > 0 && (pocetZnaku>0 || zadanyPIN != PIN));

    if(pokusy=0)
        printf("Mate 0 dalsich pokusu. \n "
                "Zadejte PUK:"  );
    do{
        printf("Zadejte PUK:");
        scanf("%d", &zadanyPUK);
        pokusyPuk--;
        pocetZnakuPUK=0;
        while(getchar() != '\n')
            pocetZnakuPUK++;
        if(pocetZnakuPUK>0){
            printf("Zadal/a jste chybny PUK. \n"
                    "Zbyva vam %d pokusu.",pokusyPuk);
        }
        else if(zadanyPUK != PUK)
            printf("Chybny PUK. \n"
                    "Zbyva vam %d pokusu.",pokusyPuk);
        else
            printf("Zadal jste spravny PUK! \n");
    }while(pokusyPuk > 0 && (pocetZnaku>0 || zadanyPUK != PUK));
  
    return (EXIT_SUCCESS);
}