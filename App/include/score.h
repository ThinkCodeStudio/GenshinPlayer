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

#ifndef __SCORE_H__
#define __SCORE_H__

#include <stdint.h>

typedef struct{
	char keys[6];
	uint32_t keys_len;
	uint32_t delay;
}beat_t;

typedef struct{
	beat_t beats[2048];
	uint32_t beats_count;
	uint32_t beats_size;
	uint64_t time_all;
}score_t;

void score_init(void);
void score_load_key(const char *keys, uint32_t r_delay);
void score_loading(void);
score_t* score_get(void);

#endif
