#ifndef FUNCTIONS_H
#define FUNCTIONS_H
 
#include <stdio.h>
#include <stdbool.h> 
 
bool is_leap_year(int);

extern const int days_in_month[];
extern const char* month_names[];

void add_days_to_date(int*, int*, int*, int);
const char* calculate_day_of_week(int, int, int);
const char* get_suffix(int);
bool is_valid_date(int, int, int);

#endif
