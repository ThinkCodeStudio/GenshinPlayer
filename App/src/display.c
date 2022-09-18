#include "display.h"
#include "lcd_header.h"

#define TEXT_HIGH 25
#define TEXT_WIDTH 80

void display_init(score_t* score){
	BACK_COLOR = WHITE;
	POINT_COLOR = BLACK;
	
	for(int i=0; i<score->beats_count; i++){
		LCD_ShowString(TEXT_WIDTH*(i%6),TEXT_HIGH*(i/6),TEXT_WIDTH, TEXT_HIGH, 16, (uint8_t*)score->beats[i].keys);
		if(TEXT_HIGH*(i/6)>800)
			break;
	}
	
}
