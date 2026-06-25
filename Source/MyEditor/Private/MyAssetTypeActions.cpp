// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyAssetTypeActions.h"
#include "MyCustomAsset.h"
#include "AssetToolsModule.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "MyEditor"

FText FMyAssetTypeActions::GetName() const
{
    return NSLOCTEXT("MyEditor", "MyAssetTypeActions", "My Custom Asset XXX");
}

FColor FMyAssetTypeActions::GetTypeColor() const
{
    return FColor(255, 128, 0);
}

UClass* FMyAssetTypeActions::GetSupportedClass() const
{
    return UMyCustomAsset::StaticClass();
}

uint32 FMyAssetTypeActions::GetCategories()
{
    return EAssetTypeCategories::Basic;
}

FText FMyAssetTypeActions::GetAssetDescription(const FAssetData& AssetData) const
{
    return NSLOCTEXT("MyEditor", "MyAssetTypeActions_Desc", "A custom asset type created in MyEditor");
}

#undef LOCTEXT_NAMESPACE
