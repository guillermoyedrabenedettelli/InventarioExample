#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IE_InteractInterface.h"
#include "IE_PickUpObject.generated.h"

class UIE_PickUpDataAsset;
class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class INVENTORYEXAMPLE_API AIE_PickUpObject : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UIE_PickUpDataAsset* DataAsset = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UStaticMeshComponent* Mesh = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UBoxComponent* InteractCollision = nullptr;

	UFUNCTION(BlueprintCallable)
		FText GetName() const;
	UFUNCTION(BlueprintCallable)
		FText GetDescription() const;
	UFUNCTION(BlueprintCallable)
		EObjectCategories GetCategory() const;

	AIE_PickUpObject();

	virtual void InteractWithMe() {};

protected:
	virtual void BeginPlay() override;
};
