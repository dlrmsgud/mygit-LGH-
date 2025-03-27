// Fill out your copyright notice in the Description page of Project Settings.


#include "AOurGameMode.h"
#include "Math/UnrealMathUtility.h"

AOurGameMode::AOurGameMode()
{
    HostTries = 0;
    GuestTries = 0;
    bHostWin = false;
    bGuestWin = false;
    SecretNumber = GenerateRandomNumber();
}

void AOurGameMode::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("������ ���۵Ǿ����ϴ�! ���ڸ� ���纸����."));
}

FString AOurGameMode::GenerateRandomNumber()
{
    TArray<int32> Numbers;
    for (int32 i = 1; i <= 9; i++)
        Numbers.Add(i);

    FString Result = "";
    for (int32 i = 0; i < 3; i++)
    {
        int32 Index = FMath::RandRange(0, Numbers.Num() - 1);
        Result.Append(FString::FromInt(Numbers[Index]));
        Numbers.RemoveAt(Index);
    }
    return Result;
}

bool AOurGameMode::IsValidInput(FString Input)
{
    if (Input.Len() != 3) return false;
    TSet<TCHAR> UniqueChars;
    for (TCHAR Char : Input)
    {
        if (!FChar::IsDigit(Char) || Char == '0' || UniqueChars.Contains(Char))
            return false;
        UniqueChars.Add(Char);
    }
    return true;
}

TPair<int32, int32> AOurGameMode::CheckStrikeAndBall(FString Input)
{
    int32 Strikes = 0, Balls = 0;
    for (int32 i = 0; i < 3; i++)
    {
        if (Input[i] == SecretNumber[i])
            Strikes++;
        else if (SecretNumber.Contains(Input[i]))
            Balls++;
    }
    return TPair<int32, int32>(Strikes, Balls);
}

void AOurGameMode::ProcessPlayerInput(FString PlayerName, FString Input)
{
    if (!IsValidInput(Input))
    {
        UE_LOG(LogTemp, Warning, TEXT("%s OUT (�߸��� �Է�)"), *PlayerName);
        if (PlayerName == "Host") bGuestWin = true;
        else bHostWin = true;
        ResetGame();
        return;
    }

    TPair<int32, int32> Result = CheckStrikeAndBall(Input);
    UE_LOG(LogTemp, Warning, TEXT("%s ���: %dS%dB"), *PlayerName, Result.Key, Result.Value);

    if (Result.Key == 3)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s Won!! �ٽ� ������ ���۵ƴ�."), *PlayerName);
        ResetGame();
        return;
    }

    if (PlayerName == "Host") HostTries++;
    else GuestTries++;

    if (HostTries == 3 && GuestTries == 3)
    {
        UE_LOG(LogTemp, Warning, TEXT("���ºα�. �ٽ� ������ ��������"));
        ResetGame();
    }
}

void AOurGameMode::ResetGame()
{
    SecretNumber = GenerateRandomNumber();
    HostTries = GuestTries = 0;
    bHostWin = bGuestWin = false;
    UE_LOG(LogTemp, Warning, TEXT("���ο� ������ ���۵Ǿ����ϴ�!"));
}
