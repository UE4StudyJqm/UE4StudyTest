// Fill out your copyright notice in the Description page of Project Settings.

//#include "Developer/TargetPlatform/Public/Interfaces/TargetDeviceId.h"

#include "GameEditorEngineJqm.h"

//#include "Developer/TargetPlatform/Public/Interfaces/ITargetDevice.h"
//#include "Developer/TargetPlatform/Public/Interfaces/ITargetPlatform.h"




//#include "Runtime/Core/Public/Logging/MessageLog.h"
//#include "IXRTrackingSystem.h"
#include "ILevelViewport.h"
#include "Editor/MainFrame/Public/Interfaces/IMainFrameModule.h"

#include "Misc/MessageDialog.h"
#include "Misc/CommandLine.h"
#include "Misc/Paths.h"
#include "Misc/Guid.h"
#include "Stats/Stats.h"
#include "GenericPlatform/GenericApplication.h"
#include "Misc/App.h"
#include "Modules/ModuleManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/GarbageCollection.h"
#include "UObject/Class.h"
#include "UObject/UObjectIterator.h"
#include "UObject/Package.h"
#include "UObject/LazyObjectPtr.h"
#include "UObject/SoftObjectPtr.h"
#include "Serialization/ArchiveTraceRoute.h"
#include "Misc/PackageName.h"
#include "InputCoreTypes.h"
#include "Layout/Margin.h"
#include "Layout/SlateRect.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SWindow.h"
#include "Layout/WidgetPath.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/SViewport.h"
#include "Framework/Docking/TabManager.h"
#include "EditorStyleSet.h"
#include "EditorStyleSettings.h"
#include "Engine/EngineTypes.h"
#include "Async/TaskGraphInterfaces.h"
#include "GameFramework/Actor.h"
#include "Engine/Blueprint.h"
#include "Engine/GameViewportClient.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Settings/LevelEditorPlaySettings.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Editor/EditorEngine.h"
#include "Editor/UnrealEdEngine.h"
#include "Settings/ProjectPackagingSettings.h"
#include "GameMapsSettings.h"
#include "GeneralProjectSettings.h"
#include "Engine/NavigationObjectBase.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/GameModeBase.h"
#include "Components/AudioComponent.h"
#include "Engine/Note.h"
#include "Engine/Selection.h"
#include "UnrealEngine.h"
#include "EngineUtils.h"
#include "Editor.h"
#include "LevelEditorViewport.h"
#include "EditorModeManager.h"
#include "EditorModes.h"
#include "UnrealEdMisc.h"
#include "FileHelpers.h"
#include "UnrealEdGlobals.h"
#include "EditorAnalytics.h"
#include "AudioDevice.h"
#include "BusyCursor.h"
#include "ScopedTransaction.h"
#include "PackageTools.h"
#include "Slate/SceneViewport.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Toolkits/AssetEditorManager.h"
#include "LevelEditor.h"
//#include "ILevelViewport.h"
#include "BlueprintEditorModule.h"
//#include "Interfaces/ITargetPlatform.h"
//#include "Interfaces/ITargetPlatformManagerModule.h"
//#include "Interfaces/IMainFrameModule.h"
#include "Logging/TokenizedMessage.h"
#include "Logging/MessageLog.h"
#include "Misc/UObjectToken.h"
#include "Misc/MapErrors.h"
//#include "ITargetDeviceServicesModule.h"
//#include "ILauncherServicesModule.h"
//#include "GameProjectGenerationModule.h"
#include "SourceCodeNavigation.h"
#include "PhysicsPublic.h"
//#include "AnalyticsEventAttribute.h"
//#include "Interfaces/IAnalyticsProvider.h"
#include "EngineAnalytics.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Engine/LocalPlayer.h"
#include "Slate/SGameLayerManager.h"

#include "IHeadMountedDisplay.h"
#include "IXRTrackingSystem.h"
#include "Engine/LevelStreaming.h"
#include "Components/ModelComponent.h"
#include "GameDelegates.h"
#include "Net/OnlineEngineInterface.h"
#include "Kismet2/DebuggerCommands.h"
#include "Misc/ScopeExit.h"
#include "IVREditorModule.h"



#define LOCTEXT_NAMESPACE "GameEditorEngineJqm"
const static FName NAME_CategoryPIE("Jqm-PIE");
//void UGameEngineJqm::Init(class IEngineLoop* InEngineLoop)
//{
//	FString();
//}
//
//void UGameEngineJqm::Start()
//{
//	FString();
//}

void UGameEditorEngineJqm::FinishDestroy()
{
	FString();
}

void UGameEditorEngineJqm::CloseEditor()
{
	FString();
}

void UGameEditorEngineJqm::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);
	FString();
}

void UGameEditorEngineJqm::PreExit()
{

}

void UGameEditorEngineJqm::Tick(float DeltaSeconds, bool bIdleMode)
{
	Super::Tick(DeltaSeconds, bIdleMode);
}

UGameInstance* UGameEditorEngineJqm::CreatePIEGameInstance(int32 InPIEInstance, bool bInSimulateInEditor, bool bAnyBlueprintErrors, bool bStartInSpectatorMode, bool bRunAsDedicated, float PIEStartTime)
{
	FString();

	const FString WorldPackageName = EditorWorld->GetOutermost()->GetName();

	const bool bUseVRPreview = bUseVRPreviewForPlayWorld && (InPIEInstance >= 0 && InPIEInstance <= 1);

	// Start a new PIE log page
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Package"), FText::FromString(FPackageName::GetLongPackageAssetName(WorldPackageName)));
		Arguments.Add(TEXT("TimeStamp"), FText::AsDateTime(FDateTime::Now()));

		FText PIESessionLabel = bInSimulateInEditor ?
			FText::Format(LOCTEXT("SIESessionLabel", "SIE session: {Package} ({TimeStamp})"), Arguments) :
			FText::Format(LOCTEXT("PIESessionLabel", "PIE session: {Package} ({TimeStamp})"), Arguments);

		FMessageLog(NAME_CategoryPIE).NewPage(PIESessionLabel);
	}

	// create a new GameInstance
	FSoftClassPath GameInstanceClassName = GetDefault<UGameMapsSettings>()->GameInstanceClass;
	UClass* GameInstanceClass = (GameInstanceClassName.IsValid() ? LoadObject<UClass>(NULL, *GameInstanceClassName.ToString()) : UGameInstance::StaticClass());

	// If the GameInstance class from the settings cannot be found, fall back to the base class
	if (GameInstanceClass == nullptr)
	{
		GameInstanceClass = UGameInstance::StaticClass();
	}
	UGameInstance* GameInstance = NewObject<UGameInstance>(this, GameInstanceClass);

	// We need to temporarily add the GameInstance to the root because the InitPIE call can do garbage collection wiping out the GameInstance
	GameInstance->AddToRoot();

	FGameInstancePIEParameters GameInstanceParams;
	GameInstanceParams.bAnyBlueprintErrors = bAnyBlueprintErrors;
	GameInstanceParams.bSimulateInEditor = bInSimulateInEditor;
	GameInstanceParams.bStartInSpectatorMode = bStartInSpectatorMode;
	GameInstanceParams.bRunAsDedicated = bRunAsDedicated;


	const FGameInstancePIEResult InitializeResult = GameInstance->InitializeForPlayInEditor(InPIEInstance, GameInstanceParams);
	if (!InitializeResult.IsSuccess())
	{
		FMessageDialog::Open(EAppMsgType::Ok, InitializeResult.FailureReason);

		FEditorDelegates::EndPIE.Broadcast(bInSimulateInEditor);

		if (EditorWorld->GetNavigationSystem())
		{
			EditorWorld->GetNavigationSystem()->OnPIEEnd();
		}

		return nullptr;
	}

	FWorldContext* const PieWorldContext = GameInstance->GetWorldContext();
	check(PieWorldContext);
	PlayWorld = PieWorldContext->World();

	GWorld = PlayWorld;
	SetPlayInEditorWorld(PlayWorld);

#if PLATFORM_64BITS
	const FString PlatformBitsString(TEXT("64"));
#else
	const FString PlatformBitsString(TEXT("32"));
#endif

	const FText WindowTitleOverride = GetDefault<UGeneralProjectSettings>()->ProjectDisplayedTitle;

	FFormatNamedArguments Args;
	Args.Add(TEXT("GameName"), FText::FromString(FString(WindowTitleOverride.IsEmpty() ? FApp::GetProjectName() : WindowTitleOverride.ToString())));
	Args.Add(TEXT("PlatformBits"), FText::FromString(PlatformBitsString));
	Args.Add(TEXT("RHIName"), FText::FromName(LegacyShaderPlatformToShaderFormat(GShaderPlatformForFeatureLevel[GMaxRHIFeatureLevel])));

	const ULevelEditorPlaySettings* PlayInSettings = GetDefault<ULevelEditorPlaySettings>();
	const EPlayNetMode PlayNetMode = [&PlayInSettings] { EPlayNetMode NetMode(PIE_Standalone); return (PlayInSettings->GetPlayNetMode(NetMode) ? NetMode : PIE_Standalone); }();
	if (PlayNetMode == PIE_Client)
	{
		Args.Add(TEXT("NetMode"), FText::FromString(FString::Printf(TEXT("Client %d"), PieWorldContext->PIEInstance - 1)));
	}
	else if (PlayNetMode == PIE_ListenServer)
	{
		Args.Add(TEXT("NetMode"), FText::FromString(TEXT("Server")));
	}
	else
	{
		Args.Add(TEXT("NetMode"), FText::FromString(TEXT("Standalone")));
	}

	const FText ViewportName = FText::Format(NSLOCTEXT("UnrealEd", "PlayInEditor_RHI_F", "{GameName} Game Preview {NetMode} ({PlatformBits}-bit/{RHIName})"), Args);

	// Make a list of all the selected actors
	TArray<UObject *> SelectedActors;
	TArray<UObject*> SelectedComponents;
	for (FSelectionIterator It(GetSelectedActorIterator()); It; ++It)
	{
		AActor* Actor = static_cast<AActor*>(*It);
		if (Actor)
		{
			checkSlow(Actor->IsA(AActor::StaticClass()));

			SelectedActors.Add(Actor);
		}
	}


	// Unselect everything
	GEditor->SelectNone(true, true, false);
	GetSelectedActors()->DeselectAll();
	GetSelectedObjects()->DeselectAll();
	GetSelectedComponents()->DeselectAll();

	// For every actor that was selected previously, make sure it's sim equivalent is selected
	for (int32 ActorIndex = 0; ActorIndex < SelectedActors.Num(); ++ActorIndex)
	{
		AActor* Actor = Cast<AActor>(SelectedActors[ActorIndex]);
		if (Actor)
		{
			ActorsThatWereSelected.Add(Actor);

			AActor* SimActor = EditorUtilities::GetSimWorldCounterpartActor(Actor);
			if (SimActor && !SimActor->bHidden && bInSimulateInEditor)
			{
				SelectActor(SimActor, true, false);
			}
		}
	}

	// For play in editor, this is the viewport widget where the game is being displayed
	TSharedPtr<SViewport> PieViewportWidget;

	// Initialize the viewport client.
	UGameViewportClient* ViewportClient = NULL;
	ULocalPlayer *NewLocalPlayer = NULL;

	if (GEngine->XRSystem.IsValid() && !bInSimulateInEditor)
	{
		GEngine->XRSystem->OnBeginPlay(*PieWorldContext);
	}

	if (!PieWorldContext->RunAsDedicated)
	{
		bool bCreateNewAudioDevice = PlayInSettings->IsCreateAudioDeviceForEveryPlayer();

		ViewportClient = NewObject<UGameViewportClient>(this, GameViewportClientClass);
		ViewportClient->Init(*PieWorldContext, GameInstance, bCreateNewAudioDevice);

		GameViewport = ViewportClient;
		GameViewport->bIsPlayInEditorViewport = true;
		PieWorldContext->GameViewport = ViewportClient;

		// Add a handler for game client input key
		ViewportClient->OnGameViewportInputKey().BindUObject(this, &UEditorEngine::ProcessDebuggerCommands);

		// Add a handler for viewport close requests
		ViewportCloseRequestedDelegateHandle = ViewportClient->OnCloseRequested().AddUObject(this, &UEditorEngine::OnViewportCloseRequested);
		FSlatePlayInEditorInfo& SlatePlayInEditorSession = SlatePlayInEditorMap.Add(PieWorldContext->ContextHandle, FSlatePlayInEditorInfo());
		SlatePlayInEditorSession.DestinationSlateViewport = RequestedDestinationSlateViewport;	// Might be invalid depending how pie was launched. Code below handles this.
		RequestedDestinationSlateViewport = NULL;

		FString Error;
		NewLocalPlayer = ViewportClient->SetupInitialLocalPlayer(Error);
		if (!NewLocalPlayer)
		{
			FMessageDialog::Open(EAppMsgType::Ok, FText::Format(NSLOCTEXT("UnrealEd", "Error_CouldntSpawnPlayer", "Couldn't spawn player: {0}"), FText::FromString(Error)));
			// go back to using the real world as GWorld
			RestoreEditorWorld(EditorWorld);
			EndPlayMap();
			return nullptr;
		}

		if (!bInSimulateInEditor)
		{
			SlatePlayInEditorSession.EditorPlayer = NewLocalPlayer;
		}

		// Note: For K2 debugging purposes this MUST be created before beginplay is called because beginplay can trigger breakpoints
		// and we need to be able to refocus the pie viewport afterwards so it must be created first in order for us to find it
		{
			// Only create a separate viewport and window if we aren't playing in a current viewport
			if (SlatePlayInEditorSession.DestinationSlateViewport.IsValid())
			{
				TSharedPtr<ILevelViewport> LevelViewportRef = SlatePlayInEditorSession.DestinationSlateViewport.Pin();

				LevelViewportRef->StartPlayInEditorSession(ViewportClient, bInSimulateInEditor);

				//SlatePlayInEditorSession.SlatePlayInEditorWindowViewport = MakeShareable<FSceneViewport>((FSceneViewport*)LevelViewportRef->GetActiveViewport());
			}
			else
			{
				const int32 PlayNumberOfClients = [&PlayInSettings] { int32 NumberOfClients(0); return (PlayInSettings->GetPlayNumberOfClients(NumberOfClients) ? NumberOfClients : 0); }();

				// Create the top level pie window and add it to Slate
				uint32 NewWindowHeight = PlayInSettings->NewWindowHeight;
				uint32 NewWindowWidth = PlayInSettings->NewWindowWidth;
				FIntPoint NewWindowPosition = PlayInSettings->NewWindowPosition;
				bool CenterNewWindow = PlayInSettings->CenterNewWindow && (PlayNumberOfClients == 1);

				// Setup size for PIE window
				if ((NewWindowWidth <= 0) || (NewWindowHeight <= 0))
				{
					// Get desktop metrics
					FDisplayMetrics DisplayMetrics;
					FSlateApplication::Get().GetDisplayMetrics(DisplayMetrics);

					const FVector2D DisplaySize(
						DisplayMetrics.PrimaryDisplayWorkAreaRect.Right - DisplayMetrics.PrimaryDisplayWorkAreaRect.Left,
						DisplayMetrics.PrimaryDisplayWorkAreaRect.Bottom - DisplayMetrics.PrimaryDisplayWorkAreaRect.Top
					);

					// Use a centered window at the default window size
					NewWindowPosition.X = 0;
					NewWindowPosition.Y = 0;
					NewWindowWidth = 0.75 * DisplaySize.X;
					NewWindowHeight = 0.75 * DisplaySize.Y;
					CenterNewWindow = true;
				}

				bool bUseOSWndBorder = false;
				bool bRenderDirectlyToWindow = false;
				bool bEnableStereoRendering = false;
				if (bUseVRPreview)	// @todo vreditor: Is not having an OS window border a problem?  We could spawn a dedicated VR window if so.  What about true fullscreen in VR?
				{
					// modify window and viewport properties for VR.
					bUseOSWndBorder = true;
					bRenderDirectlyToWindow = true;
					bEnableStereoRendering = true;
					CenterNewWindow = true;
				}

				TSharedPtr<SWindow> PieWindow = PlayInSettings->CustomPIEWindow.Pin();

				const bool bHasCustomWindow = PieWindow.IsValid();
				if (!bHasCustomWindow)
				{
					PieWindow = SNew(SWindow)
						.Title(ViewportName)
						.ScreenPosition(FVector2D(NewWindowPosition.X, NewWindowPosition.Y))
						.ClientSize(FVector2D(NewWindowWidth, NewWindowHeight))
						.AutoCenter(CenterNewWindow ? EAutoCenter::PreferredWorkArea : EAutoCenter::None)
						.UseOSWindowBorder(bUseOSWndBorder)
						.SaneWindowPlacement(!CenterNewWindow)
						.SizingRule(ESizingRule::UserSized);
				}


				// Setup a delegate for switching to the play world on slate input events, drawing and ticking
//				FOnSwitchWorldHack OnWorldSwitch = FOnSwitchWorldHack::CreateUObject(this, &UEditorEngine::OnSwitchWorldForSlatePieWindow);
				FOnSwitchWorldHack OnWorldSwitch = FOnSwitchWorldHack::CreateUObject(this, &UGameEditorEngineJqm::OnSwitchWorldForSlatePieWindow);
				PieWindow->SetOnWorldSwitchHack(OnWorldSwitch);

				if (!bHasCustomWindow)
				{
					// Mac does not support parenting, do not keep on top
#if PLATFORM_MAC
					FSlateApplication::Get().AddWindow(PieWindow.ToSharedRef());
#else
					TSharedRef<SWindow, ESPMode::Fast> MainWindow = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame")).GetParentWindow().ToSharedRef();
					if (PlayInSettings->PIEAlwaysOnTop)
					{
						FSlateApplication::Get().AddWindowAsNativeChild(PieWindow.ToSharedRef(), MainWindow, true);
					}
					else
					{
						FSlateApplication::Get().AddWindow(PieWindow.ToSharedRef());
					}
#endif
				}

				TSharedRef<SOverlay> ViewportOverlayWidgetRef = SNew(SOverlay);

				TSharedRef<SGameLayerManager> GameLayerManagerRef = SNew(SGameLayerManager)
					.SceneViewport_UObject(this, &UGameEditorEngineJqm::GetGameSceneViewport, ViewportClient)
					[
						ViewportOverlayWidgetRef
					];

				PieViewportWidget =
					SNew(SViewport)
					.IsEnabled(FSlateApplication::Get().GetNormalExecutionAttribute())
					.EnableGammaCorrection(false)// Gamma correction in the game is handled in post processing in the scene renderer
					.RenderDirectlyToWindow(bRenderDirectlyToWindow)
					.EnableStereoRendering(bEnableStereoRendering)
					[
						GameLayerManagerRef
					];

				// Create a wrapper widget for PIE viewport to process play world actions
				TSharedRef<SGlobalPlayWorldActions> GlobalPlayWorldActionsWidgetRef = SNew(SGlobalPlayWorldActions)
					[
						PieViewportWidget.ToSharedRef()
					];

				PieWindow->SetContent(GlobalPlayWorldActionsWidgetRef);

				if (!bHasCustomWindow)
				{
					// Ensure the PIE window appears does not appear behind other windows.
					PieWindow->BringToFront();
				}

				ViewportClient->SetViewportOverlayWidget(PieWindow, ViewportOverlayWidgetRef);
				ViewportClient->SetGameLayerManager(GameLayerManagerRef);
				bool bShouldMinimizeRootWindow = bUseVRPreview && GEngine->XRSystem.IsValid() && GetDefault<ULevelEditorPlaySettings>()->ShouldMinimizeEditorOnVRPIE;
				// Set up a notification when the window is closed so we can clean up PIE
				{
					struct FLocal
					{
						static void OnPIEWindowClosed(const TSharedRef< SWindow >& WindowBeingClosed, TWeakPtr< SViewport > PIEViewportWidget, int32 index, bool bRestoreRootWindow)
						{
							// Save off the window position
							const FVector2D PIEWindowPos = WindowBeingClosed->GetPositionInScreen();

							ULevelEditorPlaySettings* LevelEditorPlaySettings = ULevelEditorPlaySettings::StaticClass()->GetDefaultObject<ULevelEditorPlaySettings>();

							if (index <= 0)
							{
								LevelEditorPlaySettings->NewWindowPosition.X = FPlatformMath::RoundToInt(PIEWindowPos.X);
								LevelEditorPlaySettings->NewWindowPosition.Y = FPlatformMath::RoundToInt(PIEWindowPos.Y);
							}
							else
							{
								if (index >= LevelEditorPlaySettings->MultipleInstancePositions.Num())
								{
									LevelEditorPlaySettings->MultipleInstancePositions.SetNum(index + 1);
								}

								LevelEditorPlaySettings->MultipleInstancePositions[index] = FIntPoint(PIEWindowPos.X, PIEWindowPos.Y);
							}

							LevelEditorPlaySettings->PostEditChange();
							LevelEditorPlaySettings->SaveConfig();

							// Route the callback
							PIEViewportWidget.Pin()->OnWindowClosed(WindowBeingClosed);

							if (bRestoreRootWindow)
							{
								// restore previously minimized root window.
								TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
								if (RootWindow.IsValid())
								{
									RootWindow->Restore();
								}
							}
						}
					};

					const bool CanPlayNetDedicated = [&PlayInSettings] { bool PlayNetDedicated(false); return (PlayInSettings->GetPlayNetDedicated(PlayNetDedicated) && PlayNetDedicated); }();
					PieWindow->SetOnWindowClosed(FOnWindowClosed::CreateStatic(&FLocal::OnPIEWindowClosed, TWeakPtr<SViewport>(PieViewportWidget),
						(PlayNumberOfClients == 1) ? 0 : PieWorldContext->PIEInstance - (CanPlayNetDedicated ? 1 : 0), bShouldMinimizeRootWindow));
				}

				// Create a new viewport that the viewport widget will use to render the game
				SlatePlayInEditorSession.SlatePlayInEditorWindowViewport = MakeShareable(new FSceneViewport(ViewportClient, PieViewportWidget));

				const bool bShouldGameGetMouseControl = GetDefault<ULevelEditorPlaySettings>()->GameGetsMouseControl || (bUseVRPreview && GEngine->XRSystem.IsValid());
				SlatePlayInEditorSession.SlatePlayInEditorWindowViewport->SetPlayInEditorGetsMouseControl(bShouldGameGetMouseControl);
				PieViewportWidget->SetViewportInterface(SlatePlayInEditorSession.SlatePlayInEditorWindowViewport.ToSharedRef());

				FSlateApplication::Get().RegisterViewport(PieViewportWidget.ToSharedRef());

				SlatePlayInEditorSession.SlatePlayInEditorWindow = PieWindow;

				// Let the viewport client know what viewport is using it.  We need to set the Viewport Frame as 
				// well (which in turn sets the viewport) so that SetRes command will work.
				ViewportClient->SetViewportFrame(SlatePlayInEditorSession.SlatePlayInEditorWindowViewport.Get());
				// Mark the viewport as PIE viewport
				ViewportClient->Viewport->SetPlayInEditorViewport(ViewportClient->bIsPlayInEditorViewport);

				// Ensure the window has a valid size before calling BeginPlay
				SlatePlayInEditorSession.SlatePlayInEditorWindowViewport->ResizeFrame(NewWindowWidth, NewWindowHeight, EWindowMode::Windowed);

				// Change the system resolution to match our window, to make sure game and slate window are kept syncronised
				FSystemResolution::RequestResolutionChange(NewWindowWidth, NewWindowHeight, EWindowMode::Windowed);

				if (bUseVRPreview)
				{
					GEngine->StereoRenderingDevice->EnableStereo(true);

					// minimize the root window to provide max performance for the preview.
					TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
					if (RootWindow.IsValid() && bShouldMinimizeRootWindow)
					{
						RootWindow->Minimize();
					}
				}
			}

			UGameViewportClient::OnViewportCreated().Broadcast();
		}
	}

	if (GameViewport != NULL && GameViewport->Viewport != NULL)
	{
		// Set the game viewport that was just created as a pie viewport.
		GameViewport->Viewport->SetPlayInEditorViewport(true);
	}

	// Disable the screensaver when PIE is running.
	EnableScreenSaver(false);


	EditorWorld->TransferBlueprintDebugReferences(PlayWorld);

	// By this point it is safe to remove the GameInstance from the root and allow it to garbage collected as per usual
	GameInstance->RemoveFromRoot();

	// Start the game instance, make sure to set the PIE instance global as this is basically a tick
	GPlayInEditorID = InPIEInstance;
	const FGameInstancePIEResult StartResult = GameInstance->StartPlayInEditorGameInstance(NewLocalPlayer, GameInstanceParams);
	GPlayInEditorID = -1;

	if (!StartResult.IsSuccess())
	{
		FMessageDialog::Open(EAppMsgType::Ok, StartResult.FailureReason);
		RestoreEditorWorld(EditorWorld);
		EndPlayMap();
		return nullptr;
	}

	// Set up a delegate to be called in Slate when GWorld needs to change.  Slate does not have direct access to the playworld to switch itself
	FScopedConditionalWorldSwitcher::SwitchWorldForPIEDelegate = FOnSwitchWorldForPIE::CreateUObject(this, &UGameEditorEngineJqm::OnSwitchWorldsForPIE);

	if (PieViewportWidget.IsValid())
	{
		// Register the new viewport widget with Slate for viewport specific message routing.
		FSlateApplication::Get().RegisterGameViewport(PieViewportWidget.ToSharedRef());
	}

	// go back to using the real world as GWorld
	RestoreEditorWorld(EditorWorld);

	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("MapName"), FText::FromString(GameInstance->PIEMapName));
		Arguments.Add(TEXT("StartTime"), FPlatformTime::Seconds() - PIEStartTime);
		FMessageLog(NAME_CategoryPIE).Info(FText::Format(LOCTEXT("PIEStartTime", "Play in editor start time for {MapName} {StartTime}"), Arguments));
	}

	// Update the details window with the actors we have just selected
	GUnrealEd->UpdateFloatingPropertyWindows();

	// Clean up any editor actors being referenced 
	GEngine->BroadcastLevelActorListChanged();

	// Set an undo barrier so that transactions prior to PIE can't be undone
	GUnrealEd->Trans->SetUndoBarrier();

	return GameInstance;
}

int32 UGameEditorEngineJqm::OnSwitchWorldForSlatePieWindow(int32 WorldID)
{
	static const int32 EditorWorldID = 0;
	static const int32 PieWorldID = 1;

	int32 RestoreID = -1;
	if (WorldID == -1 && GWorld != PlayWorld && PlayWorld != NULL)
	{
		// When we have an invalid world id we always switch to the pie world in the PIE window
		const bool bSwitchToPIE = true;
		OnSwitchWorldsForPIE(bSwitchToPIE);
		// The editor world was active restore it later
		RestoreID = EditorWorldID;
	}
	else if (WorldID == PieWorldID && GWorld != PlayWorld)
	{
		const bool bSwitchToPIE = true;
		// Want to restore the PIE world and the current world is not already the pie world
		OnSwitchWorldsForPIE(bSwitchToPIE);
	}
	else if (WorldID == EditorWorldID && GWorld != EditorWorld)
	{
		const bool bSwitchToPIE = false;
		// Want to restore the editor world and the current world is not already the editor world
		OnSwitchWorldsForPIE(bSwitchToPIE);
	}
	else
	{
		// Current world is already the same as the world being switched to (nested calls to this for example)
	}

	return RestoreID;
}

void UGameEditorEngineJqm::OnSwitchWorldsForPIE(bool bSwitchToPieWorld)
{
	if (bSwitchToPieWorld)
	{
		SetPlayInEditorWorld(PlayWorld);
	}
	else
	{
		RestoreEditorWorld(EditorWorld);
	}
}

const FSceneViewport* UGameEditorEngineJqm::GetGameSceneViewport(UGameViewportClient* ViewportClient) const
{
	return ViewportClient->GetGameViewport();
}

#undef LOCTEXT_NAMESPACE