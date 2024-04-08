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
    FILE    *fp;
    // char    *buffer;
    // long    numbytes;
    
    /* open an existing file for reading */
    fp = fopen("test_text_file.txt", "r");
        // fastest way to get content into buffer
    char buffer[9999];
    fgets(buffer, 30, fp); 
    
    /* confirm we have read the file by
    outputing it to the console */
    
    /* free the memory we used for the buffer */
    for (int i=0; i< 30; i++ ){
        char x = buffer[i];
        printf("%c", x);
    }


    // Main game loop
    int starting_x = 20;
    int starting_y = 20;
    int x_increment = 10;
    int y_increment = 10;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        char weird[] = "seee";
        char *my_stupido_pointero = weird[0];
        char *my_stupido_pointero2 = "w";
        puts(my_stupido_pointero);
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawText(my_stupido_pointero, 150, 150, 20, BLACK);
            // for (int i = 0; i != '\0'; i++){
                // char *mychar = buffer[i];
                // DrawText("my_stupido_pointero2", starting_x + i * x_increment, starting_y + i*y_increment, 20, BLACK);

            // }
            
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
