#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"
#define SIZE 30

int unit_answer_correct;
int unit_attempts;

static char shuffled_correct_answers[4] = {0};

void menu_item_1(void) {
    int understood = 0;
    char response[10];

    //teaching section
    printf("\n>> Unit 1.1: C recap\n");
    printf("Before you use a piece of data, you must tell the computer what type it is.\n");
    printf("There are some examnple:\n");
    printf("int: For whole numbers(e.g. 5, -10)\n");
    printf("float: For numbers with decimals(e.g. 3.1415, -1.2)\n");
    printf("char: For a single character(e.g. 'A', 's')\n");
    do_you_understand(1);
    printf("The next knowledge point is if and else\n");
    printf("This lets the program make decisions\n");
    printf("if: only if the condition is true\n");
    printf("else: if the condition is false\n");
    do_you_understand(2);
    printf("The next point is about for loop and while loop\n");
    printf("Use a for loop when you know exactly how many times you want to repeat something.\n");
    printf("Use a while loop to repeat code as long as a condition is true.\n You might not know how many times it will run.\n");
    
    //question section
    ask_question(1);
    check_answer(1);
}

void menu_item_2(void) {
    printf("\n>> Unit 1.2: array and string\n");
    printf("An Array is like a row of lockers. \n");
    printf("Each locker holds one item (like an int or char), and they are all numbered starting from 0.\n");
    do_you_understand(3);
    printf("A String in C is just a special kind of array-an array of characters. \n");
    printf("The last character must always be a null character \\0 (a zero). \n");
    printf("This \\0 acts like a \"THE END\" sign, \n");
    printf("so the computer knows where the string stops.\n");
    do_you_understand(4);

    //question section
    ask_question(2);
    check_answer(2);
    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    printf("\n>> Unit 1.3: functions and modular code\n");
    printf("What is a Function?\n");
    printf("A function is a reusable block of code that performs a specific task.\n");
    printf("Think of it as a mini-program within your main program.\n");
    printf("Like a vending machine: you give it input (money), it does work, and returns output (a snack).\n\n");
    do_you_understand(5);
    printf("Modular Code - Why Use Functions?\n");
    printf("1. Reusability: Write once, use many times\n");
    printf("2. Organization: Break complex problems into smaller, manageable pieces\n");
    printf("3. Debugging: Easier to test and fix individual functions\n");
    printf("4. Collaboration: Different people can work on different functions\n");
    printf("5. Readability: main() becomes cleaner and more understandable\n\n");
    do_you_understand(6);

    //question section
    ask_question(3);
    check_answer(3);
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    printf("\n>> Menu 1.4:memory and pointers\n");
    printf("Understanding Memory\n");
    printf("- Memory is like a giant street with numbered houses.\n");
    printf("- Each house (memory location) has a unique ADDRESS.\n");
    printf("- Each house can store a VALUE (data).\n");
    printf("- In C, every variable lives at a specific memory address.\n\n");
    do_you_understand(7);
    printf("\nWhat is a Pointer?\n");
    printf("- A pointer is a SPECIAL variable that stores a MEMORY ADDRESS.\n");
    printf("- Think of it as a GPS coordinate or a house number.\n");
    printf("- It doesn't store data directly, but WHERE the data is.\n\n");
    do_you_understand(8);

    ask_question(4);
    check_answer(4);
    /* you can call a function from here that handles menu 4 */
}

void greeting(void){
    printf("Hello, my name is \n\n");
    printf("EEEEEE   CCCCC   H    H   OOOOOO\n");
    printf("EE      CC       H    H   O    O\n");
    printf("EEEEE   CC       HHHHHH   O    O\n");
    printf("EE      CC       H    H   O    O\n");
    printf("EEEEEE   CCCCC   H    H   OOOOOO\n\n");
    printf("I am an assistant here to help you understand the content of ELEC2645 Unit 1.\n");
    printf("Firstly, may I have your name please?\n");
}

void ask_name(char *name){
    printf("Please enter your name >>");
    fgets(name,SIZE,stdin);
    name[strcspn(name,"\n")] = '\0';
}/*ask for the users name*/

void do_you_understand(int part){
    int understood = 0;
    char response[10];
    do {
        printf("\nDo you understand?(Y/N)>>");
        fgets(response, sizeof(response), stdin);
        response[strcspn(response, "\r\n")] = '\0'; /* strip newline */
        if(strlen(response)==1){
            if(response[0]=='Y'||response[0]=='y'){
                printf("Good job! lets continue\n\n");
                understood = 1;
            }else if (response[0]=='N'||response[0]=='n'){

            //This section is used to change different contents.
            switch(part)
            {
                case 1:
                printf("\nFor example, you can write the code like that:\n");
                printf("int age = 20;\n");
                printf("float height = 173.5;\n");
                printf("char grade = 'A';\n");
                break;
                case 2:
                printf("\nFor example, you can write the code like that:\n\n");
                printf("if(age > 18){\n");
                printf("\tprint he/she is an adult\n");
                printf("}else{\n");
                printf("\tprint he/she is underage\n");
                printf("}\n");
                break;
                case 3:
                printf("\nExample:\n");
                printf("int scores[3]; // An array of 3 integers\n");
                printf("scores[0] = 95; // First locker\n");
                printf("scores[1] = 87; // Second locker\n");
                printf("scores[2] = 72; // Third locker\n");
                break;
                case 4:
                printf("Example:\n");
                printf("char name[5]; // An array for a 4-letter name + the '\\0'\n");
                printf("name[0] = 'J';\n");
                printf("name[1] = 'o';\n");
                printf("name[2] = 'h';\n");
                printf("name[3] = 'n';\n");
                printf("name[4] = '\\0'; // Don't forget this!\n");
                break;
                case 5:
                printf("Example:\n");
                printf("int add(int a, int b) {   // Function declaration\n");
                printf("    int result = a + b;   // Body - the actual work\n");
                printf("    return result;        // Return value\n");
                printf("}\n");
                printf("// Usage: int sum = add(5, 3); // sum becomes 8\n\n");
                break;
                case 6:
                printf("Without functions:\n");
                printf("main() { do_taskA(); do_taskA(); do_taskA(); do_taskB(); ... }\n");
                printf("// Messy and repetitive!\n\n");
                printf("With functions:\n");
                printf("main() {\n");
                printf("    process_data();\n");
                printf("    display_results();\n");
                printf("    calculate();\n");
                printf("}\n");
                printf("// Clean and organized!\n");
                break;
                case 7:
                printf("Example:\n");
                printf("int age = 25;\n");
                printf("'age' is a variable name we use in code\n");
                printf("It's stored at a specific memory address (e.g., 0x7ffd...)\n");
                printf("The value 25 is stored at that address\n");
                break;
                case 8:
                printf("Pointer Syntax:\n");
                printf("int *ptr;  // 'ptr' is a pointer to an integer\n");
                printf("// The asterisk (*) means \"pointer to\"\n\n");
                break;
            }

            }else{
                printf("Invalid input, please enter again.\n");
            }
        }else{
           printf("Error: please enter single character\n");
        } 
    } while (understood != 1);
}
void ask_question(int part){
    printf("This is the entire content of Unit 1.%d. Now, let me test your knowledge.\n",part);
    char *options[4];
    switch(part)
        {
            case 1:
            printf("Question1:What's the output of these code?\n");
            printf("---------------------------------------------\n");
            printf("#include <stdio.h>\n\n");
            printf("int main() {\n");
            printf("    int count = 0;\n");
            printf("    int number = 10;\n");
            printf("    while (number > 0) {\n");
            printf("        if (number %% 2 == 0) {\n");
            printf("            count++;\n");
            printf("        }\n");
            printf("        number--;\n");
            printf("    }\n");
            printf("    printf(\"Count: %%d\\\\n\", count);\n");
            printf("    return 0;\n");
            printf("}\n");
            printf("---------------------------------------------\n\n");
            break;
            case 2:
            printf("Question2: What is the output of the following code?\n\n");
            printf("---------------------------------------------\n\n");
            printf("#include <stdio.h>\n");
            printf("int main() {\n");
            printf("    char str[6] = \"hello\";\n");
            printf("    str[2] = '\\0';\n");
            printf("    printf(\"%%s\", str);\n");
            printf("    return 0;\n");
            printf("}\n\n");
            printf("---------------------------------------------\n\n");
            break;
            case 3:
            printf("Question3: What is the output of this program?\n\n");
            printf("---------------------------------------------\n\n");
            printf("#include <stdio.h>\n");
            printf("\nint calculate(int x) {\n");
            printf("    return x * 2 + 1;\n");
            printf("}\n");
            printf("\nint main() {\n");
            printf("    int a = 3;\n");
            printf("    int b = calculate(a);\n");
            printf("    printf(\"Result: %%d\", calculate(b));\n");
            printf("    return 0;\n");
            printf("}\n\n");
            printf("---------------------------------------------\n\n");
            break;
            case 4:
            printf("Question4: What is the output of this program?\n\n");
            printf("---------------------------------------------\n\n");
            printf("#include <stdio.h>\n");
            printf("\nint main() {\n");
            printf("    int x = 10;\n");
            printf("    int *ptr = &x;\n");
            printf("    \n");
            printf("    *ptr = 20;\n");
            printf("    int y = *ptr + 5;\n");
            printf("    \n");
            printf("    printf(\"x = %%d, y = %%d\\n\", x, y);\n");
            printf("    return 0;\n");
            printf("}\n\n");
            printf("---------------------------------------------\n\n");
            break;
        }
        shuffle_options(part);
}

void check_answer(int part){
    int correct = 0;
    char ch[10];
    int attempts = 0;
    int index = part - 1;

    char current_correct_answer = shuffled_correct_answers[index];

    do{
        attempts++;
        int input = 0;
        printf("The answer is>>");
        fgets(ch,sizeof(ch),stdin);
        ch[strcspn(ch, "\r\n")] = '\0';
        if(strlen(ch)==1){//judge weather the length of input is correct
            //if single character
            if(ch[0]>='A'&&ch[0]<='D'){//Convert capital letters to lowercase letters
                ch[0]=ch[0]+32;
                input=1;
            }   
            else if(ch[0]>='a'&&ch[0]<='d'){
                input = 1;
            }else{
                printf("Wrong input, please enter again\n");
                input = 0;
            }
        }else{
            //if it isn't a single character
            printf("Error: please enter single character\n");
            input = 0;//judge weather the length of input is correct
        }
        if(input == 1){
            if(ch[0]==current_correct_answer){
                printf("Correct answer, well done!!!\n");
                correct = 1;
            }else{
                printf("wrong answer, please try again\n");
                correct = 0; 
            }
        }
    }while(correct!=1);

    //update the value
    unit_answer_correct = correct;
    unit_attempts = attempts;
}

void shuffle_array(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); 
        
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void shuffle_options(int part) {
    srand(time(NULL));//get a random value
    
    char *option_contents[4];
    int original_indices[4] = {0, 1, 2, 3}; 
    int correct_index = 0;
    
    switch(part) {
        case 1: 
            option_contents[0] = "Count: 5";
            option_contents[1] = "Count: 10";
            option_contents[2] = "Count: 0";
            option_contents[3] = "Count: 6";
            correct_index = 0; //which one is the correct answer
            break;
            
        case 2:
            option_contents[0] = "hello";
            option_contents[1] = "he";
            option_contents[2] = "he\\0lo";
            option_contents[3] = "hel";
            correct_index = 1;
            break;
            
        case 3:
            option_contents[0] = "Result: 7";
            option_contents[1] = "Result: 14";
            option_contents[2] = "Result: 15";
            option_contents[3] = "Result: 6";
            correct_index = 2; 
            break;
            
        case 4: 
            option_contents[0] = "x = 10, y = 15";
            option_contents[1] = "x = 20, y = 25";
            option_contents[2] = "x = 10, y = 25";
            option_contents[3] = "x = 20, y = 15";
            correct_index = 1;
            break;
    }
    

    shuffle_array(original_indices, 4);


    printf("Options:\n");
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, option_contents[original_indices[i]]);
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++) {
        if (original_indices[i] == correct_index) {
            shuffled_correct_answers[part-1] = 'a' + i; 
            break;
        }
    }
}


