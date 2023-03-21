#include <stdio.h>
#include <math.h>
#include <string.h>

struct Point {
	float x;
	float y;
};

struct Circle {
	struct Point dot;
	float r;
};

int main()
{
	FILE *file_1;

	file_1 = fopen("input.txt", "r");
	char* object;
	char line[100];
	char line_1[100];
	int cnt = 0; //counter
	int kol_vo_str = 0;
	struct Circle data_object_circle[100];

	struct Circle str_now;

	while ((fgets(line, 100, file_1)) != 0) {  //cчитывает символы
		printf("\n");
		strcpy(line_1, line);   //копирует строкy
		object = strtok(line_1, "("); // ищет лексему (
		kol_vo_str++;

        if (strcmp(object, "circle") == 0) { //strcmp сравнивает строки, возвр их отношение
			if ((sscanf(line,"circle(%f %f, %f)",&str_now.dot.x,&str_now.dot.y,&str_now.r)) == 3){
				data_object_circle[cnt].dot.x = str_now.dot.x;
				data_object_circle[cnt].dot.y = str_now.dot.y;
				data_object_circle[cnt].r = str_now.r;
				cnt++;
			}
			else{
				printf("%s(%f %f, %f)\n",line_1,str_now.dot.x,str_now.dot.y,str_now.r);
				printf("\n\tError at column %d: Incorrect data of parameters of circle (where's the comma?)\n", kol_vo_str);
			}
		} 
        else{
			printf("%s\n",line);
			printf("\tError at column %d: Incorrect type format \n",kol_vo_str);
		}
	}
	printf("\n\n\n");
    for(int i = 0; i < cnt; i++){
		printf("%d. Circle(%f, %f, %f)\n\n", i+1, data_object_circle[i].dot.x, data_object_circle[i].dot.y,data_object_circle[i].r);
		printf("\tperimeter = %f\n", 2*M_PI*data_object_circle[i].r);
		printf("\tarea = %f\n\n", M_PI*pow(data_object_circle[i].r, 2));

        printf("\n\n\n");
    }
    return 0;
}
