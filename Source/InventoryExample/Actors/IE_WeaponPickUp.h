#pragma once

#include "CoreMinimal.h"
#include "Actors/IE_PickUpObject.h"
#include "IE_WeaponPickUp.generated.h"

class AIE_WeaponBase;

UCLASS()
class INVENTORYEXAMPLE_API AIE_WeaponPickUp : public AIE_PickUpObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<AIE_WeaponBase> WeapontoSpawn = nullptr;

	virtual void InteractWithMe() override;
};
