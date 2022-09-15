#ifndef __GENSHIN_PLAYER_H__
#define __GENSHIN_PLAYER_H__

#include <stdint.h>

/*******
��һ�� ������Ŀ �س�����
 >��ʱ
:ð����ʼ��

# ע��
| �ֽ� �����
�ո����

������  ������-1  1  ������+1
��ʱ  1_ �˷�ʱ  1 �ķ�ʱ 1* ����ʱ

*********/

typedef struct{
	char *keys;
	uint32_t keys_len;
	uint32_t delay;
}genshin_beat;

typedef struct{
	genshin_beat *beats;
	uint32_t beats_count;
	uint32_t beats_size;
	uint64_t time_all;
}genshin_score;

void genshin_setup(void);
void genshin_loop(void);

#endif
