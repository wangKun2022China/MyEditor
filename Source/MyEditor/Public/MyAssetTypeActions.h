// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AssetTypeActions_Base.h"
#include "CoreMinimal.h"

/**
 * FMyAssetTypeActions
 *
 * 向 Content Browser 注册自定义资产类型。
 * 继承 FAssetTypeActions_Base，默认实现大多数 IAssetTypeActions 接口方法。
 */
class FMyAssetTypeActions : public FAssetTypeActions_Base
{
public:
    // IAssetTypeActions interface
    virtual FText GetName() const override;
    virtual FColor GetTypeColor() const override;
    virtual UClass* GetSupportedClass() const override;
    virtual uint32 GetCategories() override;
    virtual FText GetAssetDescription(const FAssetData& AssetData) const override;
};
