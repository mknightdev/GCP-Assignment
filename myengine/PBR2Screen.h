#pragma once

#include "Component.h"

#include <myrenderer/myrenderer.h>

namespace myengine
{
	struct Mesh;
	struct Texture;

	struct PBR2Screen : Component
	{
		void onInitialize();
		void onTick(float _deltaTime);
	};
}