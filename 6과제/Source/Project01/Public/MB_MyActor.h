#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MB_MyActor.generated.h"

UCLASS()
class PROJECT01_API AMB_MyActor : public AActor
{
    GENERATED_BODY()

public:
    AMB_MyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(EditAnywhere, Category = "Components")
    USceneComponent* SceneRoot;

    UPROPERTY(EditAnywhere, Category = "Components")
    UStaticMeshComponent* StaticMeshComp;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MoveSpeed;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MovementRange;

    FVector InitialPosition;
    int MovementDirection;

    void MoveAutomatically(float DeltaTime);
};
