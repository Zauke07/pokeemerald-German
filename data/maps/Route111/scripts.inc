.set LOCALID_VICTOR, 1
.set LOCALID_VICTORIA, 2
.set LOCALID_VIVI, 3
.set LOCALID_VICKY, 4
.set LOCALID_ROCK_SMASH_MAN, 46

@ Note: LOCALID_ROUTE111_PLAYER_FALLING is a local id for this map used elsewhere. It's defined in event_objects.h

Route111_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route111_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route111_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route111_OnFrame
	.byte 0

Route111_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route111_EventScript_CloseDesertRuins
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_ShowTemporaryMirageTower
	end

Route111_EventScript_CloseDesertRuins::
	setmetatile 29, 86, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 29, 87, METATILE_General_RockWall_SandBase, TRUE
	return

@ Show Mirage Tower just prior to disintegration. Mirage Tower is otherwise handled by the map layout
Route111_EventScript_ShowTemporaryMirageTower::
	setmetatile 18, 53, METATILE_Mauville_MirageTower_Tile0, FALSE
	setmetatile 19, 53, METATILE_Mauville_MirageTower_Tile1, FALSE
	setmetatile 20, 53, METATILE_Mauville_MirageTower_Tile2, FALSE
	setmetatile 18, 54, METATILE_Mauville_MirageTower_Tile3, FALSE
	setmetatile 19, 54, METATILE_Mauville_MirageTower_Tile4, FALSE
	setmetatile 20, 54, METATILE_Mauville_MirageTower_Tile5, FALSE
	setmetatile 18, 55, METATILE_Mauville_MirageTower_Tile6, FALSE
	setmetatile 19, 55, METATILE_Mauville_MirageTower_Tile7, FALSE
	setmetatile 20, 55, METATILE_Mauville_MirageTower_Tile8, FALSE
	setmetatile 18, 56, METATILE_Mauville_MirageTower_Tile9, FALSE
	setmetatile 19, 56, METATILE_Mauville_MirageTower_TileA, FALSE
	setmetatile 20, 56, METATILE_Mauville_MirageTower_TileB, FALSE
	setmetatile 18, 57, METATILE_Mauville_MirageTower_TileC, FALSE
	setmetatile 19, 57, METATILE_Mauville_MirageTower_TileD, FALSE
	setmetatile 20, 57, METATILE_Mauville_MirageTower_TileE, FALSE
	setmetatile 18, 58, METATILE_Mauville_MirageTower_TileF, FALSE
	setmetatile 19, 58, METATILE_Mauville_MirageTower_Tile10, FALSE
	setmetatile 20, 58, METATILE_Mauville_MirageTower_Tile11, FALSE
	return

Route111_OnTransition:
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	call_if_eq VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_SetFallingPlayerGfx
	call_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_SetMirageTowerGone
	call Route111_EventScript_CheckSetSandstorm
	call GabbyAndTy_EventScript_UpdateLocation
	goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated
	end

Route111_EventScript_SetFallingPlayerGfx::
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_MAY, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_RED, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_LEAF, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_ETHAN, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_LYRA, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_LUCAS, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_DAWN, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_HILBERT, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_HILDA, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_NATE, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_ROSA, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_CALEM, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_SERENA, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_ELIO, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_SELENE, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_VICTOR, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_GLORIA, Route111_EventScript_SetFallingPlayerGfxFemale
	goto_if_eq VAR_RESULT, STYLE_FLORIAN, Route111_EventScript_SetFallingPlayerGfxMale
	goto_if_eq VAR_RESULT, STYLE_JULIANA, Route111_EventScript_SetFallingPlayerGfxFemale
	return

Route111_EventScript_SetFallingPlayerGfxMale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

Route111_EventScript_SetFallingPlayerGfxFemale::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

Route111_EventScript_CheckSetSandstorm::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 34, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 107, Route111_EventScript_EndCheckSetSandstorm
	goto_if_gt VAR_TEMP_1, 72, Route111_EventScript_SetSandstorm
	goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm
	goto_if_lt VAR_TEMP_0, 8, Route111_EventScript_EndCheckSetSandstorm
Route111_EventScript_SetSandstorm::
	setweather WEATHER_SANDSTORM
Route111_EventScript_EndCheckSetSandstorm::
	return

Route111_EventScript_SetWinstratesNotDefeated::
	clearflag FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	cleartrainerflag TRAINER_VICTOR
	cleartrainerflag TRAINER_VICTORIA
	cleartrainerflag TRAINER_VIVI
	end

Route111_EventScript_SetLayoutNoMirageTower::
	setmaplayoutindex LAYOUT_ROUTE111_NO_MIRAGE_TOWER
	return

Route111_EventScript_SetMirageTowerGone::
	setvar VAR_MIRAGE_TOWER_STATE, 3
	return

Route111_OnWarp:
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_HidePlayerForMirageTower
	.2byte 0

Route111_EventScript_HidePlayerForMirageTower::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	end

Route111_OnFrame:
	map_script_2 VAR_MIRAGE_TOWER_STATE, 1, Route111_EventScript_MirageTowerDisappear
	.2byte 0

Route111_EventScript_MirageTowerDisappear::
	lockall
	special StartMirageTowerShake
	waitstate
	delay 24
	playse SE_FALL
	addobject LOCALID_ROUTE111_PLAYER_FALLING
	special StartPlayerDescendMirageTower
	waitstate
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	removeobject LOCALID_ROUTE111_PLAYER_FALLING
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 16
	special StartMirageTowerDisintegration
	waitstate
	special StartMirageTowerFossilFallAndSink
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 2
	clearflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, Route111_EventScript_RootFossilDisappeared
	msgbox Route111_Text_ClawFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

Route111_EventScript_RootFossilDisappeared::
	msgbox Route111_Text_RootFossilDisappeared, MSGBOX_DEFAULT
	releaseall
	end

@ Unused
Route111_Movement_PlayerFall::
	lock_anim
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route111_EventScript_Girl::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_111_RECEIVED_BERRY, Route111_EventScript_ReceivedBerry
	msgbox Route111_Text_WateredPlantsEveryDayTakeBerry, MSGBOX_DEFAULT
	giveitem ITEM_RAZZ_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_111_RECEIVED_BERRY
	special GetPlayerBigGuyGirlString
	msgbox Route111_Text_GoingToTryToMakeDifferentColorBerries, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_ReceivedBerry::
	msgbox Route111_Text_WhatColorBerriesToLookForToday, MSGBOX_DEFAULT
	release
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerUp::
	lockall
	setvar VAR_0x8004, 0
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerDown::
	lockall
	setvar VAR_0x8004, 1
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTriggerLeft::
	lockall
	setvar VAR_0x8004, 2
	goto Route111_EventScript_ViciousSandstormTrigger
	end

@ Unused
Route111_EventScript_ViciousSandstormTriggerRight::
	lockall
	setvar VAR_0x8004, 3
	goto Route111_EventScript_ViciousSandstormTrigger
	end

Route111_EventScript_ViciousSandstormTrigger::
	checkitem ITEM_GO_GOGGLES
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_PreventRouteAccess
	setvar VAR_TEMP_3, 1
	releaseall
	end

Route111_EventScript_PreventRouteAccess::
	msgbox gText_SandstormIsVicious, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8004, 0, Route111_EventScript_PushUpFromRoute
	call_if_eq VAR_0x8004, 1, Route111_EventScript_PushDownFromRoute
	call_if_eq VAR_0x8004, 2, Route111_EventScript_PushLeftFromRoute
	call_if_eq VAR_0x8004, 3, Route111_EventScript_PushRightFromRoute
	releaseall
	end

Route111_EventScript_PushUpFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushUpFromRoute
	waitmovement 0
	return

Route111_EventScript_PushDownFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushDownFromRoute
	waitmovement 0
	return

Route111_EventScript_PushLeftFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushLeftFromRoute
	waitmovement 0
	return

Route111_EventScript_PushRightFromRoute::
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_PushRightFromRoute
	waitmovement 0
	return

Route111_Movement_PushUpFromRoute:
	walk_up
	step_end

Route111_Movement_PushDownFromRoute:
	walk_down
	step_end

Route111_Movement_PushLeftFromRoute:
	walk_left
	step_end

Route111_Movement_PushRightFromRoute:
	walk_right
	step_end

Route111_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	fadenewbgm MUS_ROUTE110
	doweather
	setvar VAR_TEMP_3, 0
	end

Route111_EventScript_SandstormTrigger::
	setweather WEATHER_SANDSTORM
	fadenewbgm MUS_DESERT
	doweather
	end

Route111_EventScript_Victor::
	lock
	faceplayer
	setflag FLAG_LANDMARK_WINSTRATE_FAMILY
	msgbox Route111_Text_BattleOurFamily, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_BattleWinstrates
	msgbox Route111_Text_IsThatSo, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_BattleWinstrates::
	msgbox Route111_Text_VictorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTOR, Route111_Text_VictorDefeat
	applymovement LOCALID_VICTOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictorPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTOR, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICTOR
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VICTORIA
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VictoriaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICTORIA, Route111_Text_VictoriaDefeat
	applymovement LOCALID_VICTORIA, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_VictoriaPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTORIA, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICTORIA
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VIVI
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_ViviIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VIVI, Route111_Text_ViviDefeat
	applymovement LOCALID_VIVI, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	msgbox Route111_Text_ViviPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIVI, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VIVI
	call Route111_EventScript_CloseWinstrateDoor
	applymovement OBJ_EVENT_ID_PLAYER, Route111_Movement_WaitForNextWinstrate
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	addobject LOCALID_VICKY
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateExitHouse
	waitmovement 0
	call Route111_EventScript_CloseWinstrateDoor
	msgbox Route111_Text_VickyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VICKY, Route111_Text_VickyDefeat
	msgbox Route111_Text_VickyPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICKY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	call Route111_EventScript_OpenWinstrateDoor
	applymovement LOCALID_VICKY, Route111_Movement_WinstrateEnterHouse
	waitmovement 0
	removeobject LOCALID_VICKY
	call Route111_EventScript_CloseWinstrateDoor
	release
	end

Route111_EventScript_OpenWinstrateDoor::
	opendoor 13, 113
	waitdooranim
	return

Route111_EventScript_CloseWinstrateDoor::
	closedoor 13, 113
	waitdooranim
	return

Route111_Movement_WinstrateEnterHouse:
	walk_in_place_faster_up
	walk_up
	step_end

Route111_Movement_WinstrateExitHouse:
	walk_down
	step_end

Route111_Movement_WaitForNextWinstrate:
	delay_16
	delay_16
	delay_16
	step_end

Route111_EventScript_RouteSignMauville::
	msgbox Route111_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route111_EventScript_WinstrateHouseSign::
	msgbox Route111_Text_WinstrateHouseSign, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign112::
	msgbox Route111_Text_RouteSign112, MSGBOX_SIGN
	end

Route111_EventScript_RouteSign113::
	msgbox Route111_Text_RouteSign113, MSGBOX_SIGN
	end

Route111_EventScript_OldLadysRestStopSign::
	msgbox Route111_Text_OldLadysRestStopSign, MSGBOX_SIGN
	end

Route111_EventScript_TrainerTipsSpAtkSpDef::
	msgbox Route111_Text_TrainerTipsSpAtkSpDef, MSGBOX_SIGN
	end

Route111_EventScript_Man1::
	msgbox Route111_Text_ToughToKeepWinningUpTheRanks, MSGBOX_NPC
	end

Route111_EventScript_Man2::
	msgbox Route111_Text_WinstrateFamilyDestroyedMe, MSGBOX_NPC
	end

Route111_EventScript_Hiker::
	lock
	faceplayer
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 3, Route111_EventScript_HikerMirageTowerGone
	goto_if_eq VAR_MIRAGE_TOWER_STATE, 2, Route111_EventScript_HikerMirageTowerDisintegrated
	goto_if_set FLAG_MIRAGE_TOWER_VISIBLE, Route111_EventScript_HikerMirageTowerVisible
	msgbox Route111_Text_ShouldBeMirageTowerAroundHere, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerGone::
	msgbox Route111_Text_MirageTowerHasntBeenSeenSince, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerDisintegrated::
	msgbox Route111_Text_ThatWasShockingSandRainedDown, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_HikerMirageTowerVisible::
	msgbox Route111_Text_MirageTowerClearlyVisible, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RockSmashTipFatMan::
	lockall
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route111_Text_MauvilleUncleToldMeToTakeRockSmash, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCK_SMASH_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

Route111_EventScript_Drew::
	trainerbattle_single TRAINER_DREW, Route111_Text_DrewIntro, Route111_Text_DrewDefeat
	msgbox Route111_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI, Route111_Text_HeidiIntro, Route111_Text_HeidiDefeat
	msgbox Route111_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Beau::
	trainerbattle_single TRAINER_BEAU, Route111_Text_BeauIntro, Route111_Text_BeauDefeat
	msgbox Route111_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Becky::
	trainerbattle_single TRAINER_BECKY, Route111_Text_BeckyIntro, Route111_Text_BeckyDefeat
	msgbox Route111_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Dusty::
	trainerbattle_single TRAINER_DUSTY_1, Route111_Text_DustyIntro, Route111_Text_DustyDefeat, Route111_EventScript_RegisterDusty
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchDusty
	msgbox Route111_Text_DustyPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterDusty::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_DustyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DUSTY_1
	release
	end

Route111_EventScript_RematchDusty::
	trainerbattle_rematch TRAINER_DUSTY_1, Route111_Text_DustyRematchIntro, Route111_Text_DustyRematchDefeat
	msgbox Route111_Text_DustyPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Travis::
	trainerbattle_single TRAINER_TRAVIS, Route111_Text_TravisIntro, Route111_Text_TravisDefeat
	msgbox Route111_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE, Route111_Text_IreneIntro, Route111_Text_IreneDefeat
	msgbox Route111_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Daisuke::
	trainerbattle_single TRAINER_DAISUKE, Route111_Text_DaisukeIntro, Route111_Text_DaisukeDefeat
	msgbox Route111_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON_1, Route111_Text_WiltonIntro, Route111_Text_WiltonDefeat, Route111_EventScript_RegisterWilton
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchWilton
	msgbox Route111_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterWilton::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WILTON_1
	release
	end

Route111_EventScript_RematchWilton::
	trainerbattle_rematch TRAINER_WILTON_1, Route111_Text_WiltonRematchIntro, Route111_Text_WiltonRematchDefeat
	msgbox Route111_Text_WiltonPostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Brooke::
	trainerbattle_single TRAINER_BROOKE_1, Route111_Text_BrookeIntro, Route111_Text_BrookeDefeat, Route111_EventScript_RegisterBrooke
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_RematchBrooke
	msgbox Route111_Text_BrookePostBattle, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_RegisterBrooke::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route111_Text_BrookeRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BROOKE_1
	release
	end

Route111_EventScript_RematchBrooke::
	trainerbattle_rematch TRAINER_BROOKE_1, Route111_Text_BrookeRematchIntro, Route111_Text_BrookeRematchDefeat
	msgbox Route111_Text_BrookePostRematch, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Hayden::
	trainerbattle_single TRAINER_HAYDEN, Route111_Text_HaydenIntro, Route111_Text_HaydenDefeat
	msgbox Route111_Text_HaydenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bianca::
	trainerbattle_single TRAINER_BIANCA, Route111_Text_BiancaIntro, Route111_Text_BiancaDefeat
	msgbox Route111_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Tyron::
	trainerbattle_single TRAINER_TYRON, Route111_Text_TyronIntro, Route111_Text_TyronDefeat
	msgbox Route111_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celina::
	trainerbattle_single TRAINER_CELINA, Route111_Text_CelinaIntro, Route111_Text_CelinaDefeat
	msgbox Route111_Text_CelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Celia::
	trainerbattle_single TRAINER_CELIA, Route111_Text_CeliaIntro, Route111_Text_CeliaDefeat
	msgbox Route111_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Bryan::
	trainerbattle_single TRAINER_BRYAN, Route111_Text_BryanIntro, Route111_Text_BryanDefeat
	msgbox Route111_Text_BryanPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_Branden::
	trainerbattle_single TRAINER_BRANDEN, Route111_Text_BrandenIntro, Route111_Text_BrandenDefeat
	msgbox Route111_Text_BrandenPostBattle, MSGBOX_AUTOCLOSE
	end

Route111_EventScript_TrainerHillSign::
	msgbox Route111_Text_TrainerHillSign, MSGBOX_SIGN
	end

Route111_Text_BattleOurFamily:
	.string "Hallo! Ich hab’s, du bist ein Reisender.\p"
	.string "Was hältst du davon? Du trittst mit\n"
	.string "deinen POKéMON gegen alle vier\l"
	.string "Familienmitglieder hintereinander an?$"

Route111_Text_IsThatSo:
	.string "Ach, wirklich? Nun, wenn du deine\n"
	.string "Meinung änderst, komm einfach wieder.$"

Route111_Text_VictorIntro:
	.string "Das nenne ich Kampfgeist! Ich mag dich!$"

Route111_Text_VictorDefeat:
	.string "Aiyah!\n"
	.string "Du bist stärker, als ich dachte.$"

Route111_Text_VictorPostBattle:
	.string "Hey, ihr! Ich habe einen starken\n"
	.string "TRAINER gefunden!$"

Route111_Text_VictoriaIntro:
	.string "Oh, du meine Güte! Bist du jung!\p"
	.string "Du musst ein sehr guter TRAINER sein,\n"
	.string "wenn du meinen Mann besiegen konntest.\p"
	.string "Nun bin ich an der Reihe.$"

Route111_Text_VictoriaDefeat:
	.string "Ach, nein! Ich komme nicht darüber\n"
	.string "hinweg, wie stark du bist!$"

Route111_Text_VictoriaPostBattle:
	.string "Hier draußen ist ein starker TRAINER!\n"
	.string "Ein wirklich starker, sage ich euch!$"

Route111_Text_ViviIntro:
	.string "Du bist stärker als Mami? Wow!\p"
	.string "Aber ich bin auch stark!\n"
	.string "Wirklich! Ganz ehrlich!$"

Route111_Text_ViviDefeat:
	.string "Was? Habe ich verloren?$"

Route111_Text_ViviPostBattle:
	.string "Das ist gemein…\p"
	.string "… Schluchz… Heul… Omaaaaa… Schluchz…$"

Route111_Text_VickyIntro:
	.string "Wie konntest du nur meine Enkelin zum\n"
	.string "Weinen bringen? Schäm dich!\p"
	.string "Dafür werde ich dich in Grund und Boden\n"
	.string "stampfen. Mach dich auf was gefasst!$"

Route111_Text_VickyDefeat:
	.string "Uaah! Du bist stark…\n"
	.string "Meine Enkelin hatte Recht…$"

Route111_Text_VickyPostBattle:
	.string "Wenn du es nicht allzu eilig hast,\n"
	.string "besuche uns doch mal wieder!$"

Route111_Text_ToughToKeepWinningUpTheRanks:
	.string "Wenn du deine POKéMON nicht ein\n"
	.string "bisschen besser trainierst, wird es\l"
	.string "schwer, sich hier durchzukämpfen.\p"
	.string "Ich habe gehört, dass die TOP VIER der\n"
	.string "POKéMON LIGA um einiges schwerer zu\l"
	.string "besiegen sind als die ARENALEITER.$"

Route111_Text_WinstrateFamilyDestroyedMe:
	.string "Ich habe die Familie SIHGERS heraus-\n"
	.string "gefordert und viermal hintereinander\l"
	.string "gekämpft… Hinterher war ich kaputt…$"

Route111_Text_RouteSignMauville:
	.string "ROUTE 111\n"
	.string "{DOWN_ARROW} MALVENFROH CITY$"

Route111_Text_WinstrateHouseSign:
	.string "DAS HAUS DER SIHGERS\n"
	.string "“Die Herzen unserer Familie schlagen im\l"
	.string "Einklang!”$"

Route111_Text_RouteSign112:
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 112$"

Route111_Text_RouteSign113:
	.string "ROUTE 111\n"
	.string "{LEFT_ARROW} ROUTE 113$"

Route111_Text_OldLadysRestStopSign:
	.string "HOTEL DER ALTEN DAME\n"
	.string "“Komm, ruh deine müden Knochen aus.”$"

Route111_Text_TrainerTipsSpAtkSpDef:
	.string "TIPPS für TRAINER\p"
	.string "Ein Indikator für die Stärke eines\n"
	.string "POKéMON ist der SP. ANG. Das steht\l"
	.string "für “SPEZIAL ANGRIFF”.\p"
	.string "SP. VER. steht für “SPEZIAL\n"
	.string "VERTEIDIGUNG”.$"

Route111_Text_ShouldBeMirageTowerAroundHere:
	.string "Hier in der Nähe sollte eigentlich ein\n"
	.string "Turm sein, der ganz aus Sand besteht.\p"
	.string "Aber aus irgendeinem Grund ist er\n"
	.string "nur manchmal sichtbar.\p"
	.string "Deshalb nenne ich ihn WUNDERTURM.$"

Route111_Text_MirageTowerClearlyVisible:
	.string "Ich sehe ihn!\n"
	.string "Den Turm aus Sand!\p"
	.string "Der Sandturm, den sie ein Wunder\n"
	.string "nennen, zeigt sich!\p"
	.string "Aber er sieht sehr brüchig aus…\n"
	.string "Er kann jeden Moment zusammenbrechen…\p"
	.string "Ich würde gerne mal hineingehen, aber\n"
	.string "so mutig bin ich dann doch nicht…$"

Route111_Text_ThatWasShockingSandRainedDown:
	.string "Whoa…\n"
	.string "Das war vielleicht ein Schreck!\p"
	.string "Plötzlich war überall Sand.\p"
	.string "Und wie war es da drin?\n"
	.string "Gibt es da Sandgeister und so?$"

Route111_Text_MirageTowerHasntBeenSeenSince:
	.string "Seit ich das letzte Mal mit dir\n"
	.string "gesprochen habe, ist der Turm noch\l"
	.string "nicht wieder sichtbar gewesen.\p"
	.string "Vielleicht war es wirklich der\n"
	.string "WUNDERTURM…$"

Route111_Text_ClawFossilDisappeared:
	.string "Das KLAUENFOSSIL ist im Sand\n"
	.string "versunken…$"

Route111_Text_RootFossilDisappeared:
	.string "Das WURZELFOSSIL ist im Sand\n"
	.string "versunken…$"

Route111_Text_MauvilleUncleToldMeToTakeRockSmash:
	.string "Oh, nein!\p"
	.string "Und mein Onkel in MALVENFROH CITY hat\n"
	.string "mir extra noch gesagt, ich soll\l"
	.string "ZERTRÜMMERER mitnehmen, wenn ich\p"
	.string "zur ROUTE 111 gehe.\n"
	.string "Mein Onkel? Der lebt gegenüber vom\l"
	.string "Fahrradladen in MALVENFROH.$"

Route111_Text_TrainerHillSign:
	.string "{RIGHT_ARROW} EINGANG TRAINERBERG\p"
	.string "“Erklimm den Gipfel, heißblütiger\n"
	.string "TRAINER!”$"

Route111_EventScript_Ende::
	msgbox Route111_Text_Ende, MSGBOX_SIGN
	end

Route111_Text_Ende::
	.string "Hey {PLAYER} wie gehts?\p"
	.string "Leider hört die Atkuelle Version\n"
	.string "hier auf. Für das Nächste Update\l"
	.string "musst du folgendes tun:\p"
	.string "Speichere IMMER vor einem update\n"
	.string "in dieser Höhle hier neben mir.\p"
	.string "Falls sich die map ändern sollte.$"
