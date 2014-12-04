//
//#define __FFPLAY__CPP
//#ifdef  __FFPLAY__CPP
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//char g_av_make_error_string[64] = {0};
//
//#ifndef inline
//#define  inline __inline
//#endif
//	/* Decimal notation.  */
//#define PRIu64       "I64u"
//#define PRId64       "I64d"
//
//
//#pragma comment(lib,"avcodec.lib")
//#pragma comment(lib,"avformat.lib")
//#pragma comment(lib,"avdevice.lib")
//#pragma comment(lib,"avutil.lib")
//#pragma comment(lib,"avfilter.lib")
//#pragma comment(lib,"avresample.lib")
//#pragma comment(lib,"swscale.lib")
//#pragma comment(lib,"swresample.lib")
//#pragma comment(lib,"postproc.lib")
//#pragma comment(lib,"SDL.lib")
//
//#include "config.h"
//#include <inttypes.h>
//#include <math.h>
//#include <limits.h>
//#include <signal.h>
//#include "libavutil/avstring.h"
//#include "libavutil/colorspace.h"
//#include "libavutil/mathematics.h"
//#include "libavutil/pixdesc.h"
//#include "libavutil/imgutils.h"
//#include "libavutil/dict.h"
//#include "libavutil/parseutils.h"
//#include "libavutil/samplefmt.h"
//#include "libavutil/avassert.h"
//#include "libavutil/time.h"
//#include "libavformat/avformat.h"
//#include "libavdevice/avdevice.h"
//#include "libswscale/swscale.h"
//#include "libavutil/opt.h"
//#include "libavcodec/avfft.h"
//#include "libswresample/swresample.h"
//
//
//#if CONFIG_AVFILTER
//# include "libavfilter/avcodec.h"
//# include "libavfilter/avfilter.h"
//# include "libavfilter/avfiltergraph.h"
//# include "libavfilter/buffersink.h"
//# include "libavfilter/buffersrc.h"
//#endif
//
//#include <SDL.h>
//#include <SDL_thread.h>
//
//#include "cmdutils.h"
//
//#include <assert.h>
//
//#ifdef __cplusplus
//}
//#endif
//
//
//static inline double rint(double x)
//{
//	return x >= 0 ? floor(x + 0.5) : ceil(x - 0.5);
//}
//
//static av_always_inline av_const int isnan(float x)
//{
//	uint32_t v = av_float2int(x);
//	if ((v & 0x7f800000) != 0x7f800000)
//		return 0;
//	return v & 0x007fffff;
//}
//
//
//const char program_name[] = "ffplay";
//const int program_birth_year = 2003;
//
//#define MAX_QUEUE_SIZE (15 * 1024 * 1024)
//#define MIN_FRAMES 5
//
///* SDL audio buffer size, in samples. Should be small to have precise
//   A/V sync as SDL does not have hardware buffer fullness info. */
//#define SDL_AUDIO_BUFFER_SIZE 1024
//
///* no AV sync correction is done if below the AV sync threshold */
//#define AV_SYNC_THRESHOLD 0.01
///* no AV correction is done if too big error */
//#define AV_NOSYNC_THRESHOLD 10.0
//
///* maximum audio speed change to get correct sync */
//#define SAMPLE_CORRECTION_PERCENT_MAX 10
//
///* external clock speed adjustment constants for realtime sources based on buffer fullness */
//#define EXTERNAL_CLOCK_SPEED_MIN  0.900
//#define EXTERNAL_CLOCK_SPEED_MAX  1.010
//#define EXTERNAL_CLOCK_SPEED_STEP 0.001
//
///* we use about AUDIO_DIFF_AVG_NB A-V differences to make the average */
//#define AUDIO_DIFF_AVG_NB   20
//
///* polls for possible required screen refresh at least this often, should be less than 1/fps */
//#define REFRESH_RATE 0.01
//
///* NOTE: the size must be big enough to compensate the hardware audio buffersize size */
///* TODO: We assume that a decoded and resampled frame fits into this buffer */
//#define SAMPLE_ARRAY_SIZE (8 * 65536)
//
//#define CURSOR_HIDE_DELAY 1000000
//
//
//
//
//class CFFPlayer
//{
//public:
//	CFFPlayer()
//	{
//
//	}
//};
//
