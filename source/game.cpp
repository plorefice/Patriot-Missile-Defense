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

#include "game.h"
#include "rendering.h"
#include "localise.h"

#include "Iw2D.h"
#include "s3eKeyboard.h"
#include "s3ePointer.h"

#include <time.h>
#include <sstream>
#include <math.h>

GameMode g_GameMode = MODE_TITLE;

//
// Input ////////////////////////////////////////////////////////////////////////
//

float delta_x, delta_y;
int position_x, position_y;
bool usingKeyboard = true;
bool fired = false;

void UpdateInput(int deltaTimeMs)
{
    s3ePointerUpdate();
    s3eKeyboardUpdate();

	if (g_GameMode != MODE_GAMEPLAY)
		return;

	delta_x = delta_y = 0;
	fired = false;

	//
	// Keyboard //////////////////////////////////////////////////
	//

	if ((s3eKeyboardGetState(s3eKeyA) & S3E_KEY_STATE_DOWN) ||
		(s3eKeyboardGetState(s3eKeyLeft) & S3E_KEY_STATE_DOWN))
	{
		delta_x = -(deltaTimeMs * g_RangeSpeed);
		usingKeyboard = true;
	}

	if ((s3eKeyboardGetState(s3eKeyD) & S3E_KEY_STATE_DOWN) ||
		(s3eKeyboardGetState(s3eKeyRight) & S3E_KEY_STATE_DOWN))
	{
		delta_x = deltaTimeMs * g_RangeSpeed;
		usingKeyboard = true;
	}

	if ((s3eKeyboardGetState(s3eKeyW) & S3E_KEY_STATE_DOWN) ||
		(s3eKeyboardGetState(s3eKeyUp) & S3E_KEY_STATE_DOWN))
	{
		delta_y = -(deltaTimeMs * g_RangeSpeed);
		usingKeyboard = true;
	}

	if ((s3eKeyboardGetState(s3eKeyS) & S3E_KEY_STATE_DOWN) ||
		(s3eKeyboardGetState(s3eKeyDown) & S3E_KEY_STATE_DOWN))
	{
		delta_y = deltaTimeMs * g_RangeSpeed;
		usingKeyboard = true;
	}

	if (s3eKeyboardGetState(s3eKeySpace) & S3E_KEY_STATE_PRESSED)
	{
		fired = true;
	}

	//
	// Pointer ///////////////////////////////////////////////////
	//

	int x = s3ePointerGetX();
	int y = s3ePointerGetY();

	if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_DOWN)
	{
		if ((x >= RANGE_X.x && x <= RANGE_X.y) &&
			(y >= GAME_HEIGHT && y <= screen.y))
		{
			position_x = x;
			usingKeyboard = false;
		}

		if ((x >= GAME_WIDTH && x <= screen.x) &&
			(y >= RANGE_Y.x && y <= RANGE_Y.y))
		{
			position_y = y;
			usingKeyboard = false;
		}
	}
}

//
// Missile class //////////////////////////////////////////////////////////////////
//

Missile::Missile()
{
	int ch = rand()%2;

	traj.start.x = (float)((ch == 0) ? 0 : (rand() % (GAME_WIDTH - 250)) + 50);
	traj.start.y = (float)((ch == 0) ? (rand() % (GAME_HEIGHT - 80)) + 60 : 0);

	traj.end = CIwFVec2((float)(GAME_WIDTH - 30), (float)(GAME_HEIGHT));
	traj.center = CIwFVec2((traj.end.x + traj.start.x)/2,
						   (traj.end.y + traj.start.y)/2);

	traj.size.x = (float) sqrt(pow(traj.end.x - traj.center.x, 2) +
							   pow(traj.end.y - traj.center.y, 2));
	traj.size.y = traj.size.x;

	traj.m = (traj.end.y - traj.start.y)/(traj.end.x - traj.start.x);
	traj.c = traj.start.y - traj.m * traj.start.x;
	
	traj.speed_h = (float) (0.05 * pow(M_E, -(traj.m))); // px/ms


	pos = traj.start;
}

void Missile::Render()
{
	Iw2DSetColour(0xffffffff);
	Iw2DDrawLine(traj.start, pos);
}

void Missile::Update(int deltaTimeMs)
{
	float dx = deltaTimeMs * traj.speed_h;

	pos.x += dx;
	pos.y = (traj.m * pos.x) + traj.c;
}

//
// Game class ////////////////////////////////////////////////////////////////////////
//

const int NUM_BUILDINGS = 15;
CIwSVec2 buildings_pos[NUM_BUILDINGS];
CIwSVec2 buildings_dim[NUM_BUILDINGS];

Game::Game()
{
    Reset();
}

Game::~Game()
{
	missiles.clear();
}

void Game::Reset()
{
    srand(time(NULL));

	g_EffectsManager->Clear();

	timer = 0;
    score = 0;
    level = 1;
	interval = 2500;
	mode = MODE_BOOTING;

	aim.x = 350;
	aim.y = 200;
	
	curr_missiles = 0;
	max_missiles = 10;
	shot_missiles = 0;

	missiles.clear();

	for (int i = 0; i < NUM_BUILDINGS; i++)
	{
		int x = (rand() % 100) + 10;
		int y = (rand() % 40) + 10;
		
		int w = (x < 30) ? (rand() % (x - 9)) + 10 : (rand() % 20) + 10;
		int h = y;

		buildings_pos[i].x = x;
		buildings_pos[i].y = y;
		buildings_dim[i].x = w;
		buildings_dim[i].y = h;
	}
}

void Game::Render()
{
	if (mode == MODE_BOOTING) {
		DrawBootSequence();
		return;
	}

    DrawGameBackground();
	DrawGround();
	DrawScale(aim);

	for (std::list<Missile>::iterator it = missiles.begin(); it != missiles.end(); it++) {
		(*it).Render();
	}

	Iw2DSetFont(font);
	
	std::string s;
	std::stringstream out;

	int w, h = font->GetHeight();

	out << "Score: " << this->score;
	s = out.str();
	w = Iw2DGetStringWidth(s.c_str());

	Iw2DDrawString(s.c_str(), CIwFVec2(10.f,10.f), CIwFVec2(w, h),
		IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);

	out.str(std::string());
	out << "Level: " << this->level;
	s = out.str();
	w = Iw2DGetStringWidth(s.c_str());

	Iw2DDrawString(s.c_str(), CIwFVec2(GAME_WIDTH - w - 20, 10), CIwFVec2(w, h),
		IW_2D_FONT_ALIGN_LEFT, IW_2D_FONT_ALIGN_TOP);

	g_EffectsManager->Render();

	if (mode == MODE_GAME_OVER) 
	{
		DrawGameOverScreen();
	}
}


void Game::ApplyUserInput()
{
	if (usingKeyboard)
	{
		aim.x += (int) delta_x;
		aim.x = (aim.x > RANGE_X.y) ? RANGE_X.y : (aim.x < RANGE_X.x) ? RANGE_X.x : aim.x;

		aim.y += (int) delta_y;
		aim.y = (aim.y > RANGE_Y.y) ? RANGE_Y.y : (aim.y < RANGE_Y.x) ? RANGE_Y.x : aim.y;

		position_x = aim.x;
		position_y = aim.y;
	}
	else
	{
		aim.x = position_x;
		aim.y = position_y;
	}

	if (fired)
	{
		ExplosionEffect * expl = new ExplosionEffect(CIwFVec2(aim.x, aim.y), 12.0f);

		explosions.push_front(expl);
		g_EffectsManager->Add(expl);
	}
}


void Game::Update(int deltaTimeMs)
{
    timer += deltaTimeMs;

	for (std::list<ExplosionEffect *>::iterator it = explosions.begin();
		it != explosions.end(); it++)
	{
		if ((*it)->timer + deltaTimeMs > ExplosionEffect::DURATION)
			it = explosions.erase(it);
	}

	g_EffectsManager->Update(deltaTimeMs);

	ApplyUserInput();

    if (s3eKeyboardGetState(s3eKeyR) & S3E_KEY_STATE_PRESSED)
    {
        Reset();
    }

    if ((s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_PRESSED) ||
		(s3eKeyboardGetState(s3eKeyBack) & S3E_KEY_STATE_PRESSED) ||
		(s3eKeyboardGetState(s3eKeyEsc) & S3E_KEY_STATE_PRESSED)
		)
    {
        g_GameMode = MODE_TITLE;
        return;
    }

    if (mode==MODE_GAME_OVER)
    {
        if (timer > 500)
        {
            if ((s3eKeyboardGetState(s3eKeyAbsASK) & S3E_KEY_STATE_PRESSED)
              || (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) & S3E_POINTER_STATE_PRESSED) )
            {
                g_GameMode = MODE_TITLE;
            }
        }
    }
    else if (mode==MODE_PLAYING)
    {
		for (std::list<Missile>::iterator it = missiles.begin(); it != missiles.end(); it++) 
		{
			(*it).Update(deltaTimeMs);

			if (((*it).pos - (*it).traj.end).GetLength() < 1.0F) 
			{
				it = missiles.erase(it);
				mode = MODE_GAME_OVER;
			}

			for (std::list<ExplosionEffect*>::iterator et = explosions.begin(); et != explosions.end(); et++)
			{
				if (((*it).pos - (*et)->pos).GetLength() < (*et)->currRadius)
				{
					it = missiles.erase(it);
					score += level;
					shot_missiles++;

					if ((shot_missiles % 15) == 0)
					{
						level++;
						interval *= 0.92;
						max_missiles += 2;
					}
				}
			}
		}

		if (timer > interval) {
			if (curr_missiles < max_missiles) {
				missiles.push_front();
			}
			timer = 0;
		}
    }
	else if (mode==MODE_BOOTING)
	{	
		if (g_Current_Line == g_Total_Lines)
		{
			if (timer > 5000)
			{
				mode = MODE_PLAYING;
				timer = 0;
			}
		}
		else if (timer > (rand() % 1000))
		{
			g_Current_Line++;
			timer = 0;
		}
	}
}
