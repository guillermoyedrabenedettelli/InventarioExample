#include "Actors/IE_PickUpObject.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DataAssets/IE_PickUpDataAsset.h"

AIE_PickUpObject::AIE_PickUpObject()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	InteractCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractCollision"));

	Mesh->SetupAttachment(RootComponent);
	InteractCollision->SetupAttachment(Mesh);
}

FText AIE_PickUpObject::GetName() const
{
	return DataAsset ? DataAsset->Name : FText();
}

FText AIE_PickUpObject::GetDescription() const
{
	return DataAsset ? DataAsset->Description : FText();
}

EObjectCategories AIE_PickUpObject::GetCategory() const
{
	return DataAsset ? DataAsset->Category : EObjectCategories::None;
}

void AIE_PickUpObject::BeginPlay()
{
	Super::BeginPlay();
}