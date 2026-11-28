
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RESULT_FILE "quiz_results.txt"
#define TOTAL_QUESTIONS 10

struct Question {
    char question[200];
    char options[4][100];
    int correctAnswer;
};

struct Result {
    char name[50];
    int score;
    int total;
    float percentage;
};

/* Read a line of text */
void readLine(const char *message, char *buffer, int size) {
    printf("%s", message);

    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

/* Read an integer within a given range */
int readChoice(const char *message, int min, int max) {
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

        printf("Invalid input. Enter a number from %d to %d.\n",
               min, max);
    }
}

/* Store quiz questions */
void loadQuestions(struct Question q[]) {
    struct Question data[TOTAL_QUESTIONS] = {
        {
            "Which language is known as the mother of many modern languages?",
            {"Python", "C", "Java", "HTML"}, 2
        },
        {
            "Which symbol ends a statement in C?",
            {".", ":", ";", ","}, 3
        },
        {
            "Which function is used to display output in C?",
            {"scanf()", "printf()", "main()", "gets()"}, 2
        },
        {
            "Which data type stores whole numbers?",
            {"int", "float", "char", "double"}, 1
        },
        {
            "Which loop executes at least once?",
            {"for", "while", "do-while", "nested for"}, 3
        },
        {
            "Which operator is used to access a structure member?",
            {"->", ".", "&", "*"}, 2
        },
        {
            "Which header file is required for printf()?",
            {"stdlib.h", "string.h", "math.h", "stdio.h"}, 4
        },
        {
            "Which keyword returns a value from a function?",
            {"break", "return", "continue", "switch"}, 2
        },
        {
            "What is the index of the first array element in C?",
            {"1", "-1", "0", "2"}, 3
        },
        {
            "Which function opens a file in C?",
            {"fopen()", "fclose()", "fread()", "fprintf()"}, 1
        }
    };

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        q[i] = data[i];
    }
}

/* Display one question */
void displayQuestion(struct Question q, int number) {
    printf("\nQuestion %d: %s\n", number, q.question);

    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

/* Run the quiz */
int startQuiz(struct Question q[]) {
    int score = 0;
    int answer;

    printf("\n========== QUIZ STARTED ==========\n");

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        displayQuestion(q[i], i + 1);

        answer = readChoice("Your answer (1-4): ", 1, 4);

        if (answer == q[i].correctAnswer) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Incorrect answer!\n");
            printf("Correct option: %d. %s\n",
                   q[i].correctAnswer,
                   q[i].options[q[i].correctAnswer - 1]);
        }
    }

    return score;
}

/* Save quiz result in a file */
void saveResult(struct Result result) {
    FILE *fp = fopen(RESULT_FILE, "a");

    if (fp == NULL) {
        printf("Unable to save quiz result.\n");
        return;
    }

    if (fprintf(fp, "%s|%d|%d|%.2f\n",
                result.name,
                result.score,
                result.total,
                result.percentage) < 0) {
        printf("Error writing result.\n");
    } else {
        printf("Quiz result saved successfully!\n");
    }

    fclose(fp);
}

/* Display final result */
void displayResult(struct Result result) {
    printf("\n========== QUIZ RESULT ==========\n");
    printf("Student Name: %s\n", result.name);
    printf("Correct Answers: %d\n", result.score);
    printf("Incorrect Answers: %d\n",
           result.total - result.score);
    printf("Total Questions: %d\n", result.total);
    printf("Percentage: %.2f%%\n", result.percentage);

    if (result.percentage >= 80) {
        printf("Performance: Excellent!\n");
    } else if (result.percentage >= 60) {
        printf("Performance: Good!\n");
    } else if (result.percentage >= 40) {
        printf("Performance: Keep Practising!\n");
    } else {
        printf("Performance: More Practice Needed!\n");
    }
}

/* Display previously saved results */
void viewPreviousResults(void) {
    FILE *fp = fopen(RESULT_FILE, "r");
    char line[200];

    if (fp == NULL) {
        printf("No previous quiz results found.\n");
        return;
    }

    printf("\n========== PREVIOUS RESULTS ==========\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

/* Main function */
int main(void) {
    struct Question questions[TOTAL_QUESTIONS];
    struct Result result;
    int choice;

    loadQuestions(questions);

    while (1) {
        printf("\n========== QUIZ APPLICATION ==========\n");
        printf("1. Start Quiz\n");
        printf("2. View Previous Results\n");
        printf("3. Exit\n");

        choice = readChoice("Enter your choice: ", 1, 3);

        switch (choice) {
            case 1:
                readLine("Enter your name: ",
                         result.name, sizeof(result.name));

                if (result.name[0] == '\0' ||
                    strchr(result.name, '|') != NULL) {
                    printf("Please enter a valid name.\n");
                    break;
                }

                result.score = startQuiz(questions);
                result.total = TOTAL_QUESTIONS;

                result.percentage =
                    (float)result.score / result.total * 100;

                displayResult(result);
                saveResult(result);
                break;

            case 2:
                viewPreviousResults();
                break;

            case 3:
                printf("Thank you for playing!\n");
                return 0;
        }
    }
}
