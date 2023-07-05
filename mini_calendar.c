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
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add ) {
    
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

int main() {
    int mm, dd, yy, days_left_to_add;
    printf("Please enter a date between the tears 1800 and 10000 in the format mm/dd/yyyy (days to add): ");
    scanf("%d/%d/%d %d", &mm, &dd, &yy, &days_left_to_add);
    
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    
    printf("The new date is now: %d/%d/%d\n", mm, dd, yy);
    
}