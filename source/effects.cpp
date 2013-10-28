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

#include "effects.h"
#include "rendering.h"

#include "Iw2D.h"

EffectManager * g_EffectsManager = NULL;

//
// ExplosionEffect Class ////////////////////////////////////////////////////////////////////////////
//

ExplosionEffect::ExplosionEffect(CIwFVec2 const & pos, float radius)
{
	this->pos = pos;
	this->maxRadius = radius;
	timer = 0;
}

bool ExplosionEffect::Update(int deltaTimeMs)
{
	timer += deltaTimeMs;

	currRadius = (timer < DURATION/2) ? (maxRadius / (DURATION/2)) * timer : 
		maxRadius * (2 - ((float)(timer) / (DURATION/2)));
	
	return timer < DURATION;
}

void ExplosionEffect::Render()
{
	Iw2DSetColour(0xffffffff);

	Iw2DFillArc(pos, CIwFVec2(currRadius, currRadius), 0.0f, 2 * PI, 30);
}

//
// EffectManager class ////////////////////////////////////////////////////////////////////////
//

EffectManager::~EffectManager()
{
    Clear();
}

void EffectManager::Clear()
{
    for (uint32 i=0; i<effects.size(); i++)
        delete effects[i];
    effects.clear();
}

void EffectManager::Update(int timeDeltaMs)
{
    for (uint32 i=0; i<effects.size(); )
    {
        Effect* e = effects[i];
        if (!effects[i]->Update(timeDeltaMs))
        {
            // Note: this is quite inefficient if many objects are removed at the same time
            effects.erase(i);
            delete e;
        }
        else
            i++;
    }
}

void EffectManager::Render()
{
    Iw2DSetColour(0xff808080);
    Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
    for (uint32 i=0; i<effects.size(); i++)
        effects[i]->Render();
    Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
    Iw2DSetColour(0xffffffff);
}
