#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolme.generated.h"

class UBoxComponent;

UCLASS()
class PROJECT04_API ASpawnVolme : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolme();

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnRandomItem();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawninBox;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	FVector GetRendomPointInVolume() const;
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnItem(TSubclassOf<AActor>ItemClass);

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnRandomItem(); 

	FItemSpawnRow* GetRandomItem() const;
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
	FVector GetRandomPointInVolume() const;
};
