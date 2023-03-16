#include "IE_WeaponBase.h"
#include "Components/StaticMeshComponent.h"

AIE_WeaponBase::AIE_WeaponBase() : Super()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}
