// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "IE_InteractionComponent.generated.h"

class AInventoryExampleCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractChanged, bool, bActive);
DECLARE_DELEGATE_OneParam(FInteractDone, AActor*);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYEXAMPLE_API UIE_InteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditDefaultsOnly)
		float InteractDistance = 200.f;
	UPROPERTY(BlueprintAssignable)
		FInteractChanged OnInteractChanged;

	FInteractDone OnInteractDone;

	UIE_InteractionComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InteractWithObject();
protected:
	virtual void BeginPlay() override;

private:
	TWeakObjectPtr<AInventoryExampleCharacter> OwnerChar = nullptr;
	TWeakObjectPtr<AActor> CurrentInteractedActor = nullptr;
		
};
