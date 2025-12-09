#ifndef FUNCS_H
#define FUNCS_H

extern int unit_answer_correct;
extern int unit_attempts;

void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);
void ask_name(char *name);
void greeting(void);
void do_you_understand(int part);
void ask_question(int part);
void check_answer(int part);
void shuffle_options(int part);


#endif