/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "include/raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(1);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // char *filename = "test_text_file.txt";
    // FILE* ptr;
    // ptr = fopen("test_text_file.txt", "r");




		

/* declare a file pointer */
FILE    *infile;
char    *buffer;
long    numbytes;
 
/* open an existing file for reading */
infile = fopen("test_text_file.txt", "r");
 
/* quit if the file does not exist */
if(infile == NULL)
    return 1;
 
/* Get the number of bytes */
fseek(infile, 0L, SEEK_END);
numbytes = ftell(infile);
 
/* reset the file position indicator to 
the beginning of the file */
fseek(infile, 0L, SEEK_SET);	
 
/* grab sufficient memory for the 
buffer to hold the text */
buffer = (char*)calloc(numbytes, sizeof(char));	
 
/* memory error */
if(buffer == NULL)
    return 1;
else{
    puts("buffer is not empty. It's good");
}
 
/* copy all the text into the buffer */
fread(buffer, sizeof(char), numbytes, infile);
fclose(infile);
 
/* confirm we have read the file by
outputing it to the console */
printf("The file called test.dat contains this text\n\n%s", buffer);
 
/* free the memory we used for the buffer */
free(buffer);


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            char ch;
            
            DrawText("x", 190, 200, 20, BLACK);
            
            // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            // DrawText("Fucking idiot", 190, 220, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
