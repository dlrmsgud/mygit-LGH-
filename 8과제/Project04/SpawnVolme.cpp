#include "SpawnVolme.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"

ASpawnVolme::ASpawnVolme()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawninBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawninBox"));
	SpawninBox->SetupAttachment(Scene);

	ItemDataTable = nullptr;
}

void ASpawnVolume::SpawnRandomItem()
{
	if (FItemSpawnRow* SelectedRow = GetRandomItem())
	{
		if (UClass* ActualClass = SelectedRow->ItemClass.Get())
		{
			SpawnItem(ActualClass);
		}
	}
}


FVector ASpawnVolme::GetRendomPointInVolume() const
{
	FVector BoxExtent = SpawninBox->GetScaledBoxExtent();
	FVector BoxOrigin = SpawninBox->GetComponentLocation();

	return BoxOrigin = FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

AActor* ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	if (!ItemClass) return nullptr;

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
		ItemClass,
		GetRandomPointInVolume(),
		FRotator::ZeroRotator
	);

	return SpawnedActor;
}
