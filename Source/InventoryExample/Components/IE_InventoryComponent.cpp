#include "Components/IE_InventoryComponent.h"
#include "Actors/IE_PickUpObject.h"

bool UIE_InventoryComponent::AddObject(AActor* ObjectToAdd)
{
	if (AIE_PickUpObject* PickUp = Cast<AIE_PickUpObject>(ObjectToAdd))
	{
		//EObjectCategories PickUpCategory = PickUp->GetCategory();
		//FInventory& CategoryInventory = Inventory[PickUpCategory];
		//
		//if (CategoryInventory.ObjectsInformation.Num() < CategoryInventory.TotalSlots)
		//{
		//	FPickUpObjectInformation NewObject;
		//
		//	NewObject.ObjectName = PickUp->GetName();
		//	NewObject.ObjectDescription = PickUp->GetDescription();
		//	NewObject.Id = CategoryInventory.ObjectsInformation.Num();
		//
		//	for (int32 Index = 0; Index < CategoryInventory.TotalSlots; ++Index)
		//	{
		//		if (CategoryInventory.ObjectsInformation[Index].IsAvailable())
		//		{
		//			CategoryInventory.ObjectsInformation[Index] = NewObject;
		//			return true;
		//		}
		//	}
		//}
	}

	return false;
}

void UIE_InventoryComponent::DeleteObject(EObjectCategories Category, int32 Id)
{
	FInventory& CategoryInventory = Inventory[Category];
	if (Id >= 0 && Id < CategoryInventory.TotalSlots)
	{
		CategoryInventory.ObjectsInformation.RemoveAt(Id);
		CategoryInventory.ObjectsInformation[Id].Reset();
	}
}

void UIE_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TPair<EObjectCategories, FInventory>& SubInventory : Inventory)
	{
		SubInventory.Value.ObjectsInformation.Reserve(SubInventory.Value.TotalSlots);
	}
}
