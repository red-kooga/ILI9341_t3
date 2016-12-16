// https://github.com/PaulStoffregen/ILI9341_t3
// http://forum.pjrc.com/threads/26305-Highly-optimized-ILI9341-(320x240-TFT-color-display)-library

/***************************************************
  This is our library for the Adafruit  ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#ifndef _ILI9341_ESPH_
#define _ILI9341_ESPH_

#ifdef __cplusplus
#include "Arduino.h"
#endif

#include <SPI.h>

#define ILI9341_TFTWIDTH  240
#define ILI9341_TFTHEIGHT 320

#define ILI9341_NOP     0x00
#define ILI9341_SWRESET 0x01
#define ILI9341_RDDID   0x04
#define ILI9341_RDDST   0x09

#define ILI9341_SLPIN   0x10
#define ILI9341_SLPOUT  0x11
#define ILI9341_PTLON   0x12
#define ILI9341_NORON   0x13

#define ILI9341_RDMODE  0x0A
#define ILI9341_RDMADCTL  0x0B
#define ILI9341_RDPIXFMT  0x0C
#define ILI9341_RDIMGFMT  0x0D
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF  0x20
#define ILI9341_INVON   0x21
#define ILI9341_GAMMASET 0x26
#define ILI9341_DISPOFF 0x28
#define ILI9341_DISPON  0x29

#define ILI9341_CASET   0x2A
#define ILI9341_PASET   0x2B
#define ILI9341_RAMWR   0x2C
#define ILI9341_RAMRD   0x2E

#define ILI9341_PTLAR    0x30
#define ILI9341_VSCRDEF  0x33  
#define ILI9341_MADCTL   0x36
#define ILI9341_VSCRSADD 0x37
#define ILI9341_PIXFMT   0x3A

#define ILI9341_FRMCTR1 0xB1
#define ILI9341_FRMCTR2 0xB2
#define ILI9341_FRMCTR3 0xB3
#define ILI9341_INVCTR  0xB4
#define ILI9341_DFUNCTR 0xB6

#define ILI9341_PWCTR1  0xC0
#define ILI9341_PWCTR2  0xC1
#define ILI9341_PWCTR3  0xC2
#define ILI9341_PWCTR4  0xC3
#define ILI9341_PWCTR5  0xC4
#define ILI9341_VMCTR1  0xC5
#define ILI9341_VMCTR2  0xC7

#define ILI9341_RDID1   0xDA
#define ILI9341_RDID2   0xDB
#define ILI9341_RDID3   0xDC
#define ILI9341_RDID4   0xDD

#define ILI9341_GMCTRP1 0xE0
#define ILI9341_GMCTRN1 0xE1
/*
#define ILI9341_PWCTR6  0xFC

*/

// Color definitions
#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_PINK        0xF81F


typedef struct {
	const unsigned char *index;
	const unsigned char *unicode;
	const unsigned char *data;
	unsigned char version;
	unsigned char reserved;
	unsigned char index1_first;
	unsigned char index1_last;
	unsigned char index2_first;
	unsigned char index2_last;
	unsigned char bits_index;
	unsigned char bits_width;
	unsigned char bits_height;
	unsigned char bits_xoffset;
	unsigned char bits_yoffset;
	unsigned char bits_delta;
	unsigned char line_space;
	unsigned char cap_height;
} ILI9341_ESP_font_t;


#ifdef __cplusplus

class ILI9341_ESP : public Print
{
  public:
	ILI9341_ESP(uint8_t _CS, uint8_t _DC, uint8_t _RST = 255);
	void begin(void);
   void beginTransaction(void);
  	void sleep(bool enable);		
	void pushColor(uint16_t color);
	void fillScreen(uint16_t color);
	void drawPixel(int16_t x, int16_t y, uint16_t color);
	void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
	void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
	void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	void setRotation(uint8_t r);
   // defines vertical scroll area
   void setupScroll(uint16_t topArea, int16_t scrollArea, int16_t bottomArea);
   // set scroll offset that scrollarea is moved
	void setScroll(uint16_t offset);
	void invertDisplay(boolean i);
	void setAddrWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
	// Pass 8-bit (each) R,G,B, get back 16-bit packed color
	static uint16_t color565(uint8_t r, uint8_t g, uint8_t b) {
		return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
	}

	//uint8_t readdata(void);
	uint8_t readcommand8(uint8_t reg, uint8_t index = 0);

	// Added functions to read pixel data...
	uint16_t readPixel(int16_t x, int16_t y);
	void readRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t *pcolors);
	void writeRect(int16_t x, int16_t y, int16_t w, int16_t h, const uint16_t *pcolors);

	// from Adafruit_GFX.h
	void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
	void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
	void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
	void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
	void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
	void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
	void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
	void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
	void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
	void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
	void setCursor(int16_t x, int16_t y);
	void setTextColor(uint16_t c);
	void setTextColor(uint16_t c, uint16_t bg);
	void setTextSize(uint8_t s);
	uint8_t getTextSize();
	void setTextWrap(boolean w);
	boolean getTextWrap();
	virtual size_t write(uint8_t);
	int16_t width(void)  { return _width; }
	int16_t height(void) { return _height; }
	uint8_t getRotation(void);
	void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
	void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	int16_t getCursorX(void) const { return cursor_x; }
	int16_t getCursorY(void) const { return cursor_y; }
	void setFont(const ILI9341_ESP_font_t &f) { font = &f; }
	void setFontAdafruit(void) { font = NULL; }
	void drawFontChar(unsigned int c);
   
   uint32_t cleanPrint( uint32_t oldV, uint32_t newV, uint16_t fgc, uint16_t bgc, int xxt, int yyt );


 protected:
	int16_t _width, _height; // Display w/h as modified by current rotation
	int16_t  cursor_x, cursor_y;
	uint16_t textcolor, textbgcolor;
	uint8_t textsize, rotation;
	boolean wrap; // If set, 'wrap' text at right edge of display
	const ILI9341_ESP_font_t *font;

  	uint8_t  _rst;
  	uint8_t _cs, _dc;
//	uint8_t pcs_data, pcs_command;
  
   void waittransfercompleted()__attribute__((always_inline))
   {
      while(SPI1CMD & SPIBUSY) {}
   }    
   
   void initializedatatransfer(void)__attribute__((always_inline))
   {
      //waittransfercompleted();
      
      digitalWrite(_dc, HIGH);
      digitalWrite(_cs, LOW);
   }  
   
   void startbuffertransfer(uint16_t bytescount)__attribute__((always_inline))
   {
      SPI.setDataBits(bytescount*8);
      SPI1CMD |= SPIBUSY;
   }     
 
   void finishtransfer(void)__attribute__((always_inline))
   {
      waittransfercompleted();
      digitalWrite(_cs, HIGH);
   }    
   
   volatile uint8_t* writeinSPIbuffer(volatile uint8_t *buffer, uint8_t data) __attribute__((always_inline))
   {
      *buffer = data;
      buffer++;
      
      return buffer;
   }    
   
   volatile uint16_t* writeinSPIbuffer(volatile uint16_t *buffer, uint16_t data) __attribute__((always_inline))
   {
      *buffer = data >> 8 | data << 8;
      buffer++;
      
      return buffer;
   }    

/*	void setAddr(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
	  __attribute__((always_inline)) {
		writecommand_cont(ILI9341_CASET); // Column addr set
      //writedata16_cont(x0);   // XSTART

      initializedatatransfer();
      SPI.setDataBits(4*8);
      
      volatile uint16_t *buffer = (volatile uint16_t*)&SPI1W0;
      // XSTART
      buffer = writeinSPIbuffer(buffer,x0);
      buffer = writeinSPIbuffer(buffer,x1);
  
      SPI1CMD |= SPIBUSY;
      while(SPI1CMD & SPIBUSY) {}
//      writedata16_cont(x1);   // XEND
		writecommand_cont(ILI9341_PASET); // Row addr set
      buffer = (volatile uint16_t*)&SPI1W0;
      initializedatatransfer();
      SPI.setDataBits(4*8);
      buffer = writeinSPIbuffer(buffer,y0);
      buffer = writeinSPIbuffer(buffer,y1);
      SPI.setDataBits(4*8);
      SPI1CMD |= SPIBUSY;
  
      finishtransfer();      
	}*/
   
	void setAddr(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
	  __attribute__((always_inline)) {
		writecommand_cont(ILI9341_CASET); // Column addr set
		writedata16_cont(x0);   // XSTART
		writedata16_cont(x1);   // XEND
		writecommand_cont(ILI9341_PASET); // Row addr set
		writedata16_cont(y0);   // YSTART
		writedata16_cont(y1);   // YEND
   }
   
   
   //write command
	void writecommand_cont(uint8_t c) __attribute__((always_inline)) {
      waittransfercompleted();     
      
      digitalWrite(_dc, LOW);
      digitalWrite(_cs, LOW);
      
      SPI.write(c);
	}
   
   //write data byte
	void writedata8_cont(uint8_t c) __attribute__((always_inline)) {
      waittransfercompleted();
      
      digitalWrite(_dc, HIGH);
      digitalWrite(_cs, LOW);      
      
      SPI.write(c);
	}
   
   //write data word
	void writedata16_cont(uint16_t d) __attribute__((always_inline)) {
      waittransfercompleted();
      
      digitalWrite(_dc, HIGH);
      digitalWrite(_cs, LOW);      
      
      SPI.write16(d);
	}

	void writecommand_last(uint8_t c) __attribute__((always_inline)) {
      writecommand_cont(c);
      
      finishtransfer();  
	}
	void writedata8_last(uint8_t c) __attribute__((always_inline)) {
      writedata8_cont(c);
      
      finishtransfer();   
	}
	void writedata16_last(uint16_t d) __attribute__((always_inline)) {
      writedata16_cont(d);
      
      finishtransfer();   
	}
   
   void fillPreparedArea(uint32_t length, uint16_t color) __attribute__((always_inline)) {   
      volatile uint16_t *fifoPtr = (volatile uint16_t*)&SPI1W0;
      volatile uint16_t *actualPtr = (volatile uint16_t*)&SPI1W0;
      uint32_t words; //SPI FIFO has 64 bytes 
      uint16_t swapColor = color >> 8 | color << 8;

      if(length<32)
      {
         SPI.setDataBits(length*16); 
         words = length;
      }
      else
      {
         SPI.setDataBits(64*8); 
         words = 32;
      }
      
      initializedatatransfer();
       
      while (length-- > 0)  
      { 
         *actualPtr = swapColor;
         actualPtr++;
         
         if(--words == 0)
         {
            SPI1CMD |= SPIBUSY;
            words = 32;
            actualPtr = fifoPtr;                       
            while(SPI1CMD & SPIBUSY) {}
            
            if(length<32)
            {
               words = length;
               SPI.setDataBits(length*16);
            }           
         }              
      } 
   }
      
	void HLine(int16_t x, int16_t y, int16_t w, uint16_t color)
	  __attribute__((always_inline)) {
		setAddr(x, y, x+w-1, y);
		writecommand_cont(ILI9341_RAMWR);      
      fillPreparedArea(w, color);
	}
	void VLine(int16_t x, int16_t y, int16_t h, uint16_t color)
	  __attribute__((always_inline)) {
		setAddr(x, y, x, y+h-1);
		writecommand_cont(ILI9341_RAMWR);
      fillPreparedArea(h, color);
	}
	void Pixel(int16_t x, int16_t y, uint16_t color)
	  __attribute__((always_inline)) {
		setAddr(x, y, x, y);
		writecommand_cont(ILI9341_RAMWR);
		writedata16_cont(color);
	}
	void drawFontBits(uint32_t bits, uint32_t numbits, uint32_t x, uint32_t y, uint32_t repeat);
};


#ifndef swap
#define swap(a, b) { int16_t t = a; a = b; b = t; }
#endif

class Adafruit_GFX_Button {
public:
	Adafruit_GFX_Button(void) { _gfx = NULL; }
	void initButton(ILI9341_ESP *gfx, int16_t x, int16_t y,
		uint8_t w, uint8_t h,
		uint16_t outline, uint16_t fill, uint16_t textcolor,
		const char *label, uint8_t textsize);
	void drawButton(bool inverted = false);
	bool contains(int16_t x, int16_t y);
	void press(boolean p) {
		laststate = currstate;
		currstate = p;
	}
	bool isPressed() { return currstate; }
	bool justPressed() { return (currstate && !laststate); }
	bool justReleased() { return (!currstate && laststate); }
private:
	ILI9341_ESP *_gfx;
	int16_t _x, _y;
	uint16_t _w, _h;
	uint8_t _textsize;
	uint16_t _outlinecolor, _fillcolor, _textcolor;
	char _label[10];
	boolean currstate, laststate;
};

#endif // __cplusplus


#endif
