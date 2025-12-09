// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcs.h"

/* Prototypes mirroring the C++ version */
static void main_menu(void);            /* runs in the main loop */
static void print_main_menu(void);      /* output the main menu description */
static int  get_user_input(void);       /* get a valid integer menu choice */
static void select_menu_item(int input);/* run code based on user's choice */
static void go_back_to_main(void);      /* wait for 'b'/'B' to continue */
static int  is_integer(const char *s);  /* validate integer string */
static void update_progress(int unit_index);
static void generate_report(void);

struct person{
    char name[40];
    int unit_completed[4];
    int answer_correct[4];
    int answer_correct_1time[4];
};

//global variable
static struct person user = {0};

extern int unit_answer_correct;
extern int unit_attempts;

int main(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    //variable define
    char name[40];

    //greeting at first
    greeting();
    //ask for use's name
    ask_name(name);
    strcpy(user.name,name);
    printf("Hello, %s\n",name);
    printf("Next, let's start learning the knowledge of the Embedded Systems Project unit 1 together.\n");

    //initialize the progress
    for (int i = 0; i < 4; i++) {
        user.unit_completed[i] = 0;
        user.answer_correct[i] = 0;
        user.answer_correct_1time[i] = 0;
    }

    for(;;) {
        main_menu();
    }
    /* not reached */
    return 0;
}

static void main_menu(void)
{
    print_main_menu();
    {

        int input = get_user_input();
        select_menu_item(input);
    }
}

static int get_user_input(void)
{
    enum { MENU_ITEMS = 6 };   /* 1..5 = items, 6 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}

static void select_menu_item(int input)
{
    unit_answer_correct = 0;
    unit_attempts = 0;
    switch (input) {
        case 1:
            menu_item_1();
            update_progress(0);
            go_back_to_main();
            break;
        case 2:
            menu_item_2();
            update_progress(1);
            go_back_to_main();
            break;
        case 3:
            menu_item_3();
            update_progress(2);
            go_back_to_main();
            break;
        case 4:
            menu_item_4();
            update_progress(3);
            go_back_to_main();
            break;
        case 5:
            generate_report();
            go_back_to_main();
            break;
        default:
            printf("Bye!\n");
            exit(0);
    }
}

static void print_main_menu(void)
{
    printf("\n----------- Choose the topic -----------\n");
    printf("\n"
           "\t1. C recap");
    if (user.unit_completed[0]) printf("\tFinish");
    printf("\n"
           "\t2. Arrays & Strings");
    if (user.unit_completed[1]) printf("\tFinish");
    printf("\n"
           "\t3. Functions & Modular Code");
    if (user.unit_completed[2]) printf("\tFinish");
    printf("\n"
           "\t4. Memory & Pointers");
    if (user.unit_completed[3]) printf("\tFinish");
    printf("\n"
           "\t5. Generate Report\n"
           "\t6. Exit\n");
    printf("----------------------------------------\n");
}

static void go_back_to_main(void)
{
    char buf[64];
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            puts("\nInput error. Exiting.");
            exit(1);
        }
        buf[strcspn(buf, "\r\n")] = '\0'; /* strip newline */
    } while (!(buf[0] == 'b' || buf[0] == 'B') || buf[1] != '\0');
}

/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
static int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}

static void update_progress(int unit_index) {
    user.unit_completed[unit_index] = 1;
    user.answer_correct[unit_index] = unit_answer_correct;

    if (unit_attempts == 1 && unit_answer_correct) {
        user.answer_correct_1time[unit_index] = 1;
    } else {
        user.answer_correct_1time[unit_index] = 0;
    }
}

static void generate_report(void){
    int completed_count = 0;
    for (int i = 0; i < 4; i++) {
        if (user.unit_completed[i]) completed_count++;
    }
    
    //if there is no learning record, go back to the menu
    if (completed_count == 0) {
        printf("\nNo learning data to report yet!\n");
        printf("Complete at least one unit to generate a report.\n");
        return;
    }

    //create the file name
    char file_name[100];
    strcpy(file_name,user.name);
    strcat(file_name,"_Report_ECHO.txt");

    //open the file
    FILE *report = fopen(file_name, "w");
    if (!report) {
        printf("Error creating report file!\n");
        return;
    }

    //write in the report
    fprintf(report,"ELEC2645: Embedded Systems Project\n");
    fprintf(report,"From ECHO learning assistant\n\n");

    fprintf(report, "Student Name: %s\n\n", user.name);

    int correct_count = 0;
    int first_try_correct = 0;
    
    for (int i = 0; i < 4; i++) {
        fprintf(report, "Unit 1.%d: ", i+1);
        
        if (user.unit_completed[i]) {
            fprintf(report, "Completed\n");
            fprintf(report, "  Final result: ");
            if (user.answer_correct[i]) 
                fprintf(report, "Correct\n");
            else 
                fprintf(report, "Incorrect\n");
            
            
            fprintf(report, "  First attempt correct: ");
            if (user.answer_correct_1time[i]) 
                fprintf(report, "Yes\n");
            else
                fprintf(report, "No\n");
            
            
            if (user.answer_correct[i]) 
                correct_count++;
            if (user.answer_correct_1time[i]) 
                first_try_correct++;
        } else {
            fprintf(report, "Not started\n");
        }
        fprintf(report, "\n");
    }

    fprintf(report, "Performance Summary:\n");
    fprintf(report, "Total units completed: %d/4 (%.0f%%)\n", completed_count, (float)completed_count/4*100);
    fprintf(report, "\nRecommendations:\n");
    
    if (completed_count == 4) {
        fprintf(report, "Excellent! You have completed all units.\n");
    } else if (completed_count >= 2) {
        fprintf(report, "Good progress! Keep completing the remaining units.\n");
    } else {
        fprintf(report, "You're getting started! Continue with the next unit.\n");
    }
    
    fprintf(report, "\n");
    fprintf(report, "Generated by ECHO Learning Assistant\n");
    fprintf(report, "ELEC2645\n");
    
    fclose(report);
    
    printf("\nReport generated successfully!\n");
    printf("File saved as: %s\n", file_name);
}