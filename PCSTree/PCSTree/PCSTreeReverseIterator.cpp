//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeReverseIterator.h"
#include "PCSTreeForwardIterator.h"

namespace Azul
{
	PCSTreeReverseIterator::PCSTreeReverseIterator(PCSNode* rootNode)
		: PCSTreeIterator()
	{
		assert(rootNode != nullptr);

		this->forwardRoot = rootNode;
		this->root = rootNode;
		this->current = rootNode;
		this->prevNode = nullptr;
		this->bDone = false;
	}

	PCSNode *PCSTreeReverseIterator::First()
	{
		this->current = this->root;
		return this->current;
	}

	PCSNode *PCSTreeReverseIterator::Next()
	{
		this->prevNode = this->current;
		this->current = this->current->GetReverse();
		return this->current;

	}

	bool PCSTreeReverseIterator::IsDone()
	{
		bDone = this->current == nullptr;
		return bDone;
	}

	PCSNode *PCSTreeReverseIterator::Current()
	{
		return  this->current;
	}

}

// ---  End of File ---
