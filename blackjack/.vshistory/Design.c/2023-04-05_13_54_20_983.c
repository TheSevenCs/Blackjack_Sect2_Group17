//Design Module - Dominic Szymanski - 03/26/2023
#define _CRT_SECURE_NO_WARNINGS
#include "Design.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <Windows.h>




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
    SetConsoleOutputCP(CP_UTF8);
   
    wchar_t spade = 0x2660;
    wchar_t heart = 0x2665;
    wchar_t club = 0x2663;
    wchar_t diamond = 0x2666;

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
        wchar_t suit;
        switch (cardArray[j].suit) {
        case(1):
            suit = spade;
            break;
        case(2):
            suit = heart;
            break;
        case(3):
            suit = club;
            break;
        case(4):
            suit = diamond;
            break;
        default:
            suit = '?'; // Unknown suit
            break;
        }

        switch (cardArray[j].card_id) {
        case(10):
            wprintf(cardLine, sizeof(cardLine), "|10 %lc|  ", suit);
            break;
        case(11):
            wprintf(cardLine, sizeof(cardLine), "|J  %lc|  ", suit);
            break;
        case(12):
            wprintf(cardLine, sizeof(cardLine), "|Q  %lc|  ", suit);
            break;
        case(13):
            wprintf(cardLine, sizeof(cardLine), "|K  %lc|  ", suit);
            break;
        default:
            wprintf(cardLine, sizeof(cardLine), "|%d  %lc|  ", cardArray[j].card_id, suit);
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

void displayASCII(const char* asciiString) {
    printf("%s\n", asciiString);
}

void updateBetDisplay(int betAmount) {
    printf("Current bet amount: $%d\n", betAmount);
}

void setFontSize(int size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = size;
    cfi.dwFontSize.Y = size * 2;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void setColor(int color) {
    char command[20];
    sprintf(command, "color %02X", color);
    system(command);
}

void customizeDesign() {
    int option;
    int continueCustomization = 1;

    while (continueCustomization) {
      
        system("cls");
        printf("Choose an option to customize:\n");
        printf("1. Change background color\n");
        printf("2. Change text color\n");
        printf("3. Change font size\n");
        printf("4. Continue to the game\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1: {
            int color;
            printf("Choose a background color:\n");
            printf("1. Yellow\n");
            printf("2. Red\n");
            printf("3. Green\n");
            printf("4. Blue\n");
            printf("5. Orange\n");
            printf("6. Purple\n");
            printf("Enter your choice: ");
            scanf("%d", &color);

            switch (color) {
            case 1:
                setColor(0xE0);
                break;
            case 2:
                setColor(0xC0);
                break;
            case 3:
                setColor(0xA0);
                break;
            case 4:
                setColor(0x90);
                break;
            case 5:
                setColor(0xB0);
                break;
            case 6:
                setColor(0xD0);
                break;
            default:
                printf("Invalid choice!\n");
            }
            break;
        }
        case 2: {
            int color;
            printf("Choose a text color:\n");
            printf("1. Yellow\n");
            printf("2. Red\n");
            printf("3. Green\n");
            printf("4. Blue\n");
            printf("5. Orange\n");
            printf("6. Purple\n");
            printf("Enter your choice: ");
            scanf("%d", &color);

            switch (color) {
            case 1:
                setColor(0x0E);
                break;
            case 2:
                setColor(0x0C);
                break;
            case 3:
                setColor(0x0A);
                break;
            case 4:
                setColor(0x09);
                break;
            case 5:
                setColor(0x0B);
                break;
            case 6:
                setColor(0x0D);
                break;
            default:
                printf("Invalid choice!\n");
            }
            break;
        }
        case 3: {
            int fontSize;
            printf("Enter the font size (recommended between 10 and 20): ");
            scanf("%d", &fontSize);
            setFontSize(fontSize);
            break;
        }
        case 4:
            continueCustomization = 0;
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
}

void displayWinScreen() {
    system("cls");
    printf("╔══════════════════════════════════════╗\n");
    printf("║                                      ║\n");
    printf("║            Congratulations!          ║\n");
    printf("║                                      ║\n");
    printf("║                You won!              ║\n");
    printf("║                                      ║\n");
    printf("╚══════════════════════════════════════╝\n");
}

void displayLoseScreen() {
    system("cls");
    printf("╔══════════════════════════════════════╗\n");
    printf("║                                      ║\n");
    printf("║               Game Over              ║\n");
    printf("║                                      ║\n");
    printf("║                You lost!             ║\n");
    printf("║                                      ║\n");
    printf("╚══════════════════════════════════════╝\n");
}


void displayWelcomeScreen() {
    system("cls");
    printf("╔══════════════════════════════════════╗\n");
    printf("║                                      ║\n");
    printf("║        Welcome to Blackjack          ║\n");
    printf("║              Have Fun!               ║\n");
    printf("║                                      ║\n");
    printf("║                                      ║\n");
    printf("╚══════════════════════════════════════╝\n");
}