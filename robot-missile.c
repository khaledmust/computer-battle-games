#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

time_t seed = 0;
char secret_code = 0;
char user_input = 0;
int lives = 4;
char play_again = 'Y';

int main(void)
{
    do
    {

        time(&seed);

        srand(seed);

        secret_code = rand() % 26 + 65;

        // printf("%c\n", secret_code);

        printf("\n\n=== MISSION: CODE RED ===\n");
        printf("The Missile has just landed and everyone is depending on you to defuse it.\n");
        printf("If you fail the entire HQ will belown up.\n");

        printf("This program will help you to find the code.\n");
        printf("Enter you guess and it will tell you whether the code is earlier or later in the alphabet.\n");
        printf("You have only four chances.\n");
        printf("\n==============================\n");

        do
        {
            printf("\n🔐 Enter a letter (A–Z) to guess the secret code: ");
            scanf(" %c", &user_input);

            if (isalpha(user_input))
            {
                user_input = toupper(user_input);

                if (user_input < secret_code)
                {
                    printf("❌ Too early in the alphabet. Try a letter *later*!\n");
                }
                else if (user_input > secret_code)
                {
                    printf("❌ Too late in the alphabet. Try a letter *earlier*\n");
                }
                else if (user_input == secret_code)
                {
                    printf("Well done, the bomb is difused.\nYou are a hero.\n");
                    break;
                }
                lives--;
                printf("❤️ Lives left: %d\n", lives);
            }
            else
            {
                printf("⚠️  Invalid input. Please enter a letter from A to Z.\n");
                lives--;
            }
        } while (lives > 0);

        if (lives == 0)
        {
            printf("\n💥 BOOM! We are all dead.\n");
        }

        printf("\n Play again? (Y/N): ");
        scanf(" %c", &play_again);
        play_again = toupper(play_again);
        lives = 4;
    } while (play_again == 'Y');

    printf("\n👋 Thanks for playing. Stay safe, agent!\n");
    return 0;
}