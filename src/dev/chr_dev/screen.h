#ifndef SCREEN_H
#define SCREEN_H

#define write_mem8(addr,data8)   (*(volatile char *)(addr))=(char)data8

#define COL8_000000 0
#define COL8_FF0000 1 
#define COL8_00FF00 2
#define COL8_FFFF00 3
#define COL8_0000FF 4
#define COL8_FF00FF 5
#define COL8_00FFFF 6
#define COL8_FFFFFF 7
#define COL8_C6C6C6 8
#define COL8_840000 9
#define COL8_008400 10
#define COL8_848400 11
#define COL8_000084 12
#define COL8_840084 13
#define COL8_008484 14
#define COL8_848484 15



//显示相关的一些启动参数
struct BootInfo
{
	char cyls,leds,vmode,reserve;
	short scrnx,scrny;
	char * vram;
};


extern void clear_screen(char color) ; //color=15 pure white color=40 red
extern void color_screen(char color) ;

extern void init_palette(void);
extern void set_palette(int start, int end, unsigned char *rgb);

extern void boxfill8(char* vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1);


void chr_dev_init();

//console 初始化
void tty_init();
//Xwindow初始化
void xwin_init();

void putfont(char* vram, int xsize, int x, int y, char c, char *font);

void putfont8(char *vram, int xsize, int x, int y, char c, char *font);

void putfonts8_asc(char* vram, int xsize, int x, int y, char c, char *s);

void init_mouse_cursor8(char *mouse,char bg);

void putblock8_8(char *vram,int xsize,int pxsize,int pysize,int px0,int py0,char *buf,int bxsize);

void sprintf(char *str,char *format ,...);
void init_screen(char *vram, int x, int y);
#endif