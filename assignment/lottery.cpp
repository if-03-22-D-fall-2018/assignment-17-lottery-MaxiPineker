/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lottery.h"

#define UUID_LEN 40
#define MAX_TIP_LEN 17
#define MAX_LINE_LEN (UUID_LEN + 1 + MAX_TIP_LEN)

FILE *_stream;
char _seperator;
int _line_number = 0;
int _last_drawing[TIP_SIZE];

int get_line_numbers();
bool is_tip_valid(int tip[TIP_SIZE]);
bool contains_digit(int tip[TIP_SIZE], int digit);

bool init_lottery(const char *csv_file, char csv_separator)
{
    _stream = fopen(csv_file, "r");
    if (_stream == 0)
    {
        return false;
    }
    _seperator = csv_separator;
    _line_number = get_line_numbers();
    for (int i = 0; i < TIP_SIZE; i++)
    {
        _last_drawing[i] = 0;
    }
    return true;
}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
    if (tip_number < 0 || tip_number >= get_line_numbers()){
      return false;
    }
    char line[MAX_LINE_LEN];
    rewind(_stream);
    for (int i = 0; i <= tip_number; i++)
    {
        if (fgets(line, MAX_LINE_LEN, _stream) == 0){
          return false;
        }
    }
    char *token;
    char seperator[2] = {_seperator};
    int count = 0;
    token = strtok(line, seperator);
    token = strtok(0, seperator);
    while (token != 0)
    {
        tip[count] = atoi(token);
        count++;
        token = strtok(0, seperator);
    }
    return true;
}
bool set_drawing(int drawing_numbers[TIP_SIZE]){
 return false;
}
int get_tip_result(int tip_number){
 return 0;
}
int get_right_tips_count(int right_digits_count){
 return 0;
}

int get_line_numbers()
{
  int previous = ftell(_stream); //Save the current position in the stream for later
rewind(_stream);               //rewind to the beginning
int amount_of_lines = 1;       //set the amount of lines to 1 because there is at least 1 line
while (!feof(_stream))
{ //run through the file until it ends
    if (fgetc(_stream) == '\n')
    { //if the line ends -> increase amount_of_lines
        amount_of_lines++;
    }
}
fseek(_stream, previous, SEEK_SET); //go back to the previous position
return amount_of_lines;
}
bool is_tip_valid(int tip[TIP_SIZE])
{
  return false;
}
bool contains_digit(int tip[TIP_SIZE], int digit)
{
  return false;
}
