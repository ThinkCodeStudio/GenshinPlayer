#include "genshin_player.h"
#include "keyboard.h"
#include "main.h"
#include "string.h"
#include <stdlib.h>

//一节拍的标准延时
const uint32_t g_one_beat = (60.0/128)*1000;


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

genshin_score g_score;

void genshin_init(uint32_t r_beat_size){
	g_score.beats_size = r_beat_size;
	g_score.beats_count = 0;
	g_score.beats = malloc(sizeof(g_score.beats)* r_beat_size);
	g_score.time_all = 0;
}

void genshin_load_key(const char* keys, uint8_t r_delay){
	if(g_score.beats_count >= g_score.beats_size)
		return;
	g_score.beats[g_score.beats_count].keys = malloc(sizeof(char)*strlen(keys));
	strcpy(g_score.beats[g_score.beats_count].keys, keys);
	g_score.beats[g_score.beats_count].keys_len = strlen(keys);
	g_score.beats[g_score.beats_count].delay = r_delay;
	g_score.time_all += r_delay;
	g_score.beats_count++;
}

void genshin_loading(){
	genshin_init(280);
	genshin_load_key("ndh", g_one_beat*2);
	
	genshin_load_key("q", g_one_beat*2);
	
	genshin_load_key("vaw", g_one_beat*2);
	
	genshin_load_key("q", g_one_beat);
	genshin_load_key("w", g_one_beat);
	
	genshin_load_key("bsw", g_one_beat);
	genshin_load_key("w", g_one_beat);
	
	genshin_load_key("t", g_one_beat);
	genshin_load_key("r", g_one_beat);
	
	genshin_load_key("zbe", g_one_beat);
	
	genshin_load_key("w", g_one_beat);
	genshin_load_key("e", g_one_beat);
	
	genshin_load_key("m", g_one_beat);
	
	
	genshin_load_key("nde", g_one_beat*2);
	
	genshin_load_key("t", g_one_beat*2);
	
	genshin_load_key("vay", g_one_beat*2);
	
	genshin_load_key("w", g_one_beat);
	genshin_load_key("q", g_one_beat);
	
	genshin_load_key("bst", g_one_beat);
	
	genshin_load_key("t", g_one_beat);
	genshin_load_key("e", g_one_beat); 
	genshin_load_key("t", g_one_beat);
	
	genshin_load_key("ndt", g_one_beat);
	genshin_load_key("y", g_one_beat);
	
	genshin_load_key("",g_one_beat*4);
	
	genshin_load_key("ndh", g_one_beat);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("nd", g_one_beat/2);
	genshin_load_key("vaw", g_one_beat);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("bsw", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("t", g_one_beat/2);
	genshin_load_key("bsr", g_one_beat/2);
	
	genshin_load_key("zbe", g_one_beat/4);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	genshin_load_key("m", g_one_beat/2);
	
	
	genshin_load_key("nde", g_one_beat);
	
	genshin_load_key("t", g_one_beat/2);
	genshin_load_key("nd", g_one_beat/2);
	genshin_load_key("vay", g_one_beat);
	
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("bsqt", g_one_beat/2);
	genshin_load_key("qt", g_one_beat/2);
	genshin_load_key("e", g_one_beat/2);
	genshin_load_key("bsqt", g_one_beat/2);
	
	genshin_load_key("ndqt", g_one_beat/2);
	genshin_load_key("ndwy", g_one_beat*2);
	
	genshin_load_key("zb", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("g", g_one_beat/4);
	genshin_load_key("g", g_one_beat);
	
	genshin_load_key("zb", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("bsq", g_one_beat);
	
	
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("g", g_one_beat/2);
	genshin_load_key("g", g_one_beat/2);
	
	genshin_load_key("bs", g_one_beat/2);
	
	genshin_load_key("g", g_one_beat/2);
	
	genshin_load_key("nde", g_one_beat/2);
	
	genshin_load_key("r", g_one_beat/2);
	genshin_load_key("e", g_one_beat/2);	
	
	genshin_load_key("bsw", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("vae", g_one_beat/2);
	
	genshin_load_key("r", g_one_beat/2);
	genshin_load_key("e", g_one_beat/2);
	
	genshin_load_key("h", g_one_beat/2);
	
	genshin_load_key("va", g_one_beat/2);
	
	genshin_load_key("h", g_one_beat/4);
	genshin_load_key("j", g_one_beat/4);
	genshin_load_key("vaq", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("vaj", g_one_beat/2);
	genshin_load_key("bsj", g_one_beat/2);
	
	genshin_load_key("bs", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/4);
	genshin_load_key("e", g_one_beat/4);
	genshin_load_key("zbr", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	
	genshin_load_key("mw", g_one_beat/2);
	genshin_load_key("ndq", g_one_beat/2);
	
	genshin_load_key("nb", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	
	
	genshin_load_key("xne", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("xnh", g_one_beat);
	
	genshin_load_key("cmh", g_one_beat);
	
	genshin_load_key("j", g_one_beat/2);
	genshin_load_key("j", g_one_beat);
	
	genshin_load_key("cm", g_one_beat);
	
	
	genshin_load_key("z", g_one_beat);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("cbg", g_one_beat/4);
	genshin_load_key("g", g_one_beat);
	
	genshin_load_key("cb", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("bq", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("msg", g_one_beat/2);
	genshin_load_key("g", g_one_beat/2);
	
	genshin_load_key("ms", g_one_beat/2);
	genshin_load_key("g", g_one_beat/2);
	
	genshin_load_key("nde", g_one_beat/2);
	
	genshin_load_key("r", g_one_beat/2);
	genshin_load_key("nde", g_one_beat/2);
	genshin_load_key("bsw", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("bsw", g_one_beat/2);
	
	genshin_load_key("vae", g_one_beat/2);
	
	genshin_load_key("r", g_one_beat/2);
	genshin_load_key("e", g_one_beat/2);
	genshin_load_key("h", g_one_beat/2);
	//重复
	genshin_load_key("va", g_one_beat/2);
	
	genshin_load_key("h", g_one_beat/4);
	genshin_load_key("j", g_one_beat/4);
	genshin_load_key("vaq", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("vaj", g_one_beat/2);
	genshin_load_key("bsj", g_one_beat/2);
	
	genshin_load_key("bs", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/4);
	genshin_load_key("e", g_one_beat/4);
	genshin_load_key("zbr", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	
	genshin_load_key("mw", g_one_beat/2);
	genshin_load_key("ndq", g_one_beat/2);
	
	genshin_load_key("nb", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	
	genshin_load_key("xne", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	//***
	genshin_load_key("xne", g_one_beat/2);
	genshin_load_key("xnr", g_one_beat/2);
	genshin_load_key("cme", g_one_beat/2);
	
	genshin_load_key("cmj", g_one_beat/2);
	
	genshin_load_key("cmq", g_one_beat/2);
	genshin_load_key("cmw", g_one_beat/2);
	genshin_load_key("cme", g_one_beat/2);
	
	genshin_load_key("vq", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("na", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("vq", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("na", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("cw", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("bm", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("nj", g_one_beat/2);
	
	genshin_load_key("h", g_one_beat/2);
	genshin_load_key("ad", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("vq", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("na", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("bw", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("ms", g_one_beat/2);
	
	genshin_load_key("h", g_one_beat/2);
	
	genshin_load_key("zg", g_one_beat/2);
	
	genshin_load_key("cbd", g_one_beat/2);
	
	genshin_load_key("mf", g_one_beat/2);
	
	genshin_load_key("g", g_one_beat/2);
	//
	genshin_load_key("vq", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("na", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("vq", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	genshin_load_key("na", g_one_beat/2);
	
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("cw", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("bm", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("nj", g_one_beat/2);
	//***
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("ad", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("xe", g_one_beat/2);
	
	genshin_load_key("r", g_one_beat/2);
	genshin_load_key("vn", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	
	genshin_load_key("xvnw", g_one_beat/2);
	
	genshin_load_key("qw", g_one_beat/2);
	
	genshin_load_key("cmqe", g_one_beat/2);
	
	genshin_load_key("cmj", g_one_beat/2);
	
	genshin_load_key("cmq", g_one_beat/2);
	
	genshin_load_key("cmw", g_one_beat/2);
	
	genshin_load_key("cme", g_one_beat);
	
	
	genshin_load_key("nh", g_one_beat);
	
	genshin_load_key("adq", g_one_beat);
	
	genshin_load_key("vw", g_one_beat);
	
	genshin_load_key("naq", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("bw", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("mst", g_one_beat/2);
	genshin_load_key("r", g_one_beat/2);
	
	genshin_load_key("ze", g_one_beat/4);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	genshin_load_key("cb", g_one_beat/2);
	genshin_load_key("m", g_one_beat/2);
	
	genshin_load_key("ne", g_one_beat);
	
	genshin_load_key("adt", g_one_beat);
	
	genshin_load_key("vy", g_one_beat);
	
	genshin_load_key("naw", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("bj", g_one_beat/2);
	genshin_load_key("j", g_one_beat/2);
	genshin_load_key("msh", g_one_beat/2);
	genshin_load_key("j", g_one_beat/2);
	
	genshin_load_key("zw", g_one_beat/2);
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/4);
	genshin_load_key("cbm", g_one_beat/2);
	genshin_load_key("m", g_one_beat/2);
	///
	genshin_load_key("nh", g_one_beat);
	
	genshin_load_key("adq", g_one_beat);
	
	genshin_load_key("vw", g_one_beat);
	
	genshin_load_key("naq", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("bw", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("mst", g_one_beat/2);
	genshin_load_key("r", g_one_beat/2);
	
	genshin_load_key("ze", g_one_beat/4);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	genshin_load_key("cb", g_one_beat/2);
	genshin_load_key("m", g_one_beat/2);
	
	genshin_load_key("ne", g_one_beat);
	
	genshin_load_key("adt", g_one_beat);
	
	genshin_load_key("vy", g_one_beat);
	
	genshin_load_key("naw", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("bqt", g_one_beat/2);
	genshin_load_key("qt", g_one_beat/2);
	genshin_load_key("msqe", g_one_beat/2);
	genshin_load_key("qt", g_one_beat/2);
	
	genshin_load_key("ndqt", g_one_beat);
	
	genshin_load_key("ndwy", g_one_beat);
	///
	///
	genshin_load_key("nh", g_one_beat);
	
	genshin_load_key("adq", g_one_beat);
	
	genshin_load_key("vw", g_one_beat);
	
	genshin_load_key("naq", g_one_beat/2);
	
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("bw", g_one_beat/2);
	genshin_load_key("w", g_one_beat/2);
	genshin_load_key("mst", g_one_beat/2);
	genshin_load_key("r", g_one_beat/2);
	
	genshin_load_key("ze", g_one_beat/4);
	genshin_load_key("w", g_one_beat/2);
	
	genshin_load_key("e", g_one_beat/2);
	genshin_load_key("cb", g_one_beat/2);
	genshin_load_key("m", g_one_beat/2);
	
	genshin_load_key("ne", g_one_beat);
	
	genshin_load_key("adt", g_one_beat);
	
	genshin_load_key("vy", g_one_beat);
	
	genshin_load_key("naw", g_one_beat/2);
	
	genshin_load_key("q", g_one_beat/2);
	
	genshin_load_key("bqt", g_one_beat/2);
	genshin_load_key("qt", g_one_beat/2);
	genshin_load_key("msqe", g_one_beat/2);
	genshin_load_key("qt", g_one_beat/2);
	
	genshin_load_key("ndqt", g_one_beat);
	
	genshin_load_key("ndwy", g_one_beat);
	///
}

void genshin_play(){
	for(int i=0; i < g_score.beats_count ;i++){
		string_to_hid(g_score.beats[i].keys, g_score.beats[i].delay);
	}
}

void genshin_start(){
	genshin_play();
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
	//***
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
	//***
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
