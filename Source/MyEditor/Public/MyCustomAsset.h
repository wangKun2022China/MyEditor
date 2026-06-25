// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MyCustomAsset.generated.h"

/**
 * EMyAssetState
 *
 * 示例枚举类型，用于 MyCustomAsset 资产生命周期状态管理。
 */
UENUM()
enum class EMyAssetState : uint8
{
    Inactive,
    Active,
    Suspended UMETA(DisplayName = "暂停")
};

/**
 * UMyCustomAsset
 *
 * 自定义资产类型，可在 Content Browser 中创建和管理。
 * 此类用于存储游戏配置、数据表引用或任何需要持久化的资源。
 */
UCLASS(BlueprintType, EditInlineNew, AutoExpandCategories=(MyCustomAsset))
class MYEDITOR_API UMyCustomAsset : public UObject
{
    GENERATED_BODY()

public:
    UMyCustomAsset();

    /** 资产显示名称 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyCustomAsset)
    FString DisplayName;

    /** 数值属性 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyCustomAsset)
    float MyFloatValue = 0.0f;

    /** 枚举状态 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyCustomAsset)
    EMyAssetState MyState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyCustomAsset)
	TObjectPtr<UMyCustomAsset> MyAsset;
};
