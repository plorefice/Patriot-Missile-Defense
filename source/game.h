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
#ifndef _GAME_H
#define _GAME_H

#include "IwArray.h"
#include "IwGeom.h"
#include "effects.h"

#include <list>

const unsigned GAME_HEIGHT = 420;
const unsigned GAME_WIDTH = 740;

const CIwSVec2 RANGE_X(10,710);
const CIwSVec2 RANGE_Y(10,410);

const float g_RangeSpeed = 0.1f;

enum GameMode
{
    MODE_TITLE,
    MODE_GAMEPLAY
};

extern GameMode g_GameMode;
extern const int NUM_BUILDINGS;
extern CIwSVec2 buildings_pos[];
extern CIwSVec2 buildings_dim[];

void UpdateInput(int deltaTimeMs);

struct Trajectory {
	CIwFVec2 start;
	CIwFVec2 end;
	CIwFVec2 center;
	CIwFVec2 size;

	float speed_h;
	float m, c;
};

struct Missile
{
	CIwFVec2 pos;
	Trajectory traj;

	Missile();
	void Render();
	void Update(int deltaTimeMs);
};

struct Game
{
	enum GameMode {
		MODE_GAME_OVER,
		MODE_PLAYING,
		MODE_BOOTING
	};

	GameMode mode;
    int timer;          
    int score;          
    int level;
	int interval;
	CIwFVec2 aim;

	int curr_missiles;
	int max_missiles;
	int shot_missiles;

	std::list<Missile> missiles;
	std::list<ExplosionEffect *> explosions;

    Game();
	~Game();
    void Reset();
    void Render();
    void ApplyUserInput();
    void Update(int deltaTimeMs);
};

#endif /* !_GAME_H */
