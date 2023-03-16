#pragma once

#include "CoreMinimal.h"
#include "InventoryExampleTypes.generated.h"

UENUM(BlueprintType)
enum class EObjectCategories : uint8
{
	None,
	Weapons,
	Bows,
	Shields,
	Clothes,
	Ingredients,
	Food,
	KeyObjects,
};

USTRUCT(BlueprintType)
struct FPickUpObjectInformation
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
		FText ObjectName;

	UPROPERTY(BlueprintReadOnly)
		FText ObjectDescription;

	int32 Id = -1;

	bool IsAvailable() { return Id != -1; }
	void Reset()
	{
		Id = -1;
	}

};