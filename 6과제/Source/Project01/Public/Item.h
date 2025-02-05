
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"



UCLASS()
class PROJECT01_API AItem : public AActor
{
	GENERATED_BODY()

public:	
	AItem();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;

	virtual void BeginPlay() override;	
	virtual void Tick(float DeltaTime) override;
};