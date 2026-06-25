// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "CoreMinimal.h"
#include "MyAssetFactory.generated.h"

/**
 * UMyAssetFactory
 *
 * 用于创建 UMyCustomAsset 资产的工厂类。
 * bCreateNew = true 使其出现在 Content Browser 的 "Create New" 菜单中。
 * ObjectFactory 元数据标签会自动将其注册到资产创建菜单。
 */
UCLASS(MinimalAPI, meta = (ObjectFactory))
class UMyAssetFactory : public UFactory
{
    GENERATED_BODY()

public:
    UMyAssetFactory();

    virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
                                     EObjectFlags Flags, UObject* Context,
                                     FFeedbackContext* Warn) override;
};
