/***************************************************/
/*  Name:  Anurag Kejriwal and Will Gonzalez            */
/*  Date:  12/04/2023                              */
/*  Assignment:  SDP 5                             */
/*  Seat: N/A Instructor: KMK Time:   08:00 AM */
/***************************************************/

/*Website Link: https://u.osu.edu/fehsdp2023akk008004/welcome-page/*/

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHRandom.h"

void displayGame();
void displayStatistics();
void displayInstructions();
void displayCredits();
void displayQuote();
void shootButton();
void playGame();

int turn = 1;
int leftLives = 3;
int rightLives = 3;
int leftShotsTaken = 0;
int rightShotsTaken = 0;

// Displays menu with 4 options
void displayMenu()
{
    LCD.Clear(BLACK);
    float x, y, a, b;
    int display;
    while (!LCD.Touch(&x, &y))
    {
        // declare an array of four icons called menu
        FEHIcon::Icon menu[4];

        // define the four menu labels
        char menu_labels[4][20] = {"START", "INSTRUCTIONS", "STATISTICS", "CREDITS"};

        // draw the menu in a 2 by 2 array with top and bottom
        // margins of 10 and left and right margins of 5
        // with the menu labels, dark orange borders, and violet text
        FEHIcon::DrawIconArray(menu, 2, 2, 10, 10, 5, 5, menu_labels, DARKORANGE, VIOLET);
        LCD.Update();
    }
    if (x < 160 && y < 120)
    {
        LCD.Clear(BLACK);
        Sleep(.3);
        LCD.Update();
        displayGame();
    }
    else if (x > 160 && y < 120)
    {
        LCD.Clear(BLACK);
        Sleep(.3);
        LCD.Update();
        displayInstructions();
    }
    else if (x > 160 && y > 120)
    {
        LCD.Clear(BLACK);
        Sleep(.3);
        LCD.Update();
        displayCredits();
    }
    else if (x < 160 && y > 120)

    {
        LCD.Clear(BLACK);
        Sleep(.3);
        LCD.Update();
        displayStatistics();
    }

    LCD.Clear(BLACK);
}

// Displays instructions for game
void displayInstructions()
{
    LCD.WriteLine("2 tanks will be displayed on opposite sides of the terrain. The main objective for each player is to shoot projectiles from their tanks in an attempt to hit the other tank to do damage and decrease their life count. The first tank to lose all of their lives loses and the other tank is the winner. ");
    bool cond = false;

    while (!cond)
    {
        float x, y;
        LCD.DrawRectangle(0, 220, 60, 20);
        LCD.WriteAt("BACK", 0, 220);
        LCD.Update();

        Sleep(500);

        while (!LCD.Touch(&x, &y))
        {
        }
        while (LCD.Touch(&x, &y))
        {
        }

        if (x < 60 && y > 220)
        {
            displayMenu();
            cond = true;
        }
    }
}

void displayStatistics()
{
    LCD.WriteLine("Left tank's lives: ");
    LCD.WriteLine(leftLives);
    LCD.WriteLine("Right tank's lives: ");
    LCD.WriteLine(rightLives);
    LCD.WriteLine("Left Tank Shots Taken: ");
    LCD.WriteLine(leftShotsTaken);
    LCD.WriteLine("Right Tank Shots Taken: ");
    LCD.WriteLine(rightShotsTaken);

    bool cond = false;

    while (!cond)
    {
        float x, y;
        LCD.DrawRectangle(0, 220, 60, 20);
        LCD.WriteAt("BACK", 0, 220);
        LCD.Update();

        Sleep(500);

        while (!LCD.Touch(&x, &y))
        {
        }
        while (LCD.Touch(&x, &y))
        {
        }

        if (x < 60 && y > 220)
        {
            displayMenu();
            cond = true;
        }
    }
}

void displayCredits()
{
    bool cond = false;
    LCD.WriteLine("Game made by Anurag Kejriwal and Will Gonzalez. The FEH Proteus Website was used in the making of this game.");

    while (!cond)
    {
        float x, y;
        LCD.DrawRectangle(0, 220, 60, 20);
        LCD.WriteAt("BACK", 0, 220);
        LCD.Update();

        Sleep(500);

        while (!LCD.Touch(&x, &y))
        {
        }
        while (LCD.Touch(&x, &y))
        {
        }

        if (x < 60 && y > 220)
        {
            displayMenu();
            cond = true;
        }
    }
}

void displayQuote()
{
    int r;
    r = ((Random.RandInt()) / 32768.0) * 5 + 1;
    switch (r)
    {
    case 1:
        LCD.WriteLine("War does not determine who is right - only who is   left. - Bertrand Russell");
        break;
    case 2:
        LCD.WriteLine("Only the dead have seen   the end of war. - George  Santayana");
        break;
    case 3:
        LCD.WriteLine("Older men declare war. But it is the youth that must fight and die. - Herbert Hoover");
        break;
    case 4:
        LCD.WriteLine("If we don't end war, war  will end us. - H.G. Wells");
        break;
    case 5:
        LCD.WriteLine("War is only a cowardly    escape from the problems  of peace. - Thomas Mann");
    }
    LCD.Update();
}

void displayGame()
{
    LCD.WriteLine("Tanks!");
    bool cond = false;

    while (!cond)
    {
        float x, y;
        LCD.DrawRectangle(0, 220, 60, 20);
        LCD.WriteAt("BACK", 0, 220);
        LCD.Update();

        /*Draw easy and hard level difficulty options*/
        LCD.DrawRectangle(100, 100, 60, 20);
        LCD.WriteAt("PLAY", 100, 100);
        LCD.Update();

        Sleep(500);

        while (!LCD.Touch(&x, &y))
        {
        }
        while (LCD.Touch(&x, &y))
        {
        }

        if (x > 100 && x < 160 && y > 100 && y < 120)
        {
            playGame();
            cond = true;
        }
        else if (x < 60 && y > 220)
        {
            displayMenu();
            cond = true;
        }
    }
}

void playGame()
{
    LCD.Clear(BLACK);
    bool cond = false;
    while (!cond)
    {
        float x, y;

        LCD.SetFontColor(GOLDENROD);
        displayQuote();
        LCD.Update();
        Sleep(5000);
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(0, 0, 350, 100);
        LCD.FillRectangle(0, 0, 350, 100);

        // shoot button
        LCD.SetFontColor(DARKKHAKI);
        LCD.DrawRectangle(130, 220, 60, 15);
        LCD.WriteAt("SHOOT", 130, 220);
        LCD.Update();

        // Central Divider
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(150, 70, 10, 120);
        LCD.FillRectangle(150, 70, 10, 120);

        // creating right and left tanks and projectiles
        LCD.SetFontColor(GREEN);
        LCD.DrawRectangle(240, 179, 30, 10);
        LCD.FillRectangle(240, 179, 30, 10);
        LCD.DrawRectangle(255, 169, 3, 10);
        LCD.FillRectangle(255, 169, 3, 10);

        LCD.SetFontColor(RED);
        LCD.DrawRectangle(35, 179, 30, 10);
        LCD.FillRectangle(35, 179, 30, 10);
        LCD.DrawRectangle(45, 169, 3, 10);
        LCD.FillRectangle(45, 169, 3, 10);
        LCD.Update();

        // display whose turn it is

        if ((leftLives == 0) || (rightLives == 0))
        {
            cond = true;
        }

        if (turn % 2 == 1)
        {
            LCD.WriteAt("Left Tank's Turn!", 70, 200);
        }
        else
        {
            LCD.WriteAt("Right Tank's Turn!", 70, 200);
        }

        // Sleep(20000);

        while (!LCD.Touch(&x, &y))
        {
        }

        while (LCD.Touch(&x, &y))
        {
        }

        if ((x < 190 && y > 220))
        {
            LCD.Update();
            shootButton();
        }

        else if (x > 195)
        {
            // rightButton();
            // cond = true;
        }

        else if (x < 125)
        {
            // leftButton();
            //   cond = true;
        }

        cond = true;
    }
}

void shootButton()
{
    int rand;
    rand = ((Random.RandInt()) / 32768.0) * 3 + 1;
    bool shootCond = false;
    while (!shootCond)
    {
        // check whose turn it is.
        // turn is odd: left tank
        // turn is even: right tank
        if (turn % 2 == 1)
        {
            leftShotsTaken++;
            for (int i = 168; i > 10; i -= 10)
            {
                LCD.SetFontColor(RED);
                LCD.DrawCircle(45, i, 5);
                LCD.FillCircle(45, i, 5);
                Sleep(50);
                LCD.SetFontColor(BLACK);
                LCD.FillCircle(45, i, 5);
                Sleep(50);
            }

            // hits tank
            if (rand == 1)
            {
                for (float j = 10; j < 190; j = 1.25 * j)
                {
                    LCD.SetFontColor(RED);
                    LCD.DrawCircle(255, j, 5);
                    LCD.FillCircle(255, j, 5);
                    Sleep(50);
                    LCD.SetFontColor(BLACK);
                    LCD.FillCircle(255, j, 5);
                    Sleep(50);
                }
                LCD.SetFontColor(ORCHID);
                LCD.WriteLine("Tank Hit!");
                rightLives--;
            }

            // misses tank
            else if (rand == 2)
            {
                for (float j = 10; j < 250; j = 1.25 * j)
                {
                    LCD.SetFontColor(RED);
                    LCD.DrawCircle(300, j, 5);
                    LCD.FillCircle(300, j, 5);
                    Sleep(50);
                    LCD.SetFontColor(BLACK);
                    LCD.FillCircle(300, j, 5);
                    Sleep(50);
                }
                LCD.SetFontColor(DARKSALMON);
                LCD.WriteLine("Tank Missed!");
            }

            // misses tank
            else if (rand == 3)
            {
                for (float j = 10; j < 250; j = 1.25 * j)
                {
                    LCD.SetFontColor(RED);
                    LCD.DrawCircle(210, j, 5);
                    LCD.FillCircle(210, j, 5);
                    Sleep(50);
                    LCD.SetFontColor(BLACK);
                    LCD.FillCircle(210, j, 5);
                    Sleep(50);
                }
                LCD.SetFontColor(DARKSALMON);
                LCD.WriteLine("Tank Missed!");
            }
        }

        else
        {
            rightShotsTaken++;
            for (int i = 168; i > 10; i -= 10)
            {
                LCD.SetFontColor(GREEN);
                LCD.DrawCircle(255, i, 5);
                LCD.FillCircle(255, i, 5);
                Sleep(50);

                LCD.SetFontColor(BLACK);
                LCD.FillCircle(255, i, 5);
                Sleep(50);
            }

            // hits tank
            if (rand == 1)
            {
                for (float j = 10; j < 190; j = 1.25 * j)
                {
                    LCD.SetFontColor(GREEN);
                    LCD.DrawCircle(45, j, 5);
                    LCD.FillCircle(45, j, 5);
                    Sleep(50);
                    LCD.SetFontColor(BLACK);
                    LCD.FillCircle(45, j, 5);
                    Sleep(50);
                }
                LCD.SetFontColor(ORCHID);
                LCD.WriteLine("Tank Hit!");
                leftLives--;
            }
            // misses tank
            else if (rand == 2)
            {
                for (float j = 10; j < 250; j = 1.25 * j)
                {
                    LCD.SetFontColor(GREEN);
                    LCD.DrawCircle(90, j, 5);
                    LCD.FillCircle(90, j, 5);
                    Sleep(50);
                    LCD.SetFontColor(BLACK);
                    LCD.FillCircle(90, j, 5);
                    Sleep(50);
                }
                LCD.SetFontColor(DARKSALMON);
                LCD.WriteLine("Tank Missed!");
            }
            // misses tank
            else if (rand == 3)
            {
                for (float j = 10; j < 250; j = 1.25 * j)
                {
                    LCD.SetFontColor(GREEN);
                    LCD.DrawCircle(10, j, 5);
                    LCD.FillCircle(10, j, 5);
                    Sleep(50);
                    LCD.SetFontColor(BLACK);
                    LCD.FillCircle(10, j, 5);
                    Sleep(50);
                }
                LCD.SetFontColor(DARKSALMON);
                LCD.WriteLine("Tank Missed!");
            }
        }
        rand = ((Random.RandInt()) / 32768.0) * 3 + 1;
        turn += 1;
        shootCond = true;
    }
    if ((leftLives != 0) && (rightLives != 0))
    {

        LCD.Clear(BLACK);
        float x, y;
        LCD.Update();
        LCD.SetFontColor(BLACK);
        LCD.DrawRectangle(0, 0, 350, 100);
        LCD.FillRectangle(0, 0, 350, 100);

        // shoot button
        LCD.SetFontColor(DARKKHAKI);
        LCD.DrawRectangle(130, 220, 60, 15);
        LCD.WriteAt("SHOOT", 130, 220);
        LCD.Update();

        // Central Divider
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(150, 70, 10, 120);
        LCD.FillRectangle(150, 70, 10, 120);

        // creating right and left tanks and projectiles
        LCD.SetFontColor(GREEN);
        LCD.DrawRectangle(240, 179, 30, 10);
        LCD.FillRectangle(240, 179, 30, 10);
        LCD.DrawRectangle(255, 169, 3, 10);
        LCD.FillRectangle(255, 169, 3, 10);

        LCD.SetFontColor(RED);
        LCD.DrawRectangle(35, 179, 30, 10);
        LCD.FillRectangle(35, 179, 30, 10);
        LCD.DrawRectangle(45, 169, 3, 10);
        LCD.FillRectangle(45, 169, 3, 10);
        LCD.Update();

        if (turn % 2 == 1)
        {
            LCD.WriteAt("Left Tank's Turn!", 70, 200);
        }
        else
        {
            LCD.WriteAt("Right Tank's Turn!", 70, 200);
        }

        // Sleep(20000);

        while (!LCD.Touch(&x, &y))
        {
        }

        while (LCD.Touch(&x, &y))
        {
        }

        if ((x < 190 && y > 220))
        {
            LCD.Update();
            shootButton();
        }
    }
}

/*have airstrike like projectile: tank shoots straight up and then projectile comes straight down onto the other tank
on the way down, the projectile starts slow and then speeds up which shows element of gravity.
*/

int main()
{
    while (1)
    {
        displayMenu();
        LCD.Update();
    }
}
