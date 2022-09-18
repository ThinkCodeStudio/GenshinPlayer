#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include "score.h"

int display_init(score_t* score);
int display_show_score(score_t* score, int index);
int display_beat_next(score_t* score, int index);
#endif
