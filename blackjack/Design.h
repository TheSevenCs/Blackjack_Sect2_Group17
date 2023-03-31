#pragma once
#include "structdef.h"

typedef struct {
    char font_type[50];
    char color_scheme[50];
    int text_size;
} DesignOptions;

void initializeDesign();
void updateDesign(char* userAction, CARD cardArray[], int cardArraySize);
char* generateTable();
void customizeDesign(char* userInput);
void displayASCII(const char* asciiString);
void updateBetDisplay(int betAmount);
void setDesignOptions(DesignOptions designOptions);
char* generateASCII(CARD cardArray[], int cardArraySize);