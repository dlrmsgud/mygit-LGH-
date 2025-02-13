#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.generated.h"


USTRUCT(BlueprintType)
class PROJECT04_API ItemSpawnRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Spawnchance;
};
