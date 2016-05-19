/* Homework 0, 600.120 Spring 2015
 * JHED: amehndi1
 * Name: Anuj Mehndiratta
 * Date: February 2nd, 2016
 *  */

#include <stdio.h>
#include <string.h>

#define LENGTH 16

int main(int argc, char* argv[])
{
	char course[LENGTH];
	if (argc == 1) 
	{ 
		printf("Usage: hw0 XX.###.###Gg#.#\n");
		return 1;  // exit program
    }
    
    strncpy(course, argv[1], LENGTH);  // copy to course string
    course[LENGTH-1] = '\0';   // make sure last character is null
    printf("course string: %s\n", course);  // echo input
	char divisions[] = {'S', 'U', 'D', 'N', 'E', 'H', 'Y', 'A', '\0'};
	char grades[] = {'A', 'B', 'C', 'D', 'F', 'I', 'S', 'U', '\0'};
	int division = course[1]-'0';
	char grade = course[10];
	for (int i = 0; i <= 7; i++) 
	{
		if (course[1] == divisions[i]) 
		{
			division = i;
		}
	}
	int grade_bit = 0;
	for (int i = 0; i <= 7; i++) 
	{
		if (grade ==  grades[i]) 
		{
			grade_bit = i;
		}
	}
	int department_digit_one = course[3]-'0';
	int department_digit_two = course[4]-'0';
	int department_digit_three = course[5]-'0';
	
	int course_digit_one = course[7]-'0';
	int course_digit_two = course[8]-'0';
	int course_digit_three = course[9]-'0';
	
	int credits = course[12]-'0';
	int credit_decimal = course[14]-'0';
	if (credit_decimal == 0) 
	{
		credit_decimal = 0;
	} 
	else {
		credit_decimal = 1;
	}	
	
	if (course[11] == '/')	
	{
		printf("Division: %d\nDepartment: %d%d%d\nCourse: %d%d%d\nGrade: %d\nCredits: %d %d\n",
			 division, department_digit_one, department_digit_two, department_digit_three, course_digit_one, course_digit_two, course_digit_three, grade_bit, credits, credit_decimal); 	 
	}
	else if (course[11] == '+') 
	{
		int plus = 0;
		printf("Division: %d\nDepartment: %d%d%d\nCourse: %d%d%d\nGrade: %d %d\nCredits: %d %d\n",
			 division, department_digit_one, department_digit_two, department_digit_three, course_digit_one, course_digit_two, course_digit_three, grade_bit, plus, credits, credit_decimal); 
	}	
	else if (course[11] == '-') 
	{
		int minus = 1;
		printf("Division: %d\nDepartment: %d%d%d\nCourse: %d%d%d\nGrade: %d %d\nCredits: %d %d\n",
			 division, department_digit_one, department_digit_two, department_digit_three, course_digit_one, course_digit_two, course_digit_three, grade_bit, minus, credits, credit_decimal); 		
	}	
	return 0;
}
