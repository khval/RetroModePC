#ifndef RETROMODE_INTERFACE_DEF_H
#define RETROMODE_INTERFACE_DEF_H

	struct retroVideo * retroAllocVideo( struct Window * window);
	void retroFreeVideo( struct retroVideo * video);
	void retroClearVideo( struct retroVideo * video);
	void retroDrawVideo( struct retroVideo * video);
	void retroDmaVideo( struct retroVideo * video);
	struct retroScreen * retroOpenScreen( int width, int height, int videomode);
	void retroCloseScreen( struct retroScreen ** screen);
	void retroApplyScreen( struct retroScreen * screen, struct retroVideo * video, int scanlinex, int scanliney, int displayWidth, int displayHeight);
	void retroPixel( struct retroScreen * screen, int x, int y, unsigned char color);
	unsigned char retroPoint( struct retroScreen * screen, int x, int y);
	void retroFlash( struct retroScreen * screen, unsigned char color, char * data);
	void retroCycleColorsUp( struct retroScreen * screen, int delay, unsigned char from_color, unsigned char to_color, unsigned char flags);
	void retroCycleColorsDown( struct retroScreen * screen, int delay, unsigned char from_color, unsigned char to_color, unsigned char flags);
	void retroBAR( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char color);
	void retroOrBAR( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char or_mask);
	void retroXorBAR( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char xor_mask);
	void retroBox( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char color);
	void retroOrBox( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char or_mask);
	void retroXorBox( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char xor_mask);
	void retroShift( struct retroScreen * screen, int x0, int y0, int x1, int y1, int bits);
	void retroCircleFilled( struct retroScreen * screen, int cx, int cy, int r, unsigned char color);
	void retroEllipse( struct retroScreen * screen, int cx, int cy, int r1, int r2, double angel, unsigned char color);
	void retroOrCircleFilled( struct retroScreen * screen, int cx, int cy, int r, unsigned char or_mask);
	void retroXorCircleFilled( struct retroScreen * screen, int cx, int cy, int r, unsigned char xor_mask);
	void retroScreenColor( struct retroScreen * screen, int color, unsigned char r, unsigned char g, unsigned char b);
	void retroScreenBlit( struct retroScreen * SourceScreen, int fromMode, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toMode, int toX, int toY);
	void retroOrScreenBlit( struct retroScreen * SourceScreen, int fromMode, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toMode, int toX, int toY);
	void retroXorScreenBlit( struct retroScreen * SourceScreen, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toMode, int toX, int toY);
	void retroBitmapBlit( struct BitMap * bitmap, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void retroOrBitmapBlit( struct BitMap * bitmap, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void retroXorBitmapBlit( struct BitMap * bitmap, int fromX, int fromY, int width, int height, struct retroScreen * screen, int toX, int toY);
	void retroAndClear( struct retroScreen * screen, int x0, int y0, int x1, int y1, unsigned char and_mask);
	void retroModeBadVideoSync( struct retroVideo * video, double sync_offset, double incRad, double r);
	void AfterEffectScanline( struct retroVideo * video);
	void AfterEffectAdjustRGB( struct retroVideo * video, unsigned int red_shift, unsigned int green_shift, unsigned int blue_shift);
	void retroTriangle( struct retroScreen * screen, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char color);
	void retroOrTriangle( struct retroScreen * screen, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char or_color);
	void retroXorTriangle( struct retroScreen * screen, int x1, int y1, int x2, int y2, int x3, int y3, unsigned char xor_color);
	void retroLine( struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);
	void retroOrLine( struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);
	void retroXorLine( struct retroScreen * screen, int x1, int y1, int x2, int y2, unsigned char color);
	struct retroFrame * retroAllocFrame( struct retroScreen * screen, int x1, int y1, int x2, int y2, int hotspotX, int hotspotY);
	void retroFreeFrame( struct retroFrame * frame);
	void retroDrawFrame( struct retroFrame * frame, struct retroScreen * screen, int X, int Y);
	int retroDeleteFlash( struct retroScreen * screen, unsigned char color);
	void retroScreenOffset( struct retroScreen * screen, int offsetx, int offsety);
	void retroScreenDetach( struct retroScreen * screen);
	void retroScreenToFront( struct retroScreen * screen);
	void retroScreenToBack( struct retroScreen * screen);
	void retroStar( struct retroScreen * screen, int x, int y, int n, int r0, int r1, double g, unsigned char color);
	void retroOrStar( struct retroScreen * screen, int x, int y, int n, int r0, int r1, double g, unsigned char color);
	void retroPolyLine( struct retroScreen * screen, unsigned char color, ...);
	void retroPolyGon( struct retroScreen * screen, unsigned char color, ...);
	void retroBoing( struct retroScreen * screen, int x, int y, int r0, int r1, unsigned char color0, unsigned char color1);
	struct retroSprite * retroLoadABKSprite( char * filename);
	void retroFreeSprite( struct retroSprite * sprite);
	void retroPasteSprite( struct retroScreen * screen, struct retroSprite * sprite, int x, int y, int image, int flags);
	void retroFill( struct retroScreen * screen, int x, int y, unsigned char color);
	void retroOrFill( struct retroScreen * screen, int x, int y, int and_mask, unsigned char or_color);
	void retroBarRounded( struct retroScreen * screen, int x0, int y0, int x1, int y1, int r, unsigned char color);
	void retroOrBarRounded( struct retroScreen * screen, int x0, int y0, int x1, int y1, int r, unsigned char color);
	void retroXorBarRounded( struct retroScreen * screen, int x0, int y0, int x1, int y1, int r, unsigned char color);
	void retroThickLine( struct retroScreen * screen, int x0, int y0, int x1, int y1, int thickness, unsigned char color);
	void retroZoom( struct retroScreen * fromScreen, int x0, int y0, int x1, int y1, struct retroScreen * toScreen, int x2, int y2, int x3, int y3);
	void retroBobble( struct retroScreen * fromScreen, int fromX, int fromY, int fromR, struct retroScreen * toScreen, int toX, int toY, int toR);
	void retroRainbowColorRange( struct retroVideo * video, int rainbowNumber, int fromLine, int fromR, int fromG, int fromB, int toLine, int toR, int toG, int toB);
	void retroRain( struct retroVideo * video, int rainbowNumber, int line, int r, int g, int b);
	struct retroScreen * retroScreenClone( struct retroScreen * SourceScreen, int videomode);
	void retroSetRainbow( struct retroVideo * video, int rainbowNumber, unsigned char color, int tableSize);
	void retroRainbow( struct retroVideo * video, int rainbowNumber, int offset, int verticalOffset, int height);
	void retroAllocSpriteObjects( struct retroVideo * video, int numberOfSprites);
	void retroFreeSpriteObjects( struct retroVideo * video);
	void AfterEffectDrawSrpites( struct retroVideo * video);
	void retroSprite( struct retroVideo * video, int number, int x, int y, int image);
	void retroColorRange( struct retroScreen * screen, int fromColor, int fromR, int fromG, int fromB, int toColor, int toR, int toG, int toB);
	void retroPolyGonArray( struct retroScreen * screen, unsigned char color, int count, int * array);
	void retroCycleOff( struct retroScreen * screen);
	void retroFadeScreen( struct retroScreen * screen);
	void retroCircle( struct retroScreen * screen, int cx, int cy, int r, unsigned char color);
	void retroAllocDoubleBuffer( struct retroScreen * screen);
	struct retroSprite * retroLoadSprite( void * fd, cust_fread_t cust_fread);
	void retroGetSprite( struct retroScreen * screen, struct retroSprite * sprite, int image, int x0, int y0, int x1, int y1);
	void retroFreeSpriteObject( struct retroSpriteObject * spriteObject, BOOL onlyData);

#endif /* RETROMODE_INTERFACE_DEF_H */
