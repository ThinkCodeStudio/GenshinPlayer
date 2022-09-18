/****
Z字顺序显示
*****/



#include "display.h"
#include "lcd_header.h"
#include <stdbool.h>
#include <string.h>



#define TEXT_HIGH 40
#define TEXT_WIDTH 80

const int show_beat_all = (SSD_VER_RESOLUTION/TEXT_HIGH)*(SSD_HOR_RESOLUTION/TEXT_WIDTH);

static uint32_t show_beat_next = 0;
static uint32_t show_beat_count = 0;
//文本
void show_text(int i,const char *str){
	int x = TEXT_WIDTH*(i%6);
	int y = TEXT_HIGH*(i/6);
	LCD_Fill(x, y, x+TEXT_WIDTH, y+TEXT_HIGH, BACK_COLOR);
	
	int txt_w = 10*strlen(str);
	int txt_h = 25;
	LCD_ShowString(x+((TEXT_WIDTH-txt_w)/2), y+((TEXT_HIGH-txt_h)/2),txt_w, txt_h, 16, (uint8_t*)str);
}
//显示部分乐谱按键表
int display_show_score(score_t* score, int index){
	show_beat_count = 0;
	show_beat_next = 0;
	BACK_COLOR = WHITE;
	LCD_Clear(WHITE);
	for(int i=index; i<score->beats_count; i++){
		show_text(i-index, score->beats[i].keys);
		show_beat_count++;
		if(i-index < show_beat_all)
			continue;
		return i;
	}
	return score->beats_count;
}
//下一拍变为焦点
int display_beat_next(score_t* score, int index){
	show_beat_next = index%show_beat_all;
	if(show_beat_next){
		BACK_COLOR = WHITE;
		show_text(show_beat_next-1, score->beats[index-1].keys);
	}
	BACK_COLOR = YELLOW;
	show_text(show_beat_next, score->beats[index].keys);
	if(show_beat_next==show_beat_all-1){
		display_show_score(score, index+1);
		return 1;
	}
	return 0;
}
//初始化
int display_init(score_t* score){
	BACK_COLOR = WHITE;
	POINT_COLOR = BLACK;
	
	return display_show_score(score,0);
}

