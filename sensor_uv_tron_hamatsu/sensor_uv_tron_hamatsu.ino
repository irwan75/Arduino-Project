#include
#include
#define kanan PORTA.0
#define kiri PORTA.1
#define geni PIND.5
void maju()
{
int i;
for(i=1;i<50;i++) { kanan=1; delay_us(2300); kanan=0; delay_us(18000); kiri=1 ; delay_us(3120); kiri=0 ; delay_us(22000); } } void main(void) { unsigned char banyaknya; PORTC=0xFF; DDRC=0×00; PORTD=0xFF; DDRD=0xFF; while (1) { if (geni==0) {banyaknya++;}; if (banyaknya>=3)
{
maju();
banyaknya=0;
};

}
}
