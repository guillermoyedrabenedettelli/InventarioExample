#include "Actors/IE_WeaponPickUp.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Weapons/IE_WeaponBase.h"

void AIE_WeaponPickUp::InteractWithMe()
{
	Super::InteractWithMe();

	//weapon_right_socket
	const FVector& SocketLocation = Mesh->GetSocketLocation(TEXT("weapon_right_socket"));
	const FRotator& SocketRotation = Mesh->GetSocketRotation(TEXT("weapon_right_socket"));
	FActorSpawnParameters Params;
	Params.Owner = Cast<AActor>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (AIE_WeaponBase* Weapon = GetWorld()->SpawnActor<AIE_WeaponBase>(WeapontoSpawn, SocketLocation, SocketRotation, Params))
	{
		Weapon->AttachToComponent(UGameplayStatics::GetPlayerCharacter(this, 0)->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("weapon_right_socket"));
	}
	
}
