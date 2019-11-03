
#include <SPI.h>
#include <GD.h>
#include "vgafont.h"

typedef enum {
	WRITE8,
	READ8,
	BEGIN,
	COMPRESS,
	LAST,
} t_command;

/**
 * Serial Protocol:
 * 
 **/

class SerialGD {
	public:
		SerialGD(void)
		: fhandle(-1)
		{
			fprintf(stdout, "%s\n", __PRETTY_FUNCTION__);
		};
		~SerialGD(void) {
			fprintf(stdout, "%s\n", __PRETTY_FUNCTION__);
			fhandle = -1;
		};
		void wr(unsigned int addr, byte v) {
			GD.wr(addr, v);
			fprintf(stdout, "%s addr: %d, byte: %d\n", __PRETTY_FUNCTION__, addr, v);
		};
		byte rd(unsigned int addr) {
			return GD.rd(addr);
			int v = 0xEA;
			fprintf(stdout, "%s addr: %d - val: %d\n", __PRETTY_FUNCTION__, addr, v);
			return v;
		}
		void begin(void) {
			GD.begin();
			fprintf(stdout, "%s\n", __PRETTY_FUNCTION__);
		}

		void uncompress(unsigned int addr, unsigned char *src) {
			GD.uncompress(addr, src);
			fprintf(stdout, "%s addr: %d, byte: %p\n", __PRETTY_FUNCTION__, addr, src);
		}

	private:
		GDClass GD;
		int fhandle;
};

SerialGD SGD;

static int atxy(int x, int y)
{
  return (y << 7) + x;
}

static void drawstr(uint16_t addr, const char *s)
{
  while (*s) {
    uint16_t w = pgm_read_word(vgafont_pic + 2 * *s);
    SGD.wr(addr, lowByte(w));
    SGD.wr(addr + 64, highByte(w));
    s++, addr++;
  }
}

void setup()
{
  SGD.begin();
  SGD.uncompress(RAM_CHR, vgafont_chr);
  SGD.uncompress(RAM_PAL, vgafont_pal);
  drawstr(atxy(0, 0), "Hello");
  drawstr(atxy(10, 2), "This is the vga font");
  for (byte i = 0; i < 14; i++) {
    drawstr(atxy(i, 4 + i), " *Gameduino* ");
  }
}

void loop()
{
}
