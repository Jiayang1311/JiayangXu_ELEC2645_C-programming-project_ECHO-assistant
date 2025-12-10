ELEC2645 Unit 2 Project: ECHO Learning Assistant

This project implements a command line learning assistant application for ELEC2645 Embedded Systems Project Unit 1 content. The application guides users through C programming fundamentals with interactive teaching and assessment.

The code has separated the menu handling code in main.c and the function implementations in funcs.c. The funcs.c file contains all the teaching content, interactive questions, and assessment logic, while main.c manages the user interface and progress tracking.

1.Run code
You can build the code as we have been using in the labs with

gcc main.c funcs.c -o main.out -lm 

(the -lm is required to link the math library). You can also use make -B to force a rebuild using the provided Makefile.

Then run the code with ./main.out or main.out

And you can also delete the file by del main.out

The report will generate at the same folder of this file.

2.Project Features
The ECHO Learning Assistant includes the following key features:
    Interactive learning with "Do you understand?" prompts and example code explanations.
    Randomized quizzes with shuffled multiple-choice options for each unit.
    Progress tracking that records completion status and quiz performance.
    Personalized reports generated as text files with student performance summary.
    User-friendly interface art logo and intuitive menu navigation.

Reference:
Knuth, Donald E. (1969). Seminumerical algorithms. The Art of Computer Programming. Vol. 2. Reading, MA: Addison–Wesley. pp. 139–140.
Wikipedia. (2023). Fisher–Yates shuffle. Wikipedia, The Free Encyclopedia. Available at: https://en.wikipedia.org/wiki/Fisher–Yates_shuffle (Accessed: 23 January 2025).
