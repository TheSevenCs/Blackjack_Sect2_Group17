#pragma once
#include "structdef.h"

typedef struct {
    char font_type[50];
    char color_scheme[50];
    int text_size;
} DesignOptions;

void initializeDesign();
void updateDesign(char* userAction, CARD cardArray[], int cardArraySize);
char* generateASCII(CARD cardArray[], int cardArraySize);
char* generateTable();
int customizeDesign();
void displayASCII(const char* asciiString);
void updateBetDisplay(int betAmount);
void setFontSize(int size);
void displayWinScreen();
void displayLoseScreen();
void displayWelcomeScreen();
void displayBustScreen();
void displayDealerBustScreen();
void updateScreen(PLAYER* player, DEALER* dealer);
void displayTieScreen();
void displayDealerBlackJackScreen();
void displayBlackJackScreen();
void setColor(int);
void displayBalance(PLAYER* player);

void displayBorderHorizontalEmpty();
void displayBorderVertical();