// Fill out your copyright notice in the Description page of Project Settings.


#include "MB_Actor.h"

// Sets default values
AMB_Actor::AMB_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMB_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMB_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

