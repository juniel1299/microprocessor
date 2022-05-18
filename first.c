//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include <avr/delay.h>
int count = 9999; //전역변수
int main(void)
{ char seg_num[10] = {0x3F, 0x06, 0x58, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
char seg_good[4] = {0x7D, 0x5C, 0x5C, 0x5E};
char seg_fail[4] = {0x71, 0x77, 0x06, 0x38};
int i = 0, N4, N3, N2, N1;
char success_flag = 0, fail_flag = 0;

//DDRC = 0x0F;
//DDRA = 0xff;

//TIMSK = 0x10; // 0CIE1A = 1, Timer1 A compare match
//TCCR1A = 0x00; 
//TCCR1B = 0x0D; //CTC mode , 1024 분주 , 16MHZ / 1024 = 15625Hz
//OCR1A = 15625; //1초마다

sei(); //SREG I = enable

while (1)
{ N4 = (count / 1000);
N3 = (count % 1000) / 100;
N2 = (count % 100) / 10;
N1 = (count % 10);

//PORTC = 0x0E;
//PORTA = seg_num[N4];
_delay_ms(5);
PORTC = 0x0D;
PORTA = seg_num[N3];
_delay_ms(5);
PORTC = 0x0B;
PORTA = seg_num[N2];
_delay_ms(5);
PORTC = 0x07;
PORTA = seg_num[N1];
_delay_ms(5);

}
}

ISR(TIMER1_COMPA_vect){
    count --;
}
