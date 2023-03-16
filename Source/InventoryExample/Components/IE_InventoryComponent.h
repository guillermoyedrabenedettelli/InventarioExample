// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryExampleTypes.h"
#include "IE_InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventory
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
		int32 TotalSlots = 0;

	TArray<FPickUpObjectInformation> ObjectsInformation;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYEXAMPLE_API UIE_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	bool AddObject(AActor* ObjectToAdd);
	void DeleteObject(EObjectCategories Category, int32 Id);

protected:
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditDefaultsOnly)
		TMap<EObjectCategories, FInventory> Inventory;
};
