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
int _last_drawing[TIP_SIZE];

bool is_empty(int drawing_numbers[]);
bool contains_digit(int tip[TIP_SIZE], int digit);

bool init_lottery(const char *csv_file, char csv_separator)
{
  _stream = fopen(csv_file, "r");
  if (_stream == 0) {
    return false;
  }
  _seperator = csv_separator;
  for (int i = 0; i < TIP_SIZE; i++) {
    _last_drawing[i] = 0;
  }
  return true;
}

bool get_tip(int tip_number, int tip[TIP_SIZE])
{
    if (tip_number < 0 || tip_number >= 44){
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
  for (int i = 0; i < TIP_SIZE; i++) {
    if (drawing_numbers[i] <= 0 || drawing_numbers[i] > 45)
    {
        return false;
    }
  }
  for (int i = 0; i < TIP_SIZE; i++)
  {
      _last_drawing[i] = drawing_numbers[i];
  }
  return true;
}

bool is_empty(int drawing_numbers[])
{
    for (int i = 0; i < TIP_SIZE; ++i) {
        if (drawing_numbers[i] != 0) return false;
    }
    return true;
}

int get_tip_result(int tip_number){
  if (tip_number < 0 || tip_number >= 44) {
    return -2;
  }
  if (is_empty(_last_drawing)){
    return -1;
  }
  int tip[TIP_SIZE];
  int count = 0;
  get_tip(tip_number,tip);
  for (int i = 0; i < TIP_SIZE; i++) {
    for (int j = 0; j < TIP_SIZE; j++) {
      if (_last_drawing[i] == tip[j]){
        count++;
      }
    }
  }
  return count;
}
int get_right_tips_count(int right_digits_count){
 return 0;
}



bool contains_digit(int tip[TIP_SIZE], int digit)
{
  return false;
}
