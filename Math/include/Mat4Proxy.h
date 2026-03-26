//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_MAT4_PROXY_H
#define ENGINE_MATH_MAT4_PROXY_H

#include "Math_DLLInterface.h"
#include "Mat4Hint.h"

namespace Azul
{
	// Matrix related proxies here:
	struct Mat4Proxy
	{
		inline Mat4Proxy(Mat4& rMat, float& _x)
			: ref(rMat), x(_x)
		{
		}

		inline Mat4Proxy operator = (float v)
		{
			x = v;

			// No knowledge on how changing this element affects the matrix
			// Generalize the matrix hint without altering the stored value

			((Mat4Hint&)ref).privSetGeneralHint();

			return *this;
		}

		inline operator float()
		{
			return this->x;
		}

		Mat4& ref;
		float& x;
	};

}

#endif

//--- End of File ---
