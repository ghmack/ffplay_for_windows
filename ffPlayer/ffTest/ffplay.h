#ifndef __FFPLAY_H__
#define __FFPLAY_H__




typedef signed long long int64_t;
typedef struct User_Param
{

	const char *input_filename;
	const char *window_title;
	int fs_screen_width;
	int fs_screen_height;
	int default_width ;// = 640;
	int default_height ;// = 480;
	int screen_width  ;//= 0;
	int screen_height ;//= 0;
	int audio_disable;
	int video_disable;
	int subtitle_disable;

	int wanted_stream[5];// = {-1,-1,-1,-1,-1	};
	int seek_by_bytes ;// = -1;
	int display_disable;
	int show_status ;// = 1;
	int av_sync_type ;// = AV_SYNC_AUDIO_MASTER;
	int64_t start_time ;//  = AV_NOPTS_VALUE;
	int64_t duration ;
	int workaround_bugs ;
	int fast  ;// = 0;
	int genpts  ;// = 0;
	int lowres  ;// = 0;
	int idct  ;// = FF_IDCT_AUTO;
	int skip_frame      ;
	int skip_idct       ;
	int skip_loop_filter ;
	int error_concealment ;
	int decoder_reorder_pts ;
	int autoexit;
	int exit_on_keydown;
	int exit_on_mousedown;
	int loop ;
	int framedrop;
	int infinite_buffer;
	int show_mode;
	const char *audio_codec_name;
	const char *subtitle_codec_name;
	const char *video_codec_name;
	double rdftspeed ;//= 0.02;
	int64_t cursor_last_shown;
	int cursor_hidden ;
	//int64_t sws_flags ;
//#if CONFIG_AVFILTER
	char *vfilters  ;// = NULL;
	//#endif

	/* current context */
	int is_full_screen;
	int64_t audio_callback_time;
	void* extra_data;
	void* is; //VideoState

}User_Param;






int ffplay_init();

void* ffplay_create(const char* filename, const char* iformat);

int ffplay_set_hwnd(void* videoState,void* hwnd);

int ffplay_run(void* arg);

User_Param* ffplay_get_param(void* arg);




#endif