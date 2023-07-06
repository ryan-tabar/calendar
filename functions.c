#include "functions.h"

// April, June, September, November = 30 days
// The rest = 31 days
// Feb = 28 unless leap year then 29
const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char* month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }   
}

void add_days_to_date(int* day, int* month, int* year, int days_left_to_add) {
    
    while (days_left_to_add > 0) {
        int days_left_in_month = days_in_month[*month] - *day;
        // if february and leap year, then add 1 day
        if (*month == 2 && is_leap_year(*year)) {
            days_left_in_month++; 
        }
        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= days_left_in_month;
            days_left_to_add--;
            *day = 1;
            // if december, change month to january and increment year
            if (*month == 12) {
                (*year)++;
                *month = 1;
            } else {
                (*month)++;
            }
        } else {
            *day += days_left_to_add;
            days_left_to_add = 0;
        }
    } 
}

const char* calculate_day_of_week(int day, int month, int year) {
    const char* days_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    if (month < 3) {
        month += 12;
        year--;
    }
    
    int century = year / 100;
    int year_of_century = year % 100;
    
    int h = (day + 13 * (month + 1) / 5 + year_of_century + year_of_century / 4 + century / 4 - 2 * century + 6) % 7;
    
    if (h < 0) {
        h += 7;
    }

    return days_of_week[h];
}

const char* get_suffix(int day) {
    int last_digit = day % 10;
    const char* suffixes[] = {"th", "st", "nd", "rd"};
    return last_digit < 1 || last_digit > 3 ? suffixes[0] : suffixes[last_digit];
}

bool is_valid_date(int day, int month, int year) {
     return !(day < 1 || day > days_in_month[month] || month < 1 || month > 12 || year < 1800 || year > 10000); 
}   
