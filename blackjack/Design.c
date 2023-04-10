//Design Module - Dominic Szymanski - 03/26/2023
#define _CRT_SECURE_NO_WARNINGS
#include "Design.h"
#include "dealer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <Windows.h>




void initializeDesign() {
    printf("----||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||----\n");
    printf("||||             Welcome to the Blackjack Game!                     ||||\n");
    printf("||||  The table and cards will be displayed using ASCII characters. ||||\n");
    printf("----||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||----\n");
}

void updateDesign(char* userAction, CARD cardArray[], int cardArraySize) {
    if (userAction == "d") {
        if (calculateTotalCardValue(cardArray, cardArraySize) < 10) {
            printf("||||       Dealers Hand: %d            ||||", calculateTotalCardValue(cardArray, cardArraySize));
        }
        else {
            printf("||||       Dealers Hand: %d           ||||", calculateTotalCardValue(cardArray, cardArraySize));
        }
    }
    else if (userAction == "u") {
        if (calculateTotalCardValue(cardArray, cardArraySize) < 10) {
            printf("||||          Your Hand: %d            ||||", calculateTotalCardValue(cardArray, cardArraySize));
        }
        else {
            printf("||||          Your Hand: %d           ||||", calculateTotalCardValue(cardArray, cardArraySize));
        }
    }
    printf("\n||||                                  ||||\n");
    displayBorderVertical();
    char* asciiCards = generateASCII(cardArray, cardArraySize);
    printf("%s", asciiCards);
    displayBorderVertical();
    displayBorderHorizontalEmpty();
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
            suit = 'S';
            break;
        case(2):
            suit = 'H';
            break;
        case(3):
            suit = 'C';
            break;
        case(4):
            suit = 'D';
            break;
        default:
            suit = '?';
            break;
        }

        switch (cardArray[j].card_id) {
        case(1 || 11):
            snprintf(cardLine, sizeof(cardLine), "|A  %c|  ", suit);
            break;
        case(0):
            snprintf(cardLine, sizeof(cardLine), "|?  ?|  ");
            break;
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
    system("cls");
    char* table = (char*)malloc(1024 * sizeof(char));
    strcpy(table, "----||||||||||||||||||||||||||||||||||----\n");
    strcat(table, "||||                                  ||||\n");
    strcat(table, "||||            BlackJack             ||||\n");
    strcat(table, "||||                                  ||||\n");
    strcat(table, "----||||||||||||||||||||||||||||||||||----\n");
    strcat(table, "||||                                  ||||\n");

    return table;
}

void displayASCII(const char* asciiString) {
    printf("%s\n", asciiString);
}

void updateBetDisplay(int betAmount) {
    printf("||||        Current bet: $%d", betAmount);
    int length = 1, num = betAmount;
    while (num >= 10) {
        num = num / 10;
        ++length;
    }
    for (int i = length; i < 10; i++) {
        printf(" ");
    }
    printf("  ||||\n");
}

void setFontSize(int size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX* cfi = (CONSOLE_FONT_INFOEX*)calloc(1, sizeof(CONSOLE_FONT_INFOEX));
    cfi->cbSize = sizeof(cfi);
    cfi->nFont = 1;
    cfi->dwFontSize.X = size;
    cfi->dwFontSize.Y = size * 2;
    cfi->FontFamily = FF_DONTCARE;
    cfi->FontWeight = FW_NORMAL;
    wcscpy(cfi->FaceName, L"Consolas");
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

void setColor(int color) {
    char command[20];
    sprintf(command, "color %02X", color);
    system(command);
}

int customizeDesign() {
    int option;
    int continueCustomization = 1;
    int background = 0;
    int colorChoice = 0;
    while (continueCustomization) {
      
        system("cls");
        printf("Choose an option to customize:\n");
        printf("1. Change background color\n");
        printf("2. Change text color\n");
        printf("3. Change font size\n");
        printf("4. Done\n");
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
            printf("7. Black\n");
            printf("8. White\n");
            printf("Enter your choice: ");
            scanf("%d", &color);
            switch (color) {
            case 1:
                background = 0xE0;
                break;
            case 2:
                background = 0xC0;
                break;
            case 3:
                background = 0x20;
                break;
            case 4:
                background = 0x90;
                break;
            case 5:
                background = 0xB0;
                break;
            case 6:
                background = 0xD0;
                break;
            case 7:
                background = 0x00;
                break;
            case 8:
                background = 0x70;
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
            printf("7. Black\n");
            printf("8. White\n");
;           printf("Enter your choice: ");
            scanf("%d", &color);

            switch (color) {
            case 1:
                colorChoice = 0x0E;
                break;
            case 2:
                colorChoice = 0x0C;
                break;
            case 3:
                colorChoice = 0x0A;
                break;
            case 4:
                colorChoice = 0x09;
                break;
            case 5:
                colorChoice = 0x0B;
                break;
            case 6:
                colorChoice = 0x0D;
                break;
            case 7:
                colorChoice = 0x00;
                break;
            case 8:
                colorChoice = 0x07;
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
        setColor(background + colorChoice);
    }
    return background + colorChoice;
}

void displayBalance(PLAYER* player) {
    printf("||||        Balance: $%d", player->balance);
    int length = 1, num = player->balance;
    while(num >= 10) {
        num = num / 10;
        ++length;
    }
    for (int i = length; i < 10; i++) {
        printf(" ");
    }
    printf("      ||||\n");
}

void displayWinScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||        Congratulations!          ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||            You won!              ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}
void displayDealerBustScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||         Dealer Busted!           ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||            You won!              ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}

void displayDealerBlackJackScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||     Dealer got Blackjack!        ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||           You lost!              ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}

void displayBlackJackScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||      You got a Blackjack!        ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||           You won!               ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}
void displayTieScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||     You Tied with Dealer!        ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||        Money Returned            ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}

void displayLoseScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||           Game Over              ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||           You lost!              ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}

void displayBustScreen() {
    displayBorderVertical();
    displayBorderHorizontalEmpty();;
    printf("||||          Game Over               ||||\n");
    displayBorderHorizontalEmpty();;
    printf("||||          You Busted              ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderVertical();
}

void displayWelcomeScreen() {
    system("cls");
    displayBorderVertical();
    displayBorderHorizontalEmpty();
    printf("||||    Welcome to Blackjack          ||||\n");
    printf("||||          Have Fun!               ||||\n");
    displayBorderHorizontalEmpty();
    displayBorderHorizontalEmpty();
    displayBorderHorizontalEmpty();
    printf("||||      Select an Option:           ||||\n");
    displayBorderHorizontalEmpty();
    printf("||||       1) Play Game               ||||\n");
    printf("||||       2) Settings                ||||\n");
    displayBorderVertical();
}
void displayBorderVertical() {
    printf("----||||||||||||||||||||||||||||||||||----\n");
}
void displayBorderHorizontalEmpty() {
    printf("||||                                  ||||\n");
}
void updateScreen(PLAYER* player, DEALER* dealer) {
    printf("%s", generateTable());
    updateDesign("d", dealer->dealersCards, dealer->nextCard);
    updateDesign("u", player->playersCards, player->nextCard);
    updateBetDisplay(player->currentBetAmount);
    displayBalance(player);
}