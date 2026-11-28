
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESULT_FILE "game_results.txt"

struct GameResult {
    char playerName[50];
    int attempts;
    int difficulty;
};

/* Read a complete line */
void readLine(const char *message, char *buffer, int size) {
    printf("%s", message);

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

/* Read a valid integer */
int readInteger(const char *message, int min, int max) {
    char input[100];
    char *end;
    long value;

    while (1) {
        readLine(message, input, sizeof(input));

        value = strtol(input, &end, 10);

        if (input[0] != '\0' && end != input &&
            *end == '\0' && value >= min && value <= max) {
            return (int)value;
        }

        printf("Invalid input. Enter a number between %d and %d.\n",
               min, max);
    }
}

/* Select difficulty level */
int selectDifficulty(void) {
    printf("\n===== SELECT DIFFICULTY =====\n");
    printf("1. Easy   (1 - 50)\n");
    printf("2. Medium (1 - 100)\n");
    printf("3. Hard   (1 - 200)\n");

    return readInteger("Enter difficulty: ", 1, 3);
}

/* Generate random number */
int generateNumber(int max) {
    return rand() % max + 1;
}

/* Save game result */
void saveResult(struct GameResult result) {
    FILE *fp = fopen(RESULT_FILE, "a");

    if (fp == NULL) {
        printf("Unable to save game result.\n");
        return;
    }

    if (fprintf(fp, "%s|%d|%d\n",
                result.playerName,
                result.attempts,
                result.difficulty) < 0) {
        printf("Error saving result.\n");
    } else {
        printf("Game result saved successfully!\n");
    }

    fclose(fp);
}

/* Display previous results */
void viewResults(void) {
    FILE *fp = fopen(RESULT_FILE, "r");
    char line[200];

    if (fp == NULL) {
        printf("No previous results found.\n");
        return;
    }

    printf("\n===== PREVIOUS GAME RESULTS =====\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

/* Play the guessing game */
void playGame(void) {
    struct GameResult result;
    int difficulty, maxNumber;
    int secretNumber, guess;
    int attempts = 0;
    int won = 0;

    readLine("Enter your name: ",
             result.playerName, sizeof(result.playerName));

    if (result.playerName[0] == '\0' ||
        strchr(result.playerName, '|') != NULL) {
        printf("Please enter a valid name.\n");
        return;
    }

    difficulty = selectDifficulty();

    switch (difficulty) {
        case 1:
            maxNumber = 50;
            break;
        case 2:
            maxNumber = 100;
            break;
        default:
            maxNumber = 200;
    }

    secretNumber = generateNumber(maxNumber);

    printf("\nGuess the number between 1 and %d.\n", maxNumber);

    while (!won) {
        guess = readInteger("Enter your guess: ", 1, maxNumber);
        attempts++;

        if (guess == secretNumber) {
            printf("\nCongratulations! You guessed correctly.\n");
            won = 1;
        } else if (guess < secretNumber) {
            printf("Too Low! Try a higher number.\n");
        } else {
            printf("Too High! Try a lower number.\n");
        }
    }

    result.attempts = attempts;
    result.difficulty = difficulty;

    printf("\n===== GAME RESULT =====\n");
    printf("Player: %s\n", result.playerName);
    printf("Attempts: %d\n", result.attempts);
    printf("Difficulty: %d\n", result.difficulty);

    saveResult(result);
}

/* Main menu */
int main(void) {
    int choice;

    srand((unsigned int)time(NULL));

    while (1) {
        printf("\n===== NUMBER GUESSING GAME =====\n");
        printf("1. Start Game\n");
        printf("2. View Previous Results\n");
        printf("3. Exit\n");

        choice = readInteger("Enter your choice: ", 1, 3);

        switch (choice) {
            case 1:
                playGame();
                break;

            case 2:
                viewResults();
                break;

            case 3:
                printf("Thanks for playing!\n");
                return 0;
        }
    }
}
