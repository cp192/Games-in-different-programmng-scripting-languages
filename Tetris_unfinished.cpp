/*C++ Game: Tetris for the Commmand Prompt 
My idea of thegame with inspiration from javidx9
learning concepts like in-/output, the logic, 
display on screen ,collision cases, flush etc..
arrays and loops
real time interaction with hardware
cpp, h etc..*/

/*Finally: step by step development 
to a graphically appealling experience*/


#include <iostream>
#inclue <Windows.h>
#include <thread>
#include <vector>
#include <stdio.h>
using namespace std: //Considered a bad practice but ok for little applications like this one.

wstring tetromino[7];					//Tetris has 7 different figures, which are stored as strings.
int nFieldWidth = 12;					//Initialize Playfield with Width 12
int nFieldHeight = 18; 					//Initialize Playfield with Height 18
unsigned char *pField = nullptr;		//The initialized elements of the field are stored as "unsigned char"(s) and they are allocated dynamically. 0 represents anempty space
										//All map information is stored in 1 array.
										
int nScreenWidth = 80;			// Console Screen Size X (columns)
int nScreenHeight = 30;			// Console Screen Size Y (rows)
wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
unsigned char *pField = nullptr;

int Rotate(int px, int py, int r) //Neccesary to be able to rotate peices.  
{
	switch (r % 4)						//r is the value-placeholder for case 0-3
	{
	case 0: return py * 4 + px; 		//0°   rotation
	case 1: return 12 + py - (px *4); 	//90°  rotation
	case 2: return 15 - (py *4) - px;	//180° rotation
	case 3: return 3 - py + (px *4);	//270° rotation
	}
	return 0;
	
	
}

int main() 

{
		//Creating a Screen Buffer for the Command Prompt
		wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
		for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' '; //"L' '" --> The screen [i] is filled blank.
		HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		SetConsoleActiveScreenBuffer(hConsole);
		DWORD dwBytesWritten = 0;
		
		
		//Illustration, how the figures look in the command prompt with 1d-arrays
		
		//1st shape (the dots represent empty spaces)
		tetromino[0].append(L"..X.");
		tetromino[0].append(L"..X.");
		tetromino[0].append(L"..X.");
		tetromino[0].append(L"..X.");
		
		//2nd shape
		tetromino[1].append(L".X..");
		tetromino[1].append(L".XX.");
		tetromino[1].append(L"..X.");
		tetromino[1].append(L"....");
		
		//3rd shape
		tetromino[2].append(L"..X.");
		tetromino[2].append(L".XX.");
		tetromino[2].append(L".X..");
		tetromino[2].append(L"....");
		
		//4th shape
		tetromino[3].append(L"....");
		tetromino[3].append(L".XX.");
		tetromino[3].append(L".XX.");
		tetromino[3].append(L"....");
		
		//5th shape
		tetromino[4].append(L"..X.");
		tetromino[4].append(L".XX.");
		tetromino[4].append(L"..X.");
		tetromino[4].append(L"....");
		
		//6th shape
		tetromino[5].append(L"....");
		tetromino[5].append(L".XX.");
		tetromino[5].append(L"..X.");
		tetromino[5].append(L"..X.");
		
		//7th shape
		tetromino[6].append(L"....");
		tetromino[6].append(L".XX.");
		tetromino[6].append(L".X..");
		tetromino[6].append(L".X..");
		
		//Initialize the array for the Playfield
		pField = new unsigned char[nFieldWidth*nFieldHeight];
		for(int x = 0, x < nFieldWidth, x++);					//board boundary Width
			for(int y = 0, y < nFieldHight, ++);				//board boundary Height
			pField[y*nFieldWidth + x] = (x == 0 || x = nFieldWith - 1 || y == nFieldHeight -1) ? 9 : 0;	//set everything in the array to 0 unless outside the boundary, 9 represents the border
			
		bool bGameOver = false:	
		
	while (!bGameOver)
	{		
		for(int x = 0, x < nFieldWidth, x++);					//From Initialization to Drawing the board while the game is not over 
			for(int y = 0, y < nFieldHight, ++);
			screen[(y+2) *nScreenWidth + (x+2)] = L" ABCDEFG=#"[pField[y*nFieldWidth + x]];		//Screen won't be directly in the left upper corner but is offset by 2 --> "y+2" & "+2". "L" ABCDEFG=#"" represents the drawn shapes.
		// Display Frame
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten); //Draws the Playscreen from the handler to the screen buffer and updates it while playing. 
	}

	return 0;
}


