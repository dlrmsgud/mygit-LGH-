#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "MineItem.generated.h"

UCLASS()
class PROJECT04_API AMineItem : public ABaseItem
{
    GENERATED_BODY()

public:
    AMineItem();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
    USphereComponent* ExplosionCollision;

    // ���߱��� �ɸ��� �ð� (5��)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionDelay;
    // ���� ����
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionRadius;
    // ���� ������
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    int ExplosionDamage;

    // ���� �ߵ� ����
    FTimerHandle ExplosionTimerHandle;

    virtual void ActivateItem(AActor* Activator) override;

    void Explode();
};