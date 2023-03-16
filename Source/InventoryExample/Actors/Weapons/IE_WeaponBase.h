#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IE_WeaponBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class INVENTORYEXAMPLE_API AIE_WeaponBase : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh = nullptr;

	AIE_WeaponBase();
};
