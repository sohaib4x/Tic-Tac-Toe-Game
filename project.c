#include <stdio.h>
#include <stdlib.h>

char player1[10];
char player2[10];

//Function prototypes

void displayBoard(char p11, char p12, char p13, char p21, char p22, char p23, char p31, char p32, char p33);

void getPlayerMove(char *position, char currentPlayerSymbol);

int checkWin(char p11, char p12, char p13, char p21, char p22, char p23, char p31, char p32, char p33, char currentPlayerSymbol );

int main()
{
    char p11 = '1', p12 = '2', p13 = '3';
    char p21 = '4', p22 = '5', p23 = '6';
    char p31 = '7', p32 = '8', p33 = '9';

    char temp;
    int moves = 0;
    char currentPlayerSymbol;
    int gameResult = 0;

    printf("Enter player 1 name:");
    fgets(player1, sizeof(player1),stdin);

    printf("Enter player 2 name:");
    fgets(player2, sizeof(player2),stdin);

    printf("\t\t Welcome to Tic Tac Toe\n\n\n");

    for(int i = 1; i <= 9; i++)
    {
        displayBoard(p11, p12,p13,p21,p22,p23,p31,p32,p33);

        currentPlayerSymbol = ( i % 2==1 ? 'X' : '0');

        getPlayerMove(&temp, currentPlayerSymbol);

        switch (temp)
        {
            case '1' :
                 if(p11 == 'X' || p11 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p11 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

         case '2' :
                 if(p12 == 'X' || p12 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p12 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

            case '3' :
                 if(p13 == 'X' || p13 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p13 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

             case '4' :
                 if(p21 == 'X' || p21 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p21 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

            case '5' :
                 if(p22 == 'X' || p22 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } 
                 else {
                   p22 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

          case '6' :
                 if(p23 == 'X' || p23 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p23 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

        case '7' :
                 if(p31 == 'X' || p31 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p31 = currentPlayerSymbol;
                   moves++;
                 }
                 break;
                
            case '8' :
                 if(p32 == 'X' || p32 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p32 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

            case '9' :
                 if(p33 == 'X' || p33 == '0')
                 {
                    printf("The desired space is allready filled. Please try again.\n\n");
                    i--;
                 } else {
                   p33 = currentPlayerSymbol;
                   moves++;
                 }
                 break;

            default :
            printf("Invalid input. Try again\n\n");
            i--;  // Decrementing i to repeat the same turn.
            break;
        }
        
        // Check for win.

        gameResult = checkWin(p11,p12,p13,p21,p22,p23,p31,p32,p33,currentPlayerSymbol);

        if(gameResult == 1)
        {
            exit(0); // End the game.
        }
      // check for draw after 9 moves.

      if(moves == 9){
          displayBoard(p11, p12,p13,p21,p22,p23,p31,p32,p33);
          printf("Its a draw!\n");
      } 
      
    }
    return 0;
}


// Function to display Tic Tac Toe board.
void displayBoard(char p11, char p12, char p13, char p21, char p22, char p23, char p31, char p32, char p33)
{
    printf("\t\t\t  %c | %c | %c \n",p11,p12,p13);
    printf("\t\t\t---------------\n");
    printf("\t\t\t  %c | %c | %c \n",p21,p22,p23);
    printf("\t\t\t---------------\n");
    printf("\t\t\t  %c | %c | %c \n",p31,p32,p33);
    
}

// Function to get player move and update the board.

void getPlayerMove(char *position, char currentPlayerSymbol)
{
    if(currentPlayerSymbol == 'X'){
        printf("Player %s : Enter number from the grid where you want to enter %c:",player1, currentPlayerSymbol);
    } else {
        printf("Player %s : Enter number from the grid where you want to enter %c:",player2, currentPlayerSymbol);
    }

    char tempers[100];

    do{
        scanf("%s",tempers);
        if(tempers[1] != '\0' && tempers[2] != '\n')
        {
            printf("\nEnter again: ");
            continue;
        }
        *position = tempers[0];
    }while (tempers[1] != '\0' && tempers[2] != '\n');
    printf("\n");
   
}

// Function to check for a win or draw.

int checkWin(char p11, char p12, char p13, char p21, char p22, char p23, char p31, char p32, char p33, char currentPlayerSymbol )
{
    if((p11 == p12 && p11 == p13) || (p21 == p22 && p21 == p23) || (p31 == p32 && p31 == p33) ||
        (p11 == p21 && p11 == p31) || (p12 == p22 && p12 == p32) || (p13 == p23 && p13 == p33) ||
        (p11 == p22 && p11 == p33) || (p13 == p22 && p13 == p31)) 
      {
           displayBoard(p11, p12,p13,p21,p22,p23,p31,p32,p33);
           printf("%s Wins!!!\n",(currentPlayerSymbol == 'X' ? player1 : player2));
           
           return 1;  // Win
      }
      return 0; // Continue playing.
}
