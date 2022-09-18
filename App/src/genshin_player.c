#include "genshin_player.h"
#include "keyboard.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>
#include "lcd_header.h"
#include "score.h"
#include "display.h"

//HID键盘数据
uint8_t g_hid_data[8] = {0};

//原神弹奏按键表
/*
uint8_t genshin_key_list[3][8] ={
	{Keyboard_null, Keyboard_q, Keyboard_w, Keyboard_e, Keyboard_r, Keyboard_t, Keyboard_y, Keyboard_u},
	{Keyboard_null, Keyboard_a, Keyboard_s, Keyboard_d, Keyboard_f, Keyboard_g, Keyboard_h, Keyboard_j},
	{Keyboard_null, Keyboard_z, Keyboard_x, Keyboard_c, Keyboard_v, Keyboard_b, Keyboard_n, Keyboard_m}
};
*/
void hid_data_clear(){
	memset(g_hid_data, 0, sizeof(g_hid_data));
}

void keyboard_press(uint32_t delay){
	const uint8_t press_time = 20;
	Keyboard_Send(g_hid_data);
	HAL_Delay(press_time);
	Keyboard_Clear();
	HAL_Delay(delay - press_time);
}

void string_to_hid(const char* str, uint32_t delay){
	for(int i = 0; i < strlen(str); i++){
		g_hid_data[2+i] = Keyboard_AsciiToHid(str[i]);
		if(i>=6)
			break;
	}
	keyboard_press(delay);
	hid_data_clear();
}



void genshin_play(score_t* score){
	for(int i=0; i < score->beats_count ;i++){
		display_beat_next(score, i);
		string_to_hid(score->beats[i].keys, score->beats[i].delay);
		
	}
}

void genshin_setup(){
	LCD_Init(HAL_Delay);
	score_loading();
	display_init(score_get());
}

void genshin_loop(){
	HAL_Delay(1000);
	genshin_play(score_get());
	/*
	string_to_hid("ndh", g_one_beat*2);
	
	string_to_hid("q", g_one_beat*2);
	
	string_to_hid("vaw", g_one_beat*2);
	
	string_to_hid("q", g_one_beat);
	string_to_hid("w", g_one_beat);
	
	string_to_hid("bsw", g_one_beat);
	string_to_hid("w", g_one_beat);
	
	string_to_hid("t", g_one_beat);
	string_to_hid("r", g_one_beat);
	
	string_to_hid("zbe", g_one_beat);
	
	string_to_hid("w", g_one_beat);
	string_to_hid("e", g_one_beat);
	
	string_to_hid("m", g_one_beat);
	
	
	string_to_hid("nde", g_one_beat*2);
	
	string_to_hid("t", g_one_beat*2);
	
	string_to_hid("vay", g_one_beat*2);
	
	string_to_hid("w", g_one_beat);
	string_to_hid("q", g_one_beat);
	
	string_to_hid("bst", g_one_beat);
	
	string_to_hid("t", g_one_beat);
	string_to_hid("e", g_one_beat); 
	string_to_hid("t", g_one_beat);
	
	string_to_hid("ndt", g_one_beat);
	string_to_hid("y", g_one_beat);
	
	HAL_Delay(g_one_beat*4);
	
	string_to_hid("ndh", g_one_beat);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("nd", g_one_beat/2);
	string_to_hid("vaw", g_one_beat);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("bsw", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	string_to_hid("t", g_one_beat/2);
	string_to_hid("bsr", g_one_beat/2);
	
	string_to_hid("zbe", g_one_beat/4);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	string_to_hid("m", g_one_beat/2);
	
	
	string_to_hid("nde", g_one_beat);
	
	string_to_hid("t", g_one_beat/2);
	string_to_hid("nd", g_one_beat/2);
	string_to_hid("vay", g_one_beat);
	
	string_to_hid("w", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("bsqt", g_one_beat/2);
	string_to_hid("qt", g_one_beat/2);
	string_to_hid("e", g_one_beat/2);
	string_to_hid("bsqt", g_one_beat/2);
	
	string_to_hid("ndqt", g_one_beat/2);
	string_to_hid("ndwy", g_one_beat*2);
	
	string_to_hid("zb", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("g", g_one_beat/4);
	string_to_hid("g", g_one_beat);
	
	string_to_hid("zb", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("bsq", g_one_beat);
	
	
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("g", g_one_beat/2);
	string_to_hid("g", g_one_beat/2);
	
	string_to_hid("bs", g_one_beat/2);
	
	string_to_hid("g", g_one_beat/2);
	
	string_to_hid("nde", g_one_beat/2);
	
	string_to_hid("r", g_one_beat/2);
	string_to_hid("e", g_one_beat/2);	
	
	string_to_hid("bsw", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("vae", g_one_beat/2);
	
	string_to_hid("r", g_one_beat/2);
	string_to_hid("e", g_one_beat/2);
	
	string_to_hid("h", g_one_beat/2);
	
	string_to_hid("va", g_one_beat/2);
	
	string_to_hid("h", g_one_beat/4);
	string_to_hid("j", g_one_beat/4);
	string_to_hid("vaq", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("vaj", g_one_beat/2);
	string_to_hid("bsj", g_one_beat/2);
	
	string_to_hid("bs", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/4);
	string_to_hid("e", g_one_beat/4);
	string_to_hid("zbr", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	
	string_to_hid("mw", g_one_beat/2);
	string_to_hid("ndq", g_one_beat/2);
	
	string_to_hid("nb", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	
	
	string_to_hid("xne", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("xnh", g_one_beat);
	
	string_to_hid("cmh", g_one_beat);
	
	string_to_hid("j", g_one_beat/2);
	string_to_hid("j", g_one_beat);
	
	string_to_hid("cm", g_one_beat);
	
	
	string_to_hid("z", g_one_beat);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("cbg", g_one_beat/4);
	string_to_hid("g", g_one_beat);
	
	string_to_hid("cb", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("bq", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("msg", g_one_beat/2);
	string_to_hid("g", g_one_beat/2);
	
	string_to_hid("ms", g_one_beat/2);
	string_to_hid("g", g_one_beat/2);
	
	string_to_hid("nde", g_one_beat/2);
	
	string_to_hid("r", g_one_beat/2);
	string_to_hid("nde", g_one_beat/2);
	string_to_hid("bsw", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("bsw", g_one_beat/2);
	
	string_to_hid("vae", g_one_beat/2);
	
	string_to_hid("r", g_one_beat/2);
	string_to_hid("e", g_one_beat/2);
	string_to_hid("h", g_one_beat/2);
	//重复
	string_to_hid("va", g_one_beat/2);
	
	string_to_hid("h", g_one_beat/4);
	string_to_hid("j", g_one_beat/4);
	string_to_hid("vaq", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("vaj", g_one_beat/2);
	string_to_hid("bsj", g_one_beat/2);
	
	string_to_hid("bs", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/4);
	string_to_hid("e", g_one_beat/4);
	string_to_hid("zbr", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	
	string_to_hid("mw", g_one_beat/2);
	string_to_hid("ndq", g_one_beat/2);
	
	string_to_hid("nb", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	
	string_to_hid("xne", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	//
	string_to_hid("xne", g_one_beat/2);
	string_to_hid("xnr", g_one_beat/2);
	string_to_hid("cme", g_one_beat/2);
	
	string_to_hid("cmj", g_one_beat/2);
	
	string_to_hid("cmq", g_one_beat/2);
	string_to_hid("cmw", g_one_beat/2);
	string_to_hid("cme", g_one_beat/2);
	
	string_to_hid("vq", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("na", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("vq", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("na", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("cw", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	string_to_hid("bm", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("nj", g_one_beat/2);
	
	string_to_hid("h", g_one_beat/2);
	string_to_hid("ad", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("vq", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("na", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("bw", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("ms", g_one_beat/2);
	
	string_to_hid("h", g_one_beat/2);
	
	string_to_hid("zg", g_one_beat/2);
	
	string_to_hid("cbd", g_one_beat/2);
	
	string_to_hid("mf", g_one_beat/2);
	
	string_to_hid("g", g_one_beat/2);
	//
	string_to_hid("vq", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("na", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("vq", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	string_to_hid("na", g_one_beat/2);
	
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("cw", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	string_to_hid("bm", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("nj", g_one_beat/2);
	//
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("ad", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("xe", g_one_beat/2);
	
	string_to_hid("r", g_one_beat/2);
	string_to_hid("vn", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	
	string_to_hid("xvnw", g_one_beat/2);
	
	string_to_hid("qw", g_one_beat/2);
	
	string_to_hid("cmqe", g_one_beat/2);
	
	string_to_hid("cmj", g_one_beat/2);
	
	string_to_hid("cmq", g_one_beat/2);
	
	string_to_hid("cmw", g_one_beat/2);
	
	string_to_hid("cme", g_one_beat);
	
	
	string_to_hid("nh", g_one_beat);
	
	string_to_hid("adq", g_one_beat);
	
	string_to_hid("vw", g_one_beat);
	
	string_to_hid("naq", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("bw", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	string_to_hid("mst", g_one_beat/2);
	string_to_hid("r", g_one_beat/2);
	
	string_to_hid("ze", g_one_beat/4);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	string_to_hid("cb", g_one_beat/2);
	string_to_hid("m", g_one_beat/2);
	
	string_to_hid("ne", g_one_beat);
	
	string_to_hid("adt", g_one_beat);
	
	string_to_hid("vy", g_one_beat);
	
	string_to_hid("naw", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("bj", g_one_beat/2);
	string_to_hid("j", g_one_beat/2);
	string_to_hid("msh", g_one_beat/2);
	string_to_hid("j", g_one_beat/2);
	
	string_to_hid("zw", g_one_beat/2);
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/4);
	string_to_hid("cbm", g_one_beat/2);
	string_to_hid("m", g_one_beat/2);
	///
	string_to_hid("nh", g_one_beat);
	
	string_to_hid("adq", g_one_beat);
	
	string_to_hid("vw", g_one_beat);
	
	string_to_hid("naq", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("bw", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	string_to_hid("mst", g_one_beat/2);
	string_to_hid("r", g_one_beat/2);
	
	string_to_hid("ze", g_one_beat/4);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	string_to_hid("cb", g_one_beat/2);
	string_to_hid("m", g_one_beat/2);
	
	string_to_hid("ne", g_one_beat);
	
	string_to_hid("adt", g_one_beat);
	
	string_to_hid("vy", g_one_beat);
	
	string_to_hid("naw", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("bqt", g_one_beat/2);
	string_to_hid("qt", g_one_beat/2);
	string_to_hid("msqe", g_one_beat/2);
	string_to_hid("qt", g_one_beat/2);
	
	string_to_hid("ndqt", g_one_beat);
	
	string_to_hid("ndwy", g_one_beat);
	///
	///
	string_to_hid("nh", g_one_beat);
	
	string_to_hid("adq", g_one_beat);
	
	string_to_hid("vw", g_one_beat);
	
	string_to_hid("naq", g_one_beat/2);
	
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("bw", g_one_beat/2);
	string_to_hid("w", g_one_beat/2);
	string_to_hid("mst", g_one_beat/2);
	string_to_hid("r", g_one_beat/2);
	
	string_to_hid("ze", g_one_beat/4);
	string_to_hid("w", g_one_beat/2);
	
	string_to_hid("e", g_one_beat/2);
	string_to_hid("cb", g_one_beat/2);
	string_to_hid("m", g_one_beat/2);
	
	string_to_hid("ne", g_one_beat);
	
	string_to_hid("adt", g_one_beat);
	
	string_to_hid("vy", g_one_beat);
	
	string_to_hid("naw", g_one_beat/2);
	
	string_to_hid("q", g_one_beat/2);
	
	string_to_hid("bqt", g_one_beat/2);
	string_to_hid("qt", g_one_beat/2);
	string_to_hid("msqe", g_one_beat/2);
	string_to_hid("qt", g_one_beat/2);
	
	string_to_hid("ndqt", g_one_beat);
	
	string_to_hid("ndwy", g_one_beat);
	///
	*/
}
