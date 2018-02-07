// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Engine/GameEngine.h"
#include "GameEngineJqm.generated.h"

/**
 * 
 */
UCLASS()
class TESTCOPY_API UGameEngineJqm : public UGameEngine
{
	GENERATED_BODY()
public:
	virtual void Init(class IEngineLoop* InEngineLoop) override;
	virtual void Start() override;
	
	
};
