/*******
第一行 歌曲曲目 回车结束
 >分时
:冒号起始符

# 注释
| 分节 不解读
空格相隔

升降调  降调：-1  1  升调：+1
分时  1_ 八分时  1 四分时 1* 二分时

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
