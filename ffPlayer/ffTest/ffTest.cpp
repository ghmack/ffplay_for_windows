// ffTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define __FFTEST_CPP
#ifdef __FFTEST_CPP

#include <list>
#include <iostream>
using namespace std;


#ifdef __cplusplus

extern "C" {

#endif

#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avdevice.lib")
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"avfilter.lib")
#pragma comment(lib,"avresample.lib")
#pragma comment(lib,"swscale.lib")

/*
#include "libavutil/avutil.h"
#include "libavformat/avformat.h"

int _tmain(int argc, _TCHAR* argv[])
{
	AVFormatContext *fmt_ctx = NULL;
	AVDictionaryEntry *tag = NULL;
	int ret;

	const char* fileName = "d:\\wildlife.wmv";

	av_register_all();
	if ((ret = avformat_open_input(&fmt_ctx, fileName, NULL, NULL)))
		return ret;

	while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
		printf("%s=%s\n", tag->key, tag->value);

	avformat_close_input(&fmt_ctx);
	return 0;
}
*/

#include "libavutil/avutil.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libavresample/avresample.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"


#define ReturnedErrLine {  printf("error lineno: %d \r\n",__LINE__); system("pause");exit(-1);  }



/* 编码jpg为mp4


class FileConvert
{
public:
	FileConvert()
	{

	}
	~FileConvert()
	{

	}


	void DecodeVideo(const char* inputFile, const char* outputFile)
	{
		av_register_all();
		
		m_inputAVFmtctx = avformat_alloc_context();
		if(avformat_open_input(&m_inputAVFmtctx,inputFile,NULL,NULL)<0)
			ReturnedErrLine;

		if(av_find_stream_info(m_inputAVFmtctx)<0)
			ReturnedErrLine;

		int vIndex = -1;
		if((vIndex=av_find_best_stream(m_inputAVFmtctx,AVMEDIA_TYPE_VIDEO,-1,0,&m_vDecode,0))<0)
			ReturnedErrLine;

		m_inputVStream = m_inputAVFmtctx->streams[vIndex];
		m_inputVCdecCxt = m_inputVStream->codec;

		m_vDecode = avcodec_find_decoder(m_inputVCdecCxt->codec_id);

		if(avcodec_open(m_inputVCdecCxt,m_vDecode)<0)
			ReturnedErrLine

		av_dump_format(m_inputAVFmtctx,0,NULL,0);

		m_outputAVFmtctx = avformat_alloc_context();
		
		if(avformat_alloc_output_context2(&m_outputAVFmtctx,m_outputAVFmtctx->oformat, "mp4",outputFile)<0)
			ReturnedErrLine

		m_vEncode = avcodec_find_encoder(m_outputAVFmtctx->oformat->video_codec);
		m_outputVStream = avformat_new_stream(m_outputAVFmtctx, m_vEncode);
		m_outputVCdecCxt = m_outputVStream->codec;

		m_outputVCdecCxt->width = m_inputVCdecCxt->width;
		m_outputVCdecCxt->height = m_inputVCdecCxt->height;
		m_outputVCdecCxt->bit_rate = m_inputVCdecCxt->bit_rate;
		m_outputVCdecCxt->pix_fmt = m_inputVCdecCxt->pix_fmt;
		m_outputVCdecCxt->time_base = m_inputVCdecCxt->time_base;
		m_outputVCdecCxt->gop_size = m_inputVCdecCxt->gop_size;
		if (m_outputAVFmtctx->oformat->flags & AVFMT_GLOBALHEADER)
		{
			m_outputVCdecCxt->flags |= CODEC_FLAG_GLOBAL_HEADER;
		}

		if (avcodec_open(m_outputVCdecCxt,m_vEncode)<0)
			ReturnedErrLine

        if (!(m_outputAVFmtctx->oformat->flags & AVFMT_NOFILE))
        {
			if(avio_open(&m_outputAVFmtctx->pb,outputFile, AVIO_FLAG_WRITE)<0)
				ReturnedErrLine
        }

		if (avformat_write_header(m_outputAVFmtctx,NULL)<0)
			ReturnedErrLine

		AVPacket packet = {0};
		av_init_packet(&packet);
		packet.data = NULL;
		packet.size = 0;
		AVFrame* srcFrame = avcodec_alloc_frame();
		while (av_read_frame(m_inputAVFmtctx, &packet)>=0)
		{
			int has_decode = -1;
			if(avcodec_decode_video2(m_inputVCdecCxt,srcFrame,&has_decode, &packet) < 0)
				ReturnedErrLine
			
			if (has_decode)
			{

			}

		}


	}


private:

	//<<<input struct
	AVFormatContext* m_inputAVFmtctx;	

	AVStream* m_inputVStream;	
	AVCodecContext* m_inputVCdecCxt;
	AVCodec* m_vDecode;

	AVStream* m_inputAStream;	
	AVCodecContext* m_inputACdecCxt;
	AVCodec*	m_adecode;


	///<<output struct
	AVFormatContext* m_outputAVFmtctx;

	AVStream* m_outputVStream;
	AVCodecContext* m_outputVCdecCxt;
	AVCodec* m_vEncode;

	AVStream* m_outputAStream;
	AVCodecContext* m_outputACodecCtx;
	AVCodec* m_aEncode;

};


int getFileSize(const char* sFile)
{
	FILE* f = fopen(sFile, "rb");
	fseek(f,0,SEEK_END);
	int s = ftell(f);
	fclose(f);
	return s;
}
class CJpgQueue
{
public:
	CJpgQueue()
	{

	}
	~CJpgQueue()
	{

	}

	
	void AppendPicFromFile(string szFile)
	{
		int s = getFileSize(szFile.c_str());
	    FILE* f = fopen(szFile.c_str(), "rb");
		char* buffer = new char[s];
		fread(buffer,1,s,f);
		string data ;
		data.append(buffer,s);
		m_lstJpg.push_back(data);
		delete[] buffer;
	}

	string* GetData(int i)
	{
		if (m_lstJpg.empty())
		{
			return NULL;
		}
		int index = i%m_lstJpg.size();
		list<string>::iterator it;
		int j = 0;
		for (it=m_lstJpg.begin();it!=m_lstJpg.end();it++,j++)
		{
			if (index == j)
			{
				return &*it;
			}
		}
		return NULL;
	}


private:
	list<string> m_lstJpg;

};

int read_src_frame(int i,CJpgQueue* q, AVPacket* packet)
{
	string* s = q->GetData(i);
	packet->data = (uint8_t *)s->data();
	packet->size = s->size();
	
	return 0;
}

#define  CHECKPOINT(p) {  if(!p) throw "NULL"; }
#define  THROWERROR { char err[256]; sprintf(err,"error line:%d \r\n",__LINE__);throw err;  }
#define  CHECKCONDITION(p) { if(!(p)) THROWERROR  }
int _tmain(int argc, _TCHAR* argv[]) 
{

	//FileConvert* fc = new FileConvert();
	//fc->DecodeVideo("d:\\wildlife.wmv","d:\\wildlife.mp4");

	//FILE* out = fopen("d:\\pgm\\out.h264","wb"); //写h264裸流
	//FILE* outyuv = fopen("d:\\pgm\\out.yuv420p","wb"); //just testing
	int err = 0;
	try{
		CJpgQueue picQueue;
		for (int i=0;i<8;i++)
		{
			char name[200]={0};
			sprintf(name,"d:\\pgm\\image\\%d.jpg",i);
			picQueue.AppendPicFromFile(string(name));
		}
		
		av_register_all();

		AVCodec* dec = avcodec_find_decoder(AV_CODEC_ID_MJPEG);
		CHECKPOINT(dec)
		AVCodecContext* dec_ctx = avcodec_alloc_context3(dec);
		CHECKPOINT(dec_ctx)
		dec_ctx->width = 1024;
		dec_ctx->height = 768;
		dec_ctx->pix_fmt = AV_PIX_FMT_YUVJ444P;
		if(dec->capabilities&CODEC_CAP_TRUNCATED)
			dec_ctx->flags|= CODEC_FLAG_TRUNCATED; // we do not send complete frames 


		if(avcodec_open2(dec_ctx,dec,NULL)<0)
			THROWERROR

        AVFormatContext* ofmt_ctx=NULL;
		const char* filename = "d:\\pgm\\out.mp4";
	    err = avformat_alloc_output_context2(&ofmt_ctx,NULL,"mp4",filename);
		CHECKCONDITION(err>=0)
      
		AVCodec* enc = avcodec_find_encoder(AV_CODEC_ID_H264);
		CHECKPOINT(enc);
		
		AVStream* video_stream=avformat_new_stream(ofmt_ctx, enc);
		CHECKPOINT(video_stream);
		video_stream->id = ofmt_ctx->nb_streams -1;
		

		AVCodecContext* enc_ctx = video_stream->codec;
		CHECKPOINT(enc_ctx);
		
		//AVCodecContext* enc_ctx = avcodec_alloc_context3(enc);
		//CHECKPOINT(enc)
		enc_ctx->codec_id = enc->id;
		enc_ctx->codec_type = AVMEDIA_TYPE_VIDEO;
		int bitrate = 1800*1000;
		enc_ctx->bit_rate = bitrate;
		enc_ctx->rc_min_rate = bitrate;
		enc_ctx->rc_max_rate = bitrate;
		enc_ctx->bit_rate_tolerance= bitrate;
		enc_ctx->rc_buffer_size = bitrate;
		enc_ctx->rc_initial_buffer_occupancy = enc_ctx->rc_buffer_size*3/4;
		enc_ctx->rc_initial_cplx = 0.5;
		enc_ctx->rc_buffer_aggressivity = (float)1.0;
		enc_ctx->qmin = 10;
		enc_ctx->qmax = 30;
		enc_ctx->qcompress = (float)0.6;
		enc_ctx->max_qdiff = 4;

		enc_ctx->width = 640;
		enc_ctx->height = 480;		
		enc_ctx->pix_fmt = AV_PIX_FMT_YUV420P;
		enc_ctx->time_base.den = 25;
		enc_ctx->time_base.num = 1;
		enc_ctx->gop_size = 12;
		enc_ctx->max_b_frames = 3;
		

		av_opt_set(enc_ctx->priv_data, "preset", "slow", 0);

		if (avcodec_open2(enc_ctx,enc,NULL)<0)
			THROWERROR
       
		

        if (ofmt_ctx->oformat->flags & AVFMT_GLOBALHEADER)
        {
			enc_ctx->flags |= CODEC_FLAG_GLOBAL_HEADER; 
        }

		if (!(ofmt_ctx->oformat->flags & AVFMT_NOFILE))
		{
			err = avio_open(&ofmt_ctx->pb,filename,AVIO_FLAG_WRITE);
			CHECKCONDITION(err>=0)
		}

		err = avformat_write_header(ofmt_ctx,NULL); //不写文件头 av_interleaved_write报除0错误
		CHECKCONDITION(err>=0)

		SwsContext* sws_cxt = sws_getContext(dec_ctx->width,dec_ctx->height,dec_ctx->pix_fmt,
			enc_ctx->width,enc_ctx->height,enc_ctx->pix_fmt,SWS_BILINEAR,NULL,NULL,NULL);
		CHECKPOINT(sws_cxt);

		AVFrame* src_frame = avcodec_alloc_frame();
		CHECKPOINT(src_frame);
		AVPacket src_packet;
		av_init_packet(&src_packet);
		src_packet.data = NULL;
		src_packet.size = 0;

		AVFrame* dst_frame = avcodec_alloc_frame();
		CHECKPOINT(dst_frame)
		int dst_size = av_image_alloc(dst_frame->data,dst_frame->linesize,
			enc_ctx->width,enc_ctx->height, enc_ctx->pix_fmt,32); 
		dst_frame->width = enc_ctx->width;
		dst_frame->height = enc_ctx->height;
		dst_frame->format = (int)enc_ctx->pix_fmt;
		dst_frame->pts = 0;
		AVPacket dst_packet;
		av_init_packet(&dst_packet);
		dst_packet.data = NULL;
		dst_packet.size = 0;

		int count = 0;
		int j = 0;
		while(read_src_frame(j,&picQueue,&src_packet) >=0)
		{
			if (count>=200)
			{
				break;
			}
			int got_frame = 0;	   
			if(avcodec_decode_video2(dec_ctx, src_frame,&got_frame,&src_packet )<0)
				THROWERROR
				if(got_frame)
				{
					sws_scale(sws_cxt, src_frame->data,src_frame->linesize,0,src_frame->height,
						dst_frame->data,dst_frame->linesize);
					//写yuv420到文件测试
					//for(int h=0;h<enc_ctx->height;h++)
					//{
					//	fwrite(dst_frame->data[0] + h * dst_frame->linesize[0],1,enc_ctx->width,outyuv);
					//}
					//for(int h=0;h<enc_ctx->height/2;h++)
					//{
					//	fwrite(dst_frame->data[1] + h * dst_frame->linesize[1],1,enc_ctx->width/2,outyuv);
					//}for(int h=0;h<enc_ctx->height/2;h++)
					//{
					//	fwrite(dst_frame->data[2] + h * dst_frame->linesize[2],1,enc_ctx->width/2,outyuv);
					//}fflush(outyuv);
					
					int got_packet = 0;
					
					if(avcodec_encode_video2(enc_ctx,&dst_packet,dst_frame,&got_packet)<0)
						THROWERROR;
					if (got_packet)
					{
						//int ret = fwrite(dst_packet.data,1,dst_packet.size, out);
						//fflush(out);
						//dst_packet.pts = dst_packet.dts = dst_frame->pts;
						if(enc_ctx->coded_frame->key_frame)
							dst_packet.flags |= AV_PKT_FLAG_KEY;
						dst_packet.stream_index = video_stream->index;
						dst_packet.dts=dst_packet.pts= dst_frame->pts;
						err = av_interleaved_write_frame(ofmt_ctx, &dst_packet);
						CHECKCONDITION(err>=0)
						av_free_packet(&dst_packet);
						dst_packet.data = NULL; //重置否则出错
						dst_packet.size = 0;

					}

					count++; 
					j++;
					dst_frame->pts += av_rescale_q(1, video_stream->codec->time_base, video_stream->time_base);;
				}			

		}

		av_write_trailer(ofmt_ctx);
	}
	catch(exception e)
	{
		std::cout<<e.what()<<endl;
	}

	
	//fclose(out);

	return 0;
}
*/
#include "SDL.h"

#pragma comment(lib,"sdl2.lib")






#define inline __inline
#define snprintf _snprintf  
//#undef av_ts2timestr(ts, tb)
//#define av_ts2timestr(ts, tb) 0


static AVFormatContext *fmt_ctx = NULL;
static AVCodecContext *video_dec_ctx = NULL;
static AVStream *video_stream = NULL;
static const char *src_filename = NULL;
static const char *video_dst_filename = NULL;
static FILE *video_dst_file = NULL;
static SwsContext* sws_cxt = NULL;

static uint8_t *video_dst_data[4] = {NULL};
static int      video_dst_linesize[4];
static int video_dst_bufsize;


static int video_stream_idx = -1;
static AVFrame *frame = NULL;
static AVPacket pkt;



static SDL_Window* window = NULL;
static  SDL_Renderer* render = NULL;
static SDL_Texture* texture = NULL;


static int decode_packet(int *got_frame, int cached)
{
    int ret = 0;

    if (pkt.stream_index == video_stream_idx) {
        /* decode video frame */
        ret = avcodec_decode_video2(video_dec_ctx, frame, got_frame, &pkt);
        if (ret < 0) {
            fprintf(stderr, "Error decoding video frame\n");
            return ret;
        }

        if (*got_frame) {
            /* copy decoded frame to destination buffer:
             * this is required since rawvideo expects non aligned data */
            /*av_image_copy(video_dst_data, video_dst_linesize,
                          (const uint8_t **)(frame->data), frame->linesize,
                          video_dec_ctx->pix_fmt, video_dec_ctx->width, video_dec_ctx->height);*/
			sws_scale(sws_cxt, frame->data,frame->linesize,0,video_dec_ctx->height,
				video_dst_data,video_dst_linesize);

			SDL_UpdateTexture(texture,0,video_dst_data[0],3*video_dec_ctx->width);
			SDL_RenderClear(render);
			SDL_RenderCopy(render, texture, NULL, NULL);
			SDL_RenderPresent(render);
			/*video_dst_bufsize = video_dec_ctx->height * video_dec_ctx->width * 3;
			fwrite(video_dst_data[0], 1, video_dst_bufsize, video_dst_file);
			fflush(video_dst_file);*/

        }
    } 

    return ret;
}

static int open_codec_context(int *stream_idx,
                              AVFormatContext *fmt_ctx, enum AVMediaType type)
{
    int ret;
    AVStream *st;
    AVCodecContext *dec_ctx = NULL;
    AVCodec *dec = NULL;

    ret = av_find_best_stream(fmt_ctx, type, -1, -1, NULL, 0);
    if (ret < 0) {
        fprintf(stderr, "Could not find %s stream in input file '%s'\n",
                av_get_media_type_string(type), src_filename);
        return ret;
    } else {
        *stream_idx = ret;
        st = fmt_ctx->streams[*stream_idx];

        /* find decoder for the stream */
        dec_ctx = st->codec;
        dec = avcodec_find_decoder(dec_ctx->codec_id);
        if (!dec) {
            fprintf(stderr, "Failed to find %s codec\n",
                    av_get_media_type_string(type));
            return ret;
        }

        if ((ret = avcodec_open2(dec_ctx, dec, NULL)) < 0) {
            fprintf(stderr, "Failed to open %s codec\n",
                    av_get_media_type_string(type));
            return ret;
        }
    }

    return 0;
}



int main (int argc, char **argv)
{
	double v1 = 1 / (29.97 * 90000);
	double v2 =  1 / 29.97 * 90000;


	AVInputFormat* fmtInput ;
	char deviceBuffer[256] ={0};
    int ret = 0, got_frame;
	AVDictionary* options = NULL;
	

	src_filename = "rtsp://admin:12345@192.168.0.6/ch1/main/av_stream"; //"d:\\wildlife.wmv";
	video_dst_filename = "d:\\pgm\\wildlife.jpg";

    /* register all formats and codecs */
     
	av_register_all();	
	avformat_network_init();
	 
	av_dict_set(&options, "rtsp_transport", "tcp", 0);
	if (avformat_open_input(&fmt_ctx, src_filename, NULL, &options) < 0) {
        fprintf(stderr, "Could not open source file %s\n", src_filename);
        exit(1);
    }
	
    /* retrieve stream information */
    if (avformat_find_stream_info(fmt_ctx, NULL) < 0) {
        fprintf(stderr, "Could not find stream information\n");
        exit(1);
    }

    if (open_codec_context(&video_stream_idx, fmt_ctx, AVMEDIA_TYPE_VIDEO) >= 0) {
        video_stream = fmt_ctx->streams[video_stream_idx];
        video_dec_ctx = video_stream->codec;


        /* allocate image where the decoded image will be put */
        ret = av_image_alloc(video_dst_data, video_dst_linesize,
                             video_dec_ctx->width, video_dec_ctx->height,
                             AV_PIX_FMT_RGB24, 1);
        if (ret < 0) {
            fprintf(stderr, "Could not allocate raw video buffer\n");
            goto end;
        }
        video_dst_bufsize = ret;
    }

	video_dst_file = fopen(video_dst_filename, "wb");
	if (!video_dst_file) {
		fprintf(stderr, "Could not open destination file %s\n", video_dst_filename);
		ret = 1;
		goto end;
	}

	sws_cxt = sws_getContext(video_dec_ctx->width,video_dec_ctx->height,video_dec_ctx->pix_fmt,
		video_dec_ctx->width,video_dec_ctx->height,AV_PIX_FMT_RGB24,SWS_BILINEAR,NULL,NULL,NULL);

    /* dump input information to stderr */
    av_dump_format(fmt_ctx, 0, src_filename, 0);
          

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2


	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"",                  // window title
		50,           // initial x position
		50,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL |SDL_WINDOW_RESIZABLE                // flags - see below
		);
	// Check that the window was successfully made
	if (window == NULL) {
		// In the event that the window could not be made...
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	
	render = SDL_CreateRenderer(window, -1,0);
	texture = SDL_CreateTexture(render,SDL_PIXELFORMAT_RGB24,SDL_TEXTUREACCESS_STREAMING,video_dec_ctx->width,video_dec_ctx->height);


	


    if (!video_stream) {
        fprintf(stderr, "Could not find  video stream in the input, aborting\n");
        ret = 1;
        goto end;
    }

    frame = avcodec_alloc_frame();
    if (!frame) {
        fprintf(stderr, "Could not allocate frame\n");
        ret = AVERROR(ENOMEM);
        goto end;
    }

    /* initialize packet, set data to NULL, let the demuxer fill it */
    av_init_packet(&pkt);
    pkt.data = NULL;
    pkt.size = 0;

    if (video_stream)
        printf("Demuxing video from file '%s' into '%s'\n", src_filename, video_dst_filename);


    /* read frames from the file */
    while (av_read_frame(fmt_ctx, &pkt) >= 0) {
        decode_packet(&got_frame, 0);
        av_free_packet(&pkt);
    }

    /* flush cached frames */
    pkt.data = NULL;
    pkt.size = 0;
    do {
        decode_packet(&got_frame, 1);
    } while (got_frame);

    printf("Demuxing succeeded.\n");

    if (video_stream) {
        printf("Play the output video file with the command:\n"
               "ffplay -f rawvideo -pix_fmt %s -video_size %dx%d %s\n",
               av_get_pix_fmt_name(video_dec_ctx->pix_fmt), video_dec_ctx->width, video_dec_ctx->height,
               video_dst_filename);
    }



end:
    if (video_dec_ctx)
        avcodec_close(video_dec_ctx);
    
    avformat_close_input(&fmt_ctx);
    
    av_free(frame);
    av_free(video_dst_data[0]);

    return ret < 0;
}


#ifdef __cplusplus

}

#endif




#endif