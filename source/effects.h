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

#ifndef _EFFECTS_H
#define _EFFECTS_H

#include "IwArray.h"
#include "IwGeom.h"
#include "IwString.h"

struct Effect
{
    virtual bool Update(int timeDeltaMs) = 0;
    virtual void Render() = 0;
    virtual ~Effect() {}
};

struct ExplosionEffect : public Effect
{
	CIwFVec2 pos;
	float maxRadius, currRadius;
	int timer;

	static const int DURATION = 3000;

	ExplosionEffect(CIwFVec2 const & pos, float radius);
	bool Update(int timeDeltaMs);
	void Render();
};

struct EffectManager
{
    CIwArray<Effect*> effects;

    ~EffectManager();
    void Add(Effect* e) { effects.append(e); }
    void Clear();
    void Update(int timeDeltaMs);
    void Render();
};

extern EffectManager * g_EffectsManager;

#endif /* !_EFFECTS_H */
