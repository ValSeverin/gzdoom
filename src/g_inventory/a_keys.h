#ifndef A_KEYS_H
#define A_KEYS_H

#include "a_pickups.h"

class AKey : public AInventory
{
	DECLARE_CLASS (AKey, AInventory)
public:
	virtual bool HandlePickup (AInventory *item);

	BYTE KeyNumber;

protected:
	virtual bool ShouldStay ();
};

bool P_CheckKeys (AActor *owner, int keynum, bool remote);
void P_InitKeyMessages ();
void P_DeinitKeyMessages ();
int P_GetMapColorForLock (int lock);
int P_GetMapColorForKey (AInventory *key);


// PuzzleItems work in conjunction with the UsePuzzleItem special
class PClassPuzzleItem : public PClassInventory
{
	DECLARE_CLASS(PClassPuzzleItem, PClassInventory);
protected:
public:
	virtual void DeriveData(PClass *newclass);
	FString PuzzFailMessage;
};

class APuzzleItem : public AInventory
{
	DECLARE_CLASS_WITH_META(APuzzleItem, AInventory, PClassPuzzleItem)
public:
	
	bool ShouldStay ();
	bool Use (bool pickup);
	bool HandlePickup (AInventory *item);

	int PuzzleItemNumber;
};


#endif
