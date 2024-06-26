/*
 * File:   view_log.c
 * Author: sarang mp
 *
 * Created on 27 May, 2024, 4:48 PM
 */

#include <xc.h>
#include "main.h"
#include "clcd.h"
#include "external_eeprom_2.h"
#include"matrix_keypad.h"

extern char main_f;
char view_array[11];
extern char lap;
extern char overflow;
extern unsigned short adc_reg_val;
extern unsigned char time[9];
extern char *events[8];
extern char store[5];

char start_index = 0, apend_index = 0;

void view_log(char key) {


    if (key == 16) {
        main_f = 2;
    }


    if (overflow == 0) {
        start_index = 0;

        if (key == MK_SW5 && apend_index < lap - 1) {
            apend_index++;
        }

        if (key == MK_SW6 && apend_index > 0) {
            apend_index--;
        }


        

    } else if (overflow == 1) {
        start_index = lap;

        if (key == MK_SW5 && apend_index < 9) {
            apend_index++;
        }
        if (key == MK_SW6 && apend_index > 0) {
            apend_index--;
        }


    }


    for (int j = 0; j < 5; j++) {
        view_array[j] = read_external_eeprom((start_index + apend_index) % 10 * 10 + j);
    }


    clcd_print("Entered View Log", LINE1(0));
    clcd_putch('0' + apend_index, LINE2(0));

    /*time*/
    clcd_putch((view_array[0]/10)+48, LINE2(2));
    clcd_putch((view_array[0]%10)+48, LINE2(3));
    clcd_putch(':', LINE2(4));

    clcd_putch((view_array[1]/10)+48, LINE2(5));
    clcd_putch((view_array[1]%10)+48, LINE2(6));
    clcd_putch(':', LINE2(7));

    clcd_putch((view_array[2]/10)+48, LINE2(8));
    clcd_putch((view_array[2]%10)+48, LINE2(9));

    /*event*/
    clcd_print(events[view_array[3]], LINE2(11));
    //clcd_putch(view_array[3], LINE2(12));

    /*speed*/
    clcd_putch((view_array[4]/10)+48, LINE2(14));
    clcd_putch((view_array[4]%10)+48, LINE2(15));
   

}
