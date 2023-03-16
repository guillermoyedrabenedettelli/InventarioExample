#include "Components/IE_InteractionComponent.h"
#include "Actors/IE_WeaponPickUp.h"
#include "Camera/CameraComponent.h"
#include "CollisionQueryParams.h"
#include "InventoryExampleCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

UIE_InteractionComponent::UIE_InteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UIE_InteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	OwnerChar = Cast<AInventoryExampleCharacter>(GetOwner());
}


void UIE_InteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AInventoryExampleCharacter* OwnerCharacter = OwnerChar.Get();
	if (!OwnerCharacter)
		return;

	const FVector& StartLocation = OwnerCharacter->GetActorLocation();
	const FVector& EndLocation = StartLocation + OwnerCharacter->GetFollowCamera()->GetComponentRotation().Vector() * InteractDistance;
	FCollisionQueryParams Params(NAME_None, true, OwnerChar.Get());
	
	FHitResult OutHitResult;
	const bool bHit = GetWorld()->LineTraceSingleByChannel(OutHitResult, StartLocation, EndLocation, ECollisionChannel::ECC_GameTraceChannel1, Params);
	
	if (bHit && CurrentInteractedActor.Get() != OutHitResult.GetActor())
	{
		CurrentInteractedActor = OutHitResult.GetActor();
		OnInteractChanged.Broadcast(true);
	}
	else if (!bHit && CurrentInteractedActor.Get())
	{
		CurrentInteractedActor = nullptr;
		OnInteractChanged.Broadcast(false);
	}
}

void UIE_InteractionComponent::InteractWithObject()
{
	if (CurrentInteractedActor.Get())
	{
		AIE_PickUpObject* PickUp = Cast<AIE_PickUpObject>(CurrentInteractedActor.Get());
		if (!PickUp)
			return;

		OnInteractDone.ExecuteIfBound(CurrentInteractedActor.Get());
		PickUp->InteractWithMe();
		CurrentInteractedActor.Get()->Destroy();
		CurrentInteractedActor.Reset();
		OnInteractChanged.Broadcast(false);
	}
}

