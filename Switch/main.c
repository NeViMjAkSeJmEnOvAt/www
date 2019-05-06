/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: student
 *
 * Created on 10. prosince 2018, 7:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char** argv) {
    float r;
    int pocetZnaku;
    int cislo;
    int jedna;
    int dva;
    int tri;
    int ctyri; 
    
    
    do{
    do{
        printf("Zadej polomer.");
        scanf("%f", &r);
        
        pocetZnaku=0;
        while(getchar() != '\n')
            pocetZnaku++;
        if(pocetZnaku>0)
            printf("Nezadal jste realne cislo.\n");
        else if (r<0)
            printf("Zadal jste zaporne cislo, nebo 0.\n");
            }while(pocetZnaku>0 || r<0 );
            
            
            printf("////MENU////\n");
            printf("---------------\n");
            printf("1-Obvod kruhu\n");
            printf("2-Obsah kruhu\n");
            printf("3-Objem koule\n");
            printf("4-Povrch koule\n");
            printf("5-zmena polomeru\n");
            printf("6-konec\n");
            printf("---------------\n");
            
            do{
            do{
                printf("Zadejte volbu:");
                scanf("%d", &cislo);
            
            pocetZnaku=0; 
           while(getchar() != '\n')
            pocetZnaku++;
            if(pocetZnaku>0)
                printf("Nezadal jste cele cislo.\n");
            }while(pocetZnaku>0);
                switch(cislo){    
                    case 1:
                        printf("Obvod kruhu o polomeru %.2f je %.2f cm\n", r,2*M_PI*r);
                         break;
                    case 2:
                        printf("Obsah kruhu o polomeru %.2f je %.2f cm2\n", r,M_PI * r * r);
                         break;
                    case 3:
                        printf("Objem koule o polomeru %.2f je %.2f cm3\n",r,4.0/3.0*M_PI*r*r*r);
                         break;
                    case 4:
                        printf("Povrch koule o polomeru %.2f je %.2f cm2\n",r,4*M_PI*r*r);
                        break;
                    case 5:
                        
                        break;
                    case 6:
                        break;
                    default:
                        printf("Tato moznost neexistuje, zadejte znovu.\n");
            }
                    
            }while(cislo != 6 && cislo !=5);
    }while(cislo == 5);
            
                
            
            
    return (EXIT_SUCCESS);
}

