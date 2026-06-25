// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyEditor.h"
#include "Modules/ModuleManager.h"

#include "MyCustomAsset.h"
#include "MyAssetTypeActions.h"
#include "MyAssetFactory.h"

#include "AssetToolsModule.h"
#include "IAssetTools.h"

#define LOCTEXT_NAMESPACE "MyEditor"

// 保存已注册的资产类型actions，防止被GC回收
static TArray<TSharedRef<FMyAssetTypeActions>> RegisteredAssetTypeActions;

void FMyEditorModule::StartupModule()
{
    // 注册资产类型actions
    FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");

    TSharedRef<FMyAssetTypeActions> MyAssetTypeActions = MakeShared<FMyAssetTypeActions>();
    AssetToolsModule.Get().RegisterAssetTypeActions(MyAssetTypeActions);
    RegisteredAssetTypeActions.Add(MyAssetTypeActions);
}

void FMyEditorModule::ShutdownModule()
{
    // 注销所有已注册的资产类型actions
    if (FAssetToolsModule::IsModuleLoaded())
    {
        FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
        IAssetTools& AssetTools = AssetToolsModule.Get();

        for (const TSharedRef<FMyAssetTypeActions>& Actions : RegisteredAssetTypeActions)
        {
            AssetTools.UnregisterAssetTypeActions(Actions);
        }
    }
    RegisteredAssetTypeActions.Empty();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_PRIMARY_GAME_MODULE(FMyEditorModule, MyEditor, "MyEditor");
