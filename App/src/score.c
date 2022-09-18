#include "score.h"
#include <stdlib.h>
#include <string.h>

//һ���ĵı�׼��ʱ
const uint32_t g_one_beat = (60.0/128)*1000;

static score_t g_score;


score_t* score_get(){
	return &g_score;
}

//�ڴ�ռ�����
void score_init(){
	//�����������ĸ���
	g_score.beats_size = 2048;
	//��������
	g_score.beats_count = 0;
	//��������
	//g_score.beats = calloc(r_beat_size, sizeof(g_score.beats));
	//��ʱ��ms
	g_score.time_all = 0;
}

//
void score_load_key(const char *keys, uint32_t r_delay){
	//�����������������ܸ���
	if(g_score.beats_count >= g_score.beats_size)
		return;
	//���뵥�������Ŀռ�
	//g_score.beats[g_score.beats_count].keys = calloc(strlen(keys),sizeof(char));
	//������������
	strcpy(g_score.beats[g_score.beats_count].keys, keys);
	//��������������
	g_score.beats[g_score.beats_count].keys_len = strlen(keys);
	//��������ʱ��
	g_score.beats[g_score.beats_count].delay = r_delay;
	//�ۼ���ʱ��
	g_score.time_all += r_delay;
	//���������ۼ�
	g_score.beats_count++;
}

//���� ���֡��п���ʹ���ж����졷
void score_loading(){
	score_init();
	score_load_key("ndh", g_one_beat*2);
	
	score_load_key("q", g_one_beat*2);
	
	score_load_key("vaw", g_one_beat*2);
	
	score_load_key("q", g_one_beat);
	score_load_key("w", g_one_beat);
	
	score_load_key("bsw", g_one_beat);
	score_load_key("w", g_one_beat);
	
	score_load_key("t", g_one_beat);
	score_load_key("r", g_one_beat);
	
	score_load_key("zbe", g_one_beat);
	
	score_load_key("w", g_one_beat);
	score_load_key("e", g_one_beat);
	
	score_load_key("m", g_one_beat);
	
	
	score_load_key("nde", g_one_beat*2);
	
	score_load_key("t", g_one_beat*2);
	
	score_load_key("vay", g_one_beat*2);
	
	score_load_key("w", g_one_beat);
	score_load_key("q", g_one_beat);
	
	score_load_key("bst", g_one_beat);
	
	score_load_key("t", g_one_beat);
	score_load_key("e", g_one_beat); 
	score_load_key("t", g_one_beat);
	
	score_load_key("ndt", g_one_beat);
	score_load_key("y", g_one_beat);
	
	score_load_key("",g_one_beat*4);
	
	score_load_key("ndh", g_one_beat);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("nd", g_one_beat/2);
	score_load_key("vaw", g_one_beat);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("bsw", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	score_load_key("t", g_one_beat/2);
	score_load_key("bsr", g_one_beat/2);
	
	score_load_key("zbe", g_one_beat/4);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	score_load_key("m", g_one_beat/2);
	
	
	score_load_key("nde", g_one_beat);
	
	score_load_key("t", g_one_beat/2);
	score_load_key("nd", g_one_beat/2);
	score_load_key("vay", g_one_beat);
	
	score_load_key("w", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	
	score_load_key("bsqt", g_one_beat/2);
	score_load_key("qt", g_one_beat/2);
	score_load_key("e", g_one_beat/2);
	score_load_key("bsqt", g_one_beat/2);
	
	score_load_key("ndqt", g_one_beat/2);
	score_load_key("ndwy", g_one_beat*2);
	
	score_load_key("zb", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	
	score_load_key("g", g_one_beat/4);
	score_load_key("g", g_one_beat);
	
	score_load_key("zb", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("bsq", g_one_beat);
	
	
	score_load_key("w", g_one_beat/2);
	
	score_load_key("g", g_one_beat/2);
	score_load_key("g", g_one_beat/2);
	
	score_load_key("bs", g_one_beat/2);
	
	score_load_key("g", g_one_beat/2);
	
	score_load_key("nde", g_one_beat/2);
	
	score_load_key("r", g_one_beat/2);
	score_load_key("e", g_one_beat/2);	
	
	score_load_key("bsw", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("vae", g_one_beat/2);
	
	score_load_key("r", g_one_beat/2);
	score_load_key("e", g_one_beat/2);
	
	score_load_key("h", g_one_beat/2);
	
	score_load_key("va", g_one_beat/2);
	
	score_load_key("h", g_one_beat/4);
	score_load_key("j", g_one_beat/4);
	score_load_key("vaq", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	
	score_load_key("vaj", g_one_beat/2);
	score_load_key("bsj", g_one_beat/2);
	
	score_load_key("bs", g_one_beat/2);
	
	score_load_key("w", g_one_beat/4);
	score_load_key("e", g_one_beat/4);
	score_load_key("zbr", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	
	score_load_key("mw", g_one_beat/2);
	score_load_key("ndq", g_one_beat/2);
	
	score_load_key("nb", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	
	
	score_load_key("xne", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("xnh", g_one_beat);
	
	score_load_key("cmh", g_one_beat);
	
	score_load_key("j", g_one_beat/2);
	score_load_key("j", g_one_beat);
	
	score_load_key("cm", g_one_beat);
	
	
	score_load_key("z", g_one_beat);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("cbg", g_one_beat/4);
	score_load_key("g", g_one_beat);
	
	score_load_key("cb", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	
	score_load_key("bq", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	
	score_load_key("msg", g_one_beat/2);
	score_load_key("g", g_one_beat/2);
	
	score_load_key("ms", g_one_beat/2);
	score_load_key("g", g_one_beat/2);
	
	score_load_key("nde", g_one_beat/2);
	
	score_load_key("r", g_one_beat/2);
	score_load_key("nde", g_one_beat/2);
	score_load_key("bsw", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("bsw", g_one_beat/2);
	
	score_load_key("vae", g_one_beat/2);
	
	score_load_key("r", g_one_beat/2);
	score_load_key("e", g_one_beat/2);
	score_load_key("h", g_one_beat/2);
	//�ظ�
	score_load_key("va", g_one_beat/2);
	
	score_load_key("h", g_one_beat/4);
	score_load_key("j", g_one_beat/4);
	score_load_key("vaq", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	
	score_load_key("vaj", g_one_beat/2);
	score_load_key("bsj", g_one_beat/2);
	
	score_load_key("bs", g_one_beat/2);
	
	score_load_key("w", g_one_beat/4);
	score_load_key("e", g_one_beat/4);
	score_load_key("zbr", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	
	score_load_key("mw", g_one_beat/2);
	score_load_key("ndq", g_one_beat/2);
	
	score_load_key("nb", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	
	score_load_key("xne", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	//***
	score_load_key("xne", g_one_beat/2);
	score_load_key("xnr", g_one_beat/2);
	score_load_key("cme", g_one_beat/2);
	
	score_load_key("cmj", g_one_beat/2);
	
	score_load_key("cmq", g_one_beat/2);
	score_load_key("cmw", g_one_beat/2);
	score_load_key("cme", g_one_beat/2);
	
	score_load_key("vq", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("na", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("vq", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("na", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("cw", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	score_load_key("bm", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	
	score_load_key("nj", g_one_beat/2);
	
	score_load_key("h", g_one_beat/2);
	score_load_key("ad", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("vq", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("na", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("bw", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("ms", g_one_beat/2);
	
	score_load_key("h", g_one_beat/2);
	
	score_load_key("zg", g_one_beat/2);
	
	score_load_key("cbd", g_one_beat/2);
	
	score_load_key("mf", g_one_beat/2);
	
	score_load_key("g", g_one_beat/2);
	//
	score_load_key("vq", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("na", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("vq", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	score_load_key("na", g_one_beat/2);
	
	score_load_key("j", g_one_beat/2);
	
	score_load_key("cw", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	score_load_key("bm", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	
	score_load_key("nj", g_one_beat/2);
	//***
	score_load_key("q", g_one_beat/2);
	
	score_load_key("ad", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	
	score_load_key("xe", g_one_beat/2);
	
	score_load_key("r", g_one_beat/2);
	score_load_key("vn", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	
	score_load_key("xvnw", g_one_beat/2);
	
	score_load_key("qw", g_one_beat/2);
	
	score_load_key("cmqe", g_one_beat/2);
	
	score_load_key("cmj", g_one_beat/2);
	
	score_load_key("cmq", g_one_beat/2);
	
	score_load_key("cmw", g_one_beat/2);
	
	score_load_key("cme", g_one_beat);
	
	
	score_load_key("nh", g_one_beat);
	
	score_load_key("adq", g_one_beat);
	
	score_load_key("vw", g_one_beat);
	
	score_load_key("naq", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	
	score_load_key("bw", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	score_load_key("mst", g_one_beat/2);
	score_load_key("r", g_one_beat/2);
	
	score_load_key("ze", g_one_beat/4);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	score_load_key("cb", g_one_beat/2);
	score_load_key("m", g_one_beat/2);
	
	score_load_key("ne", g_one_beat);
	
	score_load_key("adt", g_one_beat);
	
	score_load_key("vy", g_one_beat);
	
	score_load_key("naw", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	
	score_load_key("bj", g_one_beat/2);
	score_load_key("j", g_one_beat/2);
	score_load_key("msh", g_one_beat/2);
	score_load_key("j", g_one_beat/2);
	
	score_load_key("zw", g_one_beat/2);
	score_load_key("q", g_one_beat/2);
	
	score_load_key("q", g_one_beat/4);
	score_load_key("cbm", g_one_beat/2);
	score_load_key("m", g_one_beat/2);
	///
	score_load_key("nh", g_one_beat);
	
	score_load_key("adq", g_one_beat);
	
	score_load_key("vw", g_one_beat);
	
	score_load_key("naq", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	
	score_load_key("bw", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	score_load_key("mst", g_one_beat/2);
	score_load_key("r", g_one_beat/2);
	
	score_load_key("ze", g_one_beat/4);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	score_load_key("cb", g_one_beat/2);
	score_load_key("m", g_one_beat/2);
	
	score_load_key("ne", g_one_beat);
	
	score_load_key("adt", g_one_beat);
	
	score_load_key("vy", g_one_beat);
	
	score_load_key("naw", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	
	score_load_key("bqt", g_one_beat/2);
	score_load_key("qt", g_one_beat/2);
	score_load_key("msqe", g_one_beat/2);
	score_load_key("qt", g_one_beat/2);
	
	score_load_key("ndqt", g_one_beat);
	
	score_load_key("ndwy", g_one_beat);
	///
	///
	score_load_key("nh", g_one_beat);
	
	score_load_key("adq", g_one_beat);
	
	score_load_key("vw", g_one_beat);
	
	score_load_key("naq", g_one_beat/2);
	
	score_load_key("w", g_one_beat/2);
	
	score_load_key("bw", g_one_beat/2);
	score_load_key("w", g_one_beat/2);
	score_load_key("mst", g_one_beat/2);
	score_load_key("r", g_one_beat/2);
	
	score_load_key("ze", g_one_beat/4);
	score_load_key("w", g_one_beat/2);
	
	score_load_key("e", g_one_beat/2);
	score_load_key("cb", g_one_beat/2);
	score_load_key("m", g_one_beat/2);
	
	score_load_key("ne", g_one_beat);
	
	score_load_key("adt", g_one_beat);
	
	score_load_key("vy", g_one_beat);
	
	score_load_key("naw", g_one_beat/2);
	
	score_load_key("q", g_one_beat/2);
	
	score_load_key("bqt", g_one_beat/2);
	score_load_key("qt", g_one_beat/2);
	score_load_key("msqe", g_one_beat/2);
	score_load_key("qt", g_one_beat/2);
	
	score_load_key("ndqt", g_one_beat);
	
	score_load_key("ndwy", g_one_beat);
	///
}
