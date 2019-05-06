/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 1. dubna 2019, 6:27
 */

#include <stdio.h>
#include <stdlib.h>
#define MIN 1
#define MAX 50

int vstup(int min,int max,const char* slovo,int poradi){
    int input;
    int pocetZnaku;
    do{
        printf ("Zadejte %s %d. zlomku v intervalu od %d do %d: ",slovo,poradi,min,max);
        scanf ("%d",&input);
        pocetZnaku=0;
        while(getchar()!= '\n')
            pocetZnaku++;
        if (pocetZnaku>0)
            printf("Nebylo zadano cele cislo. Zadej znovu. \n");
        else if (input<min||input>max)
            printf("Nezadal jste cislo v intervalu od %d do %d."
            " Zadej znovu. \n",min,max);
    }while(pocetZnaku>0||input<min||input>max);
    return input;      
}

float desetinneCislo(int citatel,int jmenovatel){
    return (float)citatel / (float)jmenovatel;
}
unsigned NSN(int a,int b){
    //převedení čísla na absolutní hodnotu 
    a=abs(a);
    b=abs(b);
    unsigned nasobek = a > b ? a : b;
    while (nasobek % a != 0 || nasobek % b != 0)
        nasobek+= a > b ? a : b;
    
    return nasobek;
}

unsigned NSD(int a,int b){
    unsigned delitel= a < b ? a : b ;
    if(delitel==0)
        return 1;
    while (a % delitel != 0 || b % delitel != 0)
        delitel--; 
    
  return delitel;  
}

void nasobeni(int c1,int j1,int c2,int j2){
        unsigned spolDel;
        printf("%d/%d * %d/%d = ",c1,j1,c2,j2);
        printf("%d/%d = ",c1*c2,j1*j2);
        //krácení zlomků
        spolDel=NSD(c1*c2,j1*j2 );
        printf("%d/%d",c1*c2/spolDel,j1*j2/spolDel);
        printf("\n");
        return;
}

void deleni(int c1, int j1, int c2, int j2){
    printf("%d/%d : %d/%d = ",c1,j1,c2,j2);
    if(c2!=0){
        //výměnna hodnot
        nasobeni(c1,j1,j2,c2);
    }
    else 
            printf("Zlomkem nelze delit.\n");
    return;
}

void scitaniOdcitani(int c1,int j1,int c2,int j2,char znamenko){
    //rpznásobení čitatelů
        unsigned spolJm=NSN(j1,j2);
        int rozc1=spolJm/j1*c1;
        int rozc2=spolJm/j2*c2;
        int citatel=(znamenko=='-')? (rozc1 - rozc2):(rozc1 + rozc2);
        unsigned spolDel=NSD(spolJm,citatel);
        printf("%d/%d %c %d/%d = ",c1,j1,znamenko,c2,j2);
        printf("(%d %c %d)/%d = ",rozc1,znamenko,rozc2,spolJm);
        printf("%d/%d = ",citatel,spolJm);
        //krácení zlomku
        printf("%d/%d ",(citatel)/spolDel,spolJm/spolDel);
        printf ("\n");
}
void smiseneCislo(int c,int j){
if (c == 0)
  return;
  else if(c>j)
printf("= %d %d/%d",c/j,c%j,j);
else
  printf("%d/%d",c,j);
return;
}


int konec (){
    int znaky=0;
    int ukonceni;
    printf ("Pro ukonceni programu stisknete 0: ");
    scanf("%d",&ukonceni);
    while(getchar()!='\n')
        znaky++;
    if (znaky>0)
        return 0;
    else if (ukonceni == 0)
        return 1;
    else 
        return 0;
}

int main(int argc, char** argv) {
    int c1,j1;
    int c2,j2;
    //proměnná pro uložení hodnoty při výměně dvou proměných
    int pom;
    do{
        c1=vstup(MIN-1,MAX,"citatele",1);
        j1=vstup(MIN,MAX,"jmenovatele",1);
        c2=vstup(MIN-1,MAX,"citatele",2);
        j2=vstup(MIN,MAX,"jmenovatele",2);
        printf("%d/%d = %.2f \n",c1,j1,desetinneCislo(c1,j1));
        //Sčítání zlomku
        scitaniOdcitani(c1,j1,c2,j2,'+');
        //odečítání zlomku
        scitaniOdcitani(c1,j1,c2,j2,'-');
        //násobení zlomků
        nasobeni(c1,j1,c2,j2);
        //dělení zlomků
        deleni(c1,j1,c2,j2);
    }while (!konec());
    return (EXIT_SUCCESS);
}