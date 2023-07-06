#include <stdio.h>
#include <stdbool.h>

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

// April, June, September, November = 30 days
// The rest = 31 days
// Feb = 28 unless leap year then 29
const int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const char* month_names[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void add_days_to_date(int* dd, int* mm, int* yy, int days_left_to_add ) {
    
    while (days_left_to_add > 0) {
        int days_left_in_month = days_in_month[*mm] - *dd;
        // if february and leap year, then add 1 day
        if (*mm == 2 && is_leap_year(*yy)) {
            days_left_in_month++; 
        }
        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= days_left_in_month;
            days_left_to_add--;
            *dd = 1;
            // if december, change month to january and increment year
            if (*mm == 12) {
                (*yy)++;
                *mm = 1;
            } else {
                (*mm)++;
            }
        } else {
            *dd += days_left_to_add;
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
    return last_digit < 1 | last_digit > 3 ? suffixes[0] : suffixes[last_digit];
}

int main() {
    int dd, mm, yy, days_left_to_add;
    printf("Please enter a date between the years 1800 and 10000 in the format dd/mm/yyyy (days to add): ");
    scanf("%d/%d/%d %d", &dd, &mm, &yy, &days_left_to_add);
    
    add_days_to_date(&dd, &mm, &yy, days_left_to_add);
    
    const char* day_of_week = calculate_day_of_week(dd, mm, yy);
    printf("The new date is now: %s %d%s %s, %d.\n", day_of_week, dd, get_suffix(dd), month_names[mm], yy); 

}
