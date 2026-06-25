// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyAssetFactory.h"
#include "MyCustomAsset.h"

UMyAssetFactory::UMyAssetFactory()
{
    SupportedClass = UMyCustomAsset::StaticClass();
    bCreateNew = true;
    bEditAfterNew = true;
}

UObject* UMyAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent,
                                           FName InName, EObjectFlags Flags,
                                           UObject* Context, FFeedbackContext* Warn)
{
    UMyCustomAsset* NewAsset = NewObject<UMyCustomAsset>(InParent, InClass, InName, Flags);
    return NewAsset;
}
