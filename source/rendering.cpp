/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This source code is intended only as a supplement to the Marmalade SDK.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */

#include "rendering.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "IwResManager.h"
#include "titlescreen.h"
#include "localise.h"

CIw2DFont* font;
CIw2DFont* fontLarge;

CIwSVec2 screen;

void CleanupImages()
{
    delete font;
	delete fontLarge;
}

void SetupImages(void)
{
    CleanupImages();
}

void DrawTitleScreen(TitleScreen *title)
{
	int border = 10;

	Iw2DSetColour(0xffffffff);
	Iw2DFillRect(title->btnTopLeft, title->btnDim);

	Iw2DSetColour(0xff000000);
	Iw2DFillRect(CIwFVec2(title->btnTopLeft.x + border, title->btnTopLeft.y + border),
				 CIwFVec2(title->btnDim.x - 2 * border, title->btnDim.y - 2 * border));
	
	Iw2DSetFont(fontLarge);
	int fh = fontLarge->GetHeight();
	int sw = Iw2DGetStringWidth("P L A Y");

	Iw2DSetColour(0xffffffff);
	Iw2DDrawString("P L A Y", CIwFVec2(title->btnTopLeft.x + border, title->btnTopLeft.y + border),
		CIwFVec2(title->btnDim.x - 2 * border, title->btnDim.y - 2 * border), IW_2D_FONT_ALIGN_CENTRE, IW_2D_FONT_ALIGN_TOP);
}

void DrawGameBackground()
{
	Iw2DSetColour(0xffffffff);
	Iw2DDrawRect(CIwFVec2(0,0), CIwFVec2(GAME_WIDTH, GAME_HEIGHT));
}

void DrawGround()
{
	for (int i = 0; i < NUM_BUILDINGS; i++) {
		Iw2DSetColour(0xff000000);
		Iw2DFillRect(CIwFVec2(GAME_WIDTH - buildings_pos[i].x, GAME_HEIGHT - buildings_pos[i].y),
					 CIwFVec2(buildings_dim[i].x, buildings_dim[i].y));
		Iw2DSetColour(0xffffffff);
		Iw2DDrawRect(CIwFVec2(GAME_WIDTH - buildings_pos[i].x, GAME_HEIGHT - buildings_pos[i].y),
					 CIwFVec2(buildings_dim[i].x, buildings_dim[i].y));
	}
}

void DrawBootSequence()
{
	Iw2DSetFont(font);

	int h = font->GetHeight();

	for (unsigned i = 0; i < g_Current_Line; i++) {
		int w = Iw2DGetStringWidth(g_Bootup_Sequence[i]);

		Iw2DSetColour(0xffffffff);
		Iw2DDrawString(g_Bootup_Sequence[i], CIwFVec2(0, i*h),
			CIwFVec2(w, h), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
	}
}

void DrawGameOverScreen()
{
	int border = 10;
	CIwFVec2 dialogDim(480.f, 120.f);

	CIwFVec2 outerTopLeft((screen.x - dialogDim.x)/2, (screen.y - dialogDim.y)/2);
	CIwFVec2 innerTopLeft((screen.x - dialogDim.x)/2 + border, (screen.y - dialogDim.y)/2 + border);

	Iw2DSetColour(0xffffffff);
	Iw2DFillRect(outerTopLeft, dialogDim);
	Iw2DSetColour(0xff000000);
	Iw2DFillRect(innerTopLeft, CIwFVec2(dialogDim.x - 2 * border, dialogDim.y - 2 * border));

	Iw2DSetColour(0xffffffff);
	Iw2DSetFont(fontLarge);

	Iw2DDrawString("G A M E   O V E R", outerTopLeft, dialogDim, IW_2D_FONT_ALIGN_CENTRE, IW_2D_FONT_ALIGN_CENTRE);
}

void DrawScale(CIwFVec2 aim)
{
	Iw2DSetColour(0xffffffff);

	for (int i = RANGE_X.x; i <= RANGE_X.y; i += 10)
	{
		if ((i - RANGE_X.x) % 100 == 0) {
			Iw2DDrawLine(CIwFVec2(i, GAME_HEIGHT + 10), CIwFVec2(i, GAME_HEIGHT + 50));
		}
		else {
			Iw2DDrawLine(CIwFVec2(i, GAME_HEIGHT + 20), CIwFVec2(i, GAME_HEIGHT + 40));
		}
	}

	for (int i = RANGE_Y.x; i <= RANGE_Y.y; i += 10)
	{
		if ((i - RANGE_Y.x) % 100 == 0) {
			Iw2DDrawLine(CIwFVec2(GAME_WIDTH + 10, i), CIwFVec2(GAME_WIDTH + 50, i));
		}
		else {
			Iw2DDrawLine(CIwFVec2(GAME_WIDTH + 20, i), CIwFVec2(GAME_WIDTH + 40, i));
		}
	}

	CIwFVec2 triangle_x[] = {
		CIwFVec2(aim.x, GAME_HEIGHT + 20),
		CIwFVec2(aim.x + 10, GAME_HEIGHT + 40),
		CIwFVec2(aim.x - 10, GAME_HEIGHT + 40)
	};

	CIwFVec2 triangle_y[] = {
		CIwFVec2(GAME_WIDTH + 20, aim.y),
		CIwFVec2(GAME_WIDTH + 40, aim.y - 10),
		CIwFVec2(GAME_WIDTH + 40, aim.y + 10)
	};

	Iw2DFillPolygon(triangle_x, 3);
	Iw2DFillPolygon(triangle_y, 3);
	
	Iw2DDrawLine(CIwFVec2(aim.x - 10, aim.y), CIwFVec2(aim.x + 10, aim.y));
	Iw2DDrawLine(CIwFVec2(aim.x, aim.y - 10), CIwFVec2(aim.x, aim.y + 10));

	Iw2DDrawLine(CIwFVec2(aim.x - 5, aim.y - 10), CIwFVec2(aim.x + 5, aim.y - 10));
	Iw2DDrawLine(CIwFVec2(aim.x - 5, aim.y + 10), CIwFVec2(aim.x + 5, aim.y + 10));

	Iw2DDrawLine(CIwFVec2(aim.x - 10, aim.y - 5), CIwFVec2(aim.x - 10, aim.y + 5));
	Iw2DDrawLine(CIwFVec2(aim.x + 10, aim.y - 5), CIwFVec2(aim.x + 10, aim.y + 5));
}