#include <stdio.h>

#define YEARS 5
#define MONTHS 12
#define STARTYEAR 2018

int main() {
    float temps[YEARS][MONTHS];
    for(int year = 0; year < YEARS; year++) {
        printf("År %d\n", year + STARTYEAR);
        for(int month = 0; month < MONTHS; month++) {
            printf("\tMån %d: ", month + 1);
            float temp;
            scanf("%f", &temp);
            temps[year][month] = temp;
        }
    }

    // medeltemp/år
    for(int year = 0; year < YEARS; year++) {
        float sum = 0;
        for(int month = 0; month < MONTHS; month++) {
            sum += temps[year][month];
        }
        printf("År %d: %.2f\n", year + STARTYEAR, sum / MONTHS);
    }

    // MEDELTEMP TOT
    float sumTotal = 0;
    for(int year = 0; year < YEARS; year++) {
        for(int month = 0; month < MONTHS; month++) {
            sumTotal += temps[year][month];
        }
    }
    printf("Medeltemp totalt: %.2f\n", sumTotal / (YEARS * MONTHS));

    // VARMAst & KALLAST TEMP/ÅR
    for(int year = 0; year < YEARS; year++) {
        float coldest = temps[year][0];
        float warmest = temps[year][0];
        for(int month = 0; month < MONTHS; month++) {
            if(temps[year][month] > warmest) {
                warmest = temps[year][month];
            }
            if(temps[year][month] < coldest) {
                coldest = temps[year][month];
            }
        }
        printf("År %d kallast: %.2f varmast: %.2f\n", year + STARTYEAR, coldest, warmest);
    }

    // VARMAST & KALLAST TOT
    float coldest = temps[0][0];
    float warmest = temps[0][0];
    for(int year = 0; year < YEARS; year++) {
        for(int month = 0; month < MONTHS; month++) {
            if(temps[year][month] > warmest) {
                warmest = temps[year][month];
            }
            if(temps[year][month] < coldest) {
                coldest = temps[year][month];
            }
        }
    }
    printf("Totalt kallast: %.2f varmast: %.2f\n", coldest, warmest);

    return 0;
}