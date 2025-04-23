#include "foo.h"
#include <stdio.h>

static char buffer[11];  // "DD/MM/YYYY" + '\0'

char* foo(int month, int day, int year) {
    if (year < 1900 || year > 2099) return "E03";        // NODO 01
    if (month < 1 || month > 12) return "E01";           // NODO 02

    int daysInMonth; 

    switch (month) {// dias no mês                       // NODO 03
        case 1: case 3: case 5: case 7:                  // NODO 04
        case 8: case 10: case 12:                        
            daysInMonth = 31;                            
            break;										 
        case 4: case 6: case 9: case 11:				 // NODO 05
            daysInMonth = 30;							 
            break;										
        case 2:											 // NODO 06
            // NODO 07
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) 
                daysInMonth = 29;					   
            else										// NODO 08
                daysInMonth = 28;						
            break;
        default:										// NODO 09
            return "E01";  
    }

    // Valida de dia no mês
    if (day < 1 || day > daysInMonth) return "E02";     // NODO 10


    int nd = day + 1;
    int nm = month; 
    int ny = year;

    if (nd > daysInMonth) {                            // NODO 11
        nd = 1;										
        nm++;
        if (nm > 12) {								  // NODO 12
            nm = 1; 
            ny++;
            if (ny > 2099) return "E04";			// NODO 13
        }
    }
    snprintf(buffer, sizeof(buffer), "%02d/%02d/%04d", nd, nm, ny); 
    return buffer;// NODO 14
}
