#include <stdio.h>
#include "functions.h"

int main() {
    int day, month, year, days_left_to_add;
    printf("Please enter a date between the years 1800 and 10000 in the format dd/mm/yyyy (days to add): ");
    if (scanf("%d/%d/%d %d", &day, &month, &year, &days_left_to_add) != 4) {
        printf("Date format incorrect!\n");
        return 1;
    }
    if (!is_valid_date(day, month, year)) {
        printf("Date entered is not valid!\n");
        return 1;
    }    
    
    add_days_to_date(&day, &month, &year, days_left_to_add);
    
    const char* day_of_week = calculate_day_of_week(day, month, year);
    printf("The new date is now: %s %d%s %s, %d.\n", day_of_week, day, get_suffix(day), month_names[month], year); 

}
