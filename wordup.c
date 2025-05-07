/* Project 10 Not Wordle
Author: Emiliano Casillas-Rodriguez
Wow, We've Come A Long Way*/

#include<stdio.h>
# define FileRead "mystery.txt"
//Different Names With The Same Values For Sake Of Book Keeping.
# define ROW 5
# define COLUM 6
# define SIZE 6

void GetWord(char Wordle[SIZE],FILE *InputFilePrt);
void TestGuess(char Guess[ROW], int Test);
void FirstCheck(char Guess[ROW], char Wordle[SIZE], int win, int* winner);
void SecondCheck(char Guess[ROW], char Worlde[SIZE], char FeedBack[ROW]);
void DisplayWin(int attempt);
void DisplayHistory(char GuessHistory[][COLUM], char FeedBackHistory[][COLUM], int attempt);
int main(){ 
	char GuessHistory[ROW][COLUM];
	char Guess[ROW];
	char FeedBack[ROW];
	char FeedBackHistory[ROW][COLUM];
	char Wordle[SIZE];
	int Test, attempt, win, winna;
	int* winner;
	FILE *InputFilePrt = fopen(FileRead,"r");
	if(InputFilePrt == NULL){
		printf("The File Did Not Open");
		return 0;
	}
	GetWord(Wordle,InputFilePrt);
	printf("\tGuess The Word!\n");
	for(attempt = 0; attempt < ROW ; attempt++){
		Test = 0;
		printf("\nGuess %d: ", attempt + 1);
		scanf("%s",Guess);
		TestGuess(Guess,Test);
		FirstCheck(Guess,Wordle,win,&winna);
		if(winna == 5){
			DisplayWin(attempt);
			return 0;
			}
			SecondCheck(Guess,Wordle,FeedBack);
			for(int i = 0; i < ROW; i++){
				GuessHistory[attempt][i] = Guess[i];
				}	
			
			for(int i = 0; i < ROW; i++){
			FeedBackHistory[attempt][i] = FeedBack[i];
			} 
		DisplayHistory(GuessHistory,FeedBackHistory,attempt);
		}
	printf("\n");
	printf("\n========================");
	printf("\nSorry You Ran Out Of Guesses!");
	printf("\nThe Word Was %s",Wordle);
	printf("\n========================\n");
		
	
	return 0;
	}
	//gets the word and closes the file
	void GetWord(char Wordle[SIZE],FILE *InputFilePrt){
	fscanf(InputFilePrt, "%s",Wordle);
	fclose(InputFilePrt);
	}
 	//This Is The Tester
 	void TestGuess(char Guess[ROW], int Test){
 	for(int j = 0; Guess[j] != '\0' ; j++){
		Test++;
		}
			while(Test != 5){
				Test = 0;
				printf("\nThe Guess needs to be 5 Lower Case Letters: ");
				scanf("%s",Guess);
					for(int j = 0; Guess[j] != '\0' ; j++){
						Test++;
					}
			}
 	}
 	//This Compares The Guesses With Each Other For Exact Matches
 	void FirstCheck(char Guess[ROW], char Wordle[SIZE], int win, int* winner){
 	for(int i = 0; i < ROW; i++){
		if(Guess[i] == Wordle[i]){
			Guess[i] = Guess[i] - 32;
			win++;
			}
			*winner = win;
		}	
 	}
 	//This Compares The Guesses To See if The Letters Are In Wrong Spots
 	void SecondCheck(char Guess[ROW], char Wordle[SIZE], char FeedBack[ROW]){
 	for(int i = 0; i < ROW; i++){
 	 for(int j = 0; j < ROW; j++){
 		if(Guess[i] == Wordle[j]){
 			FeedBack[i] = '^';
 			}
 		else{
 			FeedBack[i] = ' ';
 			}
 		}
 		 }
 	}
 	//This Is To Display A Win
 	void DisplayWin(int attempt){
 	switch(attempt + 1){
 	case 1:
 	printf("\n========================");
 	printf("\nYou Got It In 1 Attempts!\n");
 	printf("\tCHEATER!");
 	printf("\n========================\n");
 	break;
 	case 2:
 	printf("\n========================");
 	printf("\nYou Got It In 2 Attempts!\n");
 	printf("\tGOOD JOB!");
 	printf("\n========================\n");
 	break;
 	case 3:
 	printf("\n========================");
 	printf("\nYou Got It In 3 Attempts!\n");
 	printf("\tNICE!");
 	printf("\n========================\n");
 	break;
 	case 4:
 	printf("\n========================");
 	printf("\nYou Got It In 4 Attempts!\n");
 	printf("\tNOT BAD");
 	printf("\n========================\n");
 	break;
 	case 5:
 	printf("\n========================");
 	printf("\nYou Got It In 5 Attempts!\n");
 	printf("\tNICE SAVE!");
 	printf("\n========================\n");
 	break;
 		}
 	}
 	//This Is To Display Previous Guesses
 	void DisplayHistory(char GuessHistory[][COLUM], char FeedBackHistory[][COLUM], int attempt){
 	printf("\n========================");
 	for(int i = 0; i < attempt + 1; i++){
 		printf("\n\t%s",GuessHistory[i]);
 		printf("\n\t%s",FeedBackHistory[i]);
		} 	
 	printf("\n========================");
 	}
 	
