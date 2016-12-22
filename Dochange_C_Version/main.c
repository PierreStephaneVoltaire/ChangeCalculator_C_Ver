/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: steph
 *
 * Created on December 22, 2016, 3:15 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
static void doChange(int x,int* y) {
    int rest;
    double Dime,Nickel,Penny,Quarter,dollar ;
    
   dollar = x / 100;
    rest=(floor(dollar)*100);
     Quarter = (x-rest)/25;
    rest+= +(floor(Quarter) *25);
     Dime =(x-rest) /10;
     rest+=(floor(Dime) *10);
     Nickel = (x-rest)/5;
     rest+=(floor(Nickel) *5);
    Penny = x-rest;
  
 y[0]=Penny;
     y[1]=Nickel;
     y[2]=Dime;
     y[3]=Quarter;
     y[4]=dollar;
}
void clear(void) {
    while (getchar() != '\n');
}
int main(int argc, char** argv) {
    int money;
    //change array
    int change[5];
    for(;;){
    printf("%s","Please enter the amount of money you would like to change:");
    scanf("%d",&money);
    //cleart buffer
    clear();
     if (money >= 0) {
         //make change
    doChange(money,change);
   
    int o=  (sizeof(change) / sizeof(int));  
    //print 
    for (int i = o; i>=0; i--) {
        switch(i){
            case 0: printf("%d Penny(ies)\n",change[i]);
            break;
         case 1: printf("%d Nickel(s)\n",change[i]);
            break;
         case 2: printf("%d Dimes\n",change[i]);
            break;
         case 3: printf("%d Quarter(s)\n",change[i]);
            break;
         case 4: printf("%d Dollar(s)\n",change[i]);
            break; 
        }
    }  
     }
    //if negative
    else {
            printf("%s", "Wrong input\n");

    }}

    return (EXIT_SUCCESS);
}

