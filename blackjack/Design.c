//Design Module - Dominic Szymanski - 03/26/2023
#define _CRT_SECURE_NO_WARNINGS
#include "Design.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void initializeDesign() {
    printf("Welcome to the Blackjack Game!\n");
    printf("The table and cards will be displayed using ASCII characters.\n\n");
}

void updateDesign(char* userAction, CARD cardArray[], int cardArraySize) {
    if (userAction == "d") {
        printf("Dealers Hand:");
    }
    else if (userAction == "u") {
        printf("Your Hand:");
    }
    printf("\n\n");
    char* asciiCards = generateASCII(cardArray, cardArraySize);
    printf("%s\n", asciiCards);
    free(asciiCards);
}

char* generateASCII(CARD cardArray[], int cardArraySize) {
    setlocale(LC_CTYPE, "");

    wchar_t star1 = 0x2606;
    char* asciiCards = (char*)malloc(1024 * sizeof(char));
    strcpy(asciiCards, "");

    for (int i = 0; i < cardArraySize; i++) {
        char cardLine[50];
        snprintf(cardLine, sizeof(cardLine), "+----+  ");
        strcat(asciiCards, cardLine);
    }
    strcat(asciiCards, "\n");

    for (int j = 0; j < cardArraySize; j++) {
        char cardLine[50];
        char suit;
        switch (cardArray[j].suit) {
        case(1):
            suit = "♠";
        case(2):
            suit = "♥";
        case(3):
            suit = "♣";
        case(4):
            suit = "♦";
        default:
            suit = "ERROR";
        }

        switch (cardArray[j].card_id) {
        case(10):
            snprintf(cardLine, sizeof(cardLine), "|10 %c|  ", suit);
            break;
        case(11):
            snprintf(cardLine, sizeof(cardLine), "|J  %c|  ", suit);
            break;
        case(12):
            snprintf(cardLine, sizeof(cardLine), "|Q  %c|  ", suit);
            break;
        case(13):
            snprintf(cardLine, sizeof(cardLine), "|K  %c|  ", suit);
            break;
        default:
            snprintf(cardLine, sizeof(cardLine), "|%d  %c|  ", cardArray[j].card_id, suit);
            break;
        }
        strcat(asciiCards, cardLine);
    }
    strcat(asciiCards, "\n");

    for (int k = 0; k < cardArraySize; k++) {
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