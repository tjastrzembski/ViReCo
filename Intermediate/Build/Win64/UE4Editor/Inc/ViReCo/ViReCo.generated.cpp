// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "ViReCo.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1ViReCo() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API class UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USoundBase_NoRegister();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FVector();
	HEADMOUNTEDDISPLAY_API class UClass* Z_Construct_UClass_UMotionControllerComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AGameModeBase();
	ENGINE_API class UClass* Z_Construct_UClass_AHUD();
	ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API class UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	ENGINE_API class UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API class UClass* Z_Construct_UClass_USphereComponent_NoRegister();

	VIRECO_API class UClass* Z_Construct_UClass_AViReCoCharacter_NoRegister();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoCharacter();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoGameMode_NoRegister();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoGameMode();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoHUD_NoRegister();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoHUD();
	VIRECO_API class UFunction* Z_Construct_UFunction_AViReCoProjectile_OnHit();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoProjectile_NoRegister();
	VIRECO_API class UClass* Z_Construct_UClass_AViReCoProjectile();
	VIRECO_API class UPackage* Z_Construct_UPackage__Script_ViReCo();
	void AViReCoCharacter::StaticRegisterNativesAViReCoCharacter()
	{
	}
	UClass* Z_Construct_UClass_AViReCoCharacter_NoRegister()
	{
		return AViReCoCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_AViReCoCharacter()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_ViReCo();
			OuterClass = AViReCoCharacter::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20800080;


PRAGMA_DISABLE_DEPRECATION_WARNINGS
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(bUsingMotionControllers, AViReCoCharacter, uint8);
				UProperty* NewProp_bUsingMotionControllers = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("bUsingMotionControllers"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(bUsingMotionControllers, AViReCoCharacter), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(bUsingMotionControllers, AViReCoCharacter), sizeof(uint8), false);
				UProperty* NewProp_FireAnimation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FireAnimation"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FireAnimation, AViReCoCharacter), 0x0010000000000005, Z_Construct_UClass_UAnimMontage_NoRegister());
				UProperty* NewProp_FireSound = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FireSound"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FireSound, AViReCoCharacter), 0x0010000000000005, Z_Construct_UClass_USoundBase_NoRegister());
				UProperty* NewProp_ProjectileClass = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ProjectileClass"), RF_Public|RF_Transient|RF_MarkAsNative) UClassProperty(CPP_PROPERTY_BASE(ProjectileClass, AViReCoCharacter), 0x0014000000010001, Z_Construct_UClass_AViReCoProjectile_NoRegister(), UClass::StaticClass());
				UProperty* NewProp_GunOffset = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("GunOffset"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(GunOffset, AViReCoCharacter), 0x0010000000000005, Z_Construct_UScriptStruct_FVector());
				UProperty* NewProp_BaseLookUpRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseLookUpRate"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BaseLookUpRate, AViReCoCharacter), 0x0010000000020015);
				UProperty* NewProp_BaseTurnRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseTurnRate"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BaseTurnRate, AViReCoCharacter), 0x0010000000020015);
				UProperty* NewProp_L_MotionController = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("L_MotionController"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(L_MotionController, AViReCoCharacter), 0x00400000000a001d, Z_Construct_UClass_UMotionControllerComponent_NoRegister());
				UProperty* NewProp_R_MotionController = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("R_MotionController"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(R_MotionController, AViReCoCharacter), 0x00400000000a001d, Z_Construct_UClass_UMotionControllerComponent_NoRegister());
				UProperty* NewProp_FirstPersonCameraComponent = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FirstPersonCameraComponent"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FirstPersonCameraComponent, AViReCoCharacter), 0x00400000000a001d, Z_Construct_UClass_UCameraComponent_NoRegister());
				UProperty* NewProp_VR_MuzzleLocation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VR_MuzzleLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(VR_MuzzleLocation, AViReCoCharacter), 0x00400000000b0009, Z_Construct_UClass_USceneComponent_NoRegister());
				UProperty* NewProp_VR_Gun = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("VR_Gun"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(VR_Gun, AViReCoCharacter), 0x00400000000b0009, Z_Construct_UClass_USkeletalMeshComponent_NoRegister());
				UProperty* NewProp_FP_MuzzleLocation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FP_MuzzleLocation"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FP_MuzzleLocation, AViReCoCharacter), 0x00400000000b0009, Z_Construct_UClass_USceneComponent_NoRegister());
				UProperty* NewProp_FP_Gun = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("FP_Gun"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(FP_Gun, AViReCoCharacter), 0x00400000000b0009, Z_Construct_UClass_USkeletalMeshComponent_NoRegister());
				UProperty* NewProp_Mesh1P = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Mesh1P"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Mesh1P, AViReCoCharacter), 0x00400000000b0009, Z_Construct_UClass_USkeletalMeshComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AViReCoCharacter> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_bUsingMotionControllers, TEXT("Category"), TEXT("Gameplay"));
				MetaData->SetValue(NewProp_bUsingMotionControllers, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_bUsingMotionControllers, TEXT("ToolTip"), TEXT("Whether to use motion controller location for aiming."));
				MetaData->SetValue(NewProp_FireAnimation, TEXT("Category"), TEXT("Gameplay"));
				MetaData->SetValue(NewProp_FireAnimation, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_FireAnimation, TEXT("ToolTip"), TEXT("AnimMontage to play each time we fire"));
				MetaData->SetValue(NewProp_FireSound, TEXT("Category"), TEXT("Gameplay"));
				MetaData->SetValue(NewProp_FireSound, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_FireSound, TEXT("ToolTip"), TEXT("Sound to play each time we fire"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("Category"), TEXT("Projectile"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_ProjectileClass, TEXT("ToolTip"), TEXT("Projectile class to spawn"));
				MetaData->SetValue(NewProp_GunOffset, TEXT("Category"), TEXT("Gameplay"));
				MetaData->SetValue(NewProp_GunOffset, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_GunOffset, TEXT("ToolTip"), TEXT("Gun muzzle's offset from the characters location"));
				MetaData->SetValue(NewProp_BaseLookUpRate, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_BaseLookUpRate, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_BaseLookUpRate, TEXT("ToolTip"), TEXT("Base look up/down rate, in deg/sec. Other scaling may affect final rate."));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("ToolTip"), TEXT("Base turn rate, in deg/sec. Other scaling may affect final turn rate."));
				MetaData->SetValue(NewProp_L_MotionController, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_L_MotionController, TEXT("Category"), TEXT("ViReCoCharacter"));
				MetaData->SetValue(NewProp_L_MotionController, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_L_MotionController, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_L_MotionController, TEXT("ToolTip"), TEXT("Motion controller (left hand)"));
				MetaData->SetValue(NewProp_R_MotionController, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_R_MotionController, TEXT("Category"), TEXT("ViReCoCharacter"));
				MetaData->SetValue(NewProp_R_MotionController, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_R_MotionController, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_R_MotionController, TEXT("ToolTip"), TEXT("Motion controller (right hand)"));
				MetaData->SetValue(NewProp_FirstPersonCameraComponent, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_FirstPersonCameraComponent, TEXT("Category"), TEXT("Camera"));
				MetaData->SetValue(NewProp_FirstPersonCameraComponent, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FirstPersonCameraComponent, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_FirstPersonCameraComponent, TEXT("ToolTip"), TEXT("First person camera"));
				MetaData->SetValue(NewProp_VR_MuzzleLocation, TEXT("Category"), TEXT("Mesh"));
				MetaData->SetValue(NewProp_VR_MuzzleLocation, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_VR_MuzzleLocation, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_VR_MuzzleLocation, TEXT("ToolTip"), TEXT("Location on VR gun mesh where projectiles should spawn."));
				MetaData->SetValue(NewProp_VR_Gun, TEXT("Category"), TEXT("Mesh"));
				MetaData->SetValue(NewProp_VR_Gun, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_VR_Gun, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_VR_Gun, TEXT("ToolTip"), TEXT("Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun)"));
				MetaData->SetValue(NewProp_FP_MuzzleLocation, TEXT("Category"), TEXT("Mesh"));
				MetaData->SetValue(NewProp_FP_MuzzleLocation, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FP_MuzzleLocation, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_FP_MuzzleLocation, TEXT("ToolTip"), TEXT("Location on gun mesh where projectiles should spawn."));
				MetaData->SetValue(NewProp_FP_Gun, TEXT("Category"), TEXT("Mesh"));
				MetaData->SetValue(NewProp_FP_Gun, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_FP_Gun, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_FP_Gun, TEXT("ToolTip"), TEXT("Gun mesh: 1st person view (seen only by self)"));
				MetaData->SetValue(NewProp_Mesh1P, TEXT("Category"), TEXT("Mesh"));
				MetaData->SetValue(NewProp_Mesh1P, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_Mesh1P, TEXT("ModuleRelativePath"), TEXT("ViReCoCharacter.h"));
				MetaData->SetValue(NewProp_Mesh1P, TEXT("ToolTip"), TEXT("Pawn mesh: 1st person view (arms; seen only by self)"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AViReCoCharacter, 2858347228);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AViReCoCharacter(Z_Construct_UClass_AViReCoCharacter, &AViReCoCharacter::StaticClass, TEXT("/Script/ViReCo"), TEXT("AViReCoCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AViReCoCharacter);
	void AViReCoGameMode::StaticRegisterNativesAViReCoGameMode()
	{
	}
	UClass* Z_Construct_UClass_AViReCoGameMode_NoRegister()
	{
		return AViReCoGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_AViReCoGameMode()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_ViReCo();
			OuterClass = AViReCoGameMode::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20880288;


				static TCppClassTypeInfo<TCppClassTypeTraits<AViReCoGameMode> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ViReCoGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ViReCoGameMode.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AViReCoGameMode, 3037890992);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AViReCoGameMode(Z_Construct_UClass_AViReCoGameMode, &AViReCoGameMode::StaticClass, TEXT("/Script/ViReCo"), TEXT("AViReCoGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AViReCoGameMode);
	void AViReCoHUD::StaticRegisterNativesAViReCoHUD()
	{
	}
	UClass* Z_Construct_UClass_AViReCoHUD_NoRegister()
	{
		return AViReCoHUD::StaticClass();
	}
	UClass* Z_Construct_UClass_AViReCoHUD()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AHUD();
			Z_Construct_UPackage__Script_ViReCo();
			OuterClass = AViReCoHUD::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x2080028C;


				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AViReCoHUD> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Rendering Actor Input Replication"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ViReCoHUD.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ViReCoHUD.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AViReCoHUD, 1311473471);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AViReCoHUD(Z_Construct_UClass_AViReCoHUD, &AViReCoHUD::StaticClass, TEXT("/Script/ViReCo"), TEXT("AViReCoHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AViReCoHUD);
	void AViReCoProjectile::StaticRegisterNativesAViReCoProjectile()
	{
		UClass* Class = AViReCoProjectile::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "OnHit", (Native)&AViReCoProjectile::execOnHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 1);
	}
	UFunction* Z_Construct_UFunction_AViReCoProjectile_OnHit()
	{
		struct ViReCoProjectile_eventOnHit_Parms
		{
			UPrimitiveComponent* HitComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalImpulse;
			FHitResult Hit;
		};
		UObject* Outer=Z_Construct_UClass_AViReCoProjectile();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("OnHit"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x00C20401, 65535, sizeof(ViReCoProjectile_eventOnHit_Parms));
			UProperty* NewProp_Hit = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Hit"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(Hit, ViReCoProjectile_eventOnHit_Parms), 0x0010008008000182, Z_Construct_UScriptStruct_FHitResult());
			UProperty* NewProp_NormalImpulse = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("NormalImpulse"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(NormalImpulse, ViReCoProjectile_eventOnHit_Parms), 0x0010000000000080, Z_Construct_UScriptStruct_FVector());
			UProperty* NewProp_OtherComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(OtherComp, ViReCoProjectile_eventOnHit_Parms), 0x0010000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			UProperty* NewProp_OtherActor = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OtherActor"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(OtherActor, ViReCoProjectile_eventOnHit_Parms), 0x0010000000000080, Z_Construct_UClass_AActor_NoRegister());
			UProperty* NewProp_HitComp = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("HitComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(HitComp, ViReCoProjectile_eventOnHit_Parms), 0x0010000000080080, Z_Construct_UClass_UPrimitiveComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("ViReCoProjectile.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("called when projectile hits something"));
			MetaData->SetValue(NewProp_Hit, TEXT("NativeConst"), TEXT(""));
			MetaData->SetValue(NewProp_OtherComp, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_HitComp, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AViReCoProjectile_NoRegister()
	{
		return AViReCoProjectile::StaticClass();
	}
	UClass* Z_Construct_UClass_AViReCoProjectile()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_ViReCo();
			OuterClass = AViReCoProjectile::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20800080;

				OuterClass->LinkChild(Z_Construct_UFunction_AViReCoProjectile_OnHit());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_ProjectileMovement = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ProjectileMovement"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(ProjectileMovement, AViReCoProjectile), 0x00400000000a001d, Z_Construct_UClass_UProjectileMovementComponent_NoRegister());
				UProperty* NewProp_CollisionComp = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("CollisionComp"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(CollisionComp, AViReCoProjectile), 0x00400000000b0009, Z_Construct_UClass_USphereComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_AViReCoProjectile_OnHit(), "OnHit"); // 4242712099
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<AViReCoProjectile> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("ViReCoProjectile.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("ViReCoProjectile.h"));
				MetaData->SetValue(NewProp_ProjectileMovement, TEXT("AllowPrivateAccess"), TEXT("true"));
				MetaData->SetValue(NewProp_ProjectileMovement, TEXT("Category"), TEXT("Movement"));
				MetaData->SetValue(NewProp_ProjectileMovement, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_ProjectileMovement, TEXT("ModuleRelativePath"), TEXT("ViReCoProjectile.h"));
				MetaData->SetValue(NewProp_ProjectileMovement, TEXT("ToolTip"), TEXT("Projectile movement component"));
				MetaData->SetValue(NewProp_CollisionComp, TEXT("Category"), TEXT("Projectile"));
				MetaData->SetValue(NewProp_CollisionComp, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_CollisionComp, TEXT("ModuleRelativePath"), TEXT("ViReCoProjectile.h"));
				MetaData->SetValue(NewProp_CollisionComp, TEXT("ToolTip"), TEXT("Sphere collision component"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AViReCoProjectile, 2555482074);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AViReCoProjectile(Z_Construct_UClass_AViReCoProjectile, &AViReCoProjectile::StaticClass, TEXT("/Script/ViReCo"), TEXT("AViReCoProjectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AViReCoProjectile);
	UPackage* Z_Construct_UPackage__Script_ViReCo()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/ViReCo")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xD89625C2;
			Guid.B = 0x94A48BE8;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
