
#include "Item.h"



AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//'/Game/Resources/Props/SM_Star_B.SM_Star_B'
	//'/Game/Resources/Materials/M_Potion_MP.M_Potion_MP'

	static ConstructorHelpers::FObjectFinder<UStaticMesh>	MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>	MaterialAsset(TEXT("/Game/Resources/Materials/M_Potion_MP.M_Potion_MP"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0,	MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();	

	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));

}
void AItem::Tick(float DeltaTime)
{	
	Super::Tick(DeltaTime);

	if(!FMath::IsNearlyZero(RotationSpeed))
	{ 
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
	
}
