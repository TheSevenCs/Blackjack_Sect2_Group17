#pragma once

typedef struct {
    char suit[10];
    char rank[10];
    int value;
} Card;

typedef struct {
    char font_type[50];
    char color_scheme[50];
    int text_size;
} DesignOptions;

void initializeDesign();
void updateDesign(char* userAction, Card cardArray[], int cardArraySize);
char* generateASCII(Card cardArray[], int cardArraySize);
char* generateTable();
void customizeDesign(char* userInput);
void displayASCII(const char* asciiString);
void updateBetDisplay(int betAmount);
void setDesignOptions(DesignOptions designOptions);
