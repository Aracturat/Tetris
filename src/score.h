#ifndef h_score

#define h_score

//Считать имена в таблице результатов;
char* get_result_name(void);

//Считать счет в таблице результатов;
int* get_result(void);

//Записать результат в таблицу;
int take_result(int score,char* name,char* names,int* scores);

//Записать результат в файл;
void write_result(char* names,int* scores);

#endif
