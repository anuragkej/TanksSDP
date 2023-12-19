#include "FEHLCD.h"
#include "FEHUtility.h"

#define N_S 0
#define E_W 1
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

/*
 * Draws a stoplight to the screen
 * orientation = 0 if N/S, 1 if E/W
 * activeLight = 0 for red, 1 for yellow, 2 for green
 */
void DrawStoplight(int orientation, int activeLight)
{
    LCD.SetFontColor(LCD.White);
    LCD.WriteAt("N/S", 20, 112);
    LCD.WriteAt("E/W", 270, 112);
    if (orientation == N_S)
    {
        // N/S
        // Clear what was there before by drawing black over it
        LCD.SetFontColor(LCD.Black);
        LCD.FillRectangle(70, 10, 90, 220);
        // Draw the outline of the stoplight
        LCD.SetFontColor(LCD.White);
        LCD.DrawRectangle(70, 10, 90, 220);
        LCD.DrawCircle(115, 50, 35);
        LCD.DrawCircle(115, 120, 35);
        LCD.DrawCircle(115, 190, 35);

        // Draw the light that is currently active
        if (activeLight == RED_LIGHT)
        {
            LCD.SetFontColor(LCD.Red);
            LCD.FillCircle(115, 50, 35);
        }
        else if (activeLight == YELLOW_LIGHT)
        {
            LCD.SetFontColor(LCD.Yellow);
            LCD.FillCircle(115, 120, 35);
        }
        else if (activeLight == GREEN_LIGHT)
        {
            LCD.SetFontColor(LCD.Green);
            LCD.FillCircle(115, 190, 35);
        }
    }
    else if (orientation == E_W)
    {
        // E/W
        // Clear what was there before by drawing black over it
        LCD.SetFontColor(LCD.Black);
        LCD.FillRectangle(170, 10, 90, 220);
        // Draw the outline of the stoplight
        LCD.SetFontColor(LCD.White);
        LCD.DrawRectangle(170, 10, 90, 220);
        LCD.DrawCircle(215, 50, 35);
        LCD.DrawCircle(215, 120, 35);
        LCD.DrawCircle(215, 190, 35);

        // Draw the light that is currently active
        if (activeLight == RED_LIGHT)
        {
            LCD.SetFontColor(LCD.Red);
            LCD.FillCircle(215, 50, 35);
        }
        else if (activeLight == YELLOW_LIGHT)
        {
            LCD.SetFontColor(LCD.Yellow);
            LCD.FillCircle(215, 120, 35);
        }
        else if (activeLight == GREEN_LIGHT)
        {
            LCD.SetFontColor(LCD.Green);
            LCD.FillCircle(215, 190, 35);
        }
    }
    LCD.Update();
}

/* Entry point to the application */
int main()
{
    // Infinite loop so the stoplights run until the program is closed
    while (1)
    {
        DrawStoplight(N_S, GREEN_LIGHT);
        DrawStoplight(E_W, RED_LIGHT);
        Sleep(4000);
        DrawStoplight(N_S, YELLOW_LIGHT);
        DrawStoplight(E_W, RED_LIGHT);
        Sleep(2000);
        DrawStoplight(N_S, RED_LIGHT);
        DrawStoplight(E_W, RED_LIGHT);
        Sleep(2000);
        DrawStoplight(N_S, RED_LIGHT);
        DrawStoplight(E_W, GREEN_LIGHT);
        Sleep(4000);
        DrawStoplight(N_S, RED_LIGHT);
        DrawStoplight(E_W, YELLOW_LIGHT);
        Sleep(2000);
        DrawStoplight(N_S, RED_LIGHT);
        DrawStoplight(E_W, RED_LIGHT);
        Sleep(2000);
        // Add logic to make stoplights function
        // FILL IN
    }
    return 0;
}