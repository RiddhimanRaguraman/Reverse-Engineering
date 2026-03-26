//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "_UnitTestConfiguration.h"

#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

using namespace Azul;

// Stubbed out
TEST(Student_3_Enable, TestConfig::ALL)
{
#if Student_3_Enable

	CHECK(PCSNode::MAJOR_VERSION == 6);
	CHECK(PCSNode::MINOR_VERSION == 0);



#endif
} TEST_END

// --- End of File ---
