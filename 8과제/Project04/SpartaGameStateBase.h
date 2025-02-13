#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SpartaGameStateBase.generated.h"


UCLASS()
class PROJECT04_API ASpartaGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;

	UPROPERTY(BlueprintReadWrite, Category = "Score")
	int32 GetScore() const;
	UPROPERTY(BlueprintReadWrite, Category = "Score")
	void AddScore(int32 Amount);
};
