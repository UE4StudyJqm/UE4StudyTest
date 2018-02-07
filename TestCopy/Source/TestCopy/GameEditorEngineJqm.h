// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealEd.h"
#include "Engine.h"
//#include "Engine/GameEngine.h"
#include "GameEditorEngineJqm.generated.h"

/**
 * 
 */
UCLASS()
class TESTCOPY_API UGameEditorEngineJqm : public UUnrealEdEngine
{
	GENERATED_BODY()
public:

	virtual void FinishDestroy() override;
	virtual void CloseEditor() override;

	virtual void Init(IEngineLoop* InEngineLoop) override;
	virtual void PreExit() override;
	virtual void Tick(float DeltaSeconds, bool bIdleMode) override;

	virtual UGameInstance* CreatePIEGameInstance(int32 InPIEInstance, bool bInSimulateInEditor, bool bAnyBlueprintErrors, bool bStartInSpectatorMode, bool bRunAsDedicated, float PIEStartTime);

	//virtual void Init(class IEngineLoop* InEngineLoop) override;
	//virtual void Start() override;

private:

	/**
	* Hack to switch worlds for the PIE window before and after a slate event
	*
	* @param WorldID	The id of the world to restore or -1 if no world
	* @return The ID of the world to restore later or -1 if no world to restore
	*/
	int32 OnSwitchWorldForSlatePieWindow(int32 WorldID);

	/**
	* Called via a delegate to toggle between the editor and pie world
	*/
	void OnSwitchWorldsForPIE(bool bSwitchToPieWorld);

	/** Gets the scene viewport for a viewport client */
	const FSceneViewport* GetGameSceneViewport(UGameViewportClient* ViewportClient) const;

	
private:
	FDelegateHandle ViewportCloseRequestedDelegateHandle;
	
};
