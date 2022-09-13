#ifndef __GENSHIN_PLAYER_H__
#define __GENSHIN_PLAYER_H__

#include <stdint.h>

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

typedef struct{
	uint8_t *keys;
	uint32_t keys_len;
	uint32_t delay;
}genshin_beat;

typedef struct{
	genshin_beat *beats;
	uint32_t beats_count;
	uint32_t time_all;
}genshin_score;

void genshin_play_start(void);

#endif
