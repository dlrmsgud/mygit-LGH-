// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AOurGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ASDSAD_API AAOurGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    AOurGameMode();

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void ProcessPlayerInput(FString PlayerName, FString Input);

private:
    FString SecretNumber;
    int32 HostTries;
    int32 GuestTries;
    bool bHostWin;
    bool bGuestWin;

    FString GenerateRandomNumber();
    TPair<int32, int32> CheckStrikeAndBall(FString Input);
    bool IsValidInput(FString Input);
    void ResetGame();

};
