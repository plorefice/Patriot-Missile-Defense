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

CIwSVec2 screen;

void CleanupImages()
{
    delete font;
}

void SetupImages(void)
{
    CleanupImages();
}

void DrawTitleScreen(TitleScreen *title)
{
	int w = 200, h = 80;
	int border = 10;

	Iw2DSetColour(0xffffffff);
	Iw2DFillRect(CIwFVec2((screen.x - w)/2, (screen.y - h)/2), CIwFVec2(w,h));

	Iw2DSetColour(0xff000000);
	Iw2DFillRect(CIwFVec2((screen.x - w)/2 + border, (screen.y - h)/2 + border),
				 CIwFVec2(w - 2*border, h - 2*border));
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
	int h = font->GetHeight();

	for (unsigned i = 0; i < g_Current_Line; i++) {
		int w = Iw2DGetStringWidth(g_Bootup_Sequence[i]);

		Iw2DSetColour(0xffffffff);
		Iw2DDrawString(g_Bootup_Sequence[i], CIwFVec2(0, i*h),
			CIwFVec2(w, h), IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);
	}
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