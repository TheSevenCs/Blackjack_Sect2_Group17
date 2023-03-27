//Design Module - Dominic Szymanski - 03/26/2023

#include "Design.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeDesign() {
    printf("Welcome to the Blackjack Game!\n");
    printf("The table and cards will be displayed using ASCII characters.\n\n");
}

void updateDesign(char* userAction, Card cardArray[], int cardArraySize) {
    printf("User action: %s\n", userAction);
    char* asciiCards = generateASCII(cardArray, cardArraySize);
    printf("%s\n", asciiCards);
    free(asciiCards);
}

char* generateASCII(Card cardArray[], int cardArraySize) {
    char* asciiCards = (char*)malloc(1024 * sizeof(char));
    strcpy(asciiCards, "");

    for (int i = 0; i < cardArraySize; i++) {
        char cardLine[50];
        snprintf(cardLine, sizeof(cardLine), "+----+  ");
        strcat(asciiCards, cardLine);
    }
    strcat(asciiCards, "\n");

    for (int i = 0; i < cardArraySize; i++) {
        char cardLine[50];
        snprintf(cardLine, sizeof(cardLine), "|%s %s|  ", cardArray[i].rank, cardArray[i].suit);
        strcat(asciiCards, cardLine);
    }
    strcat(asciiCards, "\n");

    for (int i = 0; i < cardArraySize; i++) {
            char cardLine[50];
            snprintf(cardLine, sizeof(cardLine), "+----+  ");
            strcat(asciiCards, cardLine);
        }
    strcat(asciiCards, "\n");

    return asciiCards;
}

char* generateTable() {
    char* table = (char*)malloc(1024 * sizeof(char));
    strcpy(table, "-----------------------------\n");
    strcat(table, "|          Blackjack         |\n");
    strcat(table, "-----------------------------\n");

    return table;
}

void customizeDesign(char* userInput) {
    //need to implement
}

void displayASCII(const char* asciiString) {
    printf("%s\n", asciiString);
}

void updateBetDisplay(int betAmount) {
    printf("Current bet amount: $%d\n", betAmount);
}

void setDesignOptions(DesignOptions designOptions) {
    //need to implement 
}