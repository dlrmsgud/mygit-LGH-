#include "MB_MyActor.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


AMB_MyActor::AMB_MyActor()
{
    PrimaryActorTick.bCanEverTick = true;

   
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    SetRootComponent(SceneRoot);

    
    StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComp->SetupAttachment(SceneRoot);

    
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComp->SetStaticMesh(MeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Potion_MP.M_Potion_MP"));
    if (MaterialAsset.Succeeded())
    {
        StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
    }

    MoveSpeed = 200.0f;  
    MovementDirection = 1; 
    MovementRange = 500.0f; 
    InitialPosition = FVector::ZeroVector; 
}


void AMB_MyActor::BeginPlay()
{
    Super::BeginPlay();
    InitialPosition = GetActorLocation(); 
}


void AMB_MyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    MoveAutomatically(DeltaTime);
}


void AMB_MyActor::MoveAutomatically(float DeltaTime)
{
    FVector NewLocation = GetActorLocation();
    NewLocation.X += MovementDirection * MoveSpeed * DeltaTime;
    SetActorLocation(NewLocation);

    
    if (FMath::Abs(NewLocation.X - InitialPosition.X) >= MovementRange)
    {
        MovementDirection *= -1; 
    }
}
