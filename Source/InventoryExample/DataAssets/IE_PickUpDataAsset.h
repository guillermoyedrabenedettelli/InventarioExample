#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryExampleTypes.h"
#include "IE_PickUpDataAsset.generated.h"

UCLASS()
class INVENTORYEXAMPLE_API UIE_PickUpDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EObjectCategories Category;
};
