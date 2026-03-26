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
TEST(Student_1_Enable, TestConfig::ALL)
{
#if Student_1_Enable
    PCSTree tree;
    PCSNode* rootPtr = tree.GetRoot();

    // --------------------------------------------------------------------
    // Construct the same 24?node hierarchy used in the official checks so
    // the expected orders are easy to verify against by eye if needed.
    // --------------------------------------------------------------------
    PCSNode nodeRoot("Root");
    PCSNode nodeA("Node_A");
    PCSNode nodeB("Node_B");
    PCSNode nodeC("Node_C");
    PCSNode nodeD("Node_D");
    PCSNode nodeE("Node_E");
    PCSNode nodeI("Node_I");
    PCSNode nodeK("Node_K");
    PCSNode nodeL("Node_L");
    PCSNode nodeR("Node_R");
    PCSNode nodeF("Node_F");
    PCSNode nodeG("Node_G");
    PCSNode nodeJ("Node_J");
    PCSNode nodeM("Node_M");
    PCSNode nodeN("Node_N");
    PCSNode nodeO("Node_O");
    PCSNode nodeP("Node_P");
    PCSNode nodeQ("Node_Q");
    PCSNode nodeH("Node_H");
    PCSNode nodeS("Node_S");
    PCSNode nodeT("Node_T");
    PCSNode nodeU("Node_U");
    PCSNode nodeV("Node_V");
    PCSNode nodeW("Node_W");

    // Same insertion sequence as AddNodeRootABCDEIKLRFGJMNOPQHSTUVW_Check.cpp
    tree.Insert(&nodeRoot, rootPtr);
    tree.Insert(&nodeC, &nodeRoot);
    tree.Insert(&nodeB, &nodeRoot);
    tree.Insert(&nodeA, &nodeRoot);
    tree.Insert(&nodeI, &nodeA);
    tree.Insert(&nodeE, &nodeA);
    tree.Insert(&nodeD, &nodeA);
    tree.Insert(&nodeL, &nodeB);
    tree.Insert(&nodeK, &nodeB);
    tree.Insert(&nodeR, &nodeC);
    tree.Insert(&nodeF, &nodeD);
    tree.Insert(&nodeJ, &nodeI);
    tree.Insert(&nodeG, &nodeI);
    tree.Insert(&nodeN, &nodeL);
    tree.Insert(&nodeM, &nodeL);
    tree.Insert(&nodeQ, &nodeR);
    tree.Insert(&nodeP, &nodeR);
    tree.Insert(&nodeO, &nodeR);
    tree.Insert(&nodeH, &nodeF);
    tree.Insert(&nodeS, &nodeP);
    tree.Insert(&nodeW, &nodeS);
    tree.Insert(&nodeV, &nodeS);
    tree.Insert(&nodeU, &nodeS);
    tree.Insert(&nodeT, &nodeS);

    // --------------------------------------------------------------------
    // Expected traversal orders (pre?computed by hand - see analysis).
    // Forward order = pre?order, left?to?right.
    // Reverse order = exact reverse of the forward list.
    // --------------------------------------------------------------------
    std::vector<PCSNode*> forwardExpected =
    {
        &nodeRoot,
        &nodeA,
        &nodeD,
        &nodeF,
        &nodeH,
        &nodeE,
        &nodeI,
        &nodeG,
        &nodeJ,
        &nodeB,
        &nodeK,
        &nodeL,
        &nodeM,
        &nodeN,
        &nodeC,
        &nodeR,
        &nodeO,
        &nodeP,
        &nodeS,
        &nodeT,
        &nodeU,
        &nodeV,
        &nodeW,
        &nodeQ
    };

    std::vector<PCSNode*> reverseExpected =
    {
        &nodeQ,
        &nodeW,
        &nodeV,
        &nodeU,
        &nodeT,
        &nodeS,
        &nodeP,
        &nodeO,
        &nodeR,
        &nodeC,
        &nodeN,
        &nodeM,
        &nodeL,
        &nodeK,
        &nodeB,
        &nodeJ,
        &nodeG,
        &nodeI,
        &nodeE,
        &nodeH,
        &nodeF,
        &nodeD,
        &nodeA,
        &nodeRoot
    };

    // --------------------------------------------------------------------
    // Forward iterator validation
    // --------------------------------------------------------------------
    PCSTreeForwardIterator fIter(tree.GetRoot());
    size_t index = 0;
    PCSNode* pTmp = fIter.First();
    while (!fIter.IsDone())
    {
        CHECK(pTmp == forwardExpected[index]);
        pTmp = fIter.Next();
        ++index;
    }
    CHECK(index == forwardExpected.size());
    CHECK(pTmp == nullptr);
    CHECK(fIter.IsDone());

    // Basic check that the Reverse linkage was written during forward walk
    CHECK(nodeA.GetReverse() == &nodeRoot);
    CHECK(nodeD.GetReverse() == &nodeA);
    CHECK(nodeF.GetReverse() == &nodeD);

    // --------------------------------------------------------------------
    // Reverse iterator validation (walks from last node back to root)
    // --------------------------------------------------------------------
    PCSTreeReverseIterator rIter(tree.GetRoot());
    index = 0;
    pTmp = rIter.First();
    while (!rIter.IsDone())
    {
        CHECK(pTmp == reverseExpected[index]);
        pTmp = rIter.Next();
        ++index;
    }
    CHECK(index == reverseExpected.size());
    CHECK(pTmp == nullptr);
    CHECK(rIter.IsDone());

    // Basic check that Forward linkage was written during reverse walk
    CHECK(nodeRoot.GetForward() == &nodeA);
    CHECK(nodeA.GetForward() == &nodeD);
    CHECK(nodeD.GetForward() == &nodeF);
#endif
} TEST_END

// --- End of File ---
