// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "TanksAndZombiesGameModeBase.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTanksAndZombiesGameModeBase() {}
// Cross Module References
	TANKSANDZOMBIES_API UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase_NoRegister();
	TANKSANDZOMBIES_API UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TanksAndZombies();
// End Cross Module References
	void ATanksAndZombiesGameModeBase::StaticRegisterNativesATanksAndZombiesGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase_NoRegister()
	{
		return ATanksAndZombiesGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_ATanksAndZombiesGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_TanksAndZombies();
			OuterClass = ATanksAndZombiesGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900288u;


				static TCppClassTypeInfo<TCppClassTypeTraits<ATanksAndZombiesGameModeBase> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("TanksAndZombiesGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("TanksAndZombiesGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATanksAndZombiesGameModeBase, 2040496521);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATanksAndZombiesGameModeBase(Z_Construct_UClass_ATanksAndZombiesGameModeBase, &ATanksAndZombiesGameModeBase::StaticClass, TEXT("/Script/TanksAndZombies"), TEXT("ATanksAndZombiesGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATanksAndZombiesGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
