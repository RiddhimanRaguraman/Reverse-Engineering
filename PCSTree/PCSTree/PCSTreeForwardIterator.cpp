//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeForwardIterator.h" 

namespace Azul
{
	PCSTreeForwardIterator::PCSTreeForwardIterator(PCSNode *rootNode)
	{
		this->root = rootNode;
		this->current = rootNode;
	}

	PCSNode *PCSTreeForwardIterator::First()
	{
		this->current = this->root;
		return this->current;
	}


	PCSNode* PCSTreeForwardIterator::Next()
	{
		this->current = this->current->GetForward();
		return this->current;
	}


	bool PCSTreeForwardIterator::IsDone()
	{
		if (this->current == nullptr)
			bDone = true;
		return bDone;
	}

	PCSNode *PCSTreeForwardIterator::Current()
	{
		return  this->current;
	}

}

// ---  End of File ---
